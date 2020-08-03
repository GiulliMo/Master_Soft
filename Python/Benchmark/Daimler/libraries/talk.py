from tempfile import TemporaryFile

import pygame
from gtts import gTTS
from std_msgs.msg import String
import rospy
import time
import os
import pyttsx3


class talk:

    def __init__(self):
        self.voicepublisher = rospy.Publisher('voice', String, queue_size=10)
        self.peoplenottogreet = []

    def greet(self, listofpersons):
        #print(self.peoplenottogreet)
        for person in listofpersons:
            donotgreet = False
            print(person.name)
            timepassed = time.time() - person.timestamp
            print ("Nicht gesehen seit " + str(int(timepassed)) + "s.")

            if len(self.peoplenottogreet) == 0 and timepassed <= 10:
                #print("gruss2")
                self.publish("Hello and welcome " + person.name)
                self.peoplenottogreet.append(person.name)

            if len(self.peoplenottogreet) == 0 and timepassed >= 10:
                #print(" k gruss2")
                donotgreet = True

            if timepassed >= 10:
                #print("nicht gruessen")
                donotgreet = True

            for personnottogreet in self.peoplenottogreet:
                print(person.name)
                print(personnottogreet)
                if person.name == personnottogreet:
                    #print("kein gruss")
                    donotgreet = True
                    if timepassed >= 60:
                        #print("entfernen")
                        self.peoplenottogreet.remove(personnottogreet)

            if donotgreet == False:
                #print("gruss")
                self.publish("Hello and welcome " + person.name)
                self.peoplenottogreet.append(person.name)

    def newperson(self):
        self.publish("Registration completed! Please type in you name.")

    def regcompleted(self, name):
        self.publish("Thank You. Saved Person with name " + name)

    def unknown(self):
        self.publish("I dont know you! Please come closer, hold your position and look at the camera.")

    def newregprocess(self):
        self.publish("Registration Process aborted! Please try again!")

    def publish(self, str):
        tts = gTTS(str)
        f = TemporaryFile()
        tts.write_to_fp(f)
        f.seek(0)
        pygame.mixer.init()
        pygame.mixer.music.load(f)
        pygame.mixer.music.play()
        while pygame.mixer.music.get_busy():
            pygame.time.Clock().tick(10)
        f.close()

        #msg = String()
        #msg.data = str
        #self.voicepublisher.publish(msg)
        #os.system("rosrun sound_play say.py '" + str + "'")
