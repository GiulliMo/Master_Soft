from std_msgs.msg import String
import rospy
import time
import os


class talk:

    def __init__(self):
        self.voicepublisher = rospy.Publisher('voice', String, queue_size=10)
        self.peoplenottogreet = []

    def greet(self, listofpersons):
        print("g")
        donotgreet = False
        print(self.peoplenottogreet)
        for person in listofpersons:
            print(person.name)
            timepassed = time.time() - person.timestamp
            print (timepassed)

            if len(self.peoplenottogreet) == 0 and timepassed <= 10:
                print("gruss2")
                self.publish("Hello and welcome " + person.name)
                self.peoplenottogreet.append(person.name)

            if len(self.peoplenottogreet) == 0 and timepassed >= 10:
                print(" k gruss2")
                donotgreet = True

            if timepassed >= 10:
                print("nicht gruessen")
                donotgreet = True

            for personnottogreet in self.peoplenottogreet:
                print(person.name)
                print(personnottogreet)
                if person.name == personnottogreet:
                    print("kein gruss")
                    donotgreet = True
                    if timepassed >= 60:
                        print("entfernen")
                        self.peoplenottogreet.remove(personnottogreet)

            if donotgreet == False:
                print("gruss")
                self.publish("Hello and welcome " + person.name)
                self.peoplenottogreet.append(person.name)

    def newperson(self):
        self.publish("Registration completed! Please type in you name.")

    def regcompleted(self, name):
        self.publish("Thank You. Saved Person with name " + name)

    def publish(self, str):
        msg = String()
        msg.data = str
        #self.voicepublisher.publish(msg)
        os.system("rosrun sound_play say.py '" + str + "'")
