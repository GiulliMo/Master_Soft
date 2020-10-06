from libraries.nlp import *
import os

dir = 'Auswertung'
nlp = nlp(rnn=False, embedded=False)

## DeepSpeech mergen II entspricht der ergaenzung
ds_gt = nlp.loadJsons('Auswertung/ground_truthDeepSpeech.json')
ds_II_gt = nlp.loadJsons('Auswertung/ground_truthDeepSpeech21.json')
ds_ht = nlp.loadJsons('Auswertung/hypothesisDeepSpeech.json')
ds_II_ht = nlp.loadJsons('Auswertung/hypothesisDeepSpeech21.json')
ds_pt = nlp.loadJsons('Auswertung/processingtimeDeepSpeech.json')
ds_II_pt = nlp.loadJsons('Auswertung/processingtimeDeepSpeech21.json')
ds_labels = nlp.loadJsons('Auswertung/labelsTaskDeepSpeech.json')
ds_II_labels = nlp.loadJsons('Auswertung/labelsTaskDeepSpeech21.json')

ground_truthDeepSpeech = ds_gt + ds_II_gt
hypothesisDeepSpeech = ds_ht + ds_II_ht
labelsTaskDeepspeech = ds_labels + ds_II_labels
processingtimeDeepSpeech = ds_pt + ds_II_pt

nlp.saveJsons("ground_truthDeepSpeech_DataII.json", ground_truthDeepSpeech)
nlp.saveJsons("hypothesisDeepSpeech_DataII.json", hypothesisDeepSpeech)
nlp.saveJsons("labelsTaskDeepSpeech_DataII.json", labelsTaskDeepspeech)
nlp.saveJsons("processingtimeDeepSpeech_DataII.json", processingtimeDeepSpeech)


##espnet mergen
espnet_gt = nlp.loadJsons('Auswertung/ground_truthEspnet3.json')
espnet_II_gt = nlp.loadJsons('Auswertung/ground_truthEspnet21.json')
espnet_ht = nlp.loadJsons('Auswertung/hypothesisEspnet3.json')
espnet_II_ht = nlp.loadJsons('Auswertung/hypothesisEspnet21.json')
espnet_pt = nlp.loadJsons('Auswertung/processingtimeEspnet3.json')
espnet_II_pt = nlp.loadJsons('Auswertung/processingtimeEspnet21.json')
espnet_labels = nlp.loadJsons('Auswertung/labelsTaskEspnet3.json')
espnet_II_labels = nlp.loadJsons('Auswertung/labelsTaskEspnet21.json')


ground_truthEspnet = espnet_gt + espnet_II_gt
hypothesisEspnet= espnet_ht + espnet_II_ht
labelsTaskEspnet = espnet_labels + espnet_II_labels
processingtimeEspnet = espnet_pt + espnet_II_pt

nlp.saveJsons("ground_truthEspnet_DataII.json", ground_truthEspnet)
nlp.saveJsons("hypothesisEspnet_DataII.json", hypothesisEspnet)
nlp.saveJsons("labelsTaskEspnet_DataII.json", labelsTaskEspnet)
nlp.saveJsons("processingtimeEspnet_DataII.json", processingtimeEspnet)