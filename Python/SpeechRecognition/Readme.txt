1. asr_nlp_main_sr beinhaltet den aktuellen Stand und eine lauffähige Version auf dem ALF
	- launch.sh muss mit ./launch.sh im Terminal des ALF ausgeführt werden
	- deepasr.py ist ein Testprogramm für Asr Systeme - läuft prinzipiell überall
	- evaluate.py Programm zum Testen von ASR Systemen - läuft prinzipiell überall
	- main_sr.py, hier passiert die "Magie" - läuft nur auf dem ALF!
	- mergeJson.py	bei der Evaluation musste unterbrochen werden, hier werden die 		 verschiedenen José Dateien zu einer Liste zusammengeführt
1. asr_nlp_main_sr_eval
	- eigentlich wie oben nur "aufgeräumt" 

2. DeepSpeech beinhaltet Programm zum trainieren von Netzwerken
	- audioStream_ros.py ist legacy, der genutzte Audio stream liegt in (1)
	- audioStream.py
	- tflite Modelle sollten da nicht rein
	- Hier wurden einige Klassifikationen ausprobiert (Bayes, HMM, NN und KNN)
	- classification_NeuronalNetwork.py hier wird mit BOW und OHE trainiert
	- word_Embedding hier werden KNN mit Word Embedding und RNN trainiert
	- classification_Neronalnetwork_predict ausprobieren der trainierten Tflite 		Modelle
	-classification-AutonomManual.py Netzwerk zur Klassifikation zwischen Autonom/		Manuell (trainignsdaten werden im Programm erzeugt

3. SpeechRecognition beinhaltet IBM stt (legacy)

4. Verifikation beinhaltet das Programm für Probanden in Windows und Unix Version. Die Auswertung darin stammen vom ALF und gehören zu anderen Daten








