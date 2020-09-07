##################################################
## Author: Hannes Dittmann
## Version: 1.0
## Email: hannes.dittmann@stud.hshl.de
## Status: In Entwicklung
##################################################
## Dieses Skript dient dazu, ein neuronales Netz um bedienugnsorientierte Handlungen des ALF zu trainieren
## Ein Tflite Modell sowie eine Wortliste wird aus dem neuronalen Netz abgeleitet
## abhängig von datensatz "random_distributed_dataset"


# use natural language toolkit
import time
from lib.preprocessing import preProcessing
import nltk
import tflite as tflite
from nltk.stem.lancaster import LancasterStemmer
stemmer = LancasterStemmer()
import tensorflow as tf
from tensorflow import keras, lite
import numpy as np
import os
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

# Definieren von Trainingsdaten aus dataset analysis
with open('data/random_distributed_dataset.json') as json_file:
    random_distributed_dataset= json.load(json_file)


set, output, words, documents, classes, labels = preProcessing(random_distributed_dataset)

# daten splitten 2/3 1/3
ratio=3/4
training_data = set[0:int(len(random_distributed_dataset)*ratio)]
training_labels = labels[0:int(len(random_distributed_dataset)*ratio)]
print(training_labels)
test_data = set[int(len(random_distributed_dataset)*ratio):len(random_distributed_dataset)]
test_labels = labels[int(len(random_distributed_dataset)*ratio):len(random_distributed_dataset)]

X = np.array(training_data)
y = np.array(output[0:int(len(random_distributed_dataset)*ratio)])
print ("# words", len(words))
print ("# classes", len(classes))
labels = np.array(training_labels)
print(documents)

#X = np.array(test_data)
#print(len(X))
#y = np.array(test_data)
#print(len(y))

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
model.fit(X,labels, epochs=1500)

# Speichern als keras Modell
#model.save('taskClassifier')

# Konvertieren in Tflite Modell
converter = tf.lite.TFLiteConverter.from_keras_model(model)
tflite_model = converter.convert()
open("taskClassifierPhon.tflite", "wb").write(tflite_model)



labels = np.array(test_labels)
X = np.array(test_data)
results = model.evaluate(X, labels, batch_size=1)
print("test loss, test acc:", results)
# classes of training data
# drive to = 0
# slam = 1
# wait for = 2
# localization = 3
# stop = 5
# unknow = 6


XRNN = np.reshape(X,(X.shape[0],-1, X.shape[1]))

## Recurennt Neuronal Network
modelRNN = keras.Sequential()

# Input Layer
#model.add(tf.keras.layers.Embedding(input_dim=len(words), input_length = len(words), output_dim=100,
 #             trainable=True,
   #           mask_zero=True))
modelRNN.add(tf.keras.layers.InputLayer(input_shape=(1, X.shape[1]), name="input"))
# Masking layer for pre-trained embeddings
modelRNN.add(tf.keras.layers.Masking(mask_value=0.0))
# Recurrent layer
modelRNN.add(tf.keras.layers.LSTM(units=64, input_shape=(1, 2, X.shape[1]), return_sequences=True, dropout=0.4, recurrent_dropout=0.4))
modelRNN.add(tf.keras.layers.LSTM(units=64, return_sequences=True, dropout=0.3, recurrent_dropout=0.3))
modelRNN.add(tf.keras.layers.LSTM(64))
# Fully connected layer
modelRNN.add(tf.keras.layers.Dense(20, activation='relu'))
# Dropout for regularization
modelRNN.add(tf.keras.layers.Dropout(0.7))
# Output layer
modelRNN.add(tf.keras.layers.Dense(y.shape[1], activation='softmax', name="output"))

modelRNN.summary()

# Definieren des Optimizers
optimizer = tf.keras.optimizers.Adam(
    learning_rate=0.0001, beta_1=0.9, beta_2=0.999, epsilon=1e-07, amsgrad=False,
    name='RMSprop'
)

# Compilieren des Modells
modelRNN.compile(optimizer=optimizer,
              loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])

start = time.time()
# Trainieren des Modells
modelRNN.fit(XRNN,labels, epochs=1250)
print(time.time()-start)

sentence1 = "use simultaneous localization and mapping"
input = bow(sentence1.lower(), words, show_details=False)
print(modelRNN.predict(np.reshape(input,(1, 1, len(words)))))

# Speichern als keras Modell
#modelRNN.save('taskClassifierRNN')

# Konvertieren in Tflite Modell

converter = tf.lite.TFLiteConverter.from_keras_model(modelRNN)
converter.allow_custom_ops=True
tflite_model = converter.convert()
open("taskClassifierRNN.tflite", "wb").write(tflite_model)


labels = np.array(test_labels)
X = np.array(test_data)
X = np.reshape(X,(X.shape[0],-1, X.shape[1]))

results = modelRNN.evaluate(X, labels, batch_size=1)
print("test loss, test acc:", results)
