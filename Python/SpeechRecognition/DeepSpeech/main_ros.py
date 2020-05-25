import os
from os.path import join
import deepspeech
import wave
import numpy as np
import pyaudio
from pydub import AudioSegment
import speech_recognition as sr
from watson_developer_cloud import SpeechToTextV1
import json


# import rospy
# from std_msgs.msg import String


def initRecognizer():
    # recognizer for ibm cloud
    recognizer = sr.Recognizer()
    speech_to_text = SpeechToTextV1(
        iam_apikey="wsDeuwes_FSm3bo_QiLLQl1Er81u1sqIQxMNZFB67aVq",
        url="https://api.eu-gb.speech-to-text.watson.cloud.ibm.com/instances/472d7157-6ba9-4041-b3f3-8b014ebd62cf")
    return recognizer


def initModel(VERSION):
    # load and initialzie model for python3
    if VERSION == 'PYTHON3':
        model_file_path = 'deepspeech-0.7.1-models.pbmm'
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
                type(data16)
                print(type(data16))
                text = self.model.stt(data16)
                print(text)
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

    '''
    def processing_qhd(self, msg):
        try:
            self.imagebgrqhd = self.bridge.imgmsg_to_cv2(msg, "bgr8")
            self.framebgrsmall = imutils.resize(self.imagebgrqhd, width=min(400, self.imagebgrqhd.shape[1]))
        except CvBridgeError as e:
            print(e)


    def startnode(self):
        rospy.init_node('listener', anonymous=True)
        rospy.Subscriber("/" + self.namespaceofcamera + "/qhd/image_color", Image, self.processing_qhd)
        try:
            rospy.spin()

        except KeyboardInterrupt:
            print("Shutting down")
        cv2.destroyAllWindows()
    '''

    # Recognition from stream

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
    s = SpeechRecognition(newRecord=False, filename='berg.wav', pyVersion='PYTHON2')
    s.speechRecognitionDNN(s.record, s.filename)
    s.speechRecognitionIBM(s.filename)
