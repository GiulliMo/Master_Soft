# Python 2.x program for Speech Recognition

import speech_recognition as sr
from watson_developer_cloud import SpeechToTextV1
import json

# enter the name of usb microphone that you found
# using lsusb
# the following name is only used as an example
mic_name = "Boltune BT-BH020"
# Sample rate is how often values are recorded
sample_rate = 44000
# Chunk is like a buffer. It stores 2048 samples (bytes of data)
# here.
# it is advisable to use powers of 2 such as 1024 or 2048
chunk_size = 2048
# Initialize the recognizer
r = sr.Recognizer()

# generate a list of all audio cards/microphones
mic_list = sr.Microphone.list_microphone_names()
mic_name = mic_list[1]
# the following loop aims to set the device ID of the mic that
# we specifically want to use to avoid ambiguity.
for i, microphone_name in enumerate(mic_list):
    if microphone_name == mic_name:
        device_id = i
m = sr.Microphone(device_index=1)
speech_to_text = SpeechToTextV1(
    iam_apikey="wsDeuwes_FSm3bo_QiLLQl1Er81u1sqIQxMNZFB67aVq",
    url="https://api.eu-gb.speech-to-text.watson.cloud.ibm.com/instances/472d7157-6ba9-4041-b3f3-8b014ebd62cf")


# use the microphone as source for input. Here, we also specify
# which device ID to specifically look for incase the microphone
# is not working, an error will pop up saying "device_id undefined"

def loop():
    try:
        with sr.Microphone() as source:
            # wait for a second to let the recognizer adjust the
            # energy threshold based on the surrounding noise level
            print("Say Something")

            # listens for the user's input
            audio_file = r.adjust_for_ambient_noise(source)
            audio_file = r.listen(source)
            speech_recognition_results = speech_to_text.recognize(audio=audio_file.get_wav_data(),
                                                                  content_type='audio/wav').get_result()
            print(json.dumps(speech_recognition_results, indent=2))

    except KeyboardInterrupt:
        pass


loop()


def main():
    loop()


if __name__ == '__main__':
    print("Hello World")
    a = 1
    while a:
        try:
            main()
        except KeyboardInterrupt:
            a = 0
