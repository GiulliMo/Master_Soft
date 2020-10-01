#!/usr/bin/env python
# license removed for brevity

##################################################
## Author: Hannes Dittmann
## Version: 2.0
## Email: hannes.dittmann@stud.hshl.de
## Status: In Entwicklung
## unbedingt models einbinden in unterordner
##################################################



import rospy
from std_msgs.msg import String, Int16MultiArray, Int16, Float32MultiArray
from geometry_msgs.msg import PoseStamped
import tensorflow as tf
from libraries.asr import *
from libraries.nlp import *
import time


class recognizer:

    def __init__(self, recsec, language, nodename, topicnameTranscript, topicnameTask,topicnameTaskConfidence, topicnameBuzz, topicnameSub, topicnameModus, topicnameModusConfidence, topicnameGoal):

        # Eigenschaften der Klasse festlegen
        self.nodename = nodename
        self.topicnameTranscript = topicnameTranscript  # zum veroeffentlichen des deepspeech transkripts
        self.topicnameSub = topicnameSub  # subscriben des audio streams
        self.topicnameTask = topicnameTask  # veroeffentlichten der klassifizierten Handlung
        self.topicnameTaskConfidence = topicnameTaskConfidence  # Konfidenz der Klassifizierung
        self.topicnameBuzz = topicnameBuzz  # Schlagwoerter werden veroeffentlicht
        self.topicnameModus = topicnameModus  # modus autonom/manual
        self.topicnameModusConfidence = topicnameModusConfidence  # konfidenzen fuer modus klassifizierung
        self.topicnameGoal = topicnameGoal  # zielpose wird veroeffentlicht        self.chunksize = 2048
        self.rate = 16000
        self.recsec = recsec
        self.chunksize = 2048
        self.buffer = np.zeros(int(int(self.rate / self.chunksize * self.recsec) * self.chunksize))
        self.lstMsg = np.zeros(int(int(self.rate / self.chunksize * self.recsec) * self.chunksize))
        self.frames = []
        self.msgClass = Float32MultiArray() #Message fuer confidence veroeffentlichung
        self.msgClass.data = []
        self.msgModus = Float32MultiArray()#Message fuer confidence veroeffentlichung
        self.msgModus.data = []
        self.msgGoal = PoseStamped()
        self.asr = asr(language=language)
        self.nlp = nlp(rnn=False, embedded=True)
        self.class_names = self.nlp.class_names
        self.modus_names = self.nlp.modus_names
        self.recognizedBuzzwords = []
        self.ask = True


    ## ROS Initialiserung, Subscriber, und Publisher ##
    def callback(self, msg):
        self.buffer = np.int16(np.asarray(msg.data))


    # ROS Publisher definieren fuer gesamtes Transkript
    def talkerTranscript(self, size, text):

        pub = rospy.Publisher(self.topicnameTranscript, String, queue_size=size)
        rospy.loginfo(text)
        pub.publish(text)

    # ROS Publisher definieren fuer klassifizierte Handlung
    def talkerTask(self, size, text, size_confidence):

        pub = rospy.Publisher(self.topicnameTask, String, queue_size=size)
        pub2 = rospy.Publisher(self.topicnameTaskConfidence, Float32MultiArray, queue_size=size_confidence)

        rospy.loginfo(text)
        pub.publish(text)

        rospy.loginfo(self.msgClass.data)
        pub2.publish(self.msgClass)

    # ROS Publisher definieren fuer klassifizierten Modus
    def talkerModus(self, size, text, size_confidence):

        pub = rospy.Publisher(self.topicnameModus, String, queue_size=size)
        pub2 = rospy.Publisher(self.topicnameModusConfidence, Float32MultiArray, queue_size=size_confidence)

        rospy.loginfo(text)
        pub.publish(text)

        rospy.loginfo(self.msgModus.data)
        pub2.publish(self.msgModus)

    # ROS Publisher definieren fuer erkanntes Objekt/Person etc. aus Buzzword matcher
    def talkerBuzz(self, size, text):

        pub = rospy.Publisher(self.topicnameBuzz, String, queue_size=size)

        rospy.loginfo(text)
        pub.publish(text)

    # ROS Publisher definieren um Zielpose zu veroeffentlichen
    def talkerGoal(self, poseName, data):

        pub = rospy.Publisher(self.topicnameGoal, PoseStamped, queue_size=10)

        self.msgGoal.header.frame_id = "map"
        self.msgGoal.pose.position.y = data[0]
        self.msgGoal.pose.position.x = data[1]
        self.msgGoal.pose.position.z = data[2]
        self.msgGoal.pose.orientation.x = data[3]
        self.msgGoal.pose.orientation.y = data[4]
        self.msgGoal.pose.orientation.z = data[5]
        self.msgGoal.pose.orientation.w = data[6]
        self.msgGoal.header.stamp = rospy.Time.now()

        rospy.loginfo("Publish pose: " + poseName)
        pub.publish(self.msgGoal)

        # ausgeben von Ton der destination

    ## Methode um Datenstrom abhaengig der Aufnahmedauer zusammenzusetzen ##
    def processDataStream(self):
        self.lstMsg = np.int16(np.asarray(self.buffer))
        try:
            # msg.data als array abspeichern
            self.frames = np.asarray(self.buffer)

            self.asr.createWav(filename="transcript.wav", frames=self.frames)
            # Aufruf Transkriptionsmethode
            # speechtotext = deepspeech ==> self.frames
            # speechtotextpockesphinx = pocketsphinx ==> self.frames
            # speechtotextIBM = ibm ==> wavfile
            # speechtotextEspnnet = espnet ==> wavfile

            # where the magic happen
           # self.asr.speechtotext(self.frames)
           #self.asr.speechtotextESPnet(wavfile="transcript.wav")
            self.asr.speechtotextPocketSphinx(stream=self.frames)

        except KeyboardInterrupt:
            print("Keyboard Interrupt")
        pass

    def classifierPostProcessing(self, classified, mode):


        self.nlp.texttospeech( "i understand " + self.asr.transcript)

        # festlegen von konfidenzleveln bei unkritischen (wait und stop) deutlich geringer als bei fahraufgaben
        threshold_modus = 0.65 #threshold fuer modus autonom oder manuell
        threshold_drive = 0.7
        threshold_slam = 0.7
        threshold_waitfor = 0.5
        threshold_localization = 0.5
        threshold_stop = 0.5
        threshold_unknow = 0.5

        # drive to = 0
        # slam = 1
        # wait for = 2
        # localization = 3
        # stop = 4
        # unknow = 5

        #veroeffentlichung der klassifizierten Handlunge und Ziele etc.
        if classified == self.class_names[0] and self.msgClass.data[np.argmax(self.msgClass.data)]>threshold_drive:

            # veroeffentlichen von erkannter handlung und konfidenz DRIVE TO
            self.talkerTask(len(self.class_names[np.argmax(self.msgClass.data)]), self.class_names[np.argmax(self.msgClass.data)], len(self.class_names))
            self.ask = False
            cnt = 0

            ## Hier wird nach einem Ziel nachgefragt, solange bis "exit" gesagt wird
            while not rospy.is_shutdown():

                time.sleep(0.01)

                # ein ziel und klasse 0 oder eine person und klasse 2 aus buzzwords und wenn modus auch autonom dann wird sofort veroeffentlicht
                if len(self.recognizedBuzzwords)==1 and (self.recognizedBuzzwords[0]['buzzword'][0]['class'] == 0 or self.recognizedBuzzwords[0]['buzzword'][0]['class'] == 2) and (mode == self.modus_names[0] and self.msgModus.data[np.argmax(self.msgModus.data)]>threshold_modus):

                    # tonausgabe des verstandenen Transcripts
                    time.sleep(1.0)
                    self.nlp.texttospeech("i found " + self.recognizedBuzzwords[0]['buzzword'][0]['name'] + " as a buzzword and its a valid destination")
                    rospy.loginfo("Valid location!")

                    # Veroeffentlichung autonomer modus und konfidenz
                    self.talkerModus(len(self.modus_names[np.argmax(self.msgModus.data)]),self.modus_names[np.argmax(self.msgModus.data)], len(self.modus_names))

                    # Veroeffentlichung des Ziels

                    ## Ziel oder Schlagwort veroeffentlichen?
                    ## Gggf nur Schlagwort um Ziel in SImulink zu verarbeiten

                    self.talkerGoal(self.recognizedBuzzwords[0]['buzzword'][0]['name'], self.recognizedBuzzwords[0]['buzzword'][0]['value'])
                    break

                # uerberpruefen ob autonom mit 0.6 prozent anliegt, dann wird nach Ziel gefragt bis  eines anliegt oder exit gesagt wird
                elif mode == self.modus_names[0] and self.msgModus.data[np.argmax(self.msgModus.data)]>threshold_modus and len(self.recognizedBuzzwords)==0:

                    # tonausgabe
                    self.nlp.texttospeech("i found" + "no valid location push start and repeat your target!")
                    rospy.loginfo("No valid location, push start and repeat your goal!")  # tts

                    # veroeffentlichung autonomer modus und konfidenz
                    self.talkerModus(len(self.modus_names[np.argmax(self.msgModus.data)]),self.modus_names[np.argmax(self.msgModus.data)], len(self.modus_names))

                    ## Hier wird nach einem Ziel nachgefragt, solange bis "exit" gesagt wird, da er autonom schon hat
                    while not rospy.is_shutdown():

                        checksum = sum(self.lstMsg - self.buffer)  # letzte Message gleich neuer? wenn gleich verwerfen

                        if not checksum == 0:

                            ## hier geht er nur hin wenn eine neue message da ist, checksumme ungleich 0
                            # Audio verarbeiten und auf Buzzwords checken
                            self.processDataStream()
                            self.nlp.getAlfBuzzWords(self.asr.transcript)
                            self.recognizedBuzzwords = self.nlp.recognizedBuzzwords

                            # laenge 1 und classe 0 oder 1 dann valide position
                            if len(self.recognizedBuzzwords)==1 and (self.recognizedBuzzwords[0]['buzzword'][0]['class'] == 0 or self.recognizedBuzzwords[0]['buzzword'][0]['class'] == 2):
                                self.nlp.texttospeech("i understand " + self.recognizedBuzzwords[0]['buzzword'][0]['name'] + " as a buzzword")
                                rospy.loginfo("Valid location!")

                                # veröffentlichung des Ziels

                                ## Ziel oder Schlagwort veroeffentlichen?
                                ## Gggf nur Schlagwort um Ziel in SImulink zu verarbeiten
                                
                                self.talkerGoal(self.recognizedBuzzwords[0]['buzzword'][0]['name'], self.recognizedBuzzwords[0]['buzzword'][0]['value'])
                                break

                            elif len(self.recognizedBuzzwords)==1 and self.recognizedBuzzwords[0]['buzzword'][0]['name'] == "exit":
                                self.nlp.texttospeech("Exit target finding Process")
                                rospy.loginfo("Exit target finding!")
                                break

                            else:
                                self.nlp.texttospeech("i understand " + "no valid location push start and repeat your goal!")
                                rospy.loginfo("No valid location, push start and repeat your goal!")

                        time.sleep(0.01)


                # ueberpruefen ob manuell mit 0,6 prozent anliegt wenn ja, veroeffentlichen ==> Joystick rumfahren
                elif mode == self.modus_names[1] and self.msgModus.data[np.argmax(self.msgModus.data)] > threshold_modus:
                    # veroeffentlichung manueller modus wenn konfidenz groesser als 0.6 ist
                    self.talkerModus(len(self.modus_names[np.argmax(self.msgModus.data)]), self.modus_names[np.argmax(self.msgModus.data)], len(self.modus_names))
                    break

                # autonom oder manuell erfragen da konfidenzen nicht ausreichten (kein valider modus) ==> Danach wird noch ein Ziel abgefragt
                else:

                    # damit nur eine Ausgabe bei durch die while schleifen kommt
                    if cnt == 0:
                        self.nlp.texttospeech("i understand " + "no valid mode push start and repeat your mode!")
                        rospy.loginfo("No valid mode, push start and repeat your mode!")
                        cnt = 1

                    checksum = sum(self.lstMsg - self.buffer)  # letzte Message gleich neuer? wenn gleich verwerfen

                    # standard fuer transkript und audio holen
                    if not checksum == 0:

                        ## hier geht er nur hin wenn eine neue message da ist, checksumme ungleich 0
                        # Audio verarbeiten und auf Buzzwords checken
                        self.processDataStream()

                        # modus neu klassifizieren
                        self.classifierModus(self.asr.transcript)
                        mode = self.modus_names[np.argmax(self.msgModus.data)]

                        # zaehler ruecksetzen
                        cnt = 0


        ## Bei SLAM muss zwischen autonom und manuell unterschieden werden bzw gehandelt
        elif classified == self.class_names[1] and self.msgClass.data[np.argmax(self.msgClass.data)]>threshold_slam:

            # veroeffentlichung von erkannter Handlung un zugehoeriger konfidenz
            self.talkerTask(len(self.class_names[np.argmax(self.msgClass.data)]), self.class_names[np.argmax(self.msgClass.data)], len(self.class_names))
            self.ask = False
            cnt = 0

            # solange nachfragen bis klar ist welcher modus genutzt werden soll, oder exit gesagt wird
            while not rospy.is_shutdown():

                # ueberpruefen ob autonom mit 0,6 prozent anliegt wenn ja, veroeffentlichen
                if mode == self.modus_names[0] and self.msgModus.data[np.argmax(self.msgModus.data)] > threshold_modus:
                    # Veroeffentlichung autonomer modus und konfidenz
                    self.talkerModus(len(self.modus_names[np.argmax(self.msgModus.data)]),self.modus_names[np.argmax(self.msgModus.data)], len(self.modus_names))
                    break

                # ueberpruefen ob manuell mit 0,6 prozent anliegt wenn ja, veroeffentlichen
                elif mode == self.modus_names[1] and self.msgModus.data[np.argmax(self.msgModus.data)] > threshold_modus:
                    # Veroeffentlichung manueller modus wenn konfidenz groesser als 0.6 ist
                    self.talkerModus(len(self.modus_names[np.argmax(self.msgModus.data)]),self.modus_names[np.argmax(self.msgModus.data)], len(self.modus_names))
                    break

                # exit strategie wenn man keine lust mehr hat nachzufragen
                elif len(self.recognizedBuzzwords) == 1 and self.recognizedBuzzwords[0]['buzzword'][0]['name'] == "exit":
                    self.nlp.texttospeech("Exit target finding process")
                    os.system(str)
                    rospy.loginfo("Exit mode finding for slam!")
                    break

                # autonom oder manuell erfragen da konfidenzen nicht ausreichten (kein valider modus)
                else:

                    if cnt == 0:
                        self.nlp.texttospeech("i understand " + "no valid mode push start and repeat your mode!")
                        rospy.loginfo("No valid mode, push start and repeat your mode!")
                        cnt = 1

                    checksum = sum(self.lstMsg - self.buffer)  # letzte Message gleich neuer? wenn gleich verwerfen

                    if not checksum == 0:

                        ## hier geht er nur hin wenn eine neue message da ist, checksumme ungleich 0
                        # Audio verarbeiten und auf Buzzwords checken
                        self.processDataStream()

                        # Schlagwort erzeugen um exit bedienen zu koennen
                        self.getAlfBuzzWords(self.asr.transcript)
                        self.recognizedBuzzwords = self.nlp.recognizedBuzzwords

                        # modus neu klassifizieren
                        self.classifierModus(self.asr.transcript)
                        mode = self.modus_names[np.argmax(self.msgModus.data)]

                        # zaehler ruecksetzen
                        cnt = 0

                time.sleep(0.01)


        # keine Unterscheidung bei WAIT FOR (manuell oder autonom)
        elif classified == self.class_names[2] and self.msgClass.data[np.argmax(self.msgClass.data)]>threshold_waitfor:

            # veroeffentlichung von erkannter Handlung un zugehoeriger konfidenz
            self.talkerTask(len(self.class_names[np.argmax(self.msgClass.data)]),self.class_names[np.argmax(self.msgClass.data)], len(self.class_names))
            self.ask = False

        # keine Unterscheidung bei LOCALIZATION
        elif classified == self.class_names[3] and self.msgClass.data[np.argmax(self.msgClass.data)]>threshold_localization:

            # veroeffentlichung von erkannter Handlung un zugehoeriger konfidenz
            self.talkerTask(len(self.class_names[np.argmax(self.msgClass.data)]), self.class_names[np.argmax(self.msgClass.data)], len(self.class_names))
            self.ask = False

        # keine Unterscheidung bei STOP
        elif classified == self.class_names[4] and self.msgClass.data[np.argmax(self.msgClass.data)]>threshold_stop:

            # veroeffentlichung von erkannter Handlung un zugehoeriger konfidenz
            self.talkerTask(len(self.class_names[np.argmax(self.msgClass.data)]),self.class_names[np.argmax(self.msgClass.data)], len(self.class_names))
            self.ask = False

        # keine Unterscheidung bei UNKNOW
        elif classified == self.class_names[5] and self.msgClass.data[np.argmax(self.msgClass.data)]>threshold_unknow:

            # veroeffentlichung von erkannter Handlung un zugehoeriger konfidenz sowie sprachausgabe
            self.talkerTask(len(self.class_names[np.argmax(self.msgClass.data)]),self.class_names[np.argmax(self.msgClass.data)], len(self.class_names))
            self.nlp.texttospeech("i classified no valid task, pleas repeat your command")

            rospy.loginfo("No valid task classified, repeat your command!")
            self.ask = False

        # Kein threshold reicht aus ==> erneute eingabe
        if self.ask:
            self.nlp.texttospeech("i classified no valid task, pleas repeat your command")
            rospy.loginfo("No valid task classified, repeat your command!")

        self.ask = True

    # ROS Knoten initialisieren und Subscriber aufrufen
    def listener(self):

        # ROS-Knoten initialisieren
        rospy.init_node(self.nodename, anonymous=False)
        rospy.Subscriber(self.topicnameSub, Int16MultiArray, self.callback)

        # Alle Talker initialisieren
        self.talkerTranscript(size=1, text='init')
        self.talkerBuzz(size=1, text='init')
        self.talkerTask(size=1, text='init', size_confidence=0)
        self.talkerModus(size=1, text='init', size_confidence=0)
        self.talkerGoal(poseName="init", data=[0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0])

        while not rospy.is_shutdown():
            try:
                checksum = sum(self.lstMsg - self.buffer)  # letzte Message gleich neuer? wenn gleich verwerfen, wird ueperprueft durch array summe
                if not checksum == 0:

                    rospy.loginfo("Start recognition")
                    self.processDataStream()  # wird zyklisch
                    rospy.loginfo("Speech recognition finished")

                    # transkript in ROS veroeffentlichen
                    self.talkerTranscript(len(self.asr.transcript), self.asr.transcript)

                    # Schlagwoerter finden
                    self.nlp.getAlfBuzzWords(self.asr.transcript)
                    self.recognizedBuzzwords = self.nlp.recognizedBuzzwords

                    # Aufruf Methode um bedienungsorientierte Handlung zu klassifizieren
                    self.msgClass.data = self.nlp.classifierTask(self.asr.transcript)

                    # Aufruf der Modusklassifizierung
                    self.msgModus.data = self.nlp.classifierModus(self.asr.transcript)

                    ## veroeffentliche der klassifizierten handlung, modus und ziel nach nachbearbeitung
                    self.classifierPostProcessing(self.nlp.class_names[np.argmax(self.msgClass.data)], self.nlp.modus_names[np.argmax(self.msgModus.data)])

            except KeyboardInterrupt:
                print("Keyboard interrupt")
                break
            pass

# Main Methode
if __name__ == '__main__':


    # Klasse recognizer initialisieren
    # Parameter werden innerhalb der lauch
    r = recognizer(topicnameSub=rospy.get_param('pub/stream/topic'), language=rospy.get_param('language'),
                          nodename=rospy.get_param('nodename_speechrecognizer'), topicnameTranscript=rospy.get_param('topicname/transcript'),
                          topicnameTask=rospy.get_param('topicname/task'), topicnameBuzz=rospy.get_param('topicname/buzz'),
                          recsec=rospy.get_param('/audioStream/recsec'), topicnameTaskConfidence=rospy.get_param('topicname/task_confidence'),
                          topicnameModus = rospy.get_param('topicname/modus'), topicnameModusConfidence = rospy.get_param('topicname/modus_confidence'),
                          topicnameGoal = rospy.get_param('topicname/goal'))

    # ASR initialisieren
    r.asr.initModel()

    # NLP initialisieren
    r.nlp.buzzwords = r.nlp.loadJsons("models/buzzwords.json")
    r.nlp.words = r.nlp.readWords("models/words.txt")
    r.nlp.vocab_size = len(r.nlp.words)
    r.nlp.wordsModus = r.nlp.readWords("models/words_modus.txt")
    r.nlp.modelTaskClassifier = tf.lite.Interpreter("models/taskClassifierPhonWordEmbedding.tflite")
    r.nlp.modelModusClassifier = tf.lite.Interpreter("models/autonom_manual.tflite")
    r.nlp.modelTaskClassifier.allocate_tensors()

    # ROS initialisieren
    r.listener()