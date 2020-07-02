##################################################
## Author: Hannes Dittmann
## Version: 1.0
## Email: hannes.dittmann@stud.hshl.de
## Status: In Entwicklung
##################################################
## Dieses Skript dient dazu, eine transkription auf dem Entwicklungsrechner durchzuführen, ein Deepspeech Modell muss mit passender Version vorliegen.
## Es wird eine WAV Datei transkribiert, diese kann vorhanden sein, oder neu aufgenommen werden.
## Ein Tflite Modell zur bedienungsorientierten Handlungsklassifizierung muss mit entsprechender Wortliste vorliegen
## Wortliste muss Exportiert werden nachdem trainiert wurde!!!!!


import os
import deepspeech
import wave
import numpy as np
import pyaudio
import speech_recognition as sr
from watson_developer_cloud import SpeechToTextV1
import json
import phonetics
import webbrowser
import tensorflow as tf
from tensorflow import lite
import time
import nltk
from nltk.stem.lancaster import LancasterStemmer
stemmer = LancasterStemmer()

# Methode um IBM SpeechRecognition aufzurufen
def initRecognizer():
    #recognizer for ibm cloud
    recognizer = sr.Recognizer()
    speech_to_text = SpeechToTextV1(
        iam_apikey="wsDeuwes_FSm3bo_QiLLQl1Er81u1sqIQxMNZFB67aVq",
        url="https://api.eu-gb.speech-to-text.watson.cloud.ibm.com/instances/472d7157-6ba9-4041-b3f3-8b014ebd62cf")
    return recognizer

# Methode um Deepspeech Modell zu initialisieren
def initModel(VERSION):

    #load and initialzie model for python3 #deepspeech 0.7.1
    if VERSION == 'PYTHON3':
        model_file_path = 'models/deepspeech-0.7.1-models.pbmm'
        model = deepspeech.Model(model_file_path)
        #model.enableExternalScorer('models/deepspeech-0.7.1-models.scorer')
        model.setScorerAlphaBeta(alpha=1, beta=1.1)  # alpha=0.931289039105002, beta=1.1834137581510284)
        print('load finished')

    elif VERSION == 'PYTHON2':
        # load and initialize model for python2# pbmm deepspeech 0.6.1
        DEEPSPEECH_MODEL_DIR = 'models-De'
        model_file_path = os.path.join(DEEPSPEECH_MODEL_DIR, 'output_graph.pb')
        BEAM_WIDTH = 500
        LM_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'lm.binary')
        TRIE_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'trie')
        ALPHABET_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'alphabet.txt')
        LM_ALPHA = 0.6
        LM_BETA = 1.18
        model = deepspeech.Model(model_file_path, BEAM_WIDTH)
        model.enableDecoderWithLM(LM_FILE_PATH, TRIE_FILE_PATH, LM_ALPHA, LM_BETA)
        print('load finished')
    return model


class SpeechRecognition:
    def __init__(self, newRecord, filename, pyVersion):

        # Definieren von Objekteigenschaften
        self.record = newRecord
        self.filename = filename
        self.Version = pyVersion
        self.channels = 1
        self.Format = pyaudio.paInt16
        self.rate = 16000
        self.chunksize = 2048
        self.recsec = 5
        self.devIndex = 0  # 0=Boltune, 1= boltune, 2 = builtin Microphone
        self.audio = pyaudio.PyAudio()
        self.format = pyaudio.paInt16
        self.model = initModel(self.Version)
        self.modelTaskClassifier = tf.lite.Interpreter("taskClassifier.tflite")
        self.recognizer = sr
        self.buffer = np.empty(0)
        self.buzzwordName = "buzzwords.json"
        self.buzzwords = []
        self.transcript = []
        self.words = [0]
        self.speech_to_text = SpeechToTextV1(iam_apikey="wsDeuwes_FSm3bo_QiLLQl1Er81u1sqIQxMNZFB67aVq",
                                             url="https://api.eu-gb.speech-to-text.watson.cloud.ibm.com/instances/472d7157-6ba9-4041-b3f3-8b014ebd62cf")

    # Methode um WAV Datei zu erzeugen
    def createWav(self, filename):

        #loeschen wenn WAV existiert
        if os.path.exists(filename):
            os.remove(filename)

        # start Recording
        stream = self.audio.open(format=self.Format, rate=self.rate, channels=self.channels,
                                 input_device_index=self.devIndex, input=True,
                                 frames_per_buffer=self.chunksize)
        print("recording...")
        frames = []

        for i in range(0, int(self.rate / self.chunksize * self.recsec)):
            frames.append(stream.read(self.chunksize)) #Frames werden angehangen je nachdem wie groß recsec ist

        print("finished recording!")

        stream.stop_stream()
        stream.close()
        #self.audio.terminate()

        waveFile = wave.open(filename, 'wb')
        waveFile.setnchannels(self.channels)
        waveFile.setsampwidth(self.audio.get_sample_size(self.Format))
        waveFile.setframerate(self.rate)
        waveFile.writeframes(b''.join(frames))
        waveFile.close()

    # read data from wav file
    def getBuffer(self, w):
        frames = w.getnframes()
        buffer = w.readframes(frames)
        type(buffer)
        return (buffer)

    # Methode um Sprache zu transkripieren
    def speechRecognitionDNN(self, record, filename):
        # Recognition from record
        if record:
            try:

                # record a wav file, bei ROS nur buffer
                self.createWav(self.filename)
                # predict Audio with deepspeech
                buffer = self.getBuffer(wave.open(filename, 'r'))
                data16 = np.frombuffer(buffer, dtype=np.int16)
                type(data16)
                self.transcript = self.model.stt(data16)
                print(self.transcript)

                # bedienungsorientierte Nachbearbeitung/Klassifizierung
                self.classifierNN(self.transcript)

                print("Speech recognition finished")

            except KeyboardInterrupt:
                print("Keyboard Interrupt")
            pass

        elif not record:
            try:
                buffer = self.getBuffer(wave.open(filename, 'r'))
                data16 = np.frombuffer(buffer, dtype=np.int16)
                self.transcript = self.model.stt(data16)
                print(self.transcript)
                self.classifierNN(self.transcript)
                print("Speech recognition finished")
            except KeyboardInterrupt:
                print("Keyboard Interrupt")
            pass

    #Methode um Handlungen zu klassifizieren
    def classifierNN(self, transcript):

        self.modelTaskClassifier.allocate_tensors()

        input_details = self.modelTaskClassifier.get_input_details()
        output_details = self.modelTaskClassifier.get_output_details()
        input_shape = input_details[0]['shape']

        input = self.bow(transcript.lower(), self.words, show_details=False)
        input = np.reshape(input, [input_shape[0], input_shape[1]])
        print(input)
        input_data = np.array(input, dtype=np.float32)

        self.modelTaskClassifier.set_tensor(input_details[0]['index'], input_data)
        self.modelTaskClassifier.invoke()
        output_data = self.modelTaskClassifier.get_tensor(output_details[0]['index'])
        class_names = ['drive to', 'slam', 'wait for', 'localization', 'stop']
        print(output_data, class_names[np.argmax(output_data)])

        # classes of training data
        # drive to = 0
        # slam = 1
        # wait for = 2
        # localization = 3
        # stop = 4

    def speechRecognitionIBM(self, filename):
        with self.recognizer.WavFile(filename) as source:  # use "test.wav" as the audio source
            r = initRecognizer()
            audio_file = r.record(source)

        speech_recognition_results = self.speech_to_text.recognize(audio=audio_file.get_wav_data(),
                                                                   content_type='audio/wav').get_result()
        print(json.dumps(speech_recognition_results, indent=2))

    #Pattern Matcher String
    def Rabin_Karp_Matcher(self, text, pattern, d, q):
        n = len(text)
        m = len(pattern)
        h = pow(d, m - 1) % q
        p = 0
        t = 0
        result = []
        if len(text)>=len(pattern):
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
            return result #begin of string position
        else:
            print("Exception")
            return []

    def converttoStr(self, s):
        # initialization of string to ""
        new = ""
        # traverse in the string
        for x in s:
            new += x + " "
        # return string
        return new

    # Methode um Schlagwoerter in Transkription zu finden
    def getAlfBuzzWords(self):
            recognizedBuzzwords = []
            res = self.transcript.split()
            phoneResMetaphone = []
            phoneResSoundex = []
           # phoneResNysi = []

            # Phonetischer Code der Transkription
            for k in range(len(res)):

                phoneResMetaphone.append(phonetics.metaphone(res[k]))
                phoneResSoundex.append(phonetics.soundex(res[k]))
                #phoneResNysi.append(phonetics.nysiis(res[k]))

            # Sind Schalgwoerter in dem Transcript? Phonetisch oder direkt
            for i in range(len(self.buzzwords)):

                # Pruefe auf direktes string-match
                if self.Rabin_Karp_Matcher(self.transcript, self.buzzwords[i]['buzzword'][0]['name'], 257,1):  # Direktes Buzzword?
                    recognizedBuzzwords.append(self.buzzwords[i]['buzzword'][0]['name'])  # Buzzword zu Liste hinzufuegen

                # Pruefe auf phonetisches match nach Metaphone codierung
                elif self.Rabin_Karp_Matcher(self.converttoStr(phoneResMetaphone), phonetics.metaphone(self.buzzwords[i]['buzzword'][0]['name']), 257, 11):
                    recognizedBuzzwords.append(self.buzzwords[i]['buzzword'][0]['name'])  # Buzzword to list

                # Pruefe auf phonetisches match nach Soundex codierung
                elif self.Rabin_Karp_Matcher(self.converttoStr(phoneResSoundex), phonetics.soundex(self.buzzwords[i]['buzzword'][0]['name']), 257, 11):
                    recognizedBuzzwords.append(self.buzzwords[i]['buzzword'][0]['name'])  # Buzzword to list

                # Pruefe auf phonetisches match nach Nysi codierung
                #elif self.Rabin_Karp_Matcher(self.converttoStr(phoneResNysi),
                 #                            phonetics.nysiis(self.buzzwords[i]['buzzword'][0]['name']), 257, 11):
                  #  recognizedBuzzwords.append(self.buzzwords[i]['buzzword'][0]['id'])  # Buzzword to list

            return recognizedBuzzwords
    '''
    def getAlfTransition(self, recognizedBuzzwords): #schlagwoerter suchen und transition finden
        transitionCandidates = []
        firstrun = True
        sum = 0
        confidence = np.empty(len(self.transitions))
        
        ## suchen nach tranistionen mit buzzwords
        for j in range(len(self.transitions)):
            score = 0

            for k in range(len(recognizedBuzzwords)):
                # Schlagwort in transition? ==> score+1

                if self.Rabin_Karp_Matcher(self.transitions[j]['transition'][0]['signature'], recognizedBuzzwords[k], 257, 11):
                    score = score + 1  # anzahl matches

                    if firstrun:
                        transitionCandidates.append([{'score': score, 'name': self.transitions[j]['transition'][0]['name']}])
                        firstrun = False

                    elif not firstrun:
                        transitionCandidates.append([{'score': score, 'name': self.transitions[j]['transition'][0]['name']}]) #Kandidaten anhängen

                        if transitionCandidates[len(transitionCandidates)-1][0]['name']==transitionCandidates[len(transitionCandidates)-2][0]['name']:
                            transitionCandidates.remove(transitionCandidates[len(transitionCandidates)-2]) # gleichamigen Kandidaten loeschen mit niedrigeren Score

        confidence = np.empty(len(transitionCandidates))
        print(transitionCandidates)
        # Bei erkannten Transitionen Konfindez und besten Kandidat auswaehlen
        if transitionCandidates:
            for n in range(len(transitionCandidates)):
                sum = sum + transitionCandidates[n][0]['score']
                confidence[n] = transitionCandidates[n][0]['score']
            print(confidence*(1/sum))
            return transitionCandidates[np.argmax(confidence*(1/sum))][0]['name']
        else:
            print("No Alf Buzzwords or Transcript Candidates")
    '''
    # Methode um Json Dateien zu laden
    def loadJsons(self):
        f = open(self.buzzwordName, "r")
      #  f2 = open(self.transitions, "r")
        self.buzzwords = json.loads(f.read())
       #self.transitions = json.loads(f2.read())
        f.close()
       # f2.close()

    # Methode um Wortliste aus neuronalem Netz einzulesen
    def readWords(self):
        file = open("words.txt", 'r')
        words = [line.split(',') for line in file.readlines()]
        words = words[0]
        self.words = words[0:len(words) - 1]  # split fügt ein leeren String ans ende der Datei ''

    # Methode um Wortstamm zu bekommen (Lancasterstemmer
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


if __name__ == '__main__':
    # Version entspricht DS Modell, newRecord == False wav wird genutzt
    s = SpeechRecognition(newRecord=True, filename='test.wav', pyVersion='PYTHON3')

    # Json Dateien laden (Buzzwords und Transitions)
    s.loadJsons()

    # Wortliste aus Handlungsklassifizierung
    s.readWords()

    # Transkription wav Datei und Nachbearbeitung
    start = time.time()
    while True:
        try:
            s.speechRecognitionDNN(s.record, s.filename)
            print(s.getAlfBuzzWords())
            print(time.time()-start)
        except KeyboardInterrupt:
            print("Keyboard Interrupt")
