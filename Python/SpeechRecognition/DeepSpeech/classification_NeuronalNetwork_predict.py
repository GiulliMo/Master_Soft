##################################################
## Author: Hannes Dittmann
## Version: 1.0
## Email: hannes.dittmann@stud.hshl.de
## Status: In Entwicklung
##################################################
## Dieses Skript dient dazu, ein neuronales Netz an Beispielsätzen zu trainieren
## Ein Tflite Modell zur bedienungsorientierten Handlungsklassifizierung muss mit entsprechender Wortliste vorliegen

import nltk
from nltk.stem.lancaster import LancasterStemmer
stemmer = LancasterStemmer()
import tensorflow as tf
from tensorflow import lite
from keras_preprocessing.sequence import pad_sequences
from keras_preprocessing.text import Tokenizer
import numpy as np
import phonetics

file = open("words_embedding.txt", 'r')
words = [line.split(',') for line in file.readlines()]
words = words[0]
words = words[0:len(words)-1] #split fügt ein wort hinzu wo keins hinsoll

def clean_up_sentence(sentence):
    # tokenize the pattern
    sentence_words = nltk.word_tokenize(sentence)
    # stem each word
    #sentence_words = [stemmer.stem(word.lower()) for word in sentence_words]
    return sentence_words

# return bag of words array: 0 or 1 for each word in the bag that exists in the sentence
def bow(sentence, words, show_details=True):
    # tokenize the pattern
    sentence_words = clean_up_sentence(sentence)
    # bag of words
    bag = [0] * len(words)
    one = []
    onehot = [0]
    for s in sentence_words:
        print(s)
        for i, w in enumerate(words):
            if w == s:
                bag[i] = 1
                one.append(i+1)
                if show_details:
                    print("found in bag: %s" % w)
    onehot[0] = list(one)
    return (np.array(bag)), onehot

interpreter = tf.lite.Interpreter("taskClassifierPhon.tflite")
interpreter.allocate_tensors()

input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()
input_shape = input_details[0]['shape']

sentence = "stop the slam mode"
sentence1 = sentence.replace("'", "")
res = sentence.split()
phoneRes = []

# phonetischen Teil mit metaphone bestimmen
for k in res:
    phoneRes.append(phonetics.metaphone(k))
sentence1 = sentence1 + ' ' + ' '.join(phoneRes)

bow, onehot = bow(sentence = sentence1.lower(), words=words, show_details=False)
input = pad_sequences(onehot, maxlen=25, padding='post')
input = np.reshape(bow,(input_shape[0], input_shape[1]))#input_shape[0], input_shape[1]) fuer normales Netz
input_data = np.array(input, dtype=np.float32)

interpreter.set_tensor(input_details[0]['index'], input_data)
interpreter.invoke()

output_data = interpreter.get_tensor(output_details[0]['index'])
class_names = ['drive to', 'slam', 'wait for', 'localization', 'stop', 'unknow']
print(output_data, class_names[np.argmax(output_data)])
