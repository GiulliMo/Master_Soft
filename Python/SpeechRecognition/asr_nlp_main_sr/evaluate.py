from libraries.asr import *
from libraries.nlp import *
import os
import tensorflow as tf
from jiwer import wer, mer

## preprocessing bevor getestet werden kann
## Ordner Data muss angelegt werden mit Data/Name/....
## libraries beinhalten code von alf
## wav dateien aus data werden alle(!) in wavfiles gelegt ==> len(wavefiles) == len(mergedlist)

nlp = nlp()
dataname = "Data_II"
wavfilename = "wavfiles"

datadir = os.listdir(dataname)
wavdir = os.listdir(wavfilename)
ignore1 = '.DS_Store'
ignore2 = '.json'

# ignore _DS_store in data direcotry
if ignore1 in datadir:
    datadir.remove(ignore1)

if ignore1 in wavdir:
    wavdir.remove(ignore1)

# data zu strings hinzufuegen ==> Data/name
for i, s in enumerate(datadir):
    s = dataname + "/" + s
    datadir[i] = s

datalabels = []

for d in datadir:
    files = os.listdir(d)

    if ignore1 in files:
        files.remove(ignore1)

    # json in data/name finden und isoliert speichern
    for s in files:
        if ".json" in s:
            datalabels.append(s)

mergedlist = []
listofclass = []
listofmodus = []
for i in range (len(datadir)):
    string = "".join(datadir[i])
    dir = string + "/" + datalabels[i]
    list = nlp.loadJsons(dir)
    files = os.listdir(datadir[i])

    #ignore ds store
    if ignore1 in files:
        files.remove(ignore1)
        
    # ignore json
    for f in files:
        if ignore2 in f:
            files.remove(f)

    for k in range(len(list)):
        for f in files:
            add = str(k)
            # add = zahl aus k + namensstamm 
            if add in f:
                #liste der daten mit label und namen, wav namen sind noch nicht dabei
                list[k]["name"] = f

    # merged list = liste mit namen, klasse und modus, sowie original wortgruppe
    mergedlist = mergedlist + list

## labels fuer klassifizierung
for obj in mergedlist:
    listofclass.append(obj["class"])
    listofmodus.append(obj["modus"])

## jetzt hab ich eine Liste mit Namen in "list" fuer jedes datadir
nlp.saveJsons("mergedlabelsfull.json", mergedlist)
mergedlabels = nlp.loadJsons("mergedlabelsfull.json")


## wav Dateien liegen in extra Ordner Anzahl muss stimmen
## ab hier wird getestet!!

## asr objekt und modelle ladem
asr = asr(language="gb")

#deepspeech initialisieren
model = asr.initModel()

#klassifizierer initialisieren
nlp.words = nlp.readWords("models/words.txt")
nlp.wordsModus = nlp.readWords("models/words_modus.txt")
nlp.modelTaskClassifier = tf.lite.Interpreter("models/taskClassifierRNN.tflite")
nlp.modelModusClassifier = tf.lite.Interpreter("models/autonom_manualRNN.tflite")

# index und scores zaehler initialisieren
i = 0
scoreTask = 0
scoreUnknowTask = 0
scoreModus = 0
scoreUnknowModus = 0
scoreWrongModus = 0
hypothesis = []
ground_truth = []


for obj in mergedlabels:

    #obj["name"] ist das original
    filename = obj["name"]
    task = obj["class"]
    sentence = obj["sentence"]
    print(filename)
    if any(filename in s for s in wavdir):
        print("1")
        asr.speechtotext(stream=asr.getBuffer(w=wave.open(wavfilename + "/" + filename, 'r')))
        #asr.speechtotextIBM("wavfiles/" + filename)
        classified = nlp.classifierTask(asr.transcript)
        modus = nlp.classifierModus(asr.transcript)

        # Speichern der Hypothesen und Groudn truthWER von transcript berechnen
        hypothesis.append(asr.transcript)
        ground_truth.append(sentence)

        # score berechnen mit np. argmax und klasse, dann prozentualen anteil bestimmen von der klassifizierten handlun
        # konfidenz auswerten mittlere konfidenz bei richtigem erkennen
        if np.argmax(classified)==listofclass[i]:
            scoreTask = scoreTask+1

        # unknow ist prinzipiell nicht falsch
        elif nlp.class_names[np.argmax(classified)] == "unknown":
            scoreUnknowTask = scoreUnknowTask + 1

        # wie stand es um die wer und konfidenz?
        else:
            print(sentence)
            print(asr.transcript)
            print(listofclass[i])
            # wer bei fehlern sehr hoch?
            # wer von transcript mit einbeziehen

        # score berechnen mit np. argmax und klasse, dann prozentualen anteil bestimmen des klassifizierten modi
        # -1 bei labels beachten ==> fallen raus
        if np.argmax(modus)==listofmodus[i]:# and np.argmax(modus)>=0.65:
            scoreModus = scoreModus+1
        elif listofmodus[i] == -1:
            scoreUnknowModus = scoreUnknowModus + 1
        else:
            scoreWrongModus = scoreWrongModus + 1
            # oder zu niedrige konfidenz

    # index zaehlen
    i = i + 1

# hypotheses und ground truth absoeicher fuer wer und mer
nlp.saveJsons("ground_truth.json", ground_truth)
nlp.saveJsons("hypothesis.json", hypothesis)

# Quoten
print("Gesamtanzahl Daten: " + str(len(mergedlabels)))
print("Richtig klassifizierte Handlung: " + str(scoreTask))
print("Unbekannte Handlungen: " + str(scoreUnknowTask))
print("Richtig klassifizierte Modi: " + str(scoreModus))
print("Unbekannte/n.n. Modi: " + str(scoreUnknowModus))
# welche modi wurden falsch? bei schlechtem transkript?
print("Falsch klassifizierte Modi: " + str(scoreWrongModus))

# wer und mer
#print(wer(ground_truth,hypothesis))
#print(mer(ground_truth,hypothesis))
