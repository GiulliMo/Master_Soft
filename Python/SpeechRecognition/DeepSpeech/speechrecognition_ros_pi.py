##################################################
## Author: Hannes Dittmann
## Version: 1.0
## Email: hannes.dittmann@stud.hshl.de
## Status: In Entwicklung
##################################################
## Kommentare:
## Dieses Skript dient dazu, eine transkription auf dem Raspberry Pi in Kombination mit dem Robot Operating System durchzuführen,
## Ein Deepspeech Modell muss mit passender Version vorliegen. Ein Datenstrom wird aus dem ROS-Netzwerk aufgenommen
## Es wird eine WAV Datei transkribiert, diese kann vorhanden sein, oder neu aufgenommen werden.
## Ein Tflite Modell zur bedienungsorientierten Handlungsklassifizierung muss mit entsprechender Wortliste vorliegen
## python audio_stream.py -di 7 -nn audio -tp audio_stream auf ALF PC um ROS-Message mit Audio Inhalt zu streamen
## python3 main_ros_pi.py -r 5 -lm gb -tpp recognition -tps audio_stream -nn recognizer auf Pi ausfuehren
## rosrun startbuttondetection startbuttondetection_node Knoten
## Wortliste, Buzzword.json und taskClassifier.tflie mueesen vorhanden sein

import os
import deepspeech
import rospy
from std_msgs.msg import String, Int16MultiArray, Float32MultiArray, Int16
import time
import json
import phonetics
import nltk
from nltk.stem.lancaster import LancasterStemmer
stemmer = LancasterStemmer()
import tflite_runtime.interpreter as tflite
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

    def __init__(self, recsec,  pyVersion, nodename, topicnameTranscript, topicnameTask,topicnameTaskConfidence, topicnameBuzz, topicnameSub):

        # Definieren von Objekteigenschaften der Klasse Speech Recognition
        self.nodename = nodename
        self.topicnameTranscript = topicnameTranscript # zum veroeffentlichen des deepspeech transkripts
        self.topicnameSub = topicnameSub    # subscriben des audio streams
        self.topicnameTask = topicnameTask
        self.topicnameTaskConfidence = topicnameTaskConfidence
        self.topicnameBuzz = topicnameBuzz
        self.Version = pyVersion
        self.chunksize = 2048
        self.rate = 16000
        self.recsec = recsec
        self.modelDs = initModel(self.Version)
        self.modelTaskClassifier = tflite.Interpreter("models/taskClassifier.tflite")
        self.buffer = np.zeros(int(self.rate / self.chunksize) * self.recsec * self.chunksize)
        self.frames = []
        self.lstMsg = np.zeros(int(self.rate / self.chunksize) * self.recsec * self.chunksize)
        self.buzzwords = []
        self.transcript = []
        self.words = [0]
        self.msg = Float32MultiArray()
        self.msg.data = []



    # Methode um Sprache zu transkripieren
    def speechRecognitionDNN(self, stream):

        # Recognition from record
        try:
            print("Start recognition")
            start = time.time()

            #Transkription erzeugen
            self.transcript = self.modelDs.stt(stream)

            if not self.transcript:
                self.transcript = "none"


            #Transkript in ROS veroeffentlichen
            self.talkerTranscript(len(self.transcript), self.transcript)
            print(self.transcript)
            print("Speech recognition finished")

            # Zeit fuer Transkription berechnen
            print(time.time() - start)

        except KeyboardInterrupt:
            print("Keyboard Interrupt")
        pass

    # Methode um Handlungen zu klassifizieren
    def classifierNN(self, transcript):

        self.modelTaskClassifier.allocate_tensors()

        #  Ein- und Ausgabe Tensoren bestimmen
        input_details = self.modelTaskClassifier.get_input_details()
        output_details = self.modelTaskClassifier.get_output_details()
        input_shape = input_details[0]['shape']

        # Eingabe Tensor definieren
        input = self.bow(transcript.lower(), self.words, show_details=False)
        input = np.reshape(input, [input_shape[0], input_shape[1]])
        input_data = np.array(input, dtype=np.float32)

        # Eingabe Tensor setzen
        self.modelTaskClassifier.set_tensor(input_details[0]['index'], input_data)
        self.modelTaskClassifier.invoke()

        # Ausgabe Tensor berechnen
        output_data = self.modelTaskClassifier.get_tensor(output_details[0]['index'])
        class_names = ['drive to', 'slam', 'wait for', 'localization', 'stop', 'unknow']

        # Ausgabe der Klassifizierung
        #print(output_data, class_names[np.argmax(output_data)])
        self.msg.data = output_data[0]
        self.talkerTask(len(class_names[np.argmax(output_data)]), class_names[np.argmax(output_data)],len(class_names))

        # classes of training data
        # drive to = 0
        # slam = 1
        # wait for = 2
        # localization = 3
        # stop = 4
        # Methode um WAV Datei zu erzeugen

    # Methode um Rohdaten aus WAV Datei zu lesen
    def getBuffer(self, w):
        frames = w.getnframes()
        buffer = w.readframes(frames)
        type(buffer)
        return (buffer)

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

            # Aufruf Methode um bedienungsorientierte Handlung zu klassifizieren
            self.classifierNN(self.transcript)

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
        r = rospy.Rate(0.05)
        while not rospy.is_shutdown():
            try:
                checksum = sum(self.lstMsg - self.buffer)  # letzte Message gleich neuer? wenn gleich verwerfen
                if not checksum == 0:
                    ## hier geht er nur hin wenn eine neue message da ist, checksumme ungleich 0
                    self.processDataStream(self.buffer)  # wird zyklisch
                    self.getAlfBuzzWords()
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

        rospy.loginfo(self.msg.data)
        pub2.publish(self.msg)

    # ROS Publisher aufrufen fuer erkanntes Objekt/Person etc. aus Buzzword matcher
    def talkerBuzz(self, size, text):

        pub = rospy.Publisher(self.topicnameBuzz, String, queue_size=size)
        rospy.loginfo(text)
        pub.publish(text)


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

    # Methode um Schlagwoerter zu finden
    def getAlfBuzzWords(self):

        recognizedBuzzwords = []
        # Apostroph wird mit leerzeichen ersetzt
        self.transcript = self.transcript.replace("'", "")
        res = self.transcript.split()
        phoneResSoundex = []
        #phoneResNysi = []

        # phonetischen code der transkription nach Soundex
        for k in range(len(res)):
            #phoneResMetaphone.append(phonetics.metaphone(res[k]))
            phoneResSoundex.append(phonetics.soundex(res[k]))
            #phoneResNysi.append(phonetics.nysiis(res[k]))

        # phonetischen code der transkription nach metaphone
        phoneResMetaphone = phonetics.metaphone(self.transcript.replace(" ", ""))
        #print(phoneResMetaphone)

        # Sind Schalgwoerter in dem Transcript, wenn eines vorhanden ist
        if self.transcript:

            for i in range(len(self.buzzwords)):

                # Pruefe auf direktes match
                if self.Rabin_Karp_Matcher(self.transcript, self.buzzwords[i]['buzzword'][0]['name'], 257, 11):  # is there a buzzword?
                    recognizedBuzzwords.append(self.buzzwords[i]['buzzword'][0]['name'])  # Buzzword to list

                # Pruefe auf phonetische uebereinstimmung nach Metaphone Codierung
                elif self.Rabin_Karp_Matcher(phoneResMetaphone, phonetics.metaphone(self.buzzwords[i]['buzzword'][0]['name']), 257, 11):
                    recognizedBuzzwords.append(self.buzzwords[i]['buzzword'][0]['name'])  # Buzzword to list


                # Pruefe auf phonetische uebereinstimmung nach Soundex Codierung
                elif self.Rabin_Karp_Matcher(self.converttoStr(phoneResSoundex), phonetics.soundex(self.buzzwords[i]['buzzword'][0]['name']), 257, 11):
                    recognizedBuzzwords.append(self.buzzwords[i]['buzzword'][0]['name'])  # Buzzword to list


                # Pruefe auf phonetisches match nach Nysii codierung
                #elif self.Rabin_Karp_Matcher(self.converttoStr(phoneResNysi), phonetics.nysiis(self.buzzwords[i]['buzzword'][0]['name']), 257, 11):
                    #recognizedBuzzwords.append(self.buzzwords[i]['buzzword'][0]['id'])  # Buzzword to list

            my_string = ','.join(recognizedBuzzwords)

            if not my_string:
                rospy.loginfo('No valid buzzwords found')

            elif my_string:
                #print(my_string)
                self.talkerBuzz(len(my_string), my_string)


    #Schlagwort- und Transitionsliste laden
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

# Main Methode
if __name__ == '__main__':

    name = rospy.get_param("/audioStream/nodename/") + '/'

    #recsec,  pyVersion, nodename, topicnameTranscript, topicnameTask, topicnameBuzz, topicnameSub
    s = SpeechRecognition(topicnameSub=rospy.get_param(name + 'pub/stream/topic'), pyVersion=rospy.get_param(name + 'language'),
                          nodename=rospy.get_param(name + 'nodename_speechrecognizer'), topicnameTranscript=rospy.get_param(name + 'topicname/transcript'),
                          topicnameTask=rospy.get_param(name + 'topicname/task'), topicnameBuzz=rospy.get_param(name + 'topicname/buzz'),
                          recsec=rospy.get_param(name + 'recsec'), topicnameTaskConfidence=rospy.get_param(name + 'topicname/task_confidence'))
    s.loadJsons()
    s.readWords()
    s.listener()

