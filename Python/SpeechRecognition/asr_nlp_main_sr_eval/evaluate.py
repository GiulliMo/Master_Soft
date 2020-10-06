##################################################
## Author: Hannes Dittmann
## Version: 1.0
## Email: hannes.dittmann@stud.hshl.de / hannes.dittmann@t-online.de
## Status: Fertig
## Kommentar: -Programm zum Erzeugen von Hypothesen mit ausgewählten ASR System
##            -Ordner Data muss angelegt werden mit Data/Name/Name1.wav
##            -Ordner Data/Name/ benötigt eine json Datei mit labels Data/Name/Name.json
##            -Json beinhaltet {"class": 5, "sentence": "none", "modus": 2},
##            - Je nach ASR kann es laufen, im venv "asr" laufen alle Stt Programme ==> siehe launch.sh
##################################################

from libraries.asr import *
from libraries.nlp import *
import os
from numpy import savetxt
import time
import multiprocessing as mp

## preprocessing bevor getestet werden kann

## libraries beinhalten code von alf


def listdir_nohidden(path):
    dir = []
    for item in os.listdir(path):
        if not item.startswith('.') and os.path.isfile(os.path.join(path, item)):
            print(item)
            dir.append(item)
    return dir

nlp = nlp(rnn=False, embedded=False)
dataname = "Data_IV"
datadir = listdir_nohidden(dataname)
ignore1 = '._.DS_Store'
ignore2 = '.DS_Store'
postfix = "Espnet3"

## asr objekt und modelle laden
asr = asr(language="gb")

#deepspeech initialisieren
model = asr.initModel()

# index und scores zaehler initialisieren
hypothesis = []
ground_truth = []
allLabels = []
processingtime = []

# ignore _DS_store in data direcotry
if ignore1 in datadir:
    datadir.remove(ignore1)

if ignore2 in datadir:
    datadir.remove(ignore2)

check = 0## addieren je nach checkpoint und postfix erweitern
datadir = datadir[check:len(datadir)]# hier wird je nach checkpoint abgeschnitten
print(datadir)
wavdir=[]
# data zu strings hinzufuegen ==> Data/name
for i, s in enumerate(datadir):
    s = dataname + "/" + s
    wavdir.append(s)

for i in enumerate(wavdir):
    files = os.listdir(i[1]) # files in wavdir i = (index , directory)
    jsonfile = datadir[i[0]] + '.json'
    ignore4='._'+jsonfile

    # ignore ds store
    if ignore1 in files:
        files.remove(ignore1)

    if ignore2 in files:
        files.remove(ignore2)

    # ignore jsonfile
    if jsonfile in files:
        files.remove(jsonfile)

    # ignore jsonfile._
    if ignore4 in files:
        files.remove(ignore4)

    print(i[0])
    check = i[0]
    nlp.saveJsons("check" + postfix + ".json", check)

    labels = nlp.loadJsons(i[1] + "/" + jsonfile) # jsonfiles sind geladen

    if len(labels)==len(files):

        ## ab hier wird getestet!!
        for k in range(len(files)):

            # len(wavdir) == len(dataname)
            filename = i[1] + "/" + datadir[i[0]] + str(k) + ".wav"
            task = labels[k]["class"]
            sentence = labels[k]["sentence"]
            start = time.time()
            # asr.speechtotext(stream=asr.getBuffer(w=wave.open(filename, 'r')))
            #asr.speechtotextPocketSphinx(stream=asr.getBuffer(w=wave.open(filename, 'r')))
            asr.speechtotextESPnet(filename)
            print(time.time() - start)
            processingtime.append(time.time() - start)
            # asr.speechtotextIBM("wavfiles/" + filename)
            allLabels.append(task)
           # print(asr.transcript)
            #print(sentence)
            #print("Satznummer: " + str(k))
            if not asr.transcript:
                asr.transcript = "none"
                print(asr.transcript)


            # Speichern der Hypothesen und Groudn truthWER von transcript berechnen
            hypothesis.append(asr.transcript)
            ground_truth.append(sentence)

    # loeschen wegen checkpoint existiert
    nlp.saveJsons("ground_truth" + postfix + ".json", ground_truth)
    nlp.saveJsons("hypothesis" + postfix + ".json", hypothesis)
    nlp.saveJsons("processingtime" + postfix + ".json", processingtime)
    nlp.saveJsons("labelsTask" + postfix + ".json", allLabels)

