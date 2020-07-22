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
                namearr = person.name.split()
                newname = []
                for chars in namearr:
                    newname.append(chars)
                    newname.append(" ")
                person.name.join(newname)
                self.publish("Hello and welcome. your name has to be " + person.name)
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
                namearr = person.name.split()
                newname = []
                for chars in namearr:
                    newname.append(chars)
                    newname.append(" ")
                person.name.join(newname)
                self.publish("Hello and welcome. your name has to be " + person.name)
                self.peoplenottogreet.append(person.name)



    def publish(self, str):
        msg = String()
        msg.data = str
        #self.voicepublisher.publish(msg)
        os.system("rosrun sound_play say.py '" + str + "'")
