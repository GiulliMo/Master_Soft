from libraries.asr import *
from libraries.nlp import *
import os
import tensorflow as tf
from numpy import asarray
from numpy import savetxt
from jiwer import wer, mer
import time

## preprocessing bevor getestet werden kann
## Ordner Data muss angelegt werden mit Data/Name/....
## libraries beinhalten code von alf
## wav dateien aus data werden alle(!) in wavfiles gelegt ==> len(wavefiles) == len(mergedlist)

nlp = nlp()
dataname = "Data_III"
datadir = os.listdir(dataname)
ignore1 = '.DS_Store'
print(datadir)

## asr objekt und modelle laden

asr = asr(language="gb")

#deepspeech initialisieren
model = asr.initModel()

#klassifizierer initialisieren
nlp.words = nlp.readWords("models/words.txt")
nlp.wordsModus = nlp.readWords("models/words_modus.txt")
nlp.modelTaskClassifier = tf.lite.Interpreter("models/taskClassifierRNN.tflite")
nlp.modelModusClassifier = tf.lite.Interpreter("models/autonom_manualRNN.tflite")

# index und scores zaehler initialisieren
iterationen = 0
scoreTask = 0
scoreUnknowTask = 0
scoreModus = 0
scoreUnknowModus = 0
scoreWrongModus = 0
hypothesis = []
ground_truth = []
confidence = []
allLabels = []



# ignore _DS_store in data direcotry
if ignore1 in datadir:
    datadir.remove(ignore1)

wavdir=[]
# data zu strings hinzufuegen ==> Data/name
for i, s in enumerate(datadir):
    s = dataname + "/" + s
    wavdir.append(s)

start = time.time()

for i in enumerate(wavdir):
    files = os.listdir(i[1]) # files in wavdir i = (index , directory)
    jsonfile = datadir[i[0]] + '.json'

    # ignore ds store
    if ignore1 in files:
        files.remove(ignore1)

    # ignore jsonfile
    if jsonfile in files:
        files.remove(jsonfile)

    print(i[0])
    labels = nlp.loadJsons(i[1] + "/" + jsonfile) # jsonfiles sind geladen

    if len(labels)==len(files):

        ## ab hier wird getestet!!
        for k in range(len(files)):

            # len(wavdir) == len(dataname)
            filename = i[1] + "/" + datadir[i[0]] + str(k) + ".wav"
            task = labels[k]["class"]
            sentence = labels[k]["sentence"]
            print(k)
            asr.speechtotext(stream=asr.getBuffer(w=wave.open(filename, 'r')))
            allLabels.append(task)
            if not asr.transcript:
                asr.transcript = "none"
                print(asr.transcript)

            #asr.speechtotextIBM("wavfiles/" + filename)
            print(time.time() - start)
            classified = nlp.classifierTask(asr.transcript)
            #modus = nlp.classifierModus(asr.transcript)

            confidence.append(classified)

            # Speichern der Hypothesen und Groudn truthWER von transcript berechnen
            hypothesis.append(asr.transcript)
            ground_truth.append(sentence)

            # score berechnen mit np. argmax und klasse, dann prozentualen anteil bestimmen von der klassifizierten handlun
            # konfidenz auswerten mittlere konfidenz bei richtigem erkennen
            if np.argmax(classified)==task:
                scoreTask = scoreTask+1

            # unknow ist prinzipiell nicht falsch
            elif nlp.class_names[np.argmax(classified)] == "unknown":
                scoreUnknowTask = scoreUnknowTask + 1

            # wie stand es um die wer und konfidenz?
            else:
                print(sentence)
                print(asr.transcript)

            
            '''
            iterationen = iterationen + 1
            # score berechnen mit np. argmax und klasse, dann prozentualen anteil bestimmen des klassifizierten modi
            # -1 bei labels beachten ==> fallen raus
            if np.argmax(modus)==listofmodus[i]:# and np.argmax(modus)>=0.65:
                scoreModus = scoreModus+1
            elif listofmodus[i] == -1:
                scoreUnknowModus = scoreUnknowModus + 1
            else:
                scoreWrongModus = scoreWrongModus + 1
                # oder zu niedrige konfidenz
            '''
scores = []
scores.append({"task":scoreTask, "unknow":scoreUnknowTask, "iterationen":iterationen})

# hypotheses und ground truth absoeicher fuer wer und mer
nlp.saveJsons("ground_truth.json", ground_truth)
nlp.saveJsons("hypothesis.json", hypothesis)
savetxt('confidence.csv', confidence, delimiter=',')
nlp.saveJsons("scores.json", scores)
nlp.saveJsons("labelsTask.json", allLabels)
