import json
import tensorflow as tf
import phonetics
import nltk
import os
from nltk.stem.lancaster import LancasterStemmer
stemmer = LancasterStemmer()
from keras_preprocessing.sequence import pad_sequences
from keras_preprocessing.text import Tokenizer, one_hot
from matplotlib import pyplot
from sklearn.decomposition import PCA
from tensorflow import keras
import numpy as np
from numpy import savetxt



class_names = ['drive to', 'slam', 'wait for', 'localization', 'stop', 'unknow']

# Definieren von Trainingsdaten
#with open('data/training_data_II.json') as json_file:
  #  training_data = json.load(json_file)

with open('data/test_data_II.json') as json_file:
    test_data = json.load(json_file)

# Definieren von Trainingsdaten aus dataset analysis
with open('data/random_distributed_dataset.json') as json_file:
    training_data= json.load(json_file)


def loadJsons(dir):
    f = open(dir, "r")
    jsonfile = json.loads(f.read())
    f.close()
    return jsonfile


hypothesis = loadJsons("data/hypothesisDeepSpeech_DataII.json")
labelsTask = loadJsons("data/labelsTaskDeepSpeech_DataII.json")
hypothesis2 = loadJsons("data/hypothesisEspnet_DataII.json")
labelsTask2 = loadJsons("data/labelsTaskEspnet_DataII.json")
hypothesis3 = loadJsons("data/hypothesisPocket_DataII.json")
labelsTask3 = loadJsons("data/labelsTaskPocket_DataII.json")

hypothesis1_val = loadJsons("data/hypothesisDeepSpeech_DataI.json")
labelsTask1_val = loadJsons("data/labelsTaskDeepSpeech_DataI.json")
hypothesis2_val = loadJsons("data/hypothesisEspnetDataI.json")
labelsTask2_val = loadJsons("data/labelsTaskEspnetDataI.json")
hypothesis3_val = loadJsons("data/hypothesisPocketDataI.json")
labelsTask3_val = loadJsons("data/labelsTaskPocketDataI.json")
hypothesis4_val = loadJsons("data/hypothesisIBM_DataI.json")
labelsTask4_val = loadJsons("data/labelsTaskIBM_DataI.json")

with open('data/training_data_II.json') as json_file:
    set = json.load(json_file)

sentence = []
lbl = []

for data in set:
    lbl.append(data["class"])
    sentence.append(data["sentence"])


hypothesis = hypothesis + hypothesis2 + hypothesis3 + sentence
labelsTask = labelsTask + labelsTask2 + labelsTask3 + lbl
hypothesisPhon =[]

hypothesis_val = hypothesis1_val+ hypothesis2_val + hypothesis3_val + hypothesis4_val
labelsTask_val = labelsTask1_val + labelsTask2_val + labelsTask3_val + labelsTask4_val



numclass1 = []
numclass2 = []
numclass3 = []
numclass4 = []
numclass5 = []
numclass6 = []
training_data_phon=[]
test_data_phon = []
labels = []
testlabels = []


# add labels with loop through each training_data element
# phonetischen Teil anhängen
for i in range(len(training_data)):
    #labels.append(training_data[i]["class"])
    sentence = training_data[i]["sentence"].replace("'", "")
    res = sentence.split()
    phoneRes = []
    for k in res:
        phoneRes.append(phonetics.metaphone(k))
    training_data_phon.append({"class": training_data[i]["class"], "sentence": training_data[i]["sentence"] + ' ' + ' '.join(phoneRes)})

    # numclasses fuer scatter plot
    if training_data[i]["class"] == 0:
        numclass1.append(i)

    if training_data[i]["class"] == 1:
        numclass2.append(i)

    if training_data[i]["class"] == 2:
        numclass3.append(i)

    if training_data[i]["class"] == 3:
        numclass4.append(i)

    if training_data[i]["class"] == 4:
        numclass5.append(i)

    if training_data[i]["class"] == 5:
        numclass6.append(i)


# add labels with loop through each training_data element
for i in range(len(hypothesis)):
    #labels.append(training_data[i]["class"])
    #sentence = training_data[i]["sentence"].replace("'", "")
    sentence = hypothesis[i].replace("'", "")
    res = sentence.split()
    phoneRes = []
    for k in res:
        phoneRes.append(phonetics.metaphone(k))
    #training_data_phon.append({"class": training_data[i]["class"], "sentence": training_data[i]["sentence"] + ' ' + ' '.join(phoneRes)})
    hypothesisPhon.append(hypothesis[i]+ ' ' + ' '.join(phoneRes))
print(hypothesisPhon)

## fuer scatter plot
for i in range(len(test_data)):
    testlabels.append(training_data[i]["class"])
    sentence = test_data[i]["sentence"].replace("'", "")
    res = sentence.split()
    phoneRes = []
    for k in res:
        phoneRes.append(phonetics.metaphone(k))
    test_data_phon.append(
        {"class": training_data[i]["class"], "sentence": training_data[i]["sentence"] + ' ' + ' '.join(phoneRes)})


print(len(numclass1))
print(len(numclass2))
print(len(numclass3))
print(len(numclass4))
print(len(numclass5))
print(len(numclass6))


## pre processign neuronales netz
corpus=[]
for sen in hypothesisPhon:#training_data_phon:
    corpus.append(sen)#['sentence'])

# integer encode the documents
t = Tokenizer()
t.fit_on_texts(corpus)
words = list(t.word_index)


def clean_up_sentence(sentence):
    # tokenize the pattern
    sentence_words = nltk.word_tokenize(sentence)
    # stem each word
    #sentence_words = [stemmer.stem(word.lower()) for word in sentence_words]
    return sentence_words

# return bag of words array: 0 or 1 for each word in the bag that exists in the sentence
def bow(sentence, words, show_details=False):
    # tokenize the pattern
    sentence_words = clean_up_sentence(sentence)
    # bag of words
    bag = [0] * len(words)
    one = []
    for s in sentence_words:
        #print(s)
        for i, w in enumerate(words):
            if w == s:
                bag[i] = 1
                one.append(i+1)
                if show_details:
                    print("found in bag: %s" % w)
    onehot = list(one)
    return onehot

# words = words_embedding!!
# List of Words schreiben, da wörter unterschiedlich angeordnet werden
with open('words_embedding.txt', 'w') as f:
    for item in list(t.word_index):
        f.write("%s," % item)

encoded_docs = []
for d in corpus:
    encoded_docs.append(bow(sentence=d.lower(),words=words, show_details=False))
vocab_size = len(t.word_index) + 1
print(vocab_size)

#encoded_docs = [one_hot(d, vocab_size) for d in corpus]
# embedding dimension
edim = 8

max_length = 25
padded_docs = pad_sequences(encoded_docs, maxlen=max_length, padding='post')
# define the model
model = keras.Sequential()
model.add(tf.keras.layers.Embedding(vocab_size,8, input_length=max_length, name="first"))
model.add(tf.keras.layers.Flatten(name='second'))
model.add(tf.keras.layers.Dropout(0.2, input_shape=(1, max_length*edim)))
model.add(keras.layers.Dense(units=300, activation='sigmoid'))
model.add(keras.layers.Dense(units=6, activation='softmax', name = 'third'))

# Definieren des Optimizers
optimizer = tf.keras.optimizers.Adam(
    learning_rate=0.0001, beta_1=0.9, beta_2=0.999, epsilon=1e-07, amsgrad=False,
    name='RMSprop'
)

# Compilieren des Modells
model.compile(optimizer=optimizer,
              loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])

# summarize the model
print(model.summary())

padded_docs = np.array(padded_docs)
labels = np.array(labelsTask)


sentence_validate = []
lbl_validate = []
encoded_docs = []

for data in test_data:
    lbl_validate.append(data["class"])
    transcript = data["sentence"]
    ## Bearbeiten des Transcripts
    transcript = transcript.replace("'", "")
    res = transcript.split()
    phoneRes = []

    # phonetischen Teil mit metaphone bestimmen
    for k in res:
        phoneRes.append(phonetics.metaphone(k))
    transcript = transcript + ' ' + ' '.join(phoneRes)
    sentence_validate.append(transcript)

print(lbl_validate)

for de in hypothesis_val:
    sentence = de
    res = sentence.split()
    phoneRes = []
    for k in res:
        phoneRes.append(phonetics.metaphone(k))
    de = de + ' ' + ' '.join(phoneRes)
    encoded_docs.append(bow(sentence=de.lower(),words=words, show_details=False))

padded_docs_validate = pad_sequences(encoded_docs, maxlen=max_length, padding='post')
print(padded_docs_validate)
padded_docs_validate = np.array(padded_docs_validate)
lbl_validate = np.array(labelsTask_val)

# fit the model
history = model.fit(padded_docs, labels, batch_size=50, epochs=200, validation_data=(padded_docs_validate, lbl_validate))

name = "historyFFWE.csv"
if os.path.exists(name):
    os.remove(name)
np.savetxt(name,(history.history['accuracy'],history.history['loss'],history.history['val_accuracy'],history.history['val_loss'] ),fmt='%f')
# Konvertieren in Tflite Modell
converter = tf.lite.TFLiteConverter.from_keras_model(model)
tflite_model = converter.convert()


modelRNN = keras.Sequential()
modelRNN.add(tf.keras.layers.Embedding(vocab_size,12, input_length=max_length, name="first"))
modelRNN.add(tf.keras.layers.SimpleRNN(12, return_sequences=True))
modelRNN.add(tf.keras.layers.SimpleRNN(8))
modelRNN.add(keras.layers.Dense(units=8, activation='sigmoid'))
modelRNN.add(keras.layers.Dense(units=6, activation='softmax'))


# Compilieren des Modells
modelRNN.compile(optimizer=optimizer,
              loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])
print(modelRNN.summary())

# Definieren des Optimizers
optimizer = tf.keras.optimizers.Adam(
    learning_rate=0.0001, beta_1=0.9, beta_2=0.999, epsilon=1e-07, amsgrad=False,
    name='RMSprop'
)

# fit the model

history = modelRNN.fit(padded_docs, labels, batch_size=20, epochs=200,validation_data=(padded_docs_validate, lbl_validate))

name = "historyRNN.csv"
if os.path.exists(name):
    os.remove(name)
np.savetxt(name,(history.history['accuracy'],history.history['loss'],history.history['val_accuracy'],history.history['val_loss'] ),fmt='%f')

# Konvertieren in Tflite Modell
converter = tf.lite.TFLiteConverter.from_keras_model(modelRNN)
tflite_model = converter.convert()
open("taskClassifierPhonWordEmbeddingRNN.tflite", "wb").write(tflite_model)

#results = modelRNN.evaluate(padded_docs[int(len(training_data)*ratio):len(training_data)], labels[int(len(training_data)*ratio):len(training_data)], batch_size=1)
#print("test loss, test acc:", results)


## jetzt das ganze plotten

minput = model.get_layer('first')
mhidden = model.get_layer('second')
N=len(model.layers) # Anzahl Layer
weights = [None] * N

for i in range(N):
    weights[i]=model.layers[i].get_weights()


testmodel = keras.Model(model.get_layer('first').input, outputs=model.get_layer("second").output)
N=len(testmodel.layers) # Anzahl Layer
weights = [None] * N

for i in range(N):
    weights[i]=testmodel.layers[i].get_weights()

X=[]
sen = []

for i in range(len(training_data)):
    #print(training_data_phon[i]['sentence'])
    sentence = training_data_phon[i]['sentence']
    encoded_sentence = [0]
    encoded_sentence[0] = bow(sentence=sentence.lower(), words=words, show_details=False)
    padded_sentence = pad_sequences(list(encoded_sentence), maxlen=max_length, padding='post')
    X.append(testmodel.predict(padded_sentence))
    sen.append(str(i))

X = np.asarray(X)
pca = PCA(n_components=3)
result = pca.fit_transform(np.reshape(X,(X.shape[0],-1)))

# create a scatter plot of the projection
#pyplot.scatter(result[:, 0], result[:, 1])
result_x = result[:, 0]
result_y = result[:, 1]
result_z = result[:, 2]

print(numclass1)
print(numclass2)
print(numclass3)
print(numclass4)
print(numclass5)
print(numclass6)
savetxt('pca_results346.csv', [result_x,result_y, result_z], delimiter=',')

colors = ['b', 'c', 'y', 'm', 'r', 'g']
drive = pyplot.scatter(result_x[numclass1],result_y[numclass1],color=colors[0])
slam = pyplot.scatter(result_x[numclass2],result_y[numclass2],color=colors[1])
wait = pyplot.scatter(result_x[numclass3],result_y[numclass3],color=colors[2])
local = pyplot.scatter(result_x[numclass4],result_y[numclass4],color=colors[3])
stop = pyplot.scatter(result_x[numclass5],result_y[numclass5],color=colors[4])
unknow = pyplot.scatter(result_x[numclass6],result_y[numclass6],color=colors[5])

for i, sent in enumerate(sen):
	pyplot.annotate(sent, xy=(result[i, 0], result[i, 1]))


pyplot.legend((drive, slam, wait, local, stop, unknow),
           (class_names),
           scatterpoints=1,
           loc='lower right',
           ncol=3,
           fontsize=8)
pyplot.show()

