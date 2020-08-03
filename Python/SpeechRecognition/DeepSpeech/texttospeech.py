import pyttsx3

def SpeakText(command):
    # Initialize the engine
    engine = pyttsx3.init()
    engine.setProperty('voice', "com.apple.speech.synthesis.voice.samantha")
    voices = engine.getProperty('voices')
    engine.say(command)
    engine.runAndWait()
    for voice in voices:
        print("Voice:")
        print(" - ID: %s" % voice.id)
        print(" - Name: %s" % voice.name)
        print(" - Languages: %s" % voice.languages)
        print(" - Gender: %s" % voice.gender)
        print(" - Age: %s" % voice.age)



SpeakText("occupancy grid")