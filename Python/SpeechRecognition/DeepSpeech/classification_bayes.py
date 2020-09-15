##################################################
## Author: Hannes Dittmann
## Version: 1.0
## Email: hannes.dittmann@stud.hshl.de
## Status: In Entwicklung
##################################################
## Dieses Skript dient dazu, einen Bayes Klassifikator fuer eine Handlungsklassifizierung zu trainieren


# use natural language toolkit
import time

import nltk
import tflite as tflite
from nltk.stem.lancaster import LancasterStemmer
stemmer = LancasterStemmer()
import tensorflow as tf
from tensorflow import keras, lite
import numpy as np
import phonetics
from sklearn.naive_bayes import GaussianNB, ComplementNB, MultinomialNB, BernoulliNB
import json

### Pre-proecessing

# classes of training data
# drive to = 0
# slam = 1
# wait for = 2
# localization = 3
# stop = 5
# unknow = 6

class_names = ['drive to', 'slam', 'wait for', 'localization', 'stop', 'unknow']

# Definieren von Trainingsdaten
with open('data/training_data_II.json') as json_file:
    training_data = json.load(json_file)

#Preprocessing
print ("%s sentences in training data" % len(training_data))
words = []
labels = []
classes = []
documents = []
ignore_words = ['?']

training_data_phon=[]
# add labels with loop through each training_data element
for i in range(len(training_data)):
    labels.append(training_data[i]["class"])
    sentence = training_data[i]["sentence"].replace("'", "")
    res = sentence.split()
    phoneRes = []
    for k in res:
        phoneRes.append(phonetics.metaphone(k))
    training_data_phon.append({"class": training_data[i]["class"], "sentence": training_data[i]["sentence"] + ' ' + ' '.join(phoneRes)})

print(training_data_phon[1]["sentence"])

# loop through each sentence in our training data
for pattern in training_data_phon:
    # tokenize each word in the sentence
    w = nltk.word_tokenize(pattern['sentence'])
    # add to our words list
    words.extend(w)
    # add to documents in our corpus
    documents.append((w, pattern['class']))
    # add to our classes list
    if pattern['class'] not in classes:
        classes.append(pattern['class'])


# stem and lower each word and remove duplicates
words = [stemmer.stem(w.lower()) for w in words if w not in ignore_words]
words = list(set(words))

# remove duplicates
classes = list(set(classes))

print (len(documents), "documents")
print (len(classes), "classes", classes)
print (len(words), "unique stemmed words", words)

# List of Words schreiben, da wörter unterschiedlich angeordnet werden
with open('words.txt', 'w') as f:
    for item in words:
        f.write("%s," % item)

# create our training data
training = []
output = []
# create an empty array for our output
output_empty = [0] * len(classes)


# training set, bag of words for each sentence
for doc in documents:
    # initialize our bag of words
    bag = []
    # list of tokenized words for the pattern
    pattern_words = doc[0]
    # stem each word
    pattern_words = [stemmer.stem(word.lower()) for word in pattern_words]
    # create our bag of words array
    for w in words:
        bag.append(1) if w in pattern_words else bag.append(0)

    training.append(bag)
    # output is a '0' for each tag and '1' for current tag
    output_row = list(output_empty)
    output_row[classes.index(doc[1])] = 1
    output.append(output_row)


X = np.array(training)
y = np.array(output)
print ("# words", len(words))
print ("# classes", len(classes))
labels = np.array(labels)
print(documents)

# Reduzieren auf Wortstamm
def clean_up_sentence(sentence):
    # tokenize the pattern
    sentence_words = nltk.word_tokenize(sentence)
    # stem each word
    sentence_words = [stemmer.stem(word.lower()) for word in sentence_words]
    return sentence_words

# return bag of words array: 0 or 1 for each word in the bag that exists in the sentence
def bow(sentence, words, show_details=False):

    # tokenize the pattern
    sentence_words = clean_up_sentence(sentence)
    # bag of words
    bag = [0] * len(words)
    for s in sentence_words:
        for i, w in enumerate(words):
            if w == s:
                bag[i] = 1
                if show_details:
                    print("found in bag: %s" % w)

    return (np.array(bag))

gnb = MultinomialNB() # verschiedene Bayes Klassifikator koennen hier eingesetzt werden
gnb = gnb.fit(X,labels)
sentence1 = "slam"
input = bow(sentence1.lower(), words, show_details=False)
input = np.reshape(input, (-1,len(words)))
print(gnb.predict_proba(input))
