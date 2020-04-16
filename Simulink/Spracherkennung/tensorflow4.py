# -*- coding: utf-8 -*-
"""
Created on Mon Mar 11 17:17:14 2019

@author: hannes.dittmann
"""
import time
import psutil
#import GPUtil
print('CPU Auslastung: ',psutil.cpu_percent())
start = time.time()

import tensorflow as tf

from tensorflow import keras

from keras.models import Sequential
from keras.layers import Dense
from keras.layers import Flatten
from keras.layers import Conv2D
from keras.layers import MaxPooling2D

import numpy as np

import matplotlib.pyplot as plt

print(tf.__version__)

#automatisches laden

#fashion_mnist = keras.datasets.fashion_mnist
#
#(train_images,train_labels),(test_images,test_labels) = fashion_mnist.load_data()

#manuelles laden der Daten


from mlxtend.data import loadlocal_mnist

print('1')

train_images,train_labels = loadlocal_mnist(images_path='/Users/hannes.dittmann/Desktop/Dataset/train-images-idx3-ubyte',
                                            labels_path='/Users/hannes.dittmann/Desktop/Dataset/train-labels-idx1-ubyte')

test_images,test_labels = loadlocal_mnist(images_path='/Users/hannes.dittmann/Desktop/Dataset/t10k-images-idx3-ubyte',
                                          labels_path='/Users/hannes.dittmann/Desktop/Dataset/t10k-labels-idx1-ubyte')

a = np.array(train_images)
train_images = np.reshape(a, (60000,28,28))

a = np.array(test_images)
test_images = np.reshape(a, (10000,28,28))


print('2')

class_names = ['T-shirt', 'Trouser', 'Pullover', 'Dress', 'Coat', 'Sandal', 'Shirt', 'Sneaker', 'Bag','Ankle boot']

plt.figure()
plt.imshow(train_images[1])
plt.colorbar()
plt.grid(False)
plt.show()

train_images, test_images = train_images / 255.0, test_images / 255.0

# Plot der ersten 25 Bilder

plt.figure(figsize=(10,10))
for i in range(25):
    plt.subplot(5,5,i+1)
    plt.xticks([])
    plt.yticks([])
    plt.grid(False)
    plt.imshow(train_images[i], cmap=plt.cm.binary)
    plt.xlabel(class_names[train_labels[i]])
plt.show()

#aus 3 dim durch reshape 4 dimensionen fuer den Faltungslayer muss angepasst  und Zeile 81 und 82 einkommentiert werden

#train_images=train_images.reshape([-1, 28, 28, 1])
#test_images=test_images.reshape([-1, 28, 28, 1])


#Modell mit Faltungslayern oder Fully Connected Layer, Anzahl der Dense Layer nur fuer erzeugen von Rechenaufwand
#tatsaechlicher nutzen im Bezug auf Genauigkeit ist nicht gegeben

model = Sequential()
#model.add(Conv2D(28, kernel_size=(7, 7), strides=(1, 1), activation=tf.nn.relu, input_shape=(28, 28, 1)))
#model.add(MaxPooling2D(pool_size=(2, 2), strides=(1, 1)))
#model.add(Conv2D(64, (7, 7),  activation=tf.nn.relu))
#model.add(MaxPooling2D(pool_size=(2, 2)))
model.add(Flatten(input_shape=(28,28)))
model.add(Dense(2048, activation=tf.nn.relu))
#model.add(Dense(1024, activation=tf.nn.relu))
#model.add(Dense(1024, activation=tf.nn.relu))
#model.add(Dense(1024, activation=tf.nn.relu))
#model.add(Dense(2048, activation=tf.nn.relu))
#model.add(Dense(1024, activation=tf.nn.relu))
#model.add(Dense(1024, activation=tf.nn.relu))
#model.add(Dense(1024, activation=tf.nn.relu))
#model.add(Dense(2048, activation=tf.nn.relu))
#model.add(Dense(1024, activation=tf.nn.relu))
#model.add(Dense(1024, activation=tf.nn.relu))
#model.add(Dense(255, activation=tf.nn.relu))
#model.add(Dense(128, activation=tf.nn.relu))
#model.add(Dense(64, activation=tf.nn.relu))
#model.add(Dense(32, activation=tf.nn.relu))
model.add(Dense(1024, activation=tf.nn.relu))
model.add(Dense(16, activation=tf.nn.softmax))

print('3')

model.compile(optimizer='adam',loss='sparse_categorical_crossentropy',metrics=['accuracy'])

model.fit(train_images, train_labels, epochs=2)

beginn_prediction=time.time()

test_loss, test_acc = model.evaluate(test_images, test_labels)

print('Test accuracy: ',test_acc)


predictions = model.predict(test_images)

ende=time.time()

print('Test predict: ',np.argmax(predictions[0]))
print('Test label: ',test_labels[0])



print('Laufzeit: {:5.3f}s'.format(ende-start))
print('Laufzeit der Prediction: {:5.3f}s'.format(ende-beginn_prediction))
print('CPU Auslastung: ',psutil.cpu_percent())

N=len(model.layers) # Anzahl Layer
weights = [None] * N
i1=255
i2=128
i3=64
i4=32
i5=16

print('N: ',N)

for i in range(N):
    weights[i]=model.layers[i].get_weights()
#
##weights[1][0] sind die gewichte und weights[1][1] sind die Bias Werte
##haendisches nachrechnen muss das gleiche ergeben wie bei der prediction der test images    
#
y_ = np.array((), dtype=np.uint8)

beginn2=time.time()

print('weight',weights[1][0])

#for x in range(10000):
#    A =  np.squeeze(np.asarray(test_images[x])).flatten()
#    o1 = A.dot(weights[1][0])+weights[1][1]
#    a1=o1
#    a1[a1<0] = 0
#    o2 = a1.dot(weights[2][0])+weights[2][1]
#    a2=o2
#    a2[a2<0] = 0
#    o3 = a2.dot(weights[3][0])+weights[3][1]
#    a3=o3
#    a3[a3<0] = 0
#    o4 = a3.dot(weights[4][0])+weights[4][1]
#    a4=o4
#    a4[a4<0] = 0
#    o5 = a4.dot(weights[5][0])+weights[5][1]
#    y_= np.append(y_, np.argmax(o5))
#
#ende2=time.time()
#    
#y_
#    
#test_labels_uint8 = np.uint8(np.array(test_labels))
#print(sum((y_ - test_labels) == 0)/len(test_labels_uint8))
##
#
#print('Laufzeit des manuell gerechneten netzes: {:5.3f}s'.format(ende2-beginn2))



#Python Progrmam ggf. ueber die Anaconda Prompt ausfuehren bei nicht 'vollstaendiger' Einrichtung der Tensorflow Umgebung






















