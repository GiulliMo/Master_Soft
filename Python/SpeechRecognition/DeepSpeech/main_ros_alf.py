#!/usr/bin/env python
# license removed for brevity

##################################################
## Author: Hannes Dittmann
## Version: 1.0
## Email: hannes.dittmann@stud.hshl.de
## Status: In Entwicklung
##################################################
## Kommentare:
## Dieses Skript dient dazu, eine transkription auf dem Raspberry Pi in Kombination mit dem Robot Operating System durchzufuehren
## Ein Deepspeech Modell muss mit passender Version vorliegen. Ein Datenstrom wird aus dem ROS-Netzwerk aufgenommen
## Es wird eine WAV Datei transkribiert, diese kann vorhanden sein, oder neu aufgenommen werden.
## Ein Tflite Modell zur bedienungsorientierten Handlungsklassifizierung muss mit entsprechender Wortliste vorliegen
## Wortliste, Buzzword.json und taskClassifier.tflie mueesen vorhanden sein

## python3 main_ros.pyr 5 -lm gb -tpp recognition -tps audio_stream -nn recognizer in Konsole auf dem ALF PC ausfuehren
## python audioStream_ros.py -di 7 -nn audio -tp audio_stream
## rosrun startbuttondetection startbuttondetection_node Knoten um Start Button als "Record-Ausloeser" aufzurufen

import os
import deepspeech
import rospy
from std_msgs.msg import String, Int16MultiArray, Int16, Float32MultiArray
from geometry_msgs.msg import PoseStamped
import time
import json
import phonetics
import nltk
from nltk.stem.lancaster import LancasterStemmer
stemmer = LancasterStemmer()
import tensorflow as tf
import numpy as np


def initModel(VERSION):

    # load and initialzie model for deepspeechenglish, ds 0.7.1 hast to be installed
    if VERSION == 'gb':
        model_file_path = 'models/deepspeech-0.7.1-models.tflite'
        model = deepspeech.Model(model_file_path)
        model.enableExternalScorer('models/deepspeech-0.7.1-models.scorer')
        model.setScorerAlphaBeta(alpha=1, beta=1.1)  # alpha=0.931289039105002, beta=1.1834137581510284)
        rospy.loginfo("Load finished!")

    elif VERSION == 'de':

        # load and initialize model for deepspeech-german, ds 0.6.1 hast to be installed
        DEEPSPEECH_MODEL_DIR = 'models'
        model_file_path = os.path.join(DEEPSPEECH_MODEL_DIR, 'output_graph.pb')
        BEAM_WIDTH = 500
        LM_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'lm.binary')
        TRIE_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'trie')
        LM_ALPHA = 1.0
        LM_BETA = 1.85
        model = deepspeech.Model(model_file_path, 500)
        model.enableDecoderWithLM(LM_FILE_PATH, TRIE_FILE_PATH, LM_ALPHA, LM_BETA)
        rospy.loginfo("Load finished!")

    return model

# Erzeugen der Klasse SpeechRecognition
class SpeechRecognition:

    def __init__(self, recsec,  pyVersion, nodename, topicnameTranscript, topicnameTask,topicnameTaskConfidence, topicnameBuzz, topicnameSub, topicnameModus, topicnameModusConfidence, topicnameGoal):

        # Definieren von Objekteigenschaften der Klasse Speech Recognition
        self.nodename = nodename
        self.topicnameTranscript = topicnameTranscript # zum veroeffentlichen des deepspeech transkripts
        self.topicnameSub = topicnameSub    # subscriben des audio streams
        self.topicnameTask = topicnameTask
        self.topicnameTaskConfidence = topicnameTaskConfidence
        self.topicnameBuzz = topicnameBuzz
        self.topicnameModus = topicnameModus
        self.topicnameModusConfidence = topicnameModusConfidence
        self.topicnameGoal = topicnameGoal
        self.Version = pyVersion
        self.chunksize = 2048
        self.rate = 16000
        self.recsec = recsec
        self.modelDs = initModel(self.Version)
        self.modelTaskClassifier = tf.lite.Interpreter("models/taskClassifierPhon.tflite")
        self.modelModusClassifier = tf.lite.Interpreter("models/autonom_manual.tflite")
        self.buffer = np.zeros(int(self.rate / self.chunksize) * self.recsec * self.chunksize)
        self.frames = []
        self.lstMsg = np.zeros(int(self.rate / self.chunksize) * self.recsec * self.chunksize)
        self.buzzwords = []
        self.recognizedBuzzwords = []
        self.transcript = []
        self.words = [0]
        self.wordsModus = [0]
        self.msgClass = Float32MultiArray() #Message fuer confidence veroeffentlichung
        self.msgClass.data = []
        self.msgModus = Float32MultiArray()#Message fuer confidence veroeffentlichung
        self.msgModus.data = []
        self.msgGoal = PoseStamped()
        self.class_names = ['drive to', 'slam', 'wait for', 'localization', 'stop', 'unknow']
        self.ask = True

    ## Methoden um Schlagwoerter in transcript zu finden

    # Pattern Matcher um Schlagwoerter zu finden
    def Rabin_Karp_Matcher(self, text, pattern, d, q):
        n = len(text)
        m = len(pattern)
        h = pow(d, m - 1) % q
        p = 0
        t = 0
        result = []
        if len(text) >= len(pattern):
            for i in range(m):  # preprocessing
                p = (d * p + ord(pattern[i])) % q
                t = (d * t + ord(text[i])) % q
            for s in range(n - m + 1):  # note the +1
                if p == t:  # check character by character
                    match = True
                    for i in range(m):
                        if pattern[i] != text[s + i]:
                            match = False
                            break
                    if match:
                        result = result + [s]
                if s < n - m:
                    t = (t - h * ord(text[s])) % q  # remove letter s
                    t = (t * d + ord(text[s + m])) % q  # add letter s+m
                    t = (t + q) % q  # make sure that t >= 0
            return result  # begin of string position

    # String-Array zu einem String
    def converttoStr(self, s):
        # initialization of string to ""
        new = ""
        # traverse in the string
        for x in s:
            new += x + " "
        # return string
        return new

    # Schlagwort- und Transitionsliste laden
    def loadJsons(self):

        f = open("models/buzzwords.json", "r")
        self.buzzwords = json.loads(f.read())
        f.close()

    # Wortliste fuer Bedienungsorientierte Klassifizierung laden
    def readWords(self):

        file = open("models/words.txt", 'r')
        words = [line.split(',') for line in file.readlines()]
        words = words[0]
        self.words = words[0:len(words) - 1]  # split fuegt ein wort hinzu wo keins hinsoll
        file.close()

        file2 = open("models/words_modus.txt", 'r')
        words = [line.split(',') for line in file2.readlines()]
        words = words[0]
        self.wordsModus = words[0:len(words) - 1]  # split fuegt ein wort hinzu wo keins hinsoll
        file2.close()

    # Methonde um nur Wortstaemme beachten
    def clean_up_sentence(self, sentence):

        # tokenize the pattern
        sentence_words = nltk.word_tokenize(sentence)

        # stem each word
        sentence_words = [stemmer.stem(word.lower()) for word in sentence_words]
        return sentence_words

    # return bag of words array: 0 or 1 for each word in the bag that exists in the sentence
    def bow(self, sentence, words, show_details=True):

        # tokenize the pattern
        sentence_words = self.clean_up_sentence(sentence)
        # bag of words
        bag = [0] * len(words)
        for s in sentence_words:
            for i, w in enumerate(words):
                if w == s:
                    bag[i] = 1
                    if show_details:
                        print("found in bag: %s" % w)
        return (np.array(bag))

    # Methode um Rohdaten aus WAV Datei zu lesen
    def getBuffer(self, w):
        frames = w.getnframes()
        buffer = w.readframes(frames)
        type(buffer)
        return (buffer)

    # Methode um Schlagwoerter zu finden
    def getAlfBuzzWords(self):

        self.recognizedBuzzwords = []
        buzz = []
        # Apostroph wird mit leerzeichen ersetzt
        self.transcript = self.transcript.replace("'", "")
        res = self.transcript.split()
        phoneResSoundex = []
        # phoneResNysi = []

        # phonetischen code der transkription nach Soundex
        for k in range(len(res)):
            # phoneResMetaphone.append(phonetics.metaphone(res[k]))
            phoneResSoundex.append(phonetics.soundex(res[k]))
            # phoneResNysi.append(phonetics.nysiis(res[k]))

        # phonetischen code der transkription nach metaphone
        phoneResMetaphone = phonetics.metaphone(self.transcript.replace(" ", ""))
        # print(phoneResMetaphone)

        # Sind Schalgwoerter in dem Transcript, wenn eines vorhanden ist
        if self.transcript:

            for i in range(len(self.buzzwords)):

                # Pruefe auf direktes match
                if self.Rabin_Karp_Matcher(self.transcript, self.buzzwords[i]['buzzword'][0]['name'], 257,
                                           11):  # is there a buzzword?
                    self.recognizedBuzzwords.append(self.buzzwords[i])  # ['buzzword'][0]['name'])  # Buzzword to list
                    buzz.append(self.buzzwords[i]['buzzword'][0]['name'])
                # Pruefe auf phonetische uebereinstimmung nach Metaphone Codierung
                elif self.Rabin_Karp_Matcher(phoneResMetaphone,
                                             phonetics.metaphone(self.buzzwords[i]['buzzword'][0]['name']), 257,
                                             11):
                    self.recognizedBuzzwords.append(self.buzzwords[i])  # ['buzzword'][0]['name'])  # Buzzword to list
                    buzz.append(self.buzzwords[i]['buzzword'][0]['name'])

                # Pruefe auf phonetische uebereinstimmung nach Soundex Codierung
                elif self.Rabin_Karp_Matcher(self.converttoStr(phoneResSoundex),
                                             phonetics.soundex(self.buzzwords[i]['buzzword'][0]['name']), 257, 11):
                    self.recognizedBuzzwords.append(self.buzzwords[i])  # ['buzzword'][0]['name'])  # Buzzword to list
                    buzz.append(self.buzzwords[i]['buzzword'][0]['name'])
                # Pruefe auf phonetisches match nach Nysii codierung
                # elif self.Rabin_Karp_Matcher(self.converttoStr(phoneResNysi), phonetics.nysiis(self.buzzwords[i]['buzzword'][0]['name']), 257, 11):
                # recognizedBuzzwords.append(self.buzzwords[i]['buzzword'][0]['id'])  # Buzzword to list
            my_string = ','.join(buzz)

            if not my_string:

                rospy.loginfo('No valid buzzwords found')

            elif my_string:
                rospy.loginfo(my_string)
                self.talkerBuzz(len(my_string), my_string)

    def classifierPostProcessing(self, classified):

        # drive to = 0
        # slam = 1
        # wait for = 2
        # localization = 3
        # stop = 4
        # unknow = 5

        # ausgabe des transcripts tts
        # print(self.transcript)
        str = "rosrun sound_play say.py" + " " + "'" + "i understand " + self.transcript + "'"
        os.system(str)

        if classified == self.class_names[0] and self.msgClass.data[np.argmax(self.msgClass.data)]>0.7:

                if len(self.recognizedBuzzwords)==1 and (self.recognizedBuzzwords[0]['buzzword'][0]['class'] == 0 or self.recognizedBuzzwords[0]['buzzword'][0]['class'] == 2):
                        # tonausgabe
                        time.sleep(2.0)
                        str = "rosrun sound_play say.py" + " " + "'"+"i found " + self.recognizedBuzzwords[0]['buzzword'][0]['name'] + " as a buzzword and its a valid destination" +"'"
                        os.system(str)
                        rospy.loginfo("Valid location!")
                        # veröffentlichung des ziels
                else:
                    # tonausgabe
                    str = "rosrun sound_play say.py" + " " + "'" + "but " + "no valid location       push start and repeat your goal!" + "'"
                    os.system(str)
                    rospy.loginfo("No valid location, push start and repeat your goal!")  # tts

                    while not rospy.is_shutdown():
                        try:
                            checksum = sum(self.lstMsg - self.buffer)  # letzte Message gleich neuer? wenn gleich verwerfen

                            if not checksum == 0:
                                ## hier geht er nur hin wenn eine neue message da ist, checksumme ungleich 0
                                self.processDataStream(self.buffer)
                                self.getAlfBuzzWords()

                                if len(self.recognizedBuzzwords)==1 and (self.recognizedBuzzwords[0]['buzzword'][0]['class'] == 0 or self.recognizedBuzzwords[0]['buzzword'][0]['class'] == 2):
                                    str = "rosrun sound_play say.py" + " " + "'" + "i understand " + self.recognizedBuzzwords[0]['buzzword'][0]['name'] + "and its a valid location" + "'"
                                    os.system(str)
                                    rospy.loginfo("Valid location!")
                                    break

                                elif len(self.recognizedBuzzwords)==1 and self.recognizedBuzzwords[0]['buzzword'][0]['name'] == "exit":
                                    str = "rosrun sound_play say.py" + " " + "'" + "exit request" + "'"
                                    os.system(str)
                                    rospy.loginfo("Exit request!")
                                    #tonausgabe
                                    break

                                else:
                                    str = "rosrun sound_play say.py" + " " + "'" + "i understand " + "no valid location       push start and repeat your goal!" + "'"
                                    os.system(str)
                                    rospy.loginfo("No valid location, push start and repeat your goal!")
                                    #tonausgabe

                        except KeyboardInterrupt:
                            print("Keyboard interrupt")
                        pass

        '''
        elif classified == self.class_names[1]:

        elif classified == self.class_names[2]:

        elif classified == self.class_names[3]:

        elif classified == self.class_names[4]:

        elif classified == self.class_names[5]:
        '''
    # Methode um Handlungen und Modus zu klassifizieren
    def classifierNN(self, transcript):

        try:
            self.modelTaskClassifier.allocate_tensors()
            self.modelModusClassifier.allocate_tensors()

            # Bearbeiten Transcript
            transcript = transcript.replace("'", "")
            res = transcript.split()
            phoneRes = []
            for k in res:
                phoneRes.append(phonetics.metaphone(k))

            transcript = transcript + ' ' + ' '.join(phoneRes)
            print(transcript)


            #  Ein- und Ausgabe Tensoren bestimmen
            input_details = self.modelTaskClassifier.get_input_details()
            output_details = self.modelTaskClassifier.get_output_details()
            input_shape = input_details[0]['shape']

            # Eingabe Tensor definieren
            input = self.bow(transcript.lower(), self.words, show_details=False)
            input = np.reshape(input, (input_shape[0], input_shape[1])) #input_shape[0], input_shape[1]) -1, input_shape[1], input_shape[2]fuer normales Netz ohne rnn
            input_data = np.array(input, dtype=np.float32)

            # Eingabe Tensor setzen
            self.modelTaskClassifier.set_tensor(input_details[0]['index'], input_data)
            self.modelTaskClassifier.invoke()

            # Ausgabe Tensor berechnen
            output_data = self.modelTaskClassifier.get_tensor(output_details[0]['index'])

            # Ausgabe der Klassifizierung
            #print(output_data, class_names[np.argmax(output_data)])
            self.msgClass.data = output_data[0]
            self.talkerTask(len(self.class_names[np.argmax(output_data)]), self.class_names[np.argmax(output_data)],len(self.class_names))

            # classes of training data
            # drive to = 0
            # slam = 1
            # wait for = 2
            # localization = 3
            # stop = 4


            ## Autonon // manual


            #  Ein- und Ausgabe Tensoren bestimmen
            input_details = self.modelModusClassifier.get_input_details()
            output_details = self.modelModusClassifier.get_output_details()
            input_shape = input_details[0]['shape']

            # Eingabe Tensor definieren
            input = self.bow(transcript.lower(), self.wordsModus, show_details=False)
            input = np.reshape(input,(input_shape[0], input_shape[1]))  # input_shape[0], input_shape[1]) fuer normales Netz
            input_data = np.array(input, dtype=np.float32)

            # Eingabe Tensor setzen
            self.modelModusClassifier.set_tensor(input_details[0]['index'], input_data)
            self.modelModusClassifier.invoke()

            # Ausgabe Tensor berechnen
            output_data = self.modelModusClassifier.get_tensor(output_details[0]['index'])
            class_namesModus = ['autonom', 'manual']

            # Ausgabe der Klassifizierung
            # print(output_data, class_names[np.argmax(output_data)])
            self.msgModus.data = output_data[0]
            self.talkerModus(len(class_namesModus[np.argmax(output_data)]), class_namesModus[np.argmax(output_data)], len(class_namesModus))

        except KeyboardInterrupt:
            print("Keyboard Interrupt")
        pass

    # Methode um Sprache zu transkripieren
    def speechRecognitionDNN(self, stream):

        # Recognition from record
        try:
            rospy.loginfo("Start recognition")
            start = time.time()

            #Transkription erzeugen
            self.transcript = self.modelDs.stt(stream)

            if not self.transcript:
                self.transcript = "none"

            #Transkript in ROS veroeffentlichen
            self.talkerTranscript(len(self.transcript), self.transcript)
            print(self.transcript)
            rospy.loginfo("Speech recognition finished")

            # Zeit fuer Transkription berechnen
            print(time.time() - start)

        except KeyboardInterrupt:
            print("Keyboard Interrupt")
        pass

    # Methode um Datenstrom abhaengig der Aufnahmedauer zusammenzusetzen
    def processDataStream(self, data):
        self.lstMsg = np.int16(np.asarray(data))

        try:
            # msg.data als array abspeichern
            self.frames = np.asarray(data)
            # int16 als Eingabe fuer Deepspeech Model
            data16 = np.frombuffer(np.asarray(self.frames), dtype=np.int16)
            # Aufruf Transkriptionsmethode
            self.speechRecognitionDNN(data16)

        except KeyboardInterrupt:
            print("Keyboard Interrupt")
        pass

    ## ROS Initialiserung, Subscriber, und Publisher ##

    def callback(self, msg):
        self.buffer = np.int16(np.asarray(msg.data))

    # ROS Knoten initialisieren und Subscriber aufrufen
    def listener(self):
        rospy.init_node(self.nodename, anonymous=False)
        rospy.Subscriber(self.topicnameSub, Int16MultiArray, self.callback)
        # talker initialisieren
        self.talkerTranscript(size=1, text='init')
        self.talkerBuzz(size=1, text='init')
        self.talkerTask(size=1, text='init', size_confidence=0)
        self.talkerModus(size=1, text='init', size_confidence=0)
        self.talkerGoal(poseName="init", data =0)
        r = rospy.Rate(0.05)

        while not rospy.is_shutdown():
            try:
                checksum = sum(self.lstMsg - self.buffer)  # letzte Message gleich neuer? wenn gleich verwerfen
                if not checksum == 0:
                    ## hier geht er nur hin wenn eine neue message da ist, checksumme ungleich 0
                    self.processDataStream(self.buffer)  # wird zyklisch
                    # Schlagwoerter finden
                    self.getAlfBuzzWords()
                    # Aufruf Methode um bedienungsorientierte Handlung zu klassifizieren
                    self.classifierNN(self.transcript)
                    ## veroeffentliche des resultierenden zieles
                    self.classifierPostProcessing(self.class_names[np.argmax(self.msgClass.data)])

            except KeyboardInterrupt:
                print("Keyboard interrupt")
            pass

    # ROS Publisher aufrufen fuer gesamtes Transkript
    def talkerTranscript(self, size, text):

        pub = rospy.Publisher(self.topicnameTranscript, String, queue_size=size)
        rospy.loginfo(text)
        pub.publish(text)

    # ROS Publisher aufrufen fuer klassifizierte Handlung
    def talkerTask(self, size, text, size_confidence):

        pub = rospy.Publisher(self.topicnameTask, String, queue_size=size)
        pub2 = rospy.Publisher(self.topicnameTaskConfidence, Float32MultiArray, queue_size=size_confidence)

        rospy.loginfo(text)
        pub.publish(text)

        rospy.loginfo(self.msgClass.data)
        pub2.publish(self.msgClass)

    # ROS Publisher aufrufen fuer klassifizierten Modus
    def talkerModus(self, size, text, size_confidence):

        pub = rospy.Publisher(self.topicnameModus, String, queue_size=size)
        pub2 = rospy.Publisher(self.topicnameModusConfidence, Float32MultiArray, queue_size=size_confidence)

        rospy.loginfo(text)
        pub.publish(text)

        rospy.loginfo(self.msgModus.data)
        pub2.publish(self.msgModus)

    # ROS Publisher aufrufen fuer erkanntes Objekt/Person etc. aus Buzzword matcher
    def talkerBuzz(self, size, text):

        pub = rospy.Publisher(self.topicnameBuzz, String, queue_size=size)
        rospy.loginfo(text)
        pub.publish(text)

    def talkerGoal(self, poseName, data):

        pub = rospy.Publisher(self.topicnameGoal, PoseStamped, queue_size=10)

        self.msgGoal.header.frame_id = poseName
        self.msgGoal.pose.position.y = data
        self.msgGoal.pose.position.x = data
        self.msgGoal.pose.position.z = 0
        self.msgGoal.pose.orientation.x = 0
        self.msgGoal.pose.orientation.y = 0
        self.msgGoal.pose.orientation.z = 0
        self.msgGoal.pose.orientation.w = 0
        self.msgGoal.header.stamp = rospy.Time.now()

        rospy.loginfo("Publish pose" + " " + poseName)

        # ausgeben von Ton der destination

# Main Methode
if __name__ == '__main__':

    name = rospy.get_param("/audioStream/nodename/") + '/'

    #recsec,  pyVersion, nodename, topicnameTranscript, topicnameTask, topicnameBuzz, topicnameSub
    s = SpeechRecognition(topicnameSub=rospy.get_param(name + 'pub/stream/topic'), pyVersion=rospy.get_param(name + 'language'),
                          nodename=rospy.get_param(name + 'nodename_speechrecognizer'), topicnameTranscript=rospy.get_param(name + 'topicname/transcript'),
                          topicnameTask=rospy.get_param(name + 'topicname/task'), topicnameBuzz=rospy.get_param(name + 'topicname/buzz'),
                          recsec=rospy.get_param(name + 'recsec'), topicnameTaskConfidence=rospy.get_param(name + 'topicname/task_confidence'),
                          topicnameModus = rospy.get_param(name + 'topicname/modus'), topicnameModusConfidence = rospy.get_param(name + 'topicname/modus_confidence'),
                          topicnameGoal = rospy.get_param(name + 'topicname/goal'))
    s.loadJsons()
    s.readWords()
    s.listener()




