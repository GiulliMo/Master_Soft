from libraries.nlp import *
import tensorflow as tf
import numpy as np
from jiwer import wer, mer
globals()
nlp = nlp()

## Daten Laden
ground_truth = nlp.loadJsons("ground_truth.json")
hypothesis = nlp.loadJsons("hypothesis.json")
#confidence = loadtxt('confidence.csv', delimiter=',')
confidence = []
#score = nlp.loadJsons("scores.json")
labelsTask = nlp.loadJsons("labelsTask.json")
#scores = [score[0]["task"], score[0]["unknow"], score[0]["iterationen"]]
ground_truth = np.asarray(ground_truth)
hypothesis = np.asarray(hypothesis)
nlp.words = nlp.readWords("../models/words_embedding.txt")
print(len(nlp.words))
nlp.vocab_size = len(nlp.words)
nlp.modelTaskClassifier = tf.lite.Interpreter("../models/taskClassifierPhonWordEmbedding.tflite") # Flags setzen!!
nlp.modelTaskClassifier.allocate_tensors()
nlp.rnn=False
nlp.embeddinglayer=True

## ab hier wird getestet
for hypo in ground_truth:
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
k = 0

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

    print(labelsTask[cnf[0]])
    print(classified)
    if idx1 == labelsTask[cnf[0]] or idx2 == labelsTask[cnf[0]]:
        score_top = score_top +1

    if classified == labelsTask[cnf[0]]:
        mean_conf_r = mean_conf_r + max(cnf[1])
        i_r = i_r + 1
        wer2 = wer(ground_truth[k], hypothesis[k])
        wer_r = wer_r + wer2

   # elif classified == 5:
        #i_r = i_r +1
      #  wer2 = wer(ground_truth[k], hypothesis[k])
       # wer_r = wer_r+ wer2

    elif classified != labelsTask[cnf[0]]:
        mean_conf_w = mean_conf_w + max(cnf[1])
        i_w = i_w +1
        wer2 = wer(ground_truth[k], hypothesis[k])
        wer_w = wer_w + wer2

    k = k+1
mean_conf_r = mean_conf_r/i_r
mean_conf_w = mean_conf_w/i_w
wer_r = wer_r/i_r
wer_w = wer_w/i_w
## thresholds herleiten durch mittlere konfidenz der klassen

print(score_top)
print("Anzahl richtige: " + str(i_r))
print("Anzahl falsche: " + str(i_w))
print("Accuracy: " + str(i_r/len(labelsTask)))
print("Top 2 Error: " + str(score_top/len(labelsTask)))
print("Mittlere Konfidenz bei den richtigen: " + str(mean_conf_r))
print("Mittlere Konfidenz bei den falschen: " + str(mean_conf_w))
print("Mittlere WER bei richtigen " + str(wer_r))
print("Mittlere WER bei falschen " + str(wer_w))
