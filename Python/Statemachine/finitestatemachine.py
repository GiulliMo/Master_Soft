import time
from tempfile import TemporaryFile

import roslaunch
import rospy
import pyttsx3
from std_msgs.msg import String
from roslaunch.parent import ROSLaunchParent
from transitions.extensions.nesting import HierarchicalMachine
from gtts import gTTS
import pygame


class ALF(object):
    states = ['wait for',
              {'name': 'drive', 'children': ['manual', {'name': 'autonomous', 'children': ['explore', 'to target']}]},
              'localization', 'stop', 'slam']

    def __init__(self, name):
        self.machine = HierarchicalMachine(self, ALF.states, 'wait for')
        self.is_map = False
        self.basic_functions = self.roslaunch("basic_functions")
        self.localization_functions = self.roslaunch("localization_functions")
        # self.drive_functions
        self.drive_manual_functions = self.roslaunch("drive_manual_functions")
        # self.drive_autonomous_functions
        self.slam_functions = self.roslaunch("slam_functions")
        self.drive_autonomous_explore_functions = self.roslaunch("drive_autonomous_explore_functions")
        self.drive_autonomous_to_target_functions = self.roslaunch("drive_autonomous_to_target_functions")
        self.task = ""
        self.mode = ""
        self.manualcontrol = True
        self.input = ""
        self.input2 = ""

        # Transitions
        self.machine.add_transition(trigger='toWait_for', source='*', dest='wait for', after='wait_for')
        self.machine.add_transition(trigger='toStop', source='*', dest='stop', after='stop')
        self.machine.add_transition(trigger='toSlam', source='*', dest='slam', after='slam')
        self.machine.add_transition(trigger='toLocalization', source='*', dest='localization', after='localization')
        self.machine.add_transition(trigger='toDrive', source='*', dest='drive', after='drive')
        self.machine.add_transition(trigger='toManual', source='*', dest='drive_manual', after='manual')
        self.machine.add_transition(trigger='toAutonomous', source='*', dest='drive_autonomous', after='autonomous')
        self.machine.add_transition(trigger='toTo_target', source='*', dest='drive_autonomous_to target',
                                    after='to_target')
        self.machine.add_transition(trigger='toExplore', source='*', dest='drive_autonomous_explore', after='explore')

    def drive(self):
        print("Changing to drive...")
        self.talk('Changed to state drive.')

        while True:
            if self.manualcontrol == True:
                self.input = input("Klasse eingeben: ")
                self.input2 = input("Modus eingeben: ")
            if self.input == "stop" or self.task == "stop":
                self.toStop()
            elif self.input == "wait for" or self.task == "wait for":
                self.toWait_for()
            elif self.input == "drive" or self.task == "drive":
                pass
            else:
                print("No legal Transition! State --> " + self.state)
                time.sleep(0.1)

            if self.input2 == "manual" or self.mode == "manual":
                self.toManual()
            elif self.input2 == "autonom" or self.mode == "autonom":
                self.toAutonomous()

    def autonomous(self):
        print("Changing to autonomous drive...")
        print("Ralfmain default autonom")
        self.talk('Changed to state drive autonomously.')

        while True:
            if self.manualcontrol == True:
                self.input = input("Klasse eingeben: ")
            if self.input == "stop" or self.task == "stop":
                self.toStop()
            elif self.input == "wait for" or self.task == "wait for":
                self.toWait_for()
            elif self.input == "drive" or self.task == "drive":
                pass
            else:
                print("No legal Transition! State --> " + self.state)
                time.sleep(0.1)

            if self.is_map == True:
                self.toTo_target()
            else:
                self.toExplore()

    def manual(self):
        print("Changing to manual drive...")
        print("Ralfmain mit default manuelle Steuerung")
        self.talk('Changed to state manual drive. Grab the controller and take control of me.')

        self.drive_manual_functions = self.roslaunch("drive_manual_functions")
        self.drive_manual_functions.start()

        while True:
            if self.manualcontrol == True:
                self.input = input("Klasse eingeben: ")
            if self.input == "stop" or self.task == "stop":
                self.toStop()
            elif self.input == "wait for" or self.task == "wait for":
                self.toWait_for()
            else:
                print("No legal Transition! State --> " + self.state)
                time.sleep(0.1)

    def explore(self):
        print("Changing to drive autonomous exlore...")
        print("Explore node starten")
        self.talk('Changed to state explore. I will now check my environment.')

        self.drive_autonomous_explore_functions = self.roslaunch("drive_autonomous_explore_functions")
        self.drive_autonomous_explore_functions.start()

        while True:
            if self.manualcontrol == True:
                self.input = input("Klasse eingeben: ")
            if self.input == "stop" or self.task == "stop":
                self.toStop()
            elif self.input == "wait for" or self.task == "wait for":
                self.toWait_for()
            else:
                print("No legal Transition! State --> " + self.state)
                time.sleep(0.1)

    def to_target(self):
        print("Changing to drive autonomous to target...")
        print("Ziel wird von Rviz veroeffentlicht")
        self.talk('Changed to state drive autonomously to target. Bye bye see you next time!')

        self.drive_autonomous_to_target_functions = self.roslaunch("drive_autonomous_to_target_functions")
        self.drive_autonomous_to_target_functions.start()

        while True:
            if self.manualcontrol == True:
                self.input = input("Klasse eingeben: ")
            if self.input == "stop" or self.task == "stop":
                self.toStop()
            elif self.input == "wait for" or self.task == "wait for":
                self.toWait_for()
            else:
                print("No legal Transition! State --> " + self.state)
                time.sleep(0.1)

    def localization(self):
        print("Changing to localization...")
        print("AMCL starten")
        self.talk('Changed to state localization. I am localizing myself in a static map.')

        self.is_map = True
        self.localization_functions = self.roslaunch("localization_functions")
        self.localization_functions.start()

        while True:
            if self.manualcontrol == True:
                self.input = input("Klasse eingeben: ")
            if self.input == "stop" or self.task == "stop":
                self.toStop()
            elif self.input == "drive" or self.task == "drive":
                self.toDrive()
            elif self.input == "wait for" or self.task == "wait for":
                self.toWait_for()
            else:
                print("No legal Transition! State --> " + self.state)
                time.sleep(0.1)

    def wait_for(self):
        print("Changing to wait for...")
        print("ROS shutdown and restart")
        print("Sensorik hochfahren")

        self.is_map = False
        self.drive_manual_functions.shutdown()
        self.localization_functions.shutdown()
        self.basic_functions.shutdown()
        self.slam_functions.shutdown()
        self.drive_autonomous_to_target_functions.shutdown()
        self.drive_autonomous_explore_functions.shutdown()
        # time.sleep(10)
        self.basic_functions = self.roslaunch("basic_functions")
        self.basic_functions.start()
        rospy.Subscriber("/transcript/modus", String, alf.getmode)
        rospy.Subscriber("/transcript/task", String, alf.gettask)
        rospy.init_node('listener', anonymous=True)
        self.talk('Changed to state wait for. Please tell me what to do.')

        while True:
            print(self.task)
            print(self.input)
            if self.manualcontrol == True:
                self.input = input("Klasse eingeben: ")
            # if self.input == "stop" or self.task == "stop":
            # self.toStop()
            if self.input == "drive" or self.task == "drive":
                print("change")
                self.toLocalization()
            elif self.input == "localization" or self.task == "localization":
                self.toLocalization()
            elif self.input == "slam" or self.task == "slam":
                self.toSlam()
            else:
                print("No legal Transition! State --> " + self.state)
                time.sleep(0.1)

    def stop(self):
        print("Changing to stop...")
        print("ROS shutdown")

        self.is_map = False
        self.drive_manual_functions.shutdown()
        self.localization_functions.shutdown()
        self.basic_functions.shutdown()
        self.slam_functions.shutdown()
        self.drive_autonomous_to_target_functions.shutdown()
        self.drive_autonomous_explore_functions.shutdown()
        rospy.sleep(10)

        while True:
            self.input = input("Quittieren mit Y: ")
            if self.input == "Y":
                self.toWait_for()
            else:
                print("No legal Transition! State --> " + self.state)
                time.sleep(0.1)

    def slam(self):
        print("Changing to slam...")
        print("Hector hochfahren")
        self.talk('Changed to state slam.')

        self.is_map = False
        self.slam_functions = self.roslaunch("slam_functions")
        self.slam_functions.start()

        if self.manualcontrol == True:
            self.input = input("Klasse eingeben: ")
        if self.input == "stop":
            self.toStop()
        elif self.input == "wait for":
            self.toWait_for()
        else:
            self.toDrive()

    def problem(self):
        pass

    def roslaunch(self, launchfile):
        uuid = roslaunch.rlutil.get_or_generate_uuid(None, False)
        roslaunch.configure_logging(uuid)
        launch = roslaunch.parent.ROSLaunchParent(uuid, [
            "/home/alf/catkin_ws2/devel/lib/statemachine/" + launchfile + ".launch.xml"])
        return launch

    def gettask(self, msg):
        print(msg.data)
        self.task = msg.data
        # self.toWait_for()

    def getmode(self, msg):
        print(msg.data)
        self.mode = msg.data
        # self.toWait_for()

    def talk(self, str):
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
        """
        engine = pyttsx3.init()
        voices = engine.getProperty('voices')
        engine.setProperty('rate', 160)
        engine.setProperty('id', 'english')
        engine.say(str)
        engine.runAndWait()
        """


if __name__ == "__main__":
    alf = ALF("alf")

    try:
        while not rospy.is_shutdown():
            alf.toWait_for()
    except KeyboardInterrupt:
        print("\nShutting down")
