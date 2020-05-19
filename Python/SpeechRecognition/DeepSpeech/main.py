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
import time

# load and initialzie model for python3

model_file_path = 'deepspeech-0.7.1-models.pbmm'
model = deepspeech.Model(model_file_path)
model.enableExternalScorer('deepspeech-0.7.1-models.scorer')
model.setScorerAlphaBeta(alpha=0.75, beta=1.1)#alpha=0.931289039105002, beta=1.1834137581510284)


# load and initialize model for python2
'''
DEEPSPEECH_MODEL_DIR = 'models'
model_file_path = os.path.join(DEEPSPEECH_MODEL_DIR, 'output_graph.pbmm')
BEAM_WIDTH = 500
LM_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'lm.binary')
TRIE_FILE_PATH = os.path.join(DEEPSPEECH_MODEL_DIR, 'trie')
LM_ALPHA = 0.75
LM_BETA = 1.85
model = deepspeech.Model(model_file_path, BEAM_WIDTH)
model.enableDecoderWithLM(LM_FILE_PATH, TRIE_FILE_PATH, LM_ALPHA, LM_BETA)
'''

# recognizer for ibm cloud
r = sr.Recognizer()
speech_to_text = SpeechToTextV1(
    iam_apikey="wsDeuwes_FSm3bo_QiLLQl1Er81u1sqIQxMNZFB67aVq",
    url="https://api.eu-gb.speech-to-text.watson.cloud.ibm.com/instances/472d7157-6ba9-4041-b3f3-8b014ebd62cf")

# create wav file
def createWav(audio, RATE, CHUNK, FORMAT, CHANNELS, RECORD_SECONDS, DEV_INDEX):
    if os.path.exists("streamStereo.wav"):
        os.remove("streamStereo.wav")
    # start Recording
    stream = audio.open(format=FORMAT, rate=RATE, channels=CHANNELS, input_device_index=DEV_INDEX, input=True,
                        frames_per_buffer=CHUNK)
    print("recording")
    frames = []

    for i in range(0, int(RATE / CHUNK * RECORD_SECONDS)):
        data = stream.read(CHUNK)
        frames.append(data)

    print("finished recording")

    stream.stop_stream()
    stream.close()
    audio.terminate()

    waveFile = wave.open('streamStereo.wav', 'wb')
    waveFile.setnchannels(CHANNELS)
    waveFile.setsampwidth(audio.get_sample_size(FORMAT))
    waveFile.setframerate(RATE)
    waveFile.writeframes(b''.join(frames))
    waveFile.close()

    if os.path.exists("streamMono.wav"):
        os.remove("streamMono.wav")

    sound = AudioSegment.from_wav("streamStereo.wav")
    sound = sound.set_channels(1)
    sound.export("streamMono.wav", format="wav")

# read data from wav file
def getBuffer(w):
    rate = w.getframerate()
    frames = w.getnframes()
    buffer = w.readframes(frames)
    type(buffer)

    return (buffer)

#Recognition from record
try:
    while True:

        # Audio Params
        audio = pyaudio.PyAudio()
        format = pyaudio.paInt16
        channels = 1
        rate = 16000
        chunksize = 2048
        recsec = 10
        devIndex = 0 # 0=Boltune, 1= boltune, 2 = builtin

        # create Audio
        createWav(audio, rate, chunksize, format, channels, recsec, devIndex)


        # predict Audio deepspeech
        filename = 'streamMono.wav'
        buffer = getBuffer(wave.open(filename, 'r'))

        data16 = np.frombuffer(buffer, dtype=np.int16)
        type(data16)
        text = model.stt(data16)
        print(text)

        # predict Audio ibm_cloud
        with sr.WavFile("streamMono.wav") as source:  # use "test.wav" as the audio source
            audio_file = r.record(source)

     #   speech_recognition_results = speech_to_text.recognize(audio=audio_file.get_wav_data(),
      #                                                        content_type='audio/wav').get_result()
       # print(json.dumps(speech_recognition_results, indent=2))


except KeyboardInterrupt:
    print("SR finished")
pass

#Recognition from stream

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