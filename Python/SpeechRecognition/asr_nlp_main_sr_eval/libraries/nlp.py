import json
import phonetics
import nltk
from nltk.stem.lancaster import LancasterStemmer
from keras_preprocessing.sequence import pad_sequences
from keras_preprocessing.text import Tokenizer
stemmer = LancasterStemmer()
import numpy as np
from gtts import gTTS
import pygame
import os
from tempfile import TemporaryFile




## Andere Klassifikatoren mit einbinden

class nlp:

    def __init__(self, rnn, embedded):

        # Definieren von Objekteigenschaften der Klasse Speech Recognition
        self.buzzwords = []
        self.recognizedBuzzwords = []
        self.words = [0]
        self.wordsModus = [0]
        self.class_names = ['drive', 'slam', 'wait for', 'localization', 'stop', 'unknown']
        self.modus_names = ['autonom','manual','unknow']
        self.modelTaskClassifier = ""
        self.modelModusClassifier = ""
        self.edim = 8 # embedded dim
        self.max_length = 25 # laenge fuer padding
        self.vocab_size = 0
        self.t = Tokenizer()
        self.ask = True
        self.rnn = rnn
        self.embeddinglayer = embedded

        #andere Klassifikatoren muessen geladen werden

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

    # Methode um json zu laden
    def loadJsons(self, dir):
        f = open(dir, "r")
        jsonfile = json.loads(f.read())
        f.close()
        return jsonfile

    def saveJsons(self, dir, data):

        if os.path.exists(dir):
            os.remove(dir)

        with open(dir, 'w') as f:
            json.dump(data, f)

    # Wortliste fuer Bedienungsorientierte Klassifizierung laden
    def readWords(self, dir):

        file = open(dir, 'r')
        words = [line.split(',') for line in file.readlines()]
        words = words[0]
        words = words[0:len(words) - 1]  # split fuegt ein wort hinzu wo keins hinsoll
        file.close()
        return words

    def clean_up_sentence(self, sentence):

        # tokenize the pattern
        sentence_words = nltk.word_tokenize(sentence)
        # stem each word
        #sentence_words = [stemmer.stem(word.lower()) for word in sentence_words]
        return sentence_words

    # Bag of Words erzeugen
    def bow(self, sentence, words, show_details=True):
        # tokenize the pattern
        sentence_words = self.clean_up_sentence(sentence)
        # bag of words
        bag = [0] * len(words)
        one = []
        onehot = [0]
        for s in sentence_words:
            for i, w in enumerate(words):
                if w == s:
                    bag[i] = 1
                    one.append(i + 1)
                    if show_details:
                        print("found in bag: %s" % w)
        onehot[0] = list(one)
        return (np.array(bag)), onehot

        ## Methode um Schlagwoerter zu finden ##
        ## getALFBuzzwords Liste muss ggf weitergepflegt werden

    def getAlfBuzzWords(self, transcript):

        # leere Schlagwortliste anlegen
        self.recognizedBuzzwords = []
        buzz = []

        # Apostroph wird mit leerzeichen ersetzt
        transcript = transcript.replace("'", "")
        res = transcript.split()

        phoneResSoundex = []
        # phoneResNysi = []

        # phonetischen code der transkription nach Soundex
        for k in range(len(res)):
            # phoneResMetaphone.append(phonetics.metaphone(res[k]))
            phoneResSoundex.append(phonetics.soundex(res[k]))
            # phoneResNysi.append(phonetics.nysiis(res[k]))

        # phonetischen code der transkription nach metaphone
        phoneResMetaphone = phonetics.metaphone(transcript.replace(" ", ""))
        # phoneResNysi = phonetics.nysiis(self.transcript.replace(" ", ""))

        # Sind Schalgwoerter in dem Transcript, wenn
        if transcript:

            for i in range(len(self.buzzwords)):

                # Pruefe auf direktes match
                if self.Rabin_Karp_Matcher(transcript, self.buzzwords[i]['buzzword'][0]['name'], 257,
                                           11):  # is there a buzzword?
                    self.recognizedBuzzwords.append(
                        self.buzzwords[i])  # ['buzzword'][0]['name'])  # Buzzword to list
                    buzz.append(self.buzzwords[i]['buzzword'][0]['name'])

                # Pruefe auf phonetische uebereinstimmung nach Metaphone Codierung
                elif self.Rabin_Karp_Matcher(phoneResMetaphone,
                                             phonetics.metaphone(self.buzzwords[i]['buzzword'][0]['name']), 257,
                                             11):
                    self.recognizedBuzzwords.append(
                        self.buzzwords[i])  # ['buzzword'][0]['name'])  # Buzzword to list
                    buzz.append(self.buzzwords[i]['buzzword'][0]['name'])

                # Pruefe auf phonetische uebereinstimmung nach Soundex Codierung
                elif self.Rabin_Karp_Matcher(self.converttoStr(phoneResSoundex),
                                             phonetics.soundex(self.buzzwords[i]['buzzword'][0]['name']), 257, 11):
                    self.recognizedBuzzwords.append(
                        self.buzzwords[i])  # ['buzzword'][0]['name'])  # Buzzword to list
                    buzz.append(self.buzzwords[i]['buzzword'][0]['name'])

                # Pruefe auf phonetisches match nach Nysii codierung
                # elif self.Rabin_Karp_Matcher(self.converttoStr(phoneResNysi), phonetics.nysiis(self.buzzwords[i]['buzzword'][0]['name']), 257, 11):
                #  self.recognizedBuzzwords.append(self.buzzwords[i])  # ['buzzword'][0]['name'])  # Buzzword to list
                # buzz.append(self.buzzwords[i]['buzzword'][0]['name'])

            my_string = ','.join(buzz)

            if not my_string:

                print('No valid buzzwords found')

            elif my_string:

                return my_string

    ## Methode um Handlungen zu klassifizieren mit neuronalem Netz##
    def classifierTask(self, transcript):

        try:

            ## Bearbeiten des Transcripts
            transcript = transcript.replace("'", "")
            res = transcript.split()
            phoneRes = []

            # phonetischen Teil mit metaphone bestimmen
            for k in res:
                phoneRes.append(phonetics.metaphone(k))
            transcript = transcript + ' ' + ' '.join(phoneRes)

            #  Ein- und Ausgabe Tensoren bestimmen
            input_details = self.modelTaskClassifier.get_input_details()
            output_details = self.modelTaskClassifier.get_output_details()
            input_shape = input_details[0]['shape']
            bow, encoded_sentence = self.bow(transcript.lower(), self.words, show_details=False)
            print(transcript)
            print(encoded_sentence)
            # Eingabe Tensor definieren
            if self.embeddinglayer:
                input = pad_sequences(encoded_sentence, maxlen=self.max_length, padding='post')

            elif self.embeddinglayer and self.rnn:
                input = pad_sequences(encoded_sentence, maxlen=self.max_length, padding='post')
                input = np.reshape(input, (-1, input_shape[1], input_shape[2]))

            elif (not self.rnn) and (not self.embeddinglayer):
                input = bow
                input = np.reshape(input, (input_shape[0], input_shape[1]))

            input_data = np.array(input, dtype=np.float32)

            # Eingabe Tensor setzen
            self.modelTaskClassifier.set_tensor(input_details[0]['index'], input_data)
            
            self.modelTaskClassifier.invoke()
            # Ausgabe Tensor berechnen
            output_data = self.modelTaskClassifier.get_tensor(output_details[0]['index'])

            # Ausgabe der Klassifizierung bzw zwischenspeichern
            #print(output_data, class_names[np.argmax(output_data)])

            print(output_data[0])

            return output_data[0]


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
            input, rest = self.bow(transcript.lower(), self.wordsModus, show_details=False)
            input = np.reshape(input, (input_shape[0], input_shape[1]))  # input_shape[0], input_shape[1])-1, input_shape[1], input_shape[2]) fuer normales Netz
            input_data = np.array(input, dtype=np.float32)

            # Eingabe Tensor setzen
            self.modelModusClassifier.set_tensor(input_details[0]['index'], input_data)
            self.modelModusClassifier.invoke()

            # Ausgabe Tensor berechnen
            output_data = self.modelModusClassifier.get_tensor(output_details[0]['index'])

            # Ausgabe der Klassifizierung
            print(output_data[0])

            return output_data[0]

        except KeyboardInterrupt:
            print("Keyboard Interrupt")
        pass

    def texttospeech(self, str):
        tts = gTTS(str)
        f = TemporaryFile()
        tts.write_to_fp(f)
        f.seek(0)
        pygame.mixer.init()
        pygame.mixer.music.load(f)
        pygame.mixer.music.play()
        while pygame.mixer.music.get_busy():
            pygame.time.Clock().tick(10)
        f.close()
