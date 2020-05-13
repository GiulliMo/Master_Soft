from centroidtracker import CentroidTracker
from imutils.object_detection import non_max_suppression
import numpy as np
import argparse
import imutils
import cv2
import rospy
import sys
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError


class PeopleTracktion:
    def __init__(self, namespaceofcamera, maxdetectionsbeforetrack=5):
        self.frame = np.empty(0)
        # self.net = cv2.dnn.readNetFromCaffe("deploy.prototxt", "res10_300x300_ssd_iter_140000.caffemodel")
        self.trackers = cv2.MultiTracker_create()
        self.ct = CentroidTracker(maxdetectionsbeforetrack)
        self.hog = cv2.HOGDescriptor()
        self.hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())
        self.namespaceofcamera = namespaceofcamera
        self.bridge = CvBridge()
        self.OPENCV_OBJECT_TRACKERS = {
            "kcf": cv2.TrackerKCF_create,
            "boosting": cv2.TrackerBoosting_create,
            "mil": cv2.TrackerMIL_create,
            "tld": cv2.TrackerTLD_create,
            "medianflow": cv2.TrackerMedianFlow_create,
            "mosse": cv2.TrackerMOSSE_create
        }

    def callback(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")

            # frame = imutils.resize(cv_image, width=300, height = 300)
            self.frame = imutils.resize(cv_image, width=min(400, cv_image.shape[1]))

            orig = self.frame.copy()
            cv2.imshow("Frame:anfang", self.frame)
            cv2.waitKey(3)
            (rects, weights) = self.hog.detectMultiScale(self.frame, winStride=(4, 4), padding=(8, 8), scale=1.05)

            for (x, y, w, h) in rects:
                cv2.rectangle(orig, (x, y), (x + w, y + h), (0, 0, 255), 2)

            rects = np.array([[x, y, x + w, y + h] for (x, y, w, h) in rects])
            pick = non_max_suppression(rects, probs=None, overlapThresh=0.65)
            # draw the final bounding boxes

            for (xA, yA, xB, yB) in pick:
                cv2.rectangle(self.frame, (xA, yA), (xB, yB), (0, 255, 0), 2)

            # update our centroid tracker using the computed set of bounding
            # box rectangles
            objects = self.ct.update(pick)
            # loop over the tracked objects
            for (objectID, centroid) in objects.items():
                # draw both the ID of the object and the centroid of the
                # object on the output frame
                text = "ID {}".format(objectID)
                cv2.putText(self.frame, text, (centroid[0] - 10, centroid[1] - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5,
                            (0, 255, 0), 2)
                cv2.circle(self.frame, (centroid[0], centroid[1]), 4, (0, 255, 0), -1)
            # show the output frame
            cv2.imshow("Frame", self.frame)
            cv2.waitKey(3)

        except CvBridgeError as e:
            print(e)

    def callback_depth(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, "32FC1")
            print(msg)
            # frame = imutils.resize(cv_image, width=300, height = 300)
            frame = imutils.resize(cv_image, width=min(400, cv_image.shape[1]))
            orig = frame.copy()

        except CvBridgeError as e:
            print(e)

    def startnode(self):
        rospy.init_node('listener', anonymous=True)
        rospy.Subscriber("/" + self.namespaceofcamera + "/qhd/image_color", Image, self.callback)
        # image_depth_sub = rospy.Subscriber("/kinect2/qhd/image_depth_rect",Image,callback_depth)
        try:
            rospy.spin()

        except KeyboardInterrupt:
            print("Shutting down")
        cv2.destroyAllWindows()


if __name__ == '__main__':
    pt = PeopleTracktion("kinect2")
    pt.startnode()
