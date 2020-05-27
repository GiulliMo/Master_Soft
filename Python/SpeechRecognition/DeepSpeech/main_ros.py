
import os
import deepspeech
import wave
import numpy as np
import speech_recognition as sr
from watson_developer_cloud import SpeechToTextV1
import json
import rospy
from std_msgs.msg import String, Int16MultiArray
import time
import threading


def initModel(VERSION):
    # load and initialzie model for python3
    if VERSION == 'PYTHON3':
        model_file_path = 'deepspeech-0.7.1-models.tflite'
        model = deepspeech.Model(model_file_path)
        model.enableExternalScorer('deepspeech-0.7.1-models.scorer')
        model.setScorerAlphaBeta(alpha=0.75, beta=1.1)  # alpha=0.931289039105002, beta=1.1834137581510284)
        print('load finished')

    elif VERSION == 'PYTHON2':
        # load and initialize model for python2
        DEEPSPEECH_MODEL_DIR = 'models'
        model_file_path = os.path.join(DEEPSPEECH_MODEL_DIR, 'output_graph.pbmm')
        BEAM_WIDTH = 500
        LM_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'lm.binary')
        TRIE_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'trie')
        LM_ALPHA = 0.75
        LM_BETA = 1.85
        model = deepspeech.Model(model_file_path, BEAM_WIDTH)
        model.enableDecoderWithLM(LM_FILE_PATH, TRIE_FILE_PATH, LM_ALPHA, LM_BETA)
        print('load finished')

    return model


class SpeechRecognition:
    def __init__(self, recsec,  pyVersion):
        self.record = True
        self.lock = threading.Lock()
        self.filename = ''
        self.Version = pyVersion
        self.speech = ''
        self.channels = 1
        self.rate = 16000
        self.chunksize = 2048
        self.recsec = recsec
        self.devIndex = 0  # 0=Boltune, 1= boltune, 2 = builtin
        self.model = initModel(self.Version)
        self.buffer = np.zeros(self.chunksize)
        self.frames = []
        self.cnt = 0
        self.start = 0
        self.lstMsg = np.zeros(self.chunksize)
    def speechRecognitionDNN(self, stream):
        # Recognition from record
        try:
            print("Start recognition")
            text = self.model.stt(stream)
            print(text)
            print("Speech recognition finished")
        except KeyboardInterrupt:
            print("Keyboard Interrupt")
        pass

    def callback(self, msg):
        self.buffer = np.asarray(msg.data)

    def processDataStream(self,data):
        self.lstMsg=np.asarray(data)
        try:
            if self.cnt==0:
                print("start recording...")
                self.frames=[]
                self.cnt = self.cnt +1
                self.start = time.time()
            if self.cnt<=int(self.rate / self.chunksize * self.recsec):
                self.frames.append(np.asarray(data))
                self.cnt = self.cnt + 1
                print(self.cnt)
            else:
                print("finished recording!")
                print(time.time()-self.start)
                data16 = np.frombuffer(np.asarray(self.frames), dtype=np.int16)
                self.speechRecognitionDNN(data16)
                self.cnt=0
        except KeyBoardInterrupt:
            print("Keyboard Interrupt")
        pass
    def listener(self):

        rospy.init_node('read_audio_stream', anonymous=True)
        rospy.Subscriber("audio_stream", Int16MultiArray, self.callback)
        # spin() simply keeps python from exiting until this node is stopped
        while not rospy.is_shutdown():
            try:
                checksum = sum(self.lstMsg-self.buffer)
                if not checksum==0:
                   #hier geht er nur hin wenn eine neue message da ist, checksumme ungleich 0
                   self.processDataStream(self.buffer)
            except KeyBoardInterrupt:
                print("Keyboard Interrupt")
            pass
if __name__ == '__main__':
    s = SpeechRecognition(recsec=10, pyVersion='PYTHON3')
    s.listener()
