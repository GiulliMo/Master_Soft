#!/usr/bin/env python
# license removed for brevity

##################################################
## Author: Hannes Dittmann
## Version: 2.0
## Email: hannes.dittmann@stud.hshl.de
## Status: In Entwicklung
##################################################
## Kommentare:
## Dieses Skript dient dazu, eine transkription auf dem Raspberry Pi in Kombination mit dem Robot Operating System durchzufuehren
## Ein Deepspeech Modell muss mit passender Version vorliegen. Ein Datenstrom wird aus dem ROS-Netzwerk aufgenommen/abonniert
## Es wird eine WAV Datei transkribiert, diese kann vorhanden sein, oder neu aufgenommen werden.
## Ein Tflite Modell zur bedienungsorientierten Handlungsklassifizierung muss mit entsprechender Wortliste vorliegen
## Wortliste kann veraltet sein ==> "gleichverteilte" Wahrscheinlichkeiten
## Wortliste, Buzzword.json und taskClassifier.tflite mueesen vorhanden sein
## GGF muss der Input_tensor bei der Klassifizierung angepasst werden, wenn ein RNN/normales Netz verwendet werden

## python3 main_ros.pyr 5 -lm gb -tpp recognition -tps audio_stream -nn recognizer in Konsole auf dem ALF PC ausfuehren
## python audioStream_ros.py -di 7 -nn audio -tp audio_stream
## rosrun startbuttondetection startbuttondetection_node Knoten um Start Button als "Record-Ausloeser" aufzurufen

import os
import wave
import deepspeech
import pyaudio
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

    # load and initialzie model for deepspeechenglish, ds 0.7.4 hast to be installed
    if VERSION == 'gb':
        model_file_path = 'models/deepspeech-0.7.4-models.tflite'
        model = deepspeech.Model(model_file_path)
        model.enableExternalScorer('models/deepspeech-0.7.4-models.scorer')
        model.setScorerAlphaBeta(alpha=0.931289039105002, beta=1.1834137581510284)  # alpha=0.931289039105002, beta=1.1834137581510284)
       # model.setBeamWidth(500)
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
        self.topicnameTask = topicnameTask  # veroeffentlichten der klassifizierten Handlung
        self.topicnameTaskConfidence = topicnameTaskConfidence  # Konfidenz der Klassifizierung
        self.topicnameBuzz = topicnameBuzz  # Schlagwoerter werden veroeffentlicht
        self.topicnameModus = topicnameModus    # modus autonom/manual
        self.topicnameModusConfidence = topicnameModusConfidence    # konfidenzen fuer modus klassifizierung
        self.topicnameGoal = topicnameGoal  # zielpose wird veroeffentlicht
        self.Version = pyVersion # de oder gb
        self.chunksize = 2048
        self.rate = 16000
        self.recsec = recsec
        self.audio = pyaudio.PyAudio()
        self.Format = pyaudio.paInt16
        self.channels = 1
        self.modelDs = initModel(self.Version)
        self.modelTaskClassifier = tf.lite.Interpreter("models/taskClassifierRNN.tflite")
        self.modelModusClassifier = tf.lite.Interpreter("models/autonom_manualRNN.tflite")
        self.buffer = np.zeros(int(int(self.rate / self.chunksize) * self.recsec * self.chunksize))
        self.frames = []
        self.lstMsg = np.zeros(int(int(self.rate / self.chunksize) * self.recsec * self.chunksize))
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
        self.class_names = ['drive', 'slam', 'wait for', 'localization', 'stop', 'unknown']
        self.modus_names = ['autonom', 'manual']
        self.ask = True

    ## Methoden um Schlagwoerter in transcript zu finden

    # Pattern Matcher um Schlagwoerter in Transkript zu finden zu finden
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

    # Methonde um nur Wortstaemme zu beachten
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

    ## Methode um Schlagwoerter zu finden ##
    ## getALFBuzzwords Liste muss ggf weitergepflegt werden

    def getAlfBuzzWords(self):

        # leere Schlagwortliste anlegen
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
        #phoneResNysi = phonetics.nysiis(self.transcript.replace(" ", ""))


        # Sind Schalgwoerter in dem Transcript, wenn
        if self.transcript:

            for i in range(len(self.buzzwords)):

                # Pruefe auf direktes match
                if self.Rabin_Karp_Matcher(self.transcript, self.buzzwords[i]['buzzword'][0]['name'], 257, 11):  # is there a buzzword?
                    self.recognizedBuzzwords.append(self.buzzwords[i])  # ['buzzword'][0]['name'])  # Buzzword to list
                    buzz.append(self.buzzwords[i]['buzzword'][0]['name'])

                # Pruefe auf phonetische uebereinstimmung nach Metaphone Codierung
                elif self.Rabin_Karp_Matcher(phoneResMetaphone, phonetics.metaphone(self.buzzwords[i]['buzzword'][0]['name']), 257, 11):
                    self.recognizedBuzzwords.append(self.buzzwords[i])  # ['buzzword'][0]['name'])  # Buzzword to list
                    buzz.append(self.buzzwords[i]['buzzword'][0]['name'])

                # Pruefe auf phonetische uebereinstimmung nach Soundex Codierung
                elif self.Rabin_Karp_Matcher(self.converttoStr(phoneResSoundex), phonetics.soundex(self.buzzwords[i]['buzzword'][0]['name']), 257, 11):
                    self.recognizedBuzzwords.append(self.buzzwords[i])  # ['buzzword'][0]['name'])  # Buzzword to list
                    buzz.append(self.buzzwords[i]['buzzword'][0]['name'])

                # Pruefe auf phonetisches match nach Nysii codierung
                #elif self.Rabin_Karp_Matcher(self.converttoStr(phoneResNysi), phonetics.nysiis(self.buzzwords[i]['buzzword'][0]['name']), 257, 11):
                   #  self.recognizedBuzzwords.append(self.buzzwords[i])  # ['buzzword'][0]['name'])  # Buzzword to list
                    # buzz.append(self.buzzwords[i]['buzzword'][0]['name'])

            my_string = ','.join(buzz)

            if not my_string:

                rospy.loginfo('No valid buzzwords found')

            elif my_string:

                self.talkerBuzz(len(my_string), "Found the following buzzwords: " + my_string)


    ## Alles was fuer die Klassifizierung gebraucht wird ##

    def classifierPostProcessing(self, classified, mode):

        # ausgabe des transcripts tts
        # print(self.transcript)
        str = "rosrun sound_play say.py" + " " + "'" + "i understand " + self.transcript + "'"
        os.system(str)

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
                    str = "rosrun sound_play say.py" + " " + "'"+"i have " + self.recognizedBuzzwords[0]['buzzword'][0]['name'] + " as a buzzword and its a valid destination" +"'"
                    os.system(str)
                    rospy.loginfo("Valid location!")

                    # Veroeffentlichung autonomer modus und konfidenz
                    self.talkerModus(len(self.modus_names[np.argmax(self.msgModus.data)]),self.modus_names[np.argmax(self.msgModus.data)], len(self.modus_names))

                    # Veroeffentlichung des Ziels
                    self.talkerGoal(self.recognizedBuzzwords[0]['buzzword'][0]['name'], self.recognizedBuzzwords[0]['buzzword'][0]['value'])
                    break

                # uerberpruefen ob autonom mit 0.6 prozent anliegt, dann wird nach Ziel gefragt bis  eines anliegt oder exit gesagt wird
                elif mode == self.modus_names[0] and self.msgModus.data[np.argmax(self.msgModus.data)]>threshold_modus and len(self.recognizedBuzzwords)==0:

                    # tonausgabe
                    str = "rosrun sound_play say.py" + " " + "'" + "but " + "no valid location push start and repeat your goal!" + "'"
                    os.system(str)
                    rospy.loginfo("No valid location, push start and repeat your goal!")  # tts

                    # veroeffentlichung autonomer modus und konfidenz
                    self.talkerModus(len(self.modus_names[np.argmax(self.msgModus.data)]),self.modus_names[np.argmax(self.msgModus.data)], len(self.modus_names))

                    ## Hier wird nach einem Ziel nachgefragt, solange bis "exit" gesagt wird, da er autonom schon hat
                    while not rospy.is_shutdown():

                        checksum = sum(self.lstMsg - self.buffer)  # letzte Message gleich neuer? wenn gleich verwerfen

                        if not checksum == 0:

                            ## hier geht er nur hin wenn eine neue message da ist, checksumme ungleich 0
                            # Audio verarbeiten und auf Buzzwords checken
                            self.processDataStream(self.buffer)
                            self.getAlfBuzzWords()

                            # laenge 1 und classe 0 oder 1 dann valide position
                            if len(self.recognizedBuzzwords)==1 and (self.recognizedBuzzwords[0]['buzzword'][0]['class'] == 0 or self.recognizedBuzzwords[0]['buzzword'][0]['class'] == 2):
                                str = "rosrun sound_play say.py" + " " + "'" + "i understand " + self.recognizedBuzzwords[0]['buzzword'][0]['name'] + " as a buzzword" + "'"
                                os.system(str)
                                rospy.loginfo("Valid location!")

                                # veröffentlichung des Ziels
                                self.talkerGoal(self.recognizedBuzzwords[0]['buzzword'][0]['name'], self.recognizedBuzzwords[0]['buzzword'][0]['value'])
                                break

                            elif len(self.recognizedBuzzwords)==1 and self.recognizedBuzzwords[0]['buzzword'][0]['name'] == "exit":
                                str = "rosrun sound_play say.py" + " " + "'" + "Exit target finding" + "'"
                                os.system(str)
                                rospy.loginfo("Exit target finding!")
                                break

                            else:
                                str = "rosrun sound_play say.py" + " " + "'" + "i understand " + "no valid location push start and repeat your goal!" + "'"
                                os.system(str)
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
                        str = "rosrun sound_play say.py" + " " + "'" + "i understand " + "no valid mode push start and repeat your mode!" + "'"
                        os.system(str)
                        rospy.loginfo("No valid mode, push start and repeat your mode!")
                        cnt = 1

                    checksum = sum(self.lstMsg - self.buffer)  # letzte Message gleich neuer? wenn gleich verwerfen

                    # standard fuer transkript und audio holen
                    if not checksum == 0:

                        ## hier geht er nur hin wenn eine neue message da ist, checksumme ungleich 0
                        # Audio verarbeiten und auf Buzzwords checken
                        self.processDataStream(self.buffer)

                        # modus neu klassifizieren
                        self.classifierModus(self.transcript)
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
                    str = "rosrun sound_play say.py" + " " + "'" + "Exit target finding" + "'"
                    os.system(str)
                    rospy.loginfo("Exit mode finding for slam!")
                    break

                # autonom oder manuell erfragen da konfidenzen nicht ausreichten (kein valider modus)
                else:

                    if cnt == 0:
                        str = "rosrun sound_play say.py" + " " + "'" + "i understand " + "no valid mode push start and repeat your mode!" + "'"
                        os.system(str)
                        rospy.loginfo("No valid mode, push start and repeat your mode!")
                        cnt = 1

                    checksum = sum(self.lstMsg - self.buffer)  # letzte Message gleich neuer? wenn gleich verwerfen

                    if not checksum == 0:

                        ## hier geht er nur hin wenn eine neue message da ist, checksumme ungleich 0
                        # Audio verarbeiten und auf Buzzwords checken
                        self.processDataStream(self.buffer)

                        # Schlagwort erzeugen um exit bedienen zu koennen
                        self.getAlfBuzzWords()

                        # modus neu klassifizieren
                        self.classifierModus(self.transcript)
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

            # veroeffentlichung von erkannter Handlung un zugehoeriger konfidenz
            self.talkerTask(len(self.class_names[np.argmax(self.msgClass.data)]),self.class_names[np.argmax(self.msgClass.data)], len(self.class_names))
            str = "rosrun sound_play say.py" + " " + "'" + "i classified no valid task, pleas repeat your command" + "'"
            os.system(str)
            rospy.loginfo("No valid task classified, repeat your command!")
            self.ask = False

        # Kein threshold reicht aus ==> erneute eingabe
        if self.ask:
            str = "rosrun sound_play say.py" + " " + "'" + "i classified no valid task, pleas repeat your command" + "'"
            os.system(str)
            rospy.loginfo("No valid task classified, repeat your command!")

        self.ask = True



    ## Methode um Handlungen zu klassifizieren ##

    def classifierTask(self, transcript):

        try:

            self.modelTaskClassifier.allocate_tensors()

            ## Bearbeiten des Transcripts
            transcript = transcript.replace("'", "")
            res = transcript.split()
            phoneRes = []

            # phonetischen Teil mit metaphone bestimmen
            for k in res:
                phoneRes.append(phonetics.metaphone(k))
            transcript = transcript + ' ' + ' '.join(phoneRes)

            # Transcript mit phonetik ausgeben
            rospy.loginfo("Transcript mit phonetischen Anteil: " + transcript)

            #  Ein- und Ausgabe Tensoren bestimmen
            input_details = self.modelTaskClassifier.get_input_details()
            output_details = self.modelTaskClassifier.get_output_details()
            input_shape = input_details[0]['shape']

            # Eingabe Tensor definieren
            input = self.bow(transcript.lower(), self.words, show_details=False)
            input = np.reshape(input, (-1, input_shape[1], input_shape[2])) #input_shape[0], input_shape[1]) -1, input_shape[1], input_shape[2]fuer normales Netz ohne rnn
            input_data = np.array(input, dtype=np.float32)

            # Eingabe Tensor setzen
            self.modelTaskClassifier.set_tensor(input_details[0]['index'], input_data)
            self.modelTaskClassifier.invoke()

            # Ausgabe Tensor berechnen
            output_data = self.modelTaskClassifier.get_tensor(output_details[0]['index'])

            # Ausgabe der Klassifizierung bzw zwischenspeichern
            #print(output_data, class_names[np.argmax(output_data)])
            self.msgClass.data = output_data[0]
            print(self.msgClass.data )
            #self.talkerTask(len(self.class_names[np.argmax(self.msgClass.data)]), self.class_names[np.argmax(self.msgClass.data)], len(self.class_names))

            # classes of training data
            # drive to = 0
            # slam = 1
            # wait for = 2
            # localization = 3
            # stop = 4
            # unknow = 5
        except KeyboardInterrupt:
            print("Keyboard Interrupt")
        pass

    ## Autonom// manual klassifzieren ##
    #eigentlich fast das gleiche wie taskclassifier nur anderer Tflite interpreter

    def classifierModus(self, transcript):
        self.modelModusClassifier.allocate_tensors()
        try:

            # Bearbeiten Transcript
            transcript = transcript.replace("'", "")
            res = transcript.split()
            phoneRes = []

            # phonetischen Teil fuer eingangs Tensor setzen
            for k in res:
                phoneRes.append(phonetics.metaphone(k))

            transcript = transcript + ' ' + ' '.join(phoneRes)

            #  Ein- und Ausgabe Tensoren bestimmen
            input_details = self.modelModusClassifier.get_input_details()
            output_details = self.modelModusClassifier.get_output_details()
            input_shape = input_details[0]['shape']

            # Eingabe Tensor definieren
            input = self.bow(transcript.lower(), self.wordsModus, show_details=False)
            input = np.reshape(input,(-1, input_shape[1], input_shape[2]))  # input_shape[0], input_shape[1]) fuer normales Netz
            input_data = np.array(input, dtype=np.float32)

            # Eingabe Tensor setzen
            self.modelModusClassifier.set_tensor(input_details[0]['index'], input_data)
            self.modelModusClassifier.invoke()

            # Ausgabe Tensor berechnen
            output_data = self.modelModusClassifier.get_tensor(output_details[0]['index'])
            self.modus_names = ['autonom', 'manual']

            # Ausgabe der Klassifizierung
            # print(output_data, class_names[np.argmax(output_data)])
            self.msgModus.data = output_data[0]
            print(self.msgModus.data)
            #self.talkerModus(len(self.modus_names[np.argmax(self.msgModus.data)]), self.modus_names[np.argmax(self.msgModus.data)], len(self.modus_names))

        except KeyboardInterrupt:
            print("Keyboard Interrupt")
        pass

    ## Methode um Sprache zu transkripieren mit dem Deepspeech Package ##

    def speechRecognitionDNN(self, stream):

        # Recognition from record
        try:
            rospy.loginfo("Start recognition")
            start = time.time()

            #Transkription erzeugen
            self.transcript = self.modelDs.stt(stream)

            #leeres Transkript durch none ersetzen
            if not self.transcript:
                self.transcript = "none"

            #Transkript in ROS veroeffentlichen
            self.talkerTranscript(len(self.transcript), self.transcript)
            rospy.loginfo("Speech recognition finished")

            # Zeit fuer Transkription berechnen
            rospy.loginfo("Dauer der Transkription: " + str(time.time() - start))

        except KeyboardInterrupt:
            print("Keyboard Interrupt")
        pass

    ## Methode um Datenstrom abhaengig der Aufnahmedauer zusammenzusetzen ##
    def processDataStream(self, data):
        self.lstMsg = np.int16(np.asarray(data))

        try:
            # msg.data als array abspeichern
            self.frames = np.asarray(data)

            '''
            waveFile = wave.open("filename6.wav", 'wb')
            waveFile.setnchannels(self.channels)
            waveFile.setsampwidth(self.audio.get_sample_size(self.Format))
            waveFile.setframerate(self.rate)
            waveFile.writeframes(b''.join(self.frames))
            waveFile.close()
            '''

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

        # ROS-Knoten initialisieren
        rospy.init_node(self.nodename, anonymous=False)
        rospy.Subscriber(self.topicnameSub, Int16MultiArray, self.callback)

        # Alle Talker initialisieren
        self.talkerTranscript(size=1, text='init')
        self.talkerBuzz(size=1, text='init')
        self.talkerTask(size=1, text='init', size_confidence=0)
        self.talkerModus(size=1, text='init', size_confidence=0)
        self.talkerGoal(poseName="init", data = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0])

        while not rospy.is_shutdown():
            try:
                checksum = sum(self.lstMsg - self.buffer)  # letzte Message gleich neuer? wenn gleich verwerfen
                if not checksum == 0:

                    ## hier geht er nur hin wenn eine neue message da ist, checksumme ungleich 0
                    self.processDataStream(self.buffer)  # wird zyklisch

                    # Schlagwoerter finden
                    self.getAlfBuzzWords()

                    # Aufruf Methode um bedienungsorientierte Handlung zu klassifizieren
                    self.classifierTask(self.transcript)

                    # Aufruf der Modusklassifizierung
                    self.classifierModus(self.transcript)

                    ## veroeffentliche der klassifizierten handlung, modus und ziel nach nachbearbeitung
                    self.classifierPostProcessing(self.class_names[np.argmax(self.msgClass.data)], self.modus_names[np.argmax(self.msgModus.data)])

                time.sleep(0.01)

                if len(self.recognizedBuzzwords)==1 and self.recognizedBuzzwords[0]['buzzword'][0]['name'] == "exit":
                    print("exit")
                    break

            except KeyboardInterrupt:
                print("Keyboard interrupt")
                break
            pass

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

# Main Methode
if __name__ == '__main__':

    #recsec,  pyVersion, nodename, topicnameTranscript, topicnameTask, topicnameBuzz, topicnameSub
    # Paramter kommen aus der Launchfile speechrecognition_alfons.launch.xml

    s = SpeechRecognition(topicnameSub=rospy.get_param('pub/stream/topic'), pyVersion=rospy.get_param('language'),
                          nodename=rospy.get_param('nodename_speechrecognizer'), topicnameTranscript=rospy.get_param('topicname/transcript'),
                          topicnameTask=rospy.get_param('topicname/task'), topicnameBuzz=rospy.get_param('topicname/buzz'),
                          recsec=rospy.get_param('/audioStream/recsec'), topicnameTaskConfidence=rospy.get_param('topicname/task_confidence'),
                          topicnameModus = rospy.get_param('topicname/modus'), topicnameModusConfidence = rospy.get_param('topicname/modus_confidence'),
                          topicnameGoal = rospy.get_param('topicname/goal'))

    s.loadJsons()
    s.readWords()
    s.listener()




