import deepspeech
import os
import pyaudio
import speech_recognition as sr
from watson_developer_cloud.speech_to_text_v1 import SpeechToTextV1
from pocketsphinx.pocketsphinx import *
import soundfile
from espnet_model_zoo.downloader import ModelDownloader
from espnet2.bin.asr_inference import Speech2Text
import json
import wave
import numpy as np



# Klasse erzeugen Automatic Speech Recognition
class asr:

    def __init__(self, language):

        # Definieren von Objekteigenschaften der Klasse Speech Recognition
        self.language = language
        self.transcript = ""
        self.model = ""
        self.recognizer = sr
        self.audio = pyaudio.PyAudio()
        self.channels = 1
        self.Format = pyaudio.paInt16
        self.rate = 16000
        self.chunksize = 2048
        self.recsec = 5
        self.devIndex = 0  # 0=Boltune, 1= boltune, 2 = builtin Microphone

        # ibm
        self.speech_to_text = SpeechToTextV1(iam_apikey="wsDeuwes_FSm3bo_QiLLQl1Er81u1sqIQxMNZFB67aVq",
                                             url="https://api.eu-gb.speech-to-text.watson.cloud.ibm.com/instances/472d7157-6ba9-4041-b3f3-8b014ebd62cf")

        # pcoketsphinx
        # sudo nano pocketsphinx-python/deps/sphinxbase/src/libsphinxad/ad_openal.c
        ##include <OpenAL/al.h>
        #include <OpenAL/alc.h> muss da für installation stehen
        self.ModeldirPocketsphinx= 'models'
        config = Decoder.default_config()
        config.set_string('-hmm', os.path.join(self.ModeldirPocketsphinx, 'en-us'))
        config.set_string('-lm', os.path.join(self.ModeldirPocketsphinx , 'en-us.lm.bin'))
        config.set_string('-dict', os.path.join(self.ModeldirPocketsphinx, 'cmudict-en-us.dict'))
        self.decoder = Decoder(config)
        # espnet
        self.d = ModelDownloader()
        self.Espnet = Speech2Text(**self.d.download_and_unpack("models/asr_train_asr_transformer_e18_raw_bpe_sp_valid.acc.best.zip"))

    # Model für deepspeechje nach Sprache waehlen
    def initModel(self):

        # load and initialzie model - for deepspeech english, ds 0.7.4 hast to be installed
        if self.language == 'gb':
            model_file_path = 'models/deepspeech-0.7.1-models.pbmm'
            self.model = deepspeech.Model(model_file_path)
            self.model.enableExternalScorer('models/deepspeech-0.7.1-models.scorer')
            self.model.setScorerAlphaBeta(alpha=0.931289039105002,
                                     beta=1.1834137581510284)  # alpha=0.931289039105002, beta=1.1834137581510284)
            self.model.setBeamWidth(500)

        elif self.language == 'de':

            # load and initialize model for deepspeech-german, ds 0.6.1 hast to be installed
            DEEPSPEECH_MODEL_DIR = 'models'
            model_file_path = os.path.join(DEEPSPEECH_MODEL_DIR, 'output_graph.pb')
            BEAM_WIDTH = 500
            LM_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'lm.binary')
            TRIE_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'trie')
            LM_ALPHA = 1.0
            LM_BETA = 1.85
            self.model = deepspeech.Model(model_file_path, 500)
            self.model.enableDecoderWithLM(LM_FILE_PATH, TRIE_FILE_PATH, LM_ALPHA, LM_BETA)

    # Methode um IBM SpeechRecognition aufzurufen
    def initRecognizer(self):
        # recognizer for ibm cloud
        recognizer = sr.Recognizer()
        return recognizer

    # Methode um WAV Datei zu erzeugen
    def createWav(self, filename, frames):

        #loeschen wenn WAV existiert
        if os.path.exists(filename):
            os.remove(filename)

        '''
        # start Recording
        stream = self.audio.open(format=self.Format, rate=self.rate, channels=self.channels,
                                 input_device_index=self.devIndex, input=True,
                                 frames_per_buffer=self.chunksize)
        print("recording...")
        frames = []

        for i in range(0, int(self.rate / self.chunksize * self.recsec)):
            frames.append(stream.read(self.chunksize)) # Frames werden angehangen je nachdem wie gross recsec ist

        print("finished recording!")

        stream.stop_stream()
        stream.close()
        #self.audio.terminate()
        '''

        waveFile = wave.open(filename, 'wb')
        waveFile.setnchannels(self.channels)
        waveFile.setsampwidth(self.audio.get_sample_size(self.Format))
        waveFile.setframerate(self.rate)
        waveFile.writeframes(b''.join(frames)) #self.frames kommen direkt aus der aufnahme
        waveFile.close()

    def getBuffer(self, w):

        # w = wave.open(filename, 'r')
        frames = w.getnframes()
        buffer = w.readframes(frames)
        type(buffer)
        return (buffer)

    def speechtotextIBM(self, filename):

        with self.recognizer.WavFile(filename) as source:  # use "test.wav" as the audio source
            r = self.initRecognizer()
            audio_file = r.record(source)
        # ibm
        speech_recognition_results = self.speech_to_text.recognize(audio=audio_file.get_wav_data(),
                                                                   content_type='audio/wav').get_result()

        self.transcript = speech_recognition_results["results"][0]["alternatives"][0]["transcript"]
        #print(json.dumps(speech_recognition_results, indent=2))
        print(self.transcript)

        #self.transcript muss noch erzeugt werden

    # Anwenden von Pocketsphinx
    def speechtotextPocketSphinx(self, stream):
        # speechtotext with pocketsphinx
        # Recognition from datastream / audiostream
        try:
            self.decoder.start_utt()
            # Typumwandlung
            data16 = np.frombuffer(stream, dtype=np.int16)
            type(data16)
            self.decoder.process_raw(data16, False, False)
            self.decoder.end_utt()
            words = []
            hypothesis = self.decoder.hyp()
            [words.append(seg.word) for seg in self.decoder.seg()]

            if not words:
                self.transcript = "none"
            # Transkription erzeugen
            else:
                self.transcript = hypothesis.hypstr

            # leeres Transkript durch none ersetzen
            if not self.transcript:
                self.transcript = "none"

        except KeyboardInterrupt:
            print("Keyboard Interrupt")
        pass


    # Anwenden von ESPnet
    def speechtotextESPnet(self, wavfile):
        # speechtotext with ESPnet from wavfile
        # Recognition from datastream / audiostream
        try:
            speech, rate = soundfile.read(wavfile)
            nbests = self.Espnet(speech)
            # Transkription erzeugen
            text, *_ = nbests[0]
            self.transcript = text.lower()

            # leeres Transkript durch none ersetzen
            if not self.transcript:
                self.transcript = "none"

        except KeyboardInterrupt:
            print("Keyboard Interrupt")
        pass

    # Anwenden von Deepspeech
    def speechtotext(self, stream):
        # speechtotext with deepspeech
        # Recognition from datastream / audiostream
        try:
            # Typumwandlung
            data16 = np.frombuffer(stream, dtype=np.int16)
            type(data16)

            #Transkription erzeugen
            self.transcript = self.model.stt(data16)

            #leeres Transkript durch none ersetzen
            if not self.transcript:
                self.transcript = "none"

        except KeyboardInterrupt:
            print("Keyboard Interrupt")
        pass
