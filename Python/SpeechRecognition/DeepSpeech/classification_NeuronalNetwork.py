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
import phonetics
from nltk.stem.lancaster import LancasterStemmer
stemmer = LancasterStemmer()
import tensorflow as tf
from tensorflow import keras, lite
import numpy as np
import os
from keras_preprocessing.sequence import pad_sequences
import json


### Pre-proecessing

class_names = ['drive to', 'slam', 'wait for', 'localization', 'stop', 'unknow']

# Definieren von Trainingsdaten aus dataset analysis
with open('data/random_distributed_dataset.json') as json_file:
    random_distributed_dataset= json.load(json_file)
# Definieren von Trainingsdaten aus dataset analysis
with open("data/test_Data_II.json") as json_file:
    test_data = json.load(json_file)
# Definieren von Trainingsdaten aus dataset analysis
with open("data/hypothesisDeepSpeech_DataII.json") as json_file:
    training_data = json.load(json_file)
with open('data/labelsTaskDeepSpeech_DataII.json') as json_file:
    training_labels = json.load(json_file)

with open("data/hypothesisEspnet_DataII.json")as json_file:
    hypothesis2  = json.load(json_file)

with open("data/labelsTaskEspnet_DataII.json")as json_file:
    labels  = json.load(json_file)

with open("data/hypothesisPocket_DataII.json")as json_file:
    hypothesis3 = json.load(json_file)

with open("data/labelsTaskPocket_DataII.json")as json_file:
    labels3 = json.load(json_file)

with open('data/training_data_II.json') as json_file:
    dataset = json.load(json_file)

sentence = []
lbl = []

for data in dataset:
    lbl.append(data["class"])
    sentence.append(data["sentence"])

def loadJsons(dir):
    f = open(dir, "r")
    jsonfile = json.loads(f.read())
    f.close()
    return jsonfile

hypothesis1_val = loadJsons("data/hypothesisDeepSpeech_DataI.json")
labelsTask1_val = loadJsons("data/labelsTaskDeepSpeech_DataI.json")
hypothesis2_val = loadJsons("data/hypothesisEspnetDataI.json")
labelsTask2_val = loadJsons("data/labelsTaskEspnetDataI.json")
hypothesis3_val = loadJsons("data/hypothesisPocketDataI.json")
labelsTask3_val = loadJsons("data/labelsTaskPocketDataI.json")
hypothesis4_val = loadJsons("data/hypothesisIBM_DataI.json")
labelsTask4_val = loadJsons("data/labelsTaskIBM_DataI.json")


# listen verketten der testdaten
hypothesis_val = hypothesis1_val+ hypothesis2_val + hypothesis3_val + hypothesis4_val
labelsTask_val = labelsTask1_val + labelsTask2_val + labelsTask3_val + labelsTask4_val

# listen verketten der trainigns daten
training_data = training_data + hypothesis2 + hypothesis3 + sentence
training_labels = training_labels + labels + labels3 + lbl


dataset = []

for i in range(len(training_data)):
    dataset.append({"class":training_labels[i], "sentence":training_data[i]})

set, output, words, documents, classes, labels = preProcessing(dataset)

# daten splitten
ratio=3/4
training_data = set#[0:int(len(random_distributed_dataset)*ratio)]
training_labels = labels#[0:int(len(random_distributed_dataset)*ratio)]
#test_data = set[int(len(random_distributed_dataset)*ratio):len(random_distributed_dataset)]
#test_labels = labels[int(len(random_distributed_dataset)*ratio):len(random_distributed_dataset)]

X = np.array(training_data)
y = np.array(output[0:int(len(random_distributed_dataset)*ratio)])
print ("# words", len(words))
print ("# classes", len(classes))
labels = np.array(training_labels)



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

## Testdaten aufbereiten
X_validate = []
lbl_validate = []

for test in hypothesis_val:
    #lbl_validate.append(test["class"])
    #transcript = test["sentence"]
    transcript = test
    ## Bearbeiten des Transcripts
    transcript = transcript.replace("'", "")
    res = transcript.split()
    phoneRes = []

    # phonetischen Teil mit metaphone bestimmen
    for k in res:
        phoneRes.append(phonetics.metaphone(k))
    transcript = transcript + ' ' + ' '.join(phoneRes)
    X_validate.append(bow(transcript.lower(),words))

X_validate = np.array(X_validate)
lbl_validate = np.array(labelsTask_val)

# Definieren Neuronales Netzwerk
model = keras.Sequential()
model.add(tf.keras.layers.InputLayer(input_shape=X.shape[1]))
model.add(tf.keras.layers.Dropout(0.2, input_shape=(1, X.shape[1])))
model.add(keras.layers.Dense(units=300, activation='sigmoid'))
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
history = model.fit(X,labels, batch_size=50,epochs=200,validation_data=(X_validate, lbl_validate))
name = "historyFFW.csv"
if os.path.exists(name):
    os.remove(name)
np.savetxt(name,(history.history['accuracy'],history.history['loss'],history.history['val_accuracy'],history.history['val_loss'] ),fmt='%f')

# Speichern als keras Modell
#model.save('taskClassifier')

# Konvertieren in Tflite Modell
converter = tf.lite.TFLiteConverter.from_keras_model(model)
tflite_model = converter.convert()
open("taskClassifierPhon.tflite", "wb").write(tflite_model)
