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

5. piplist
absl-py                                 0.9.0
aiofiles                                0.4.0
altgraph                                0.17
appdirs                                 1.4.4
ase                                     3.19.2
asr                                     19.11.19
astor                                   0.8.1
astunparse                              1.6.3
atomicwrites                            1.2.1
attrdict                                2.0.1
attrs                                   19.3.0
audioread                               2.1.8
autobahn                                20.4.3
Automat                                 20.2.0
automatic-speech-recognition            1.0.4
azure-cognitiveservices-speech          1.13.0
beautifulsoup4                          4.9.1
bleach                                  3.0.2
boto                                    2.49.0
boto3                                   1.9.28
botocore                                1.12.28
Bottleneck                              1.3.2
bz2file                                 0.98
cachetools                              4.1.1
certifi                                 2020.6.20
cffi                                    1.11.5
chardet                                 3.0.4
click                                   7.1.2
cloudpickle                             1.4.1
cmarkgfm                                0.4.2
ConfigArgParse                          1.2.3
constantly                              15.1.0
cryptography                            2.9.2
ctc-segmentation                        1.0.6
cycler                                  0.10.0
Cython                                  0.29.21
dataclasses                             0.6
decorator                               4.3.0
deepasr                                 0.1.1
deepspeech                              0.7.1
Distance                                0.1.3
docutils                                0.14
editdistance                            0.5.2
env                                     0.1.0
espnet                                  0.9.3
espnet-model-zoo                        0.0.0a16
espnet-tts-frontend                     0.0.3
fastdtw                                 0.3.4
ffmpeg                                  1.4
ffmpeg-python                           0.2.0
filelock                                3.0.12
flatbuffers                             1.12
flatdict                                3.0.1
future                                  0.16.0
Fuzzy                                   1.2.2
g2p-en                                  2.1.0
gast                                    0.3.3
gdown                                   3.12.2
gensim                                  3.8.3
google-api-core                         1.22.2
google-auth                             1.19.0
google-auth-oauthlib                    0.4.1
google-cloud-core                       1.4.1
google-cloud-storage                    1.31.0
google-crc32c                           1.0.0
google-pasta                            0.2.0
google-resumable-media                  1.0.0
googleapis-common-protos                1.52.0
grpcio                                  1.30.0
gTTS                                    2.1.1
gTTS-token                              1.1.3
gunicorn                                19.9.0
h5py                                    2.9.0
hmm                                     0.0.1
hmmlearn                                0.2.3.post13+ge872126
httptools                               0.0.11
humanfriendly                           8.2
hyperlink                               19.0.0
idna                                    2.10
ijson                                   2.3
importlib-metadata                      1.7.0
incremental                             17.5.0
inflect                                 4.1.0
jaconv                                  0.2.4
jiwer                                   2.1.0
jmespath                                0.9.3
joblib                                  0.16.0
jsonpath-rw                             1.4.0
jsonschema                              3.2.0
kaldiio                                 2.15.1
Keras-Applications                      1.0.8
Keras-Preprocessing                     1.1.2
kiwisolver                              1.2.0
librosa                                 0.8.0
llvmlite                                0.34.0
lru-dict                                1.1.6
macholib                                1.14
Markdown                                3.2.2
matplotlib                              3.1.0
mir-eval                                0.6
mlxtend                                 0.17.3
mock                                    4.0.2
more-itertools                          4.3.0
Morfessor                               2.0.6
multidict                               4.4.2
musdb                                   0.3.1
museval                                 0.3.0
namedtupled                             0.3.3
nara-wpe                                0.0.7
ndex2                                   2.0.0.1
neo4j-driver                            1.6.2
neotime                                 1.0.0
networkx                                2.2
ninja                                   1.10.0.post2
nltk                                    3.5
nnmnkwii                                0.0.21
node2vec                                0.2.2
numba                                   0.51.0
numexpr                                 2.7.1
numpy                                   1.19.0
oauthlib                                3.1.0
opt-einsum                              3.2.1
packaging                               20.4
pandas                                  0.25.3
phonetics                               1.0.5
Pillow                                  7.2.0
pip                                     20.2.3
pkginfo                                 1.4.2
plotly                                  4.9.0
pluggy                                  0.7.1
ply                                     3.11
pocketsphinx                            0.1.15
pooch                                   1.1.1
progressbar2                            3.47.0
protobuf                                3.12.2
psutil                                  5.7.0
pvporcupine                             1.8.1
py                                      1.7.0
pyaml                                   20.4.0
pyasn1                                  0.4.8
pyasn1-modules                          0.2.8
PyAudio                                 0.2.11
pycparser                               2.19
pydub                                   0.24.0
pygame                                  1.9.6
Pygments                                2.2.0
PyHamcrest                              2.0.2
PyInstaller                             3.6
pyparsing                               2.2.2
pypinyin                                0.39.0
pyrsistent                              0.17.3
pysolr                                  3.8.1
PySoundFile                             0.9.0.post1
pysptk                                  0.1.18
pystoi                                  0.3.3
pytest                                  3.8.2
python-dateutil                         2.7.3
python-Levenshtein                      0.12.0
python-speech-features                  0.6
python-utils                            2.3.0
pytorch-wpe                             0.0.0
pyttsx3                                 2.90
pytz                                    2018.5
pyworld                                 0.2.11.post0
PyYAML                                  5.3.1
readme-renderer                         22.0
redis                                   2.10.6
regex                                   2020.6.8
requests                                2.24.0
requests-oauthlib                       1.3.0
requests-toolbelt                       0.8.0
resampy                                 0.2.2
retrying                                1.3.3
rnn                                     0.0.0
ros                                     0.119
roslibpy                                1.0.0
rsa                                     4.6
s3transfer                              0.1.13
sanic                                   0.8.3
sanic-openapi                           0.4.0
scikit-learn                            0.23.1
scipy                                   1.4.1
sent2vec-prebuilt                       0.0.2
sentencepiece                           0.1.86
setuptools                              50.3.0
SimpleHMM                               1.0.0
SimpleHMMER                             0.2.3
simplejson                              3.17.2
six                                     1.15.0
sklearn                                 0.0
smart-open                              2.1.0
sounddevice                             0.3.15
SoundFile                               0.10.3.post1
soupsieve                               2.0.1
sox                                     1.3.7
SpeechRecognition                       3.8.1
speechT                                 1.0
spglib                                  1.15.1
stempeg                                 0.1.8
tables                                  3.6.1
tb-nightly                              2.3.0a20200531
tensorboard                             2.2.2
tensorboard-plugin-wit                  1.7.0
tensorboardX                            2.1
tensorflow                              2.2.0
tensorflow-estimator                    2.2.0
termcolor                               1.1.0
tf-estimator-nightly                    2.3.0.dev2020060101
tflite                                  2.2.0
tflite-runtime                          2.1.0.post1
threaded                                4.0.8
threadpoolctl                           2.1.0
toco                                    0.0.9
torch                                   1.6.0
torch-complex                           0.2.0
tornado                                 5.1.1
tqdm                                    4.26.0
twine                                   1.12.1
Twisted                                 20.3.0
txaio                                   20.4.1
typeguard                               2.9.1
ujson                                   1.35
Unidecode                               1.1.1
urllib3                                 1.25.9
uvloop                                  0.11.2
watson-developer-cloud                  2.10.1
webencodings                            0.5.1
websocket-client                        0.48.0
websockets                              5.0.1
Werkzeug                                1.0.1
wheel                                   0.35.1
wrapt                                   1.12.1
zipp                                    3.1.0
zope.interface                          5.1.0






