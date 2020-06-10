import os
from os.path import join

import deepspeech
import wave
import numpy as np
import pyaudio
import speech_recognition as sr
from watson_developer_cloud import SpeechToTextV1
import json
import phonetics

# import rospy
# from std_msgs.msg import String


def initRecognizer():
    #recognizer for ibm cloud
    recognizer = sr.Recognizer()
    speech_to_text = SpeechToTextV1(
        iam_apikey="wsDeuwes_FSm3bo_QiLLQl1Er81u1sqIQxMNZFB67aVq",
        url="https://api.eu-gb.speech-to-text.watson.cloud.ibm.com/instances/472d7157-6ba9-4041-b3f3-8b014ebd62cf")
    return recognizer


def initModel(VERSION):
    # load and initialzie model for python3 #deepspeech 0.6.1
    if VERSION == 'PYTHON3':
        model_file_path = 'models/deepspeech-0.7.1-models.pbmm'
        model = deepspeech.Model(model_file_path)
        model.enableExternalScorer('models/deepspeech-0.7.1-models.scorer')
        model.setScorerAlphaBeta(alpha=1, beta=1.1)  # alpha=0.931289039105002, beta=1.1834137581510284)
        print('load finished')

    elif VERSION == 'PYTHON2':
        # load and initialize model for python2# pbmm deepspeech 0.6.1
        DEEPSPEECH_MODEL_DIR = 'models-De'
        model_file_path = os.path.join(DEEPSPEECH_MODEL_DIR, 'output_graph.pb')
        BEAM_WIDTH = 500
        LM_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'lm.binary')
        TRIE_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'trie')
        ALPHABET_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'alphabet.txt')
        LM_ALPHA = 0.6
        LM_BETA = 1.18
        model = deepspeech.Model(model_file_path, BEAM_WIDTH)
        model.enableDecoderWithLM(LM_FILE_PATH, TRIE_FILE_PATH, LM_ALPHA, LM_BETA)
        print('load finished')

    return model


class SpeechRecognition:
    def __init__(self, newRecord, filename, pyVersion):
        self.record = newRecord
        self.filename = filename
        self.Version = pyVersion
        self.speech = ''
        self.channels = 1
        self.Format = pyaudio.paInt16
        self.rate = 16000
        self.chunksize = 2048
        self.recsec = 10
        self.devIndex = 0  # 0=Boltune, 1= boltune, 2 = builtin
        self.audio = pyaudio.PyAudio()
        self.format = pyaudio.paInt16
        self.model = initModel(self.Version)
        self.recognizer = sr
        self.buffer = np.empty(0)
        self.transitions = "transition.json"
        self.buzzwordName = "buzzwords.json"
        self.buzzwords = []
        self.transcript = []
        self.speech_to_text = SpeechToTextV1(iam_apikey="wsDeuwes_FSm3bo_QiLLQl1Er81u1sqIQxMNZFB67aVq",
                                             url="https://api.eu-gb.speech-to-text.watson.cloud.ibm.com/instances/472d7157-6ba9-4041-b3f3-8b014ebd62cf")

    # create wav file
    def createWav(self, filename):
        if os.path.exists(filename):
            os.remove(filename)
        # start Recording
        stream = self.audio.open(format=self.Format, rate=self.rate, channels=self.channels,
                                 input_device_index=self.devIndex, input=True,
                                 frames_per_buffer=self.chunksize)
        print("recording...")
        frames = []

        for i in range(0, int(self.rate / self.chunksize * self.recsec)):
            data = stream.read(self.chunksize)
            frames.append(data)

        print("finished recording!")

        stream.stop_stream()
        stream.close()
        self.audio.terminate()

        waveFile = wave.open(filename, 'wb')
        waveFile.setnchannels(self.channels)
        waveFile.setsampwidth(self.audio.get_sample_size(self.Format))
        waveFile.setframerate(self.rate)
        waveFile.writeframes(b''.join(frames))
        waveFile.close()

    # read data from wav file
    def getBuffer(self, w):
        frames = w.getnframes()
        buffer = w.readframes(frames)
        type(buffer)
        return (buffer)

    def speechRecognitionDNN(self, record, filename):
        # Recognition from record
        if record:
            try:
                # record a wav file, bei ROS nur buffer
                self.createWav(self.filename)
                # predict Audio deepspeech
                buffer = self.getBuffer(wave.open(filename, 'r'))
                data16 = np.frombuffer(buffer, dtype=np.int16)
                type(data16)
                text = self.model.stt(data16)
                print(text)
                print("Speech recognition finished")
            except KeyboardInterrupt:
                print("Keyboard Interrupt")
            pass

        elif not record:
            try:
                buffer = self.getBuffer(wave.open(filename, 'r'))
                data16 = np.frombuffer(buffer, dtype=np.int16)
                text = self.model.stt(data16)
                stream = self.model.createStream()
                stream.feedAudioContent(data16)
                print(stream.finishStreamWithMetadata(num_results=2))
                #print(text)
                #print(self.model.sttWithMetadata(data16))
                print("Speech recognition finished")
            except KeyboardInterrupt:
                print("Keyboard Interrupt")
            pass

    def speechRecognitionIBM(self, filename):
        with self.recognizer.WavFile(filename) as source:  # use "test.wav" as the audio source
            r = initRecognizer()
            audio_file = r.record(source)

        speech_recognition_results = self.speech_to_text.recognize(audio=audio_file.get_wav_data(),
                                                                   content_type='audio/wav').get_result()
        print(json.dumps(speech_recognition_results, indent=2))

    def Rabin_Karp_Matcher(self, text, pattern, d, q):
        n = len(text)
        m = len(pattern)
        h = pow(d, m - 1) % q
        p = 0
        t = 0
        result = []
        for i in range(m):  # preprocessing
            p = (d * p + ord(pattern[i])) % q
            t = (d * t + ord(text[i])) % q
        for s in range(n - m + 1):  # note the +1
            if p == t:  # check character by character
                match = True
                for i in range(m):
                    if pattern[i] != text[s + i]:
                        match = False
                        break
                if match:
                    result = result + [s]
            if s < n - m:
                t = (t - h * ord(text[s])) % q  # remove letter s
                t = (t * d + ord(text[s + m])) % q  # add letter s+m
                t = (t + q) % q  # make sure that t >= 0
        return result #begin of string position

    def getAlfTransition(self, transcript): #schlagwoerter suchen und transition finden
        recognizedBuzzwords = []
        transitionCandidates = []
        firstrun = True
        sum = 0
        confidence = np.empty(len(self.transitions))
        for i in range(len(self.buzzwords)):
          if self.Rabin_Karp_Matcher(self.transcript, self.buzzwords[i]['buzzword'][0]['name'], 257, 11): #is there a buzzword?
              recognizedBuzzwords.append(self.buzzwords[i]['buzzword'][0]['id'])#Buzzword to list

        print(recognizedBuzzwords)
        ## suchen nach tranistionen mit buzzwords
        for j in range(len(self.transitions)):
            score = 0
            for k in range(len(recognizedBuzzwords)):
                if self.Rabin_Karp_Matcher(self.transitions[j]['transition'][0]['signature'], recognizedBuzzwords[k], 257, 11):
                    score = score + 1  # anzahl matches
                    if firstrun:
                        transitionCandidates.append([{'score': score, 'name': self.transitions[j]['transition'][0]['name']}])
                        firstrun = False
                    elif not firstrun:
                        transitionCandidates.append([{'score': score, 'name': self.transitions[j]['transition'][0]['name']}]) #Kandidaten anhängen
                        if transitionCandidates[len(transitionCandidates)-1][0]['name']==transitionCandidates[len(transitionCandidates)-2][0]['name']:
                            transitionCandidates.remove(transitionCandidates[len(transitionCandidates)-2]) # gleichamigen Kandidaten loeschen

        confidence = np.empty(len(transitionCandidates))
        for n in range(len(transitionCandidates)):
            sum = sum + transitionCandidates[n][0]['score']
            confidence[n] = transitionCandidates[n][0]['score']

        print(max(confidence*(1/sum)))
        print(transitionCandidates[np.argmax(confidence*(1/sum))][0]['name'])

    def loadJsons(self):
        f = open(self.buzzwordName, "r")
        f2 = open(self.transitions, "r")
        self.buzzwords = json.loads(f.read())
        self.transitions = json.loads(f2.read())
        f.close()
        f2.close()
    '''
    # Audio Params
    audio = pyaudio.PyAudio()
    format = pyaudio.paInt16
    channels = 1
    rate = 16000
    chunksize = 2048
    recsec = 10
    devIndex = 0  # 0=Boltune, 1= boltune, 2 = builtin
    
    context = model.createStream()
    text_so_far = ''
    
    
    def process_audio(in_data, frame_count, time_info, status):
         global text_so_far
         data16 = np.frombuffer(in_data, dtype=np.int16)
         context.feedAudioContent(data16)
         text = context.intermediateDecode()
         if text != text_so_far:
             print('Interim text = {}'.format(text))
             text_so_far = text
         return (in_data, pyaudio.paContinue)
    
    
    stream = audio.open(format=format, channels=channels, rate=rate, input=True, input_device_index=devIndex,
                         frames_per_buffer=chunksize, stream_callback=process_audio)
    
    print('Please start speaking, when done press Ctrl-C ...')
    stream.start_stream()
    
    try:
         while stream.is_active():
             time.sleep(0.1)
    
    except KeyboardInterrupt:
         # PyAudio
         # stream.stop_stream()
         stream.close()
         audio.terminate()
         print('Finished recording.')
         # DeepSpeech
         text = model.finishStream(context)
         print('Final text = {}'.format(text))
    pass
    '''


if __name__ == '__main__':
    s = SpeechRecognition(newRecord=False, filename='berg.wav', pyVersion='PYTHON3')
    s.loadJsons()
    s.transcript = "drive to location Bergmann"
    s.getAlfTransition(s.transcript)
    #s.speechRecognitionDNN(s.record, s.filename)
    # s.speechRecognitionIBM(s.filename)

