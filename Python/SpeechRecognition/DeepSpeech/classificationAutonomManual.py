##################################################
## Author: Hannes Dittmann
## Version: 1.0
## Email: hannes.dittmann@stud.hshl.de
## Status: In Entwicklung
##################################################
## Dieses Skript dient dazu, ein neuronales Netz um bedienugnsorientierte Handlungen des ALF zu trainieren
## Ein Tflite Modell sowie eine Wortliste wird aus dem neuronalen Netz abgeleitet


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


### Pre-proecessing

# classes of training data
# autonom= 0
# manual = 1

class_names = ['autonom', 'manual']
# Definieren von Trainingsdaten
training_data = []
training_data.append({"class":0, "sentence":"drive to location alpha", "modus":0})
training_data.append({"class":0, "sentence":"move to alpha", "modus":0})
training_data.append({"class":0, "sentence":"use autonomous driving to location delta", "modus":0})
training_data.append({"class":0, "sentence":"move autonomously to golf", "modus":0})
training_data.append({"class":0, "sentence":"plan trip and move to location", "modus":0})
training_data.append({"class":0, "sentence":"plan a trajectorie and move to foxtrot", "modus":0})
training_data.append({"class":0, "sentence":"moving to location hotel", "modus":0})
training_data.append({"class":0, "sentence":"deliver to location delta", "modus":0})
training_data.append({"class":0, "sentence":"deliver to foxtrot", "modus":0})
training_data.append({"class":0, "sentence":"start to deliver your load to alpha", "modus":0})
training_data.append({"class":0, "sentence":"move to position india", "modus":0})
training_data.append({"class":0, "sentence":"drive autonomously", "modus":0})
training_data.append({"class":0, "sentence":"drive manually with joystick", "modus":1})
training_data.append({"class":0, "sentence":"drive manually with ros visualization", "modus":1})
training_data.append({"class":0, "sentence":"drive manually", "modus":1})
training_data.append({"class":0, "sentence":"make use of the joystick to drive manual", "modus":1})
training_data.append({"class":0, "sentence":"start to drive autonomously to location laboratory", "modus":0})
training_data.append({"class":0, "sentence":"start to drive manually with the given controller", "modus":1})
training_data.append({"class":0, "sentence":"begin with driving to location hotel", "modus":0})
training_data.append({"class":0, "sentence":"try to drive autonomously to a location of your choice", "modus":0})
training_data.append({"class":0, "sentence":"move to the laboratory to grab package", "modus":0})
training_data.append({"class":0, "sentence":"i use the joystick to drive manually", "modus":1})
training_data.append({"class":0, "sentence":"drive with rviz to a position of your choice", "modus":1})
training_data.append({"class":0, "sentence":"can you drive to the emperor and deliver your load", "modus":0})
training_data.append({"class":0, "sentence":"drive to location foxtrot", "modus":0})
training_data.append({"class":1, "sentence":"switch to expedition mode", "modus":0})
training_data.append({"class":1, "sentence":"begin mapping manually", "modus":1})
training_data.append({"class":1, "sentence":"start mapping manually", "modus":1})
training_data.append({"class":1, "sentence":"explore your environment", "modus":0})
training_data.append({"class":1, "sentence":"explore with slam", "modus":0})
training_data.append({"class":1, "sentence":"explore with simultaneous localization and mapping", "modus":0})
training_data.append({"class":1, "sentence":"change to explore mode", "modus":0})
training_data.append({"class":1, "sentence":"explore the environment with slam and drive manually", "modus":1})
training_data.append({"class":1, "sentence":"localize and map manually", "modus":1})
training_data.append({"class":1, "sentence":"drive and simultaneous localize and map your environment", "modus":0})
training_data.append({"class":1, "sentence":"simultaneous localization and mapping in unknow environment manually", "modus":1})
training_data.append({"class":1, "sentence":"simultaneous localization and mapping with joystick", "modus":1})
training_data.append({"class":1, "sentence":"simultaneous localization and mapping with controller", "modus":1})
training_data.append({"class":1, "sentence":"slam and drive manual", "modus":1})
training_data.append({"class":1, "sentence":"mapping with controller", "modus":1})
training_data.append({"class":1, "sentence":"can you solve slam with hector manually", "modus":1})
training_data.append({"class":1, "sentence":"start to solve slam and drive with joystick", "modus":1})
training_data.append({"class":1, "sentence":"start to solve slam and drive with controller", "modus":1})
training_data.append({"class":1, "sentence":"drive to", "modus":1})
training_data.append({"class":1, "sentence":"drive with slam and make use of joystick", "modus":1})
training_data.append({"class":1, "sentence":"just drive", "modus":1})


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
    labels.append(training_data[i]["modus"])
    sentence = training_data[i]["sentence"].replace("'", "")
    res = sentence.split()
    phoneResSoundex = []
    for k in res:
        phoneResSoundex.append(phonetics.metaphone(k))
    training_data_phon.append({"modus": training_data[i]["modus"], "sentence": training_data[i]["sentence"] + ' ' + ' '.join(phoneResSoundex)})

print(training_data_phon[1]["sentence"])

# loop through each sentence in our training data
for pattern in training_data_phon:
    # tokenize each word in the sentence
    w = nltk.word_tokenize(pattern['sentence'])
    # add to our words list
    words.extend(w)
    # add to documents in our corpus
    documents.append((w, pattern['modus']))
    # add to our classes list
    if pattern['modus'] not in classes:
        classes.append(pattern['modus'])

# stem and lower each word and remove duplicates
words = [stemmer.stem(w.lower()) for w in words if w not in ignore_words]
words = list(set(words))

# remove duplicates
classes = list(set(classes))

print(len(documents), "documents")
print(len(classes), "classes", classes)
print(len(words), "unique stemmed words", words)

# List of Words schreiben, da wörter unterschiedlich angeordnet werden
with open('words_modus.txt', 'w') as f:
    for item in words:
        f.write("%s," % item)

# remove duplicates
classes = list(set(classes))

print(len(documents), "documents")
print(len(classes), "classes", classes)
print(len(words), "unique stemmed words", words)
print(labels)
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

# Definieren Neuronales Netzwerk
model = keras.Sequential()
model.add(tf.keras.layers.InputLayer(input_shape=X.shape[1]))
model.add(tf.keras.layers.Dropout(0.2, input_shape=(1, X.shape[1])))
model.add(keras.layers.Dense(units=20, activation='softmax'))
model.add(keras.layers.Dense(units=y.shape[1], activation='softmax'))

model.summary()

# Definieren des Optimizers
optimizer = tf.keras.optimizers.Adam(
    learning_rate=0.0001, beta_1=0.9, beta_2=0.999, epsilon=1e-07, amsgrad=False,
    name='RMSprop'
)

# Compilieren des Modells
model.compile(optimizer=optimizer,
              loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])

# Trainieren des Modells
model.fit(X, labels, epochs=2000)

# Speichern als keras Modell
#model.save('taskClassifier')

# Konvertieren in Tflite Modell
converter = tf.lite.TFLiteConverter.from_keras_model(model)
tflite_model = converter.convert()
open("autonom_manual.tflite", "wb").write(tflite_model)

sentence1 = "drive manually with joystick"
input = bow(sentence1.lower(), words, show_details=False)
print(model.predict(np.reshape(input,(1, len(words)))))

sentence1 = "drive to hotel"
input = bow(sentence1.lower(), words, show_details=False)
print(model.predict(np.reshape(input,(1, len(words)))))