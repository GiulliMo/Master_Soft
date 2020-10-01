from libraries.nlp import *
import tensorflow as tf
import numpy as np
from jiwer import wer, mer
from numpy import savetxt
globals()
nlp = nlp(rnn=False, embedded=False)

## Daten I sind test daten und wurden vom netzwerk noch nicht gesehen
## Daten Laden
ground_truth = nlp.loadJsons("ground_truthDeepspeech_DataI.json")
hypothesis = nlp.loadJsons("hypothesisDeepspeech_DataI.json")
labelsTask = nlp.loadJsons("labelsTaskDeepspeech_DataI.json")
processingtime = nlp.loadJsons("processingtimeDeepspeech_DataI.json")
confidence = []
#scores = [score[0]["task"], score[0]["unknow"], score[0]["iterationen"]]
ground_truth = np.asarray(ground_truth)
hypothesis = np.asarray(hypothesis)
nlp.words = nlp.readWords("../models/words_embedding.txt")
print(len(nlp.words))
nlp.vocab_size = len(nlp.words)
nlp.modelTaskClassifier = tf.lite.Interpreter("../models/taskClassifierPhon.tflite"
                                              "") # Flags setzen!!
nlp.modelTaskClassifier.allocate_tensors()
numclass1 = 0
numclass2 = 0
numclass3 = 0
numclass4 = 0
numclass5 = 0
numclass6 = 0

## ab hier wird getestet
for hypo in hypothesis:
    print(hypo)
    confidence.append(nlp.classifierTask(transcript=hypo)) # Flags setzen
print(len(np.asarray(confidence)))
cnf2 = np.asarray(confidence)

###Auswertung###

## Mittlere Konfidenz
mean_conf_r = 0 # richtige confidenz
mean_conf_w = 0 # mit wieviel % liegt er falsch?

i_r = 0 # anzahl richtige
i_w = 0 # anzahl falsche
wer_r = 0
wer_w = 0
wer_g = 0
k = 0
gt = []
ht = []
gt2 = []
ht2 = []

score_top = 0
for cnf in enumerate(confidence):
    probs = list(cnf2[cnf[0]])
    max1 = max(probs)
    print(probs)
    idx1 = np.argmax(probs)
    probs[idx1] = 0
    idx2= np.argmax(probs)

    print(idx1)
    print(idx2)
    classified = np.argmax(cnf[1])
    wer2 = 0
    if ground_truth[k] == " ":
        ground_truth[k] = "none"
    wer3 = wer(ground_truth[k], hypothesis[k])
    wer_g = wer_g + wer3
    print(labelsTask[cnf[0]])
    print(classified)
    if idx1 == labelsTask[cnf[0]] or idx2 == labelsTask[cnf[0]]:
        score_top = score_top +1

    if classified == labelsTask[cnf[0]]:
        mean_conf_r = mean_conf_r + max(cnf[1])
        i_r = i_r + 1
        wer2 = wer(ground_truth[k], hypothesis[k])
        wer_r = wer_r + wer2
        gt2.append(ground_truth[k])
        ht2.append(hypothesis[k])

    elif classified != labelsTask[cnf[0]]:
        mean_conf_w = mean_conf_w + max(cnf[1])
        i_w = i_w + 1
        gt.append(ground_truth[k])
        ht.append(hypothesis[k])
        wer2 = wer(ground_truth[k], hypothesis[k])
        wer_w = wer_w + wer2
        if classified == 0:
            numclass1 = numclass1 + 1
        elif classified == 1:
            numclass2 = numclass2 + 1
        elif classified == 2:
            numclass3 = numclass3 + 1
        elif classified == 3:
            numclass4 = numclass4 + 1
        elif classified == 4:
            numclass5 = numclass5 + 1
        elif classified == 5:
            numclass6 = numclass6 + 1

    k = k+1

numclass = np.asarray([numclass1, numclass2, numclass3, numclass4, numclass5, numclass6])
mean_conf_r = mean_conf_r/i_r
mean_conf_w = mean_conf_w/i_w
wer_rg = (wer_r + wer_w)/(i_r+i_w)
print(wer_rg)
wer_r = wer_r/i_r
wer_w = wer_w/i_w

print(score_top)
print("Anzahl richtige: " + str(i_r))
print("Anzahl falsche: " + str(i_w))
print("Accuracy: " + str(i_r/len(labelsTask)))
print("Top 2 Error: " + str(score_top/len(labelsTask)))
print("Mittlere Konfidenz bei den richtigen: " + str(mean_conf_r))
print("Mittlere Konfidenz bei den falschen: " + str(mean_conf_w))
print("Mittlere bei allen WER: " + str(wer_rg))
print("Mittlere WER bei richtigen " + str(wer_r))
print("Mittlere WER bei falschen " + str(wer_w))
print("Verteilung Falsche: " + str(numclass/i_w))
print("Transkriptionszeit: " + str(np.mean(np.asarray(processingtime))))
print("wer test fuer falsch: " + str(wer(gt,ht)))
print("wer test fuer richtig: " + str(wer(gt2,ht2)))
print("wer test gesamt: " + str(wer_g/(2328+456)))
arr = list([wer_rg, wer_r,wer_w,i_r/len(labelsTask),mean_conf_r, mean_conf_w])
arr = arr + list(numclass/i_w)
arr.append(np.mean(np.asarray(processingtime)))
arr = np.asarray(arr)
print(arr)

name = 'data.csv'
if os.path.exists(name):
    os.remove(name)
np.savetxt(name, [arr], delimiter=',', fmt='%f')