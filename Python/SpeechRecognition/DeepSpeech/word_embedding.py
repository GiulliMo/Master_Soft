import json
import tensorflow as tf
import phonetics
import nltk
from gensim.models.deprecated.word2vec import Word2Vec
from keras_preprocessing.sequence import pad_sequences
from keras_preprocessing.text import Tokenizer, one_hot
from matplotlib import pyplot
from sklearn.decomposition import PCA
from tensorflow import keras
import numpy as np
from lib.sentence2vec import Sentence2Vec


class_names = ['drive to', 'slam', 'wait for', 'localization', 'stop', 'unknow']

# Definieren von Trainingsdaten
with open('data/training_data_II.json') as json_file:
    training_data = json.load(json_file)

numclass1 = []
numclass2 = []
numclass3 = []
numclass4 = []
numclass5 = []
numclass6 = []
training_data_phon=[]
labels = []
# add labels with loop through each training_data element
for i in range(len(training_data)):
    labels.append(training_data[i]["class"])
    sentence = training_data[i]["sentence"].replace("'", "")
    res = sentence.split()
    phoneRes = []
    for k in res:
        phoneRes.append(phonetics.metaphone(k))
    training_data_phon.append({"class": training_data[i]["class"], "sentence": training_data[i]["sentence"] + ' ' + ' '.join(phoneRes)})

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


print(numclass1)
print(numclass2)
print(numclass3)
print(numclass4)
print(numclass5)
print(numclass6)

corpus=[]
for sen in training_data:
    corpus.append(sen['sentence'])

words = []
classes = []
documents = []

for pattern in training_data_phon:
    # tokenize each word in the sentence
    w = nltk.word_tokenize(pattern['sentence'])
    # add to our words list
    words.extend(w)
    # add to documents in our corpus
    documents.append((w))

# integer encode the documents
t = Tokenizer()
t.fit_on_texts(corpus)
vocab_size = len(t.word_index) + 1
print(vocab_size)
encoded_docs = [one_hot(d, vocab_size) for d in corpus]
print(encoded_docs)

# pad documents to a max length of 12 words
max_length = 15
padded_docs = pad_sequences(encoded_docs, maxlen=max_length, padding='post')
print(padded_docs)


# define the model
model = keras.Sequential()
model.add(tf.keras.layers.Embedding(vocab_size,8, input_length=max_length, name="first"))
model.add(tf.keras.layers.Flatten(name='second'))
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
print(labels)
# fit the model
model.fit(np.array(padded_docs), np.array(labels), epochs=500, verbose=0)

sentence = "find yourself in known environment"
encoded_sentence = [one_hot(sentence, vocab_size)]
padded_sentence = pad_sequences(encoded_sentence, maxlen=max_length, padding='post')

print(padded_sentence)
X = model.predict(padded_sentence)
print(X)

'''

model = Word2Vec(documents, min_count=1)
model.save('word2vec.model')
model=Word2Vec.load('word2vec.model')

model = Sentence2Vec('word2vec.model')
print(model.get_vector('simultaneous localization and mapping'))
print(model.similarity('simultaneous localization and mapping',
                       'simultaneous localization'))

model=Word2Vec.load('word2vec.model')
X = model[model.wv.vocab]
print(type(X))
pca = PCA(n_components=2)
result = pca.fit_transform(np.reshape(X,(X.shape[0],-1)))

# create a scatter plot of the projection
pyplot.scatter(result[:, 0], result[:, 1])
words = list(model.wv.vocab)
print(words)
for i, word in enumerate(words):
	pyplot.annotate(word, xy=(result[i, 0], result[i, 1]))
pyplot.show()


model = Sentence2Vec('word2vec.model')
'''
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

print(np.asarray(weights[1][0]))

padded_sentence[0] = 0
X = testmodel.predict(padded_sentence)
summe = np.sum(X)
max = np.max(X)
print(X)

X=[]
sen = []
for i in range(len(training_data)):
    #print(training_data_phon[i]['sentence'])
    sentence = training_data_phon[i]['sentence']
    encoded_sentence = [one_hot(sentence, vocab_size)]
    padded_sentence = pad_sequences(encoded_sentence, maxlen=max_length, padding='post')
    X.append(testmodel.predict(padded_sentence))
    sen.append(str(i))

X = np.asarray(X)
pca = PCA(n_components=2)
result = pca.fit_transform(np.reshape(X,(X.shape[0],-1)))

# create a scatter plot of the projection
#pyplot.scatter(result[:, 0], result[:, 1])
result_x = result[:, 0]
result_y = result[:, 1]

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

