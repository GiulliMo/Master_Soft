from scipy.misc import bytescale
from centroidtracker import CentroidTracker
from imutils.object_detection import non_max_suppression
import numpy as np
import argparse
import imutils
import cv2
import rospy
import sys
from sensor_msgs.msg import Image, PointCloud2
import sensor_msgs.point_cloud2 as pc2
from cv_bridge import CvBridge, CvBridgeError


class PeopleTracktion:
    def __init__(self, namespaceofcamera, maxdetectionsbeforetrack=5):
        self.frame_rgb = np.empty(0)
        self.frame_depth = np.empty(0)
        # self.net = cv2.dnn.readNetFromCaffe("deploy.prototxt", "res10_300x300_ssd_iter_140000.caffemodel")
        self.trackers = cv2.MultiTracker_create()
        self.ct = CentroidTracker(maxdetectionsbeforetrack)
        self.hog = cv2.HOGDescriptor()
        self.hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())
        self.namespaceofcamera = namespaceofcamera
        self.bridge = CvBridge()
        self.detections = np.empty(0)
        self.orig = np.empty(0)
        self.xcenter = 0
        self.ycenter = 0
        self.mindepth = rospy.get_param("/" + namespaceofcamera + "_bridge/min_depth")
        self.maxdepth = rospy.get_param("/" + namespaceofcamera + "_bridge/max_depth")
        self.listofroi = []
        self.pc_list = []
        self.pointcloudmsg = 0
        self.OPENCV_OBJECT_TRACKERS = {
            "kcf": cv2.TrackerKCF_create,
            "boosting": cv2.TrackerBoosting_create,
            "mil": cv2.TrackerMIL_create,
            "tld": cv2.TrackerTLD_create,
            "medianflow": cv2.TrackerMedianFlow_create,
            "mosse": cv2.TrackerMOSSE_create
        }

    def callback_rgb(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")

            # frame = imutils.resize(cv_image, width=300, height = 300)
            self.frame_rgb = imutils.resize(cv_image, width=min(400, cv_image.shape[1]))

            self.orig = self.frame_rgb.copy()
            cv2.imshow("Frame:anfang", self.frame_rgb)
            cv2.waitKey(3)
            self.getdetections()
            self.getids()
            self.getdistance()
        except CvBridgeError as e:
            print(e)

    def callback_depth(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, "16UC1")
            self.frame_depth = imutils.resize(cv_image, width=min(400, cv_image.shape[1]))
            self.frame_depth = bytescale(self.frame_depth)
        except CvBridgeError as e:
            print(e)

    def callback_pointcloud(self, msg):
        self.pointcloudmsg = msg


    def getdetections(self):
        (rects, weights) = self.hog.detectMultiScale(self.frame_rgb, winStride=(4, 4), padding=(8, 8), scale=1.05)

        for (x, y, w, h) in rects:
            cv2.rectangle(self.orig, (x, y), (x + w, y + h), (0, 0, 255), 2)

        rects = np.array([[x, y, x + w, y + h] for (x, y, w, h) in rects])
        self.detections = non_max_suppression(rects, probs=None, overlapThresh=0.65)
        # draw the final bounding boxes

    def getids(self):
        for (xA, yA, xB, yB) in self.detections:
            cv2.rectangle(self.frame_rgb, (xA, yA), (xB, yB), (0, 255, 0), 2)

        # update our centroid tracker using the computed set of bounding
        # box rectangles
        objects = self.ct.update(self.detections)
        # loop over the tracked objects
        for (objectID, centroid) in objects.items():
            # draw both the ID of the object and the centroid of the
            # object on the output frame
            text = "ID {}".format(objectID)
            cv2.putText(self.frame_rgb, text, (centroid[0] - 10, centroid[1] - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5,
                        (0, 255, 0), 2)
            cv2.circle(self.frame_rgb, (centroid[0], centroid[1]), 4, (0, 255, 0), -1)
        # show the output frame
        cv2.imshow("Frame", self.frame_rgb)
        cv2.waitKey(3)

    def getdistance(self):
        counter = 0
        print(self.detections)
        for (xupleft, yupleft, xbellowright, ybellowright) in self.detections:
            counter += 1
            #xupleft = 0
            #yupleft = 52
            #xbellowright = 61
            #ybellowright = 191
            self.xcenter = xupleft + (xbellowright - xupleft)/2
            self.ycenter = yupleft + (ybellowright - yupleft)/2
            xnewupleft = xupleft + (self.xcenter - xupleft)*4/5
            ynewupleft = yupleft + (self.ycenter - yupleft)*4/5
            xnewbellowright = self.xcenter + (xbellowright - self.xcenter)/5
            ynewbellowright = self.ycenter + (ybellowright - self.ycenter)/5
            self.listofroi = []
            self.pc_list = []
            #print(len(self.pc_list))
            depthsum = 0
            valuecount = 0
            nonreliablevaluescount = 0
            for row in range(ynewupleft, ynewbellowright):
                for column in range(xnewupleft, xnewbellowright):
                    self.listofroi.append([int(column*4.8), int(row*4.8)])

            pc = pc2.read_points(self.pointcloudmsg, skip_nans=True, field_names=("x", "y", "z"), uvs=self.listofroi)
            for p in pc:
                self.pc_list.append([p[0], p[1], p[2]])
            #print("vor")
            #print(len(self.pc_list))
            #print("nach")
            #print(self.listofroi)

            #print(len(self.pc_list))
            for (x, y, z) in self.pc_list:
                depthsum += z
                valuecount += 1


            depthaverage = depthsum/valuecount
            print(depthaverage)
            #depthpervalue = -(self.maxdepth - self.mindepth)/254
            #depth = self.maxdepth - self.mindepth + depthpervalue * depthvaluemedian
            #print(str(depthvaluemedian) + " sind " + str(depth) + " Meter" )

            cv2.circle(self.frame_rgb, (xupleft, yupleft), 2, (0, 0, 0), -1)
            cv2.circle(self.frame_rgb, (xbellowright, ybellowright), 2, (0, 0, 0), -1)
            cv2.circle(self.frame_rgb, (100, 50), 2, (0, 0, 0), -1)
            cv2.rectangle(self.frame_rgb, (xnewupleft, ynewupleft), (xnewbellowright, ynewbellowright), (0, 255, 0), 2)

        #print("Counter:" + str(counter))
        cv2.imshow("Frame..", self.frame_rgb)
        cv2.waitKey(3)

    def startnode(self):
        rospy.init_node('listener', anonymous=True)
        rospy.Subscriber("/" + self.namespaceofcamera + "/qhd/image_color", Image, self.callback_rgb)
        rospy.Subscriber("/" + self.namespaceofcamera + "/hd/points", PointCloud2, self.callback_pointcloud)
        #rospy.Subscriber("/" + self.namespaceofcamera + "/qhd/image_depth_rect", Image, self.callback_depth)
        #rospy.Subscriber("/" + self.namespaceofcamera + "/hd/points", PointCloud2, self.callback_pointcloud)
        try:
            rospy.spin()

        except KeyboardInterrupt:
            print("Shutting down")
        cv2.destroyAllWindows()


if __name__ == '__main__':
    pt = PeopleTracktion("kinect2")
    pt.startnode()
