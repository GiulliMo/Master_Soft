import math
import tf as transform
from geometry_msgs.msg import PoseStamped
from imutils.object_detection import non_max_suppression
import face_recognition
import numpy as np
import imutils
import cv2
import rospy
import time
from sensor_msgs.msg import Image, PointCloud2
import sensor_msgs.point_cloud2 as pc2
from cv_bridge import CvBridge, CvBridgeError
from libraries.detections import *
from libraries.face import *
from libraries.person import person as ppl
from libraries.dataoperations import *
from libraries.talk import *
import shutil

class videosplitter:
    def __init__(self):
        # Liste aller bekannten Personen
        self.listofpersons = []
        self.tfbroadcaster = transform.TransformBroadcaster()
        self.namespaceofrearcamera = "kinect1"
        self.bridgefront = CvBridge()
        self.bridgeback = CvBridge()
        self.listofroi = []
        self.listener = []
        self.pointcloudmsg = 0
        self.frontframebgrsmall = np.array(0)
        self.rearframebgrsmall = np.array(0)
        self.frontimagebgrqhd = np.array(0)
        self.rearimagebgrqhd = np.array(0)
        self.face = face()
        self.talk = talk()
        self.dataoperations = dataoperations()
        self.slowdown = True


    # Callback der hinteren Kamera.
    def processingqhdrear(self, msg):
        try:
            sneak = "back"
            self.rearimagebgrqhd = self.bridgeback.imgmsg_to_cv2(msg, "bgr8")

        except CvBridgeError as e:
            print(e)

    def startnode(self):
        rospy.init_node('listener', anonymous=True)
        rospy.Subscriber("/" + self.namespaceofrearcamera + "/qhd/image_color", Image, self.processingqhdrear)
        # self.publisher = rospy.Publisher('/tracked_people/pose', PoseStamped, queue_size=10)
        try:
            rospy.sleep(4)
            # rospy.spin()
            a = 0
            shutil.rmtree('data')
            try:
                os.mkdir('data')
            except OSError:
                print ("Creation of directory failed")
            else:
                print ("Successfully create directory")
            while not rospy.is_shutdown():
                cv2.imwrite('data/' + str(a) + '.jpg', self.rearimagebgrqhd)
                print("saved frame with name " + str(a))
                a = a + 1
                time.sleep(1)

        except KeyboardInterrupt:
            print("\nShutting down")

if __name__ == '__main__':
    pt = videosplitter()
    pt.startnode()