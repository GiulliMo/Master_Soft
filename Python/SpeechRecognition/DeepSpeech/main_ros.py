##################################################
## Author: Hannes Dittmann
## Version: 1.0
## Email: hannes.dittmann@stud.hshl.de
## Status: In Entwicklung
##################################################
## Dieses Skript dient dazu, eine transkription auf dem Raspberry Pi in Kombination mit dem Robot Operating System durchzuführen,
## Ein Deepspeech Modell muss mit passender Version vorliegen. Ein Datenstrom wird aus dem ROS-Netzwerk aufgenommen
## Es wird eine WAV Datei transkribiert, diese kann vorhanden sein, oder neu aufgenommen werden.
## Ein Tflite Modell zur bedienungsorientierten Handlungsklassifizierung muss mit entsprechender Wortliste vorliegen

import os
import deepspeech
import wave
import numpy as np
import json
import pyaudio
import rospy
from std_msgs.msg import String, Int16MultiArray
import time
import threading
import argparse
import json
import phonetics
import nltk
from nltk.stem.lancaster import LancasterStemmer
stemmer = LancasterStemmer()
import tflite_runtime.interpreter as tflite
import numpy as np

parser = argparse.ArgumentParser()
parser.add_argument("-r", "--RECSEC", help="Laenge der Aufnahme",
                    type=int)
parser.add_argument("-lm", "--LANGUAGE", help="Sprachmodell, 'de' oder 'gb' ")
parser.add_argument("-tpp", "--topicnamePub", help="Name der veroeffentlichten Topic")
parser.add_argument("-tps", "--topicnameSub", help="Name der abbonierten Topic")
parser.add_argument("-nn", "--nodename", help="Name des Knotens")
args = parser.parse_args()

def initModel(VERSION):
    # load and initialzie model for deepspeechenglish, ds 0.7.1 hast to be installed
    if VERSION == 'gb':
        model_file_path = 'deepspeech-0.7.1-models.tflite'
        model = deepspeech.Model(model_file_path)
        model.enableExternalScorer('deepspeech-0.7.1-models.scorer')
        model.setScorerAlphaBeta(alpha=1, beta=1.1)  # alpha=0.931289039105002, beta=1.1834137581510284)
        print('load finished')

    elif VERSION == 'de':
        # load and initialize model for deepspeech-german, ds 0.6.1 hast to be installed
        DEEPSPEECH_MODEL_DIR = 'models-de'
        model_file_path = os.path.join(DEEPSPEECH_MODEL_DIR, 'output_graph.tflite')
        BEAM_WIDTH = 500
        LM_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'lm.binary')
        TRIE_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'trie')
        LM_ALPHA = 0.4
        LM_BETA = 1.85
        model = deepspeech.Model(model_file_path)
        model.enableDecoderWithLM(LM_FILE_PATH, TRIE_FILE_PATH, LM_ALPHA, LM_BETA)
        print('load finished')

    return model

# Erzeugen der Klasse SpeechRecognition
class SpeechRecognition:
    def __init__(self, recsec,  pyVersion, nodename, topicnamePub, topicnameSub):

        # Definieren von Objekteigenschaften der Klasse Speech Recognition
        self.record = True
        self.nodename = nodename
        self.topicnamePub = topicnamePub
        self.topicnameSub = topicnameSub
        self.lock = threading.Lock()
        self.filename = ''
        self.Version = pyVersion
        self.speech = ''
        self.channels = 1
        self.rate = 16000
        self.chunksize = 2048
        self.recsec = recsec
        self.devIndex = 0  # 0=Boltune, 1= boltune, 2 = builtin
        self.modelDs = initModel(self.Version)
        self.modelTaskClassifier = tflite.Interpreter("taskClassifier.tflite")
        self.buffer = np.zeros(self.chunksize)
        self.audio = pyaudio.PyAudio()
        self.Format = pyaudio.paInt16
        self.frames = []
        self.cnt = 0
        self.start = 0
        self.lstMsg = np.zeros(self.chunksize)
        self.transitions = "transition.json"
        self.buzzwordName = "buzzwords.json"
        self.buzzwords = []
        self.transcript = []
        self.text_so_far = ''
        self.words = [0]
        self.task = ''

    # Methode um Sprache zu transkripieren
    def speechRecognitionDNN(self, stream):
        # Recognition from record
        try:
            print("Start recognition")
            self.start = time.time()

            #Transkription erzeugen
            self.transcript = self.modelDs.stt(stream)

            #Transkript in ROS veröffentlichen
            self.talker(len(self.transcript), self.transcript)
            print(self.transcript)
            print("Speech recognition finished")
            # Zeit für Transkription berechnen
            print(time.time() - self.start)

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
        class_names = ['drive to', 'slam', 'wait for', 'localization', 'stop']

        # Ausgabe der Klassifizierung
        print(output_data, class_names[np.argmax(output_data)])

        # classes of training data
        # drive to = 0
        # slam = 1
        # wait for = 2
        # localization = 3
        # stop = 4

    # Methode um Datenstrom abhängig der Aufnahmedauer zusammenzusetzen
    def processDataStream(self,data):

        self.lstMsg=np.int16(np.asarray(data))
        try:
            if self.cnt==0:
                print("start recording...")
                self.frames=[]
                self.cnt = self.cnt +1
                # Aufnahme ueber dauer von recsec
            if self.cnt<=int(self.rate / self.chunksize * self.recsec):
                self.frames.append(np.asarray(data))
                self.cnt = self.cnt + 1
            else:
                print("finished recording!")
                data16 = np.frombuffer(np.asarray(self.frames), dtype=np.int16)

                # Aufnahme als WAV Datei abspeichern
                self.audio.terminate()
                waveFile = wave.open("test.wav", 'wb')
                waveFile.setnchannels(self.channels)
                waveFile.setsampwidth(self.audio.get_sample_size(self.Format))
                waveFile.setframerate(self.rate)
                waveFile.writeframes(b''.join(self.frames))
                waveFile.close()

                # Aufruf Transkriptionsmethode
                self.speechRecognitionDNN(data16)

                # Aufruf Methode um bedienungsorientierte Handlung zu klassifizieren
                self.classifierNN(self.transcript)

                self.cnt=0
        except KeyboardInterrupt:
            print("Keyboard Interrupt")
        pass

    def callback(self, msg):
        self.buffer = np.int16(np.asarray(msg.data))

    #ROS Knoten initialisieren und Subscriber aufrufen
    def listener(self):
        rospy.init_node(self.nodename, anonymous=True)
        rospy.Subscriber(self.topicnameSub, Int16MultiArray, self.callback)
        # spin() simply keeps python from exiting until this node is stopped
        while not rospy.is_shutdown():
            try:
                checksum = sum(self.lstMsg-self.buffer) #letzte Message gleich neuer? wenn gleich verwerfen
                if not checksum==0:
                   #hier geht er nur hin wenn eine neue message da ist, checksumme ungleich 0
                   self.processDataStream(self.buffer) #wird zyklisch
                   #self.process_audio(self.buffer)
            except KeyboardInterrupt:
                print("Keyboard interrupt")
            pass

    # ROS Publisher aufrufen
    def talker(self, size, text):
        pub = rospy.Publisher(self.topicnamePub, String, queue_size=size)
        rospy.loginfo(text)
        pub.publish(text)

    # Pattern Matcher um Schlagwörter zu finden
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
        else:
            print("Exception")
            return []

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
        res = self.transcript.split()
        phoneResMetaphone = []
        phoneResSoundex = []
        #phoneResNysi = []

        # phonetischen code der transkription
        for k in range(len(res)):
            phoneResMetaphone.append(phonetics.metaphone(res[k]))
            phoneResSoundex.append(phonetics.soundex(res[k]))
            #phoneResNysi.append(phonetics.nysiis(res[k]))

        # Sind Schalgwoerter in dem Transcript?
        for i in range(len(self.buzzwords)):
            # Pruefe auf direktes match
            if self.Rabin_Karp_Matcher(self.transcript, self.buzzwords[i]['buzzword'][0]['name'], 257, 11):  # is there a buzzword?
                recognizedBuzzwords.append(self.buzzwords[i]['buzzword'][0]['name'])  # Buzzword to list

            # Pruefe auf phonetisches match nach Metaphone codierung
            elif self.Rabin_Karp_Matcher(self.converttoStr(phoneResMetaphone), phonetics.metaphone(self.buzzwords[i]['buzzword'][0]['name']), 257, 11):
                recognizedBuzzwords.append(self.buzzwords[i]['buzzword'][0]['name'])  # Buzzword to list
                print("1")

            # Pruefe auf phonetisches match nach Soundex codierung
            elif self.Rabin_Karp_Matcher(self.converttoStr(phoneResSoundex), phonetics.soundex(self.buzzwords[i]['buzzword'][0]['name']), 257, 11):
                recognizedBuzzwords.append(self.buzzwords[i]['buzzword'][0]['name'])  # Buzzword to list
                print("2")

            # Pruefe auf phonetisches match nach Nysii codierung
            #elif self.Rabin_Karp_Matcher(self.converttoStr(phoneResNysi), phonetics.nysiis(self.buzzwords[i]['buzzword'][0]['name']), 257, 11):
                #recognizedBuzzwords.append(self.buzzwords[i]['buzzword'][0]['id'])  # Buzzword to list

        return recognizedBuzzwords


    # Methode um Alf-Spezifische Transkription zu finden
    def getAlfTransition(self, recognizedBuzzwords):  # schlagwoerter suchen und transition finden
        transitionCandidates = []
        firstrun = True
        sum = 0
        ## suchen nach tranistionen mit buzzwords
        for j in range(len(self.transitions)):
            score = 0
            for k in range(len(recognizedBuzzwords)):
                # Schlagwort in transition? ==> score+1

                if self.Rabin_Karp_Matcher(self.transitions[j]['transition'][0]['signature'], recognizedBuzzwords[k],
                                           257, 11):
                    score = score + 1  # Score fuer jede Transition

                    if firstrun:
                        transitionCandidates.append(
                            [{'score': score, 'name': self.transitions[j]['transition'][0]['name']}])
                        firstrun = False

                    elif not firstrun:
                        transitionCandidates.append([{'score': score, 'name': self.transitions[j]['transition'][0]['name']}])  # Kandidaten anhängen

                        if transitionCandidates[len(transitionCandidates) - 1][0]['name'] == \
                                transitionCandidates[len(transitionCandidates) - 2][0]['name']:
                            transitionCandidates.remove(transitionCandidates[len(
                                transitionCandidates) - 2])  # gleichamigen Kandidaten loeschen mit niedrigeren Score

        confidence = np.empty(len(transitionCandidates))
        print(transitionCandidates)

        # Bei erkannten Transitionen Konfindez und besten Kandidat auswaehlen
        if transitionCandidates:
            for n in range(len(transitionCandidates)):
                sum = sum + transitionCandidates[n][0]['score']
                confidence[n] = transitionCandidates[n][0]['score']
            print(confidence * (1 / sum))
            return transitionCandidates[np.argmax(confidence * (1 / sum))][0]['name'] #Kandidat mit groesster Konfidenz wird ausgegeben
        else:
            print("No Alf Buzzwords or Transcript Candidates")

    #Schlagwort- und Transitionsliste laden
    def loadJsons(self):
        f = open(self.buzzwordName, "r")
        f2 = open(self.transitions, "r")
        self.buzzwords = json.loads(f.read())
        self.transitions = json.loads(f2.read())
        f.close()
        f2.close()

    # Wortliste für Bedienungsorientierte Klassifizierung laden
    def readWords(self):
        file = open("words.txt", 'r')
        words = [line.split(',') for line in file.readlines()]
        words = words[0]
        self.words = words[0:len(words) - 1]  # split fügt ein wort hinzu wo keins hinsoll

    # Methonde um nur Wortstämme beachten
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
    s = SpeechRecognition(args.RECSEC, args.LANGUAGE, args.nodename, args.topicnamePub, args.topicnameSub)
    s.loadJsons()
    s.readWords()
    s.listener()


