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
# drive to = 0
# slam = 1
# wait for = 2
# localization = 3
# stop = 5
# unknow = 6

class_names = ['drive to', 'slam', 'wait for', 'localization', 'stop', 'unknow']

# Definieren von Trainingsdaten
training_data = []
training_data.append({"class":0, "sentence":"drive to location alpha", "modus":0})
training_data.append({"class":0, "sentence":"drive to position beta", "modus":0})
training_data.append({"class":0, "sentence":"drive to location charlie", "modus":0})
training_data.append({"class":0, "sentence":"change mode to driving", "modus":2})
training_data.append({"class":0, "sentence":"drive to station", "modus":0})
training_data.append({"class":0, "sentence":"drive to bergmann", "modus":0})
training_data.append({"class":0, "sentence":"drive to emperor", "modus":0})
training_data.append({"class":0, "sentence":"change state to driving", "modus":2})
training_data.append({"class":0, "sentence":"move to alpha", "modus":0})
training_data.append({"class":0, "sentence":"ride to easy", "modus":0})
training_data.append({"class":0, "sentence":"use autonomous driving to location delta", "modus":0})
training_data.append({"class":0, "sentence":"move autonomously to golf", "modus":0})
training_data.append({"class":0, "sentence":"plan trip and move to location", "modus":0})
training_data.append({"class":0, "sentence":"plan a trajectorie and move to foxtrot", "modus":0})
training_data.append({"class":0, "sentence":"plan trip to move", "modus":2})
training_data.append({"class":0, "sentence":"moving to location hotel", "modus":0})
training_data.append({"class":0, "sentence":"moving to location easy", "modus":0})
training_data.append({"class":0, "sentence":"moving to position foxtrot", "modus":0})
training_data.append({"class":0, "sentence":"move to station charlie", "modus":0})
training_data.append({"class":0, "sentence":"deliver your package", "modus":0})
training_data.append({"class":0, "sentence":"deliver to location delta", "modus":0})
training_data.append({"class":0, "sentence":"deliver package to location", "modus":0})
training_data.append({"class":0, "sentence":"deliver to beta", "modus":0})
training_data.append({"class":0, "sentence":"deliver to alpha", "modus":0})
training_data.append({"class":0, "sentence":"deliver to foxtrot", "modus":0})
training_data.append({"class":0, "sentence":"deliver to echo", "modus":0})
training_data.append({"class":0, "sentence":"start to deliver your load to alpha", "modus":0})
training_data.append({"class":0, "sentence":"move to position india", "modus":0})
training_data.append({"class":0, "sentence":"drive autonomously", "modus":0})
training_data.append({"class":0, "sentence":"drive manually with joystick", "modus":1})
training_data.append({"class":0, "sentence":"drive manually with ros visualization", "modus":1})
training_data.append({"class":0, "sentence":"drive manually", "modus":1})
training_data.append({"class":0, "sentence":"start to drive autonomously to location laboratory", "modus":0})
training_data.append({"class":0, "sentence":"start to drive manually with the given controller", "modus":1})
training_data.append({"class":0, "sentence":"begin with driving to location hotel", "modus":0})
training_data.append({"class":0, "sentence":"try to drive autonomously to a location of users choice", "modus":0})
training_data.append({"class":0, "sentence":"switch to driving mode", "modus":2})
training_data.append({"class":0, "sentence":"can you shift to the driving mode", "modus":2})
training_data.append({"class":0, "sentence":"start to drive by hand", "modus":2})
training_data.append({"class":0, "sentence":"start to drive with joystick", "modus":2})
training_data.append({"class":0, "sentence":"drive with joystick", "modus":2})
training_data.append({"class":0, "sentence":"move to the laboratory to grab package", "modus":0})
training_data.append({"class":0, "sentence":"make use of the joystick to drive manually", "modus":1})
training_data.append({"class":0, "sentence":"drive with rviz to a position of your choice", "modus":1})
training_data.append({"class":0, "sentence":"can you drive to the emperor and deliver your load", "modus":0})
training_data.append({"class":0, "sentence":"drive to location foxtrot", "modus":0})
training_data.append({"class":0, "sentence":"drive to position foxtrot", "modus":0})
training_data.append({"class":0, "sentence":"move to position foxtrot", "modus":0})
training_data.append({"class":0, "sentence":"bring the package from laboratory", "modus":0})
training_data.append({"class":0, "sentence":"follow the next person", "modus":0})
training_data.append({"class":0, "sentence":"go to last person you saw", "modus":0})
training_data.append({"class":0, "sentence":"can you drive to the last person you saw", "modus":0})
training_data.append({"class":0, "sentence":"move to a person", "modus":0})
training_data.append({"class":0, "sentence":"drive with joy stick", "modus":0})

training_data.append({"class":1, "sentence":"start slam", "modus":2})
training_data.append({"class":1, "sentence":"switch to expedition mode", "modus":0})
training_data.append({"class":1, "sentence":"change to map and localization mode", "modus":2})
training_data.append({"class":1, "sentence":"change to localization and mapping mode", "modus":2})
training_data.append({"class":1, "sentence":"simultaneous localization and mapping mode on", "modus":2})
training_data.append({"class":1, "sentence":"change to slam mode", "modus":2})
training_data.append({"class":1, "sentence":"change to slam state", "modus":2})
training_data.append({"class":1, "sentence":"create a new static map", "modus":2})
training_data.append({"class":1, "sentence":"begin with mapping and localization", "modus":2})
training_data.append({"class":1, "sentence":"begin mapping manually", "modus":1})
training_data.append({"class":1, "sentence":"start mapping manually", "modus":1})
training_data.append({"class":1, "sentence":"start mapping and localization", "modus":2})
training_data.append({"class":1, "sentence":"solve the slam problem", "modus":2})
training_data.append({"class":1, "sentence":"explore your environment", "modus":0})
training_data.append({"class":1, "sentence":"explore with slam", "modus":0})
training_data.append({"class":1, "sentence":"explore with simultaneous localization and mapping", "modus":0})
training_data.append({"class":1, "sentence":"change to explore mode", "modus":0})
training_data.append({"class":1, "sentence":"use slam for pose estimation", "modus":2})
training_data.append({"class":1, "sentence":"explore the laboratory", "modus":0})
training_data.append({"class":1, "sentence":"solve the selfe localization and mapping problem", "modus":2})
training_data.append({"class":1, "sentence":"what is your position in the unknown environment", "modus":2})
training_data.append({"class":1, "sentence":"estimate the map and your pose", "modus":2})
training_data.append({"class":1, "sentence":"localize in unknown environment", "modus":2})
training_data.append({"class":1, "sentence":"find yourself in unknown environment", "modus":2})
training_data.append({"class":1, "sentence":"estimate your pose in unknown environment", "modus":2})
training_data.append({"class":1, "sentence":"can you start with pose estimation and mapping", "modus":2})
training_data.append({"class":1, "sentence":"can you start with slam", "modus":2})
training_data.append({"class":1, "sentence":"localize yourself with slam", "modus":2})
training_data.append({"class":1, "sentence":"start slam", "modus":2})
training_data.append({"class":1, "sentence":"start slam algortihm", "modus":2})
training_data.append({"class":1, "sentence":"simultaneous localization while mapping", "modus":2})
training_data.append({"class":1, "sentence":"start simultaneous localization and mapping", "modus":2})
training_data.append({"class":1, "sentence":"start slam for pose estimation", "modus":2})
training_data.append({"class":1, "sentence":"use slam for mapping", "modus":2})
training_data.append({"class":1, "sentence":"simultaneous localization and mapping in unknow environment", "modus":2})
training_data.append({"class":1, "sentence":"explore with slam and drive autonomously", "modus":0})
training_data.append({"class":1, "sentence":"explore the environment with slam and drive manually", "modus":1})
training_data.append({"class":1, "sentence":"localize and map manually", "modus":1})
training_data.append({"class":1, "sentence":"estimate the map and your position", "modus":2})
training_data.append({"class":1, "sentence":"estimate your position and your map simultaneously", "modus":2})
training_data.append({"class":1, "sentence":"can you start to solve the slam problem", "modus":2})
training_data.append({"class":1, "sentence":"try to solve slam", "modus":2})
training_data.append({"class":1, "sentence":"try to localize yourself in unknown environment", "modus":2})
training_data.append({"class":1, "sentence":"record a static map", "modus":2})
training_data.append({"class":1, "sentence":"launch slam", "modus":2})
training_data.append({"class":1, "sentence":"provide a pose with use of the slam algorithm", "modus":2})
training_data.append({"class":1, "sentence":"try to provide a pose with slam", "modus":2})
training_data.append({"class":1, "sentence":"try to solve simultaneous localization and mapping problem with hector", "modus":2})
training_data.append({"class":1, "sentence":"start hector node", "modus":2})
training_data.append({"class":1, "sentence":"can you solve slam with hector", "modus":2})
training_data.append({"class":1, "sentence":"localize yourself with slam", "modus":2})
training_data.append({"class":1, "sentence":"start pose estimation with slam", "modus":2})
training_data.append({"class":1, "sentence":"estimate your position with slam", "modus":2})
training_data.append({"class":1, "sentence":"estimate your position and map with slam", "modus":2})
training_data.append({"class":1, "sentence":"launch slam algortihm", "modus":2})
training_data.append({"class":1, "sentence":"launch hector node", "modus":2})
training_data.append({"class":1, "sentence":"switch to slam", "modus":2})
training_data.append({"class":1, "sentence":"start the navigation stack with slam", "modus":2})
training_data.append({"class":1, "sentence":"launch state slam", "modus":2})
training_data.append({"class":1, "sentence":"change to state slam", "modus":2})
training_data.append({"class":1, "sentence":"go to simultaneously localization and mapping mode", "modus":2})
training_data.append({"class":1, "sentence":"simultaneous localization and mapping in unknow environment autonomeously", "modus":0})
training_data.append({"class":1, "sentence":"simultaneous localization and mapping in unknow environment manually", "modus":1})
training_data.append({"class":1, "sentence":"try to provide a pose with slam autonomously", "modus":0})
training_data.append({"class":1, "sentence":"can you solve slam with hector manually", "modus":1})
training_data.append({"class":1, "sentence":"can you solve slam with hector autonomously", "modus":0})
training_data.append({"class":1, "sentence":"start to solve slam and drive with joystick", "modus":1})
training_data.append({"class":1, "sentence":"start to solve slam and drive with controller", "modus":1})
training_data.append({"class":1, "sentence":"what is your position in unknown environment", "modus":1})



training_data.append({"class":2, "sentence":"wait for a person", "modus":2})
training_data.append({"class":2, "sentence":"for which command do you wait for", "modus":2})
training_data.append({"class":2, "sentence":"wait for load", "modus":2})
training_data.append({"class":2, "sentence":"wait for delivery", "modus":2})
training_data.append({"class":2, "sentence":"pause for delivery", "modus":2})
training_data.append({"class":2, "sentence":"wait for command", "modus":2})
training_data.append({"class":2, "sentence":"take a break", "modus":2})
training_data.append({"class":2, "sentence":"stay in your actual position", "modus":2})
training_data.append({"class":2, "sentence":"stay in your operation mode", "modus":2})
training_data.append({"class":2, "sentence":"start your pause", "modus":2})
training_data.append({"class":2, "sentence":"how long was your break", "modus":2})
training_data.append({"class":2, "sentence":"start waiting interval", "modus":2})
training_data.append({"class":2, "sentence":"wait for your activation", "modus":2})
training_data.append({"class":2, "sentence":"take a break and wait for a person", "modus":2})
training_data.append({"class":2, "sentence":"wait for people", "modus":2})
training_data.append({"class":2, "sentence":"hold up with activities", "modus":2})
training_data.append({"class":2, "sentence":"wait for new commands", "modus":2})
training_data.append({"class":2, "sentence":"wait for new activities", "modus":2})
training_data.append({"class":2, "sentence":"take a break from activites", "modus":2})
training_data.append({"class":2, "sentence":"how long do you wait for load", "modus":2})
training_data.append({"class":2, "sentence":"wait for commands", "modus":2})
training_data.append({"class":2, "sentence":"change state to wait for", "modus":2})
training_data.append({"class":2, "sentence":"pause your delivery", "modus":2})
training_data.append({"class":2, "sentence":"start your break", "modus":2})
training_data.append({"class":2, "sentence":"start with waiting for commands", "modus":2})
training_data.append({"class":2, "sentence":"wait for a person", "modus":2})
training_data.append({"class":2, "sentence":"got to waiting mode", "modus":2})
training_data.append({"class":2, "sentence":"change state to waiting", "modus":2})
training_data.append({"class":2, "sentence":"change state to wait for", "modus":2})
training_data.append({"class":2, "sentence":"go to wait for", "modus":2})
training_data.append({"class":2, "sentence":"wait for a person to be recognized", "modus":2})
training_data.append({"class":2, "sentence":"can you wait for a person", "modus":2})

training_data.append({"class":3,  "sentence":"find yourself in the map", "modus":2})
training_data.append({"class":3,  "sentence":"localize yourself", "modus":2})
training_data.append({"class":3,  "sentence":"change to localization mode", "modus":2})
training_data.append({"class":3,  "sentence":"change state to localization", "modus":2})
training_data.append({"class":3,  "sentence":"this paper presents a new method for localization of Robots", "modus":2})
training_data.append({"class":3,  "sentence":"the operation require localization", "modus":2})
training_data.append({"class":3,  "sentence":"find yourself in a static map", "modus":2})
training_data.append({"class":3,  "sentence":"start the particle fitler", "modus":2})
training_data.append({"class":3,  "sentence":"use the particle filter for localization", "modus":2})
training_data.append({"class":3,  "sentence":"start the localization algorithm", "modus":2})
training_data.append({"class":3,  "sentence":"use the pose estimation algorithm to drive", "modus":2})
training_data.append({"class":3,  "sentence":"estimate pose in map", "modus":2})
training_data.append({"class":3,  "sentence":"estimate pose in static map", "modus":2})
training_data.append({"class":3,  "sentence":"start amcl localization", "modus":2})
training_data.append({"class":3,  "sentence":"start amcl", "modus":2})
training_data.append({"class":3,  "sentence":"start adaptive monte carlo localization", "modus":2})
training_data.append({"class":3,  "sentence":"use probabilistic localiztation system for robot moving", "modus":2})
training_data.append({"class":3,  "sentence":"use a particle filter to track the pose of a robot against a known map", "modus":2})
training_data.append({"class":3,  "sentence":"find yourself in the known map", "modus":2})
training_data.append({"class":3,  "sentence":"localize in known map", "modus":2})
training_data.append({"class":3,  "sentence":"localize in known environment", "modus":2})
training_data.append({"class":3,  "sentence":"localize in environment", "modus":2})
training_data.append({"class":3, "sentence":"estimate your pose in known environment", "modus":2})
training_data.append({"class":3, "sentence":"localize in static map", "modus":2})
training_data.append({"class":3, "sentence":"localize in mapped environment", "modus":2})
training_data.append({"class":3, "sentence":"estimate pose in mapped environment", "modus":2})
training_data.append({"class":3, "sentence":"start localization", "modus":2})
training_data.append({"class":3, "sentence":"start to localize yourself", "modus":2})
training_data.append({"class":3, "sentence":"start to localize yourself with particle filter", "modus":2})
training_data.append({"class":3, "sentence":"localize yourself in known map", "modus":2})
training_data.append({"class":3, "sentence":"localize yourself in static map", "modus":2})
training_data.append({"class":3, "sentence":"launch localization", "modus":2})
training_data.append({"class":3, "sentence":"launch localization and map server", "modus":2})
training_data.append({"class":3, "sentence":"find yourself in static map", "modus":2})
training_data.append({"class":3, "sentence":"use particle filter for localization", "modus":2})
training_data.append({"class":3, "sentence":"start with localization", "modus":2})
training_data.append({"class":3, "sentence":"localization in static map", "modus":2})
training_data.append({"class":3, "sentence":"scatter particles to find yourself", "modus":2})
training_data.append({"class":3, "sentence":"find yourself in known environment", "modus":2})
training_data.append({"class":3, "sentence":"switch to localization", "modus":2})
training_data.append({"class":3, "sentence":"start to scatter particles", "modus":2})
training_data.append({"class":3, "sentence":"start to localize yourself", "modus":2})
training_data.append({"class":3, "sentence":"try to localize yourself in known environment", "modus":2})
training_data.append({"class":3, "sentence":"try to localize yourself in static map", "modus":2})
training_data.append({"class":3, "sentence":"start navigation stack with particle filter", "modus":2})
training_data.append({"class":3, "sentence":"start navigation stack with amcl", "modus":2})
training_data.append({"class":3, "sentence":"launch navigation stack with localization", "modus":2})
training_data.append({"class":3, "sentence":"go to localization", "modus":2})


training_data.append({"class":4,  "sentence":"stop your actual task", "modus":2})
training_data.append({"class":4,  "sentence":"stop your engine", "modus":2})
training_data.append({"class":4,  "sentence":"change to stop mode", "modus":2})
training_data.append({"class":4,  "sentence":"stop your task", "modus":2})
training_data.append({"class":4,  "sentence":"stop driving", "modus":2})
training_data.append({"class":4,  "sentence":"finish driving", "modus":2})
training_data.append({"class":4,  "sentence":"finish your task", "modus":2})
training_data.append({"class":4,  "sentence":"end your delivery", "modus":2})
training_data.append({"class":4,  "sentence":"stop deliver load", "modus":2})
training_data.append({"class":4,  "sentence":"terminate your activity", "modus":2})
training_data.append({"class":4,  "sentence":"put an end to your acitvity", "modus":2})
training_data.append({"class":4,  "sentence":"end your delivery", "modus":2})
training_data.append({"class":4,  "sentence":"put a stop to your delivery", "modus":2})
training_data.append({"class":4,  "sentence":"stop to drive", "modus":2})
training_data.append({"class":4,  "sentence":"stop the slam mode", "modus":2})
training_data.append({"class":4,  "sentence":"stop with localization", "modus":2})
training_data.append({"class":4,  "sentence":"stop waiting for a person", "modus":2})
training_data.append({"class":4,  "sentence":"stop people recognizing", "modus":2})
training_data.append({"class":4,  "sentence":"stop to deliver load", "modus":2})
training_data.append({"class":4,  "sentence":"stop to localize", "modus":2})
training_data.append({"class":4,  "sentence":"stop to solve slam", "modus":2})
training_data.append({"class":4,  "sentence":"stop to drive", "modus":2})
training_data.append({"class":4,  "sentence":"shutdown ros", "modus":2})
training_data.append({"class":4,  "sentence":"shutdown robot operating system", "modus":2})
training_data.append({"class":4,  "sentence":"shutdown the system", "modus":2})
training_data.append({"class":4,  "sentence":"finish the delivery", "modus":2})
training_data.append({"class":4,  "sentence":"finish the solution of the slam problem", "modus":2})
training_data.append({"class":4,  "sentence":"finish localization", "modus":2})
training_data.append({"class":4,  "sentence":"end your waiting process", "modus":2})
training_data.append({"class":4,  "sentence":"switch to stop", "modus":2})

training_data.append({"class":5,  "sentence":"none", "modus":2})
training_data.append({"class":5,  "sentence":"none", "modus":2})
training_data.append({"class":5,  "sentence":"none", "modus":2})
training_data.append({"class":5,  "sentence":"none", "modus":2})
training_data.append({"class":5,  "sentence":"none", "modus":2})
training_data.append({"class":5,  "sentence":"none", "modus":2})
training_data.append({"class":5,  "sentence":"none", "modus":2})
training_data.append({"class":5,  "sentence":"none", "modus":2})
training_data.append({"class":5,  "sentence":"none", "modus":2})
training_data.append({"class":5,  "sentence":"none", "modus":2})
training_data.append({"class":5,  "sentence":"none", "modus":2})
training_data.append({"class":5,  "sentence":"none", "modus":2})
training_data.append({"class":5,  "sentence":"none", "modus":2})
training_data.append({"class":5,  "sentence":"none", "modus":2})
training_data.append({"class":5,  "sentence":"none", "modus":2})
training_data.append({"class":5,  "sentence":"i", "modus":2})
training_data.append({"class":5,  "sentence":"a", "modus":2})
training_data.append({"class":5,  "sentence":"b", "modus":2})
training_data.append({"class":5,  "sentence":"y", "modus":2})
training_data.append({"class":5,  "sentence":"s", "modus":2})
training_data.append({"class":5,  "sentence":"l", "modus":2})
training_data.append({"class":5,  "sentence":"o", "modus":2})
training_data.append({"class":5,  "sentence":"e", "modus":2})
training_data.append({"class":5,  "sentence":"u", "modus":2})
training_data.append({"class":5,  "sentence":"your lack of faith is disturbing", "modus":2})
training_data.append({"class":5,  "sentence":"your power is sufficient", "modus":2})
training_data.append({"class":5,  "sentence":"look alive you", "modus":2})
training_data.append({"class":5,  "sentence":"as the aim", "modus":2})
training_data.append({"class":5,  "sentence":"why you all inanimate", "modus":2})
training_data.append({"class":5,  "sentence":"no", "modus":2})
training_data.append({"class":5,  "sentence":"more", "modus":2})
training_data.append({"class":5,  "sentence":"it any", "modus":2})
training_data.append({"class":5,  "sentence":"stars lent", "modus":2})
training_data.append({"class":5,  "sentence":"lloc", "modus":2})
training_data.append({"class":5,  "sentence":"d alpha", "modus":2})
training_data.append({"class":5,  "sentence":"a beta", "modus":2})
training_data.append({"class":5,  "sentence":"l charlie", "modus":2})
training_data.append({"class":5,  "sentence":"right o", "modus":2})
training_data.append({"class":5,  "sentence":"start in again", "modus":2})
training_data.append({"class":5,  "sentence":"start airs", "modus":2})
training_data.append({"class":5,  "sentence":"so lamormain S", "modus":2})


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
model.fit(X, labels, epochs=1500)

# Speichern als keras Modell
#model.save('taskClassifier')

# Konvertieren in Tflite Modell
converter = tf.lite.TFLiteConverter.from_keras_model(model)
tflite_model = converter.convert()
open("taskClassifierPhon.tflite", "wb").write(tflite_model)


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
model.add(tf.keras.layers.Embedding(input_dim=len(words), input_length = len(words), output_dim=100,
              trainable=True,
              mask_zero=True))
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
modelRNN.fit(XRNN[0:len(documents)], labels[0:len(documents)], epochs=1000)
print(time.time()-start)

sentence1 = "use simultaneous loc"
input = bow(sentence1.lower(), words, show_details=False)
print(modelRNN.predict(np.reshape(input,(1, 1, len(words)))))

# Speichern als keras Modell
#modelRNN.save('taskClassifierRNN')

# Konvertieren in Tflite Modell

converter = tf.lite.TFLiteConverter.from_keras_model(modelRNN)
converter.allow_custom_ops=True
tflite_model = converter.convert()
open("taskClassifierRNN.tflite", "wb").write(tflite_model)