##################################################
## Author: Hannes Dittmann
## Version: 1.0
## Email: hannes.dittmann@stud.hshl.de
## Status: In Entwicklung
##################################################
## Dieses Skript dient dazu, ein neuronales Netz um bedienugnsorientierte Handlungen des ALF zu trainieren
## Ein Tflite Modell sowie eine Wortliste wird aus dem neuronalen Netz abgeleitet


# use natural language toolkit
import nltk
import tflite as tflite
from nltk.stem.lancaster import LancasterStemmer
stemmer = LancasterStemmer()
import tensorflow as tf
from tensorflow import keras, lite
import numpy as np

### Pre-proecessing

# classes of training data
# drive to = 0
# slam = 1
# wait for = 2
# localization = 3
# stop = 5

class_names = ['drive to', 'slam', 'wait for', 'localization', 'stop']

# Definieren von Trainingsdaten
training_data = []
training_data.append({"class":0, "sentence":"drive to location alpha"})
training_data.append({"class":0, "sentence":"drive to position beta"})
training_data.append({"class":0, "sentence":"drive to location charlie"})
training_data.append({"class":0, "sentence":"change mode to driving"})
training_data.append({"class":0, "sentence":"drive to station"})
training_data.append({"class":0, "sentence":"drive to bergmann"})
training_data.append({"class":0, "sentence":"change state to driving"})
training_data.append({"class":0, "sentence":"move to alpha"})
training_data.append({"class":0, "sentence":"ride to easy "})
training_data.append({"class":0, "sentence":"use autonomeous driving"})
training_data.append({"class":0, "sentence":"move autonomeously"})
training_data.append({"class":0, "sentence":"plan trip to location"})
training_data.append({"class":0, "sentence":"trajectorie to foxtrott"})
training_data.append({"class":0, "sentence":"plan trip to move"})
training_data.append({"class":0, "sentence":"moving to location"})
training_data.append({"class":0, "sentence":"moving to location easy"})
training_data.append({"class":0, "sentence":"moving to position foxtrott"})
training_data.append({"class":0, "sentence":"move to station charlie"})
training_data.append({"class":0, "sentence":"deliver your package"})
training_data.append({"class":0, "sentence":"deliver to location delta"})


training_data.append({"class":1, "sentence":"start slam"})
training_data.append({"class":1, "sentence":"change to map and localization mode"})
training_data.append({"class":1, "sentence":"change to localization and mapping mode"})
training_data.append({"class":1, "sentence":"simultaneous localization and mapping mode on"})
training_data.append({"class":1, "sentence":"change to slam mode"})
training_data.append({"class":1, "sentence":"change to slam state"})
training_data.append({"class":1, "sentence":"create a new map"})
training_data.append({"class":1, "sentence":"start mapping"})
training_data.append({"class":1, "sentence":"start mapping and localize"})
training_data.append({"class":1, "sentence":"start to solve slam"})
training_data.append({"class":1, "sentence":"explore your environment"})
training_data.append({"class":1, "sentence":"localize in mapped environment"})
training_data.append({"class":1, "sentence":"explore with slam"})
training_data.append({"class":1, "sentence":"explore with simultaneous localization and mapping"})
training_data.append({"class":1, "sentence":"change to explore mode"})
training_data.append({"class":1, "sentence":"use slam for pose estimation"})
training_data.append({"class":1, "sentence":"explore the laboratory"})
training_data.append({"class":1, "sentence":"solve slam problem"})
training_data.append({"class":1, "sentence":"what is your position in the unknown environment?"})
training_data.append({"class":1, "sentence":"estimate the map"})
training_data.append({"class":1, "sentence":"localize in unknown environment"})

training_data.append({"class":2, "sentence":"wait for a person"})
training_data.append({"class":2, "sentence":"for which command do you wait for"})
training_data.append({"class":2, "sentence":"wait for load"})
training_data.append({"class":2, "sentence":"wait for delivery"})
training_data.append({"class":2, "sentence":"pause for delivery"})
training_data.append({"class":2, "sentence":"wait for command"})
training_data.append({"class":2, "sentence":"take a break"})
training_data.append({"class":2, "sentence":"stay in your actual position"})
training_data.append({"class":2, "sentence":"stay in your operation mode"})
training_data.append({"class":2, "sentence":"start your pause "})
training_data.append({"class":2, "sentence":"how long was your break?"})
training_data.append({"class":2, "sentence":"start waiting interval"})
training_data.append({"class":2, "sentence":"wait for your activation"})
training_data.append({"class":2, "sentence":"take a break and wait for a person"})
training_data.append({"class":2, "sentence":"wait for people"})
training_data.append({"class":2, "sentence":"hold up with activities"})
training_data.append({"class":2, "sentence":"wait for new commands"})
training_data.append({"class":2, "sentence":"wait for new activities"})
training_data.append({"class":2, "sentence":"take a break from activites"})
training_data.append({"class":2, "sentence":"how long do you wait for load?"})

training_data.append({"class":3,  "sentence":"find yourself in the map"})
training_data.append({"class":3,  "sentence":"localize yourself"})
training_data.append({"class":3,  "sentence":"change to localization mode"})
training_data.append({"class":3,  "sentence":"change state to localization"})
training_data.append({"class":3,  "sentence":"this paper presents a new method for localization of Robots"})
training_data.append({"class":3,  "sentence":"the operation require localization"})
training_data.append({"class":3,  "sentence":"find yourself in a static map"})
training_data.append({"class":3,  "sentence":"start the particle fitler"})
training_data.append({"class":3,  "sentence":"use the particle filter for localization"})
training_data.append({"class":3,  "sentence":"start the localization algorithm"})
training_data.append({"class":3,  "sentence":"use the pose estimation algorithm to drive"})
training_data.append({"class":3,  "sentence":"estimate pose in map"})
training_data.append({"class":3,  "sentence":"estimate pose in static map"})
training_data.append({"class":3,  "sentence":"start amcl localization"})
training_data.append({"class":3,  "sentence":"start amcl"})
training_data.append({"class":3,  "sentence":"start adaptive monte carlo localization"})
training_data.append({"class":3,  "sentence":"use probabilistic localiztation system for robot moving"})
training_data.append({"class":3,  "sentence":"use a particle filter to track the pose of a robot against a known map"})
training_data.append({"class":3,  "sentence":"find yourself in the known map"})
training_data.append({"class":3,  "sentence":"localize in known map"})
training_data.append({"class":3,  "sentence":"localize in known environment"})
training_data.append({"class":3,  "sentence":"localize in environment"})


training_data.append({"class":4,  "sentence":"stop your actual task"})
training_data.append({"class":4,  "sentence":"stop your engine"})
training_data.append({"class":4,  "sentence":"change to stop mode"})
training_data.append({"class":4,  "sentence":"stop your task"})
training_data.append({"class":4,  "sentence":"stop driving"})
training_data.append({"class":4,  "sentence":"finish driving"})
training_data.append({"class":4,  "sentence":"finish your task"})
training_data.append({"class":4,  "sentence":"end your delivery"})
training_data.append({"class":4,  "sentence":"stop deliver load"})
training_data.append({"class":4,  "sentence":"terminate your activity"})
training_data.append({"class":4,  "sentence":"put an end to your acitvity"})
training_data.append({"class":4,  "sentence":"end your delivery"})
training_data.append({"class":4,  "sentence":"put a stop to your delivery"})
training_data.append({"class":4,  "sentence":"stop to drive"})
training_data.append({"class":4,  "sentence":"stop the slam mode"})
training_data.append({"class":4,  "sentence":"stop localization"})
training_data.append({"class":4,  "sentence":"stop waiting for a person"})
training_data.append({"class":4,  "sentence":"stop people recognizing"})


#Preprocessing
print ("%s sentences in training data" % len(training_data))
words = []
labels = []
classes = []
documents = []
ignore_words = ['?']

# loop through each sentence in our training data
for pattern in training_data:
    # tokenize each word in the sentence
    w = nltk.word_tokenize(pattern['sentence'])
    # add to our words list
    words.extend(w)
    # add to documents in our corpus
    documents.append((w, pattern['class']))
    # add to our classes list
    if pattern['class'] not in classes:
        classes.append(pattern['class'])

# add labels with loop through each training_data element
for i in range(len(training_data)):
    labels.append(training_data[i]["class"])

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
model.add(tf.keras.layers.InputLayer(input_shape=(X.shape[1])))
model.add(tf.keras.layers.Dropout(0.2, input_shape=(X.shape[1],)))
model.add(keras.layers.Dense(20, activation='softmax'))
model.add(keras.layers.Dense(y.shape[1], activation='softmax'))

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

# Trainiered des Modells
model.fit(X, labels, epochs=5000)

# Speichern als keras Modell
model.save('taskClassifier')

# Konvertieren in Tflite Modell
converter = tf.lite.TFLiteConverter.from_keras_model_file('taskClassifier')
tflite_model = converter.convert()
open("taskClassifier.tflite", "wb").write(tflite_model)


# classes of training data
# drive to = 0
# slam = 1
# wait for = 2
# localization = 3
# stop = 5

