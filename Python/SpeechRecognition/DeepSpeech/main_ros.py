

import os
import deepspeech
import wave
import numpy as np
import json
import rospy
from std_msgs.msg import String, Int16MultiArray
import time
import threading
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("-r", "--RECSEC", help="Laenge der Aufnahme",
                    type=int)
parser.add_argument("-lm", "--LANGUAGE", help="Sprachmodell, de oder gb")
args = parser.parse_args()

def initModel(VERSION):
    # load and initialzie model for deepspeechenglish, ds 0.7.1 hast to be installed
    if VERSION == 'gb':
        model_file_path = 'deepspeech-0.7.1-models.tflite'
        model = deepspeech.Model(model_file_path)
        model.enableExternalScorer('deepspeech-0.7.1-models.scorer')
        model.setScorerAlphaBeta(alpha=0.75, beta=1.1)  # alpha=0.931289039105002, beta=1.1834137581510284)
        print('load finished')

    elif VERSION == 'de':
        # load and initialize model for deepspeech-german, ds 0.6.1 hast to be installed
        DEEPSPEECH_MODEL_DIR = 'models-de'
        model_file_path = os.path.join(DEEPSPEECH_MODEL_DIR, 'output_graph.tflite')
        BEAM_WIDTH = 500
        LM_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'lm.binary')
        TRIE_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'trie')
        LM_ALPHA = 0.4
        LM_BETA = 1.85
        model = deepspeech.Model(model_file_path)
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
        self.text=''
    def speechRecognitionDNN(self, stream):
        # Recognition from record
        try:
            print("Start recognition")
            self.text = self.model.stt(stream)
            self.talker(len(self.text), self.text)
            print(self.text)
            print("Speech recognition finished")
        except KeyboardInterrupt:
            print("Keyboard Interrupt")
        pass

    def callback(self, msg):
        self.buffer = np.int16(np.asarray(msg.data))
    def processDataStream(self,data):
        self.lstMsg=np.int16(np.asarray(data))
        try:
            if self.cnt==0:
                print("start recording...")
                self.frames=[]
                self.cnt = self.cnt +1
                self.start = time.time()
            if self.cnt<=int(self.rate / self.chunksize * self.recsec):
                self.frames.append(np.asarray(data))
                self.cnt = self.cnt + 1
            else:
                print("finished recording!")
                print(time.time()-self.start)
                data16 = np.frombuffer(np.asarray(self.frames), dtype=np.int16)
                print(len(data16))
                self.speechRecognitionDNN(data16)
                self.cnt=0
        except KeyBoardInterrupt:
            print("Keyboard Interrupt")
        pass
    def listener(self):

        rospy.init_node('SpeechRecognition', anonymous=True)
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

    def talker(self, size, text):
        pub = rospy.Publisher('recognized_text', String, queue_size=size)
        rospy.loginfo(text)
        pub.publish(text)



if __name__ == '__main__':
    s = SpeechRecognition(args.RECSEC, args.LANGUAGE)
    s.listener()

