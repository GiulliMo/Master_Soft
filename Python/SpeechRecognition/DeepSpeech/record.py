import random
import sys
import pyaudio
import os
import wave
import json
from termcolor import colored
import sounddevice as sd
import pyttsx3
import threading
import time


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



    def recordWav(self, filename, path):

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

        waveFile = wave.open(path + '/data/' + filename, 'wb')
        waveFile.setnchannels(self.channels)
        waveFile.setsampwidth(self.audio.get_sample_size(self.Format))
        waveFile.setframerate(self.rate)
        waveFile.writeframes(b''.join(frames))
        waveFile.close()

        return True

   # def createWav(self, filepath):
    #    sound = am.from_file(filepath, format='wav', frame_rate=22000)
     #   sound = sound.set_frame_rate(16000)
      #  sound.export(path + filepath + str(i), format='wav')

        #waveFile = wave.open(path + '/data/' + filename, 'wb')
        #waveFile.setnchannels(self.channels)
        #waveFile.setsampwidth(self.audio.get_sample_size(self.Format))
        #waveFile.setframerate(self.rate)
        #waveFile.writeframes(b''.join(frames))
        #waveFile.close()

if __name__ == '__main__':

    def texttospeech(command, path, filename):
        # Initialize the engine
        engine.setProperty('rate', 175)
        engine.say(command)
        #engine.save_to_file(command, path + "/" + filename)
        engine.runAndWait()

    try:
        # pfad definieren und daten laden
        path = os.path.dirname(sys.argv[0])
        with open(path + '/' + 'data/test_data_II.json') as json_file:
            test_data = json.load(json_file)

        string = sd.query_devices()
        print(string)
        print(path)
        engine = pyttsx3.init()

        ## 10 mal property setzen
        listofvoices = []
      #  listofvoices.append("com.apple.speech.synthesis.voice.Alex")# en_us
        #listofvoices.append("com.apple.speech.synthesis.voice.daniel") #en_gb
        #listofvoices.append("com.apple.speech.synthesis.voice.fiona") #en_scotland
       ## listofvoices.append("com.apple.speech.synthesis.voice.Fred") #en_us2
       # listofvoices.append("com.apple.speech.synthesis.voice.karen") #en_au
        #listofvoices.append("com.apple.speech.synthesis.voice.moira") #en_ie
       # listofvoices.append("com.apple.speech.synthesis.voice.samantha.premium") #en_us3
        #listofvoices.append("com.apple.speech.synthesis.voice.tessa") #en_za
       # listofvoices.append("com.apple.speech.synthesis.voice.veena") #en_in
        #listofvoices.append("com.apple.speech.synthesis.voice.Victoria") #en_us4
        #listofvoices.append("com.apple.speech.synthesis.voice.Vicki") #en_us6
        #listofvoices.append("com.apple.speech.synthesis.voice.tom.premium")
        listofvoices.append("com.apple.speech.synthesis.voice.susan.premium")
        listofvoices.append("com.apple.speech.synthesis.voice.serena.premium")
        listofvoices.append("com.apple.speech.synthesis.voice.Ralph")
        listofvoices.append("com.apple.speech.synthesis.voice.oliver.premium")
        listofvoices.append("com.apple.speech.synthesis.voice.lee.premium")
        listofvoices.append("com.apple.speech.synthesis.voice.kate.premium")
        listofvoices.append("com.apple.speech.synthesis.voice.fiona.premium")
        listofvoices.append("com.apple.speech.synthesis.voice.daniel.premium")
        listofvoices.append("com.apple.speech.synthesis.voice.Bruce")
        listofvoices.append("com.apple.speech.synthesis.voice.anna.premium")
        listofvoices.append("com.apple.speech.synthesis.voice.ava.premium")
        listofvoices.append("com.apple.speech.synthesis.voice.allison.premium")


        voices = engine.getProperty('voices')
        engine.setProperty('rate', 175)
        dev = 0
        s = AudioStream(dev=int(dev), recsec=7)

        print("\nSpreche die folgenden 10 Wortgruppen ein. Fuer eine neue Aufnahme hast du 7s Zeit.\nUm die Aufnahme auszuloesen, betaetige jeweils die Enter-Taste.\nFuer abbrechen druecke auf der Tastatur strg + c")

        test_labels = []
        threads = list()

        for voice in voices:
            print("Voice: %s" % voice.name)
            print(" - ID: %s" % voice.id)
            print(" - Languages: %s" % voice.languages)
            print(" - Gender: %s" % voice.gender)
            print(" - Age: %s" % voice.age)
            print("\n")
        engine.setProperty('voice', "com.apple.speech.synthesis.voice.Alex")
        engine.setProperty('voice', voices[0].id)

      #  print(len(test_data))
        for voice in listofvoices:

            with open(path + '/' + 'data/training_data_II.json') as json_file:
                test_data = json.load(json_file)
                #print(len(test_data))

            engine.setProperty('voice', voice)
            voice = voice.replace(".", "")
            s.filename = voice
            i = 0
            test_labels = []
            for i in range(len(test_data)):
                num1 = random.randint(0, len(test_data)-1)
                sentence = test_data[num1]["sentence"]
                test_labels.append(test_data[num1])
                name = s.filename + str(i) + ".wav"
                x = threading.Thread(target=s.recordWav, args=(name, path))

                #print("\nSpreche folgenden Satz in das Mikrofon: " + colored(sentence, 'red'))

                #enter = input("Zum Start der 7s Aufnahme betaetige Enter")

                ## threads um tts als aufnahme zu nutzen
                threads.append(x)

                x.start()   #start thread
                time.sleep(2.0)
                texttospeech(sentence, path = path + "/data/", filename=s.filename + str(i) + ".wav")
                x.join() # warten bis thread beendet

                #s.createWav(filepath=path + "/data/" + s.filename + str(i) + ".wav")
                #s.recordWav(s.filename + str(i) + ".wav", path = path)

                print(str(i))

                test_data.pop(num1)

            # labels mit gleichen Namen loeschen

            if os.path.exists(s.filename):
                os.remove(s.filename)

            # labels speichern
            with open(path + '/data/' + s.filename + ".json", 'w') as outfile:
                json.dump(test_labels, outfile)

    except KeyboardInterrupt:
        print("Keyboard interrupt")
        pass
    s.audio.terminate()
    print("Vielen Dank!")