import time
import roslaunch
import rospy
import os
import signal
import subprocess
from roslaunch.parent import ROSLaunchParent
from transitions.extensions.nesting import HierarchicalMachine

class ALF(object):

    states = ['wait for', {'name': 'drive', 'children': ['manual', {'name': 'autonomous', 'children': ['explore', 'to target']}]}, 'localization', 'stop', 'slam']
    def __init__(self, name):
        self.machine = HierarchicalMachine(model=self, states=ALF.states, initial='stop')
        self.is_map = False
        self.basic_functions = self.roslaunch("basic_functions")
        self.localization_functions = self.roslaunch("localization_functions")
        #self.drive_functions
        self.drive_manual_functions = self.roslaunch("drive_manual_functions")
        #self.drive_autonomous_functions
        self.slam_functions = self.roslaunch("slam_functions")
        #self.drive_autonomous_explore_functions
        #self.drive_autonomous_to_target_functions


        #Transitions
        self.machine.add_transition(trigger='toWait_for', source='*', dest='wait for', after='wait_for')
        self.machine.add_transition(trigger='toStop', source='*', dest='stop', after='stop')
        self.machine.add_transition(trigger='toSlam', source='*', dest='slam', after='slam')
        self.machine.add_transition(trigger='toLocalization', source='*', dest='localization', after='localization')
        self.machine.add_transition(trigger='toDrive', source='*', dest='drive', after='drive')
        self.machine.add_transition(trigger='toManual', source='*', dest='drive_manual', after='manual')
        self.machine.add_transition(trigger='toAutonomous', source='*', dest='drive_autonomous', after='autonomous')
        self.machine.add_transition(trigger='toTo_target', source='*', dest='drive_autonomous_to target', after='to_target')
        self.machine.add_transition(trigger='toExplore', source='*', dest='drive_autonomous_explore', after='explore')



    def drive(self):
        print("Changing to drive...")
        while True:
            input = raw_input("Klasse eingeben: ")
            input2 = raw_input("Modus eingeben: ")
            if input == "stop":
                self.toStop()
            elif input == "wait for":
                self.toWait_for()
            elif input == "drive":
                pass
            else:
                print("No legal Transition!")

            if input2 == "manual":
                self.toManual()
            if input2 == "autonomous":
                self.toAutonomous()

    def autonomous(self):
        print("Changing to autonomous drive...")
        print("Ralfmain default autonom")
        while True:
            input = raw_input("Klasse eingeben: ")
            if input == "stop":
                self.toStop()
            elif input == "wait for":
                self.toWait_for()
            elif input == "drive":
                pass
            else:
                print("No legal Transition!")

            if self.is_map == True:
                self.toTo_target()
            else:
                self.toExplore()

    def manual(self):
        print("Changing to manual drive...")
        print("Ralfmain mit default manuelle Steuerung")

        self.drive_manual_functions = self.roslaunch("drive_manual_functions")
        self.drive_manual_functions.start()

        while True:
            input = raw_input("Klasse eingeben: ")
            if input == "stop":
                self.toStop()
            elif input == "wait for":
                self.toWait_for()
            else:
                print("No legal Transition!")


    def explore(self):
        print("Changing to drive autonomous exlore...")
        print("Explore node starten")
        while True:
            input = raw_input("Klasse eingeben: ")
            if input == "stop":
                self.toStop()
            elif input == "wait for":
                self.toWait_for()
            else:
                print("No legal Transition!")

    def to_target(self):
        print("Changing to drive autonomous to target...")
        print("Ziel wird von Rviz veroeffentlicht")
        while True:
            input = raw_input("Klasse eingeben: ")
            if input == "stop":
                self.toStop()
            elif input == "wait for":
                self.toWait_for()
            else:
                print("No legal Transition!")

    def localization(self):
        print("Changing to localization...")
        print("AMCL starten")

        self.is_map = True
        self.localization_functions = self.roslaunch("localization_functions")
        self.localization_functions.start()


        while True:
            input = raw_input("Klasse eingeben: ")
            if input == "stop":
                self.toStop()
            elif input == "drive":
                self.toDrive()
            elif input == "wait for":
                self.toWait_for()
            else:
                print("No legal Transition!")

    def wait_for(self):
        print("Changing to wait for...")
        print("ROS shutdown and restart")
        print("Sensorik hochfahren")

        self.is_map = False
        self.drive_manual_functions.shutdown()
        self.localization_functions.shutdown()
        self.basic_functions.shutdown()
        self.slam_functions.shutdown()
        rospy.sleep(10)
        self.basic_functions = self.roslaunch("basic_functions")
        self.basic_functions.start()


        while True:
            input = raw_input("Klasse eingeben: ")
            if input == "stop":
                self.toStop()
            elif input == "drive":
                self.toLocalization()
            elif input == "localization":
                self.toLocalization()
            elif input == "slam":
                self.toSlam()
            else:
                print("No legal Transition!")

    def stop(self):
        print("Changing to stop...")
        print("ROS shutdown")

        self.is_map = False
        self.drive_manual_functions.shutdown()
        self.basic_functions.shutdown()
        self.localization_functions.shutdown()
        self.slam_functions.shutdown()
        rospy.sleep(10)

        while True:
            input= raw_input("Quittieren mit Y: ")
            if input == "Y":
                self.toWait_for()
            else:
                print("No legal Transition!")

    def slam(self):
        print("Changing to slam...")
        print("Hector hochfahren")

        self.is_map = False
        self.slam_functions.shutdown()
        rospy.sleep(10)
        self.slam_functions = self.roslaunch("slam_functions")
        self.slam_functions.start()

        while True:
            input = raw_input("Klasse eingeben: ")
            if input == "stop":
                self.toStop()
            elif input == "drive":
                self.toDrive()
            elif input == "wait for":
                self.toWait_for()
            else:
                print("No legal Transition!")

    def roslaunch(self, launchfile):
        uuid = roslaunch.rlutil.get_or_generate_uuid(None, False)
        roslaunch.configure_logging(uuid)
        launch = roslaunch.parent.ROSLaunchParent(uuid, ["/home/alf/catkin_ws2/devel/lib/statemachine/" + launchfile + ".launch.xml"])
        return launch

if __name__ == "__main__":
    alf = ALF("alf")
    alf.toWait_for()








