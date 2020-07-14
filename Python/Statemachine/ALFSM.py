import roslaunch
import rospy
import subprocess
import time
from statemachine import StateMachine, State

class ALF(StateMachine):
    #States
    localization = State('Localization', initial=True)
    slam = State('Slam')

    #Transitions
    ready = localization.to(slam)
    """
    roscore = subprocess.Popen('roscore')
    time.sleep(5)  # wait a bit to be sure the roscore is really launched
    rospy.init_node('SM', anonymous=True)
    """

    def bon_ready(self):
        print("hallo")
        uuid = roslaunch.rlutil.get_or_generate_uuid(None, False)
        roslaunch.configure_logging(uuid)
        launch = roslaunch.parent.ROSLaunchParent(uuid,
                                                  ["/home/alf/catkin_ws/devel/lib/loc_alfons/loc_alfons.launch.xml"])
        launch.start()
        rospy.loginfo("started")
        rospy.sleep(30)
        launch.shutdown()
        time.sleep(5)

    def on_slam(self):
        print("check")
        uuid = roslaunch.rlutil.get_or_generate_uuid(None, False)
        roslaunch.configure_logging(uuid)
        launch = roslaunch.parent.ROSLaunchParent(uuid,
                                                  ["/home/alf/catkin_ws/devel/lib/slam_alfons/slam_alfons.launch.xml"])
        launch.start()
        rospy.loginfo("started")
        rospy.sleep(30)
        launch.shutdown()


print("?")
stm = ALF()
stm.ready()


