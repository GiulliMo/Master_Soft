import random
import sys
import pyaudio
import os
import wave
import json
from colorama import init
from termcolor import colored
import sounddevice as sd
import time
init()

class AudioStream:

    def __init__(self, dev, recsec):
        self.channels = 1
        self.rate = 16000
        self.chunksize = 2048
        self.devIndex = dev
        self.Format = pyaudio.paInt16
        self.audio = pyaudio.PyAudio()
        self.recsec = recsec
        self.frames = []
        self.filename = ""

    def createWav(self, filename, path):

        #loeschen wenn WAV existiert
        if os.path.exists(filename):
            os.remove(filename)

        # start Recording
        stream = self.audio.open(format=self.Format, rate=self.rate, channels=self.channels,
                                 input_device_index=self.devIndex, input=True,
                                 frames_per_buffer=self.chunksize)

        frames = []
        frames.append(stream.read(self.chunksize)) # Erstes mal append dauert laenger


        print("recording...")
        for i in range(0, int(self.rate / self.chunksize * self.recsec)):
            frames.append(stream.read(self.chunksize)) # Frames werden angehangen je nachdem wie gross recsec ist

        print("finished recording!")

        frames.pop(0)# erster Frame wird wieder weggenommen
        stream.stop_stream()
        stream.close()

        waveFile = wave.open(path + '\\' + filename, 'wb')
        waveFile.setnchannels(self.channels)
        waveFile.setsampwidth(self.audio.get_sample_size(self.Format))
        waveFile.setframerate(self.rate)
        waveFile.writeframes(b''.join(frames))
        waveFile.close()


if __name__ == '__main__':

    try:
        # pfad definieren und daten laden
        path = os.path.dirname(sys.argv[0])
        with open(path + '\\test_data.json') as json_file:
            test_data = json.load(json_file)

        string = sd.query_devices()
        print(string)

        dev = input("Gib deine Device ID ein: ")
        s = AudioStream(dev=int(dev), recsec=7)

        s.filename = input("Gib deinen Namen ein und bestaetige mit Enter:")

        print("\nSpreche die folgenden 10 Wortgruppen ein. Fuer eine neue Aufnahme hast du 7s Zeit.\nUm die Aufnahme auszuloesen, betaetige jeweils die Enter-Taste.\nFuer abbrechen druecke auf der Tastatur strg + c")

        test_labels = []
        for i in range(10):
            num1 = random.randint(0, len(test_data)-1)
            sentence = test_data[num1]["sentence"]
            test_labels.append(test_data[num1])

            print("\nSpreche folgenden Satz in das Mikrofon: " + colored(sentence, 'green'))
            enter = input("Zum Start der 7s Aufnahme betaetige Enter")
            start = time.time()
            print(str(i))
            s.createWav(s.filename + str(i) + ".wav", path = path)

            test_data.pop(num1)

    except KeyboardInterrupt:
        print("Keyboard interrupt")
        pass

    # labels mit gleichen Namne loeschen
    if os.path.exists(s.filename):
        os.remove(s.filename)

    # labels speichern
    with open(path + '\\' + s.filename + ".json", 'w') as outfile:
        json.dump(test_labels, outfile)

    s.audio.terminate()
    print("Vielen Dank!")