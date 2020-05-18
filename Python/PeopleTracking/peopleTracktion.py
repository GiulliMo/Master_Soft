from scipy.misc import bytescale
from centroidtracker import CentroidTracker
from imutils.object_detection import non_max_suppression
import face_recognition
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
        self.framebgrsmall = np.empty(0)
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
        self.imagebgr = np.empty(0)
        self.xcenter = 0
        self.ycenter = 0
        self.mindepth = rospy.get_param("/" + namespaceofcamera + "_bridge/min_depth")
        self.maxdepth = rospy.get_param("/" + namespaceofcamera + "_bridge/max_depth")
        self.listofroi = []
        self.pc_list = []
        self.knownfaces = []
        self.pointcloudmsg = 0
        self.counter = 0
        self.OPENCV_OBJECT_TRACKERS = {
            "kcf": cv2.TrackerKCF_create,
            "boosting": cv2.TrackerBoosting_create,
            "mil": cv2.TrackerMIL_create,
            "tld": cv2.TrackerTLD_create,
            "medianflow": cv2.TrackerMedianFlow_create,
            "mosse": cv2.TrackerMOSSE_create
        }

    def processing_rgb(self, msg):
        try:
            self.imagebgr = self.bridge.imgmsg_to_cv2(msg, "bgr8")
            self.framebgrsmall = imutils.resize(self.imagebgr, width=min(400, self.imagebgr.shape[1]))
            self.orig = self.framebgrsmall.copy()
            #cv2.imshow("Frame:anfang", self.framebgrsmall)
            #cv2.waitKey(3)
            self.getdetections()
            self.getids()
            self.getdistance()
            self.getfaces()
        except CvBridgeError as e:
            print(e)
    """
    def callback_depth(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, "16UC1")
            self.frame_depth = imutils.resize(cv_image, width=min(400, cv_image.shape[1]))
            self.frame_depth = bytescale(self.frame_depth)
        except CvBridgeError as e:
            print(e)
    """
    def callback_pointcloud(self, msg):
        self.pointcloudmsg = msg

    def getdetections(self):
        (rects, weights) = self.hog.detectMultiScale(self.framebgrsmall, winStride=(4, 4), padding=(8, 8), scale=1.05)

        for (x, y, w, h) in rects:
            cv2.rectangle(self.orig, (x, y), (x + w, y + h), (0, 0, 255), 2)

        rects = np.array([[x, y, x + w, y + h] for (x, y, w, h) in rects])
        self.detections = non_max_suppression(rects, probs=None, overlapThresh=0.65)
        # draw the final bounding boxes

    def getids(self):
        for (xA, yA, xB, yB) in self.detections:
            cv2.rectangle(self.framebgrsmall, (xA, yA), (xB, yB), (0, 255, 0), 2)

        # update our centroid tracker using the computed set of bounding
        # box rectangles
        objects = self.ct.update(self.detections)
        # loop over the tracked objects
        for (objectID, centroid) in objects.items():
            # draw both the ID of the object and the centroid of the
            # object on the output frame
            text = "ID {}".format(objectID)
            cv2.putText(self.framebgrsmall, text, (centroid[0] - 10, centroid[1] - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5,
                        (0, 255, 0), 2)
            cv2.circle(self.framebgrsmall, (centroid[0], centroid[1]), 4, (0, 255, 0), -1)
        # show the output frame
        #cv2.imshow("Frame", self.framebgrsmall)
        #cv2.waitKey(3)

    def getdistance(self):
        for (xupleft, yupleft, xbellowright, ybellowright) in self.detections:
            #xupleft = 0
            #yupleft = 52
            #xbellowright = 61
            #ybellowright = 191
            shrinkfactor = 5
            self.xcenter = xupleft + (xbellowright - xupleft)/2
            self.ycenter = yupleft + (ybellowright - yupleft)/2
            xsmallrectupleft = xupleft + (self.xcenter - xupleft)*(shrinkfactor - 1)/shrinkfactor
            ysmallrectupleft = yupleft + (self.ycenter - yupleft)*(shrinkfactor - 1)/shrinkfactor
            xsmallrectbellowright = self.xcenter + (xbellowright - self.xcenter)/5
            ysmallrectbellowright = self.ycenter + (ybellowright - self.ycenter)/5
            self.listofroi = []
            self.pc_list = []
            depthsum = 0
            valuecount = 0
            for row in range(ysmallrectupleft, ysmallrectbellowright):
                for column in range(xsmallrectupleft, xsmallrectbellowright):
                    """
                    Erstellen einer Liste mit der entprechenden ROI (im qhd Bild ca. 500 Messpunkte pro Objekt). 
                    Fuer mehr Messpunkte muessen die neuen Koordinaten mit 4.8 multipliziert werden. 
                    Das Verfahren ist dasselbe.
                    """
                    self.listofroi.append([int(column*4.8), int(row*4.8)])

            pc = pc2.read_points(self.pointcloudmsg, skip_nans=True, field_names=("x", "y", "z"), uvs=self.listofroi)
            for p in pc:
                self.pc_list.append([p[0], p[1], p[2]])

            for (x, y, z) in self.pc_list:
                depthsum += z
                valuecount += 1

            if len(self.pc_list) != 0:
                depthaverage = depthsum/valuecount
                #print(depthaverage)


            cv2.circle(self.framebgrsmall, (xupleft, yupleft), 2, (0, 0, 0), -1)
            cv2.circle(self.framebgrsmall, (xbellowright, ybellowright), 2, (0, 0, 0), -1)
            cv2.circle(self.framebgrsmall, (100, 50), 2, (0, 0, 0), -1)
            cv2.rectangle(self.framebgrsmall, (xsmallrectupleft, ysmallrectupleft), (xsmallrectbellowright, ysmallrectbellowright), (0, 255, 0), 2)

        cv2.imshow("Frame..", self.framebgrsmall)
        cv2.waitKey(3)

    def getfaces(self):
        for (xupleft, yupleft, xbellowright, ybellowright) in self.detections:

            img = self.imagebgr[int(yupleft*2.4):int((ybellowright/2)*2.4), int(xupleft*2.4):int(xbellowright*2.4)]
            cv2.imshow("Frame:cut", img)
            cv2.waitKey(3)
            rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
            boxes = face_recognition.face_locations(rgb)
            print(boxes)
            for (top, right, bottom, left) in boxes:
                face = face_recognition.face_encodings(rgb, boxes)[0]
                #if self.counter == 0:
                #    self.knownfaces.append(face)
                #    self.counter += 1
                isknown = face_recognition.compare_faces(self.knownfaces, face, 0.6)
                if isknown == []:
                    self.knownfaces.append(face)
                for index, element in enumerate(isknown):
                    if isknown[index] == True:
                        text = "ID " + str(index)
                        cv2.putText(self.framebgrsmall, text, (left, top),
                                    cv2.FONT_HERSHEY_SIMPLEX, 0.5,
                                    (0, 255, 0), 2)
                        break
                    elif index + 1 == len(isknown):
                        print("b")
                        self.knownfaces.append(face)


                print(face)
                print(self.knownfaces)
                print(isknown)
                cv2.rectangle(self.framebgrsmall, (int(xupleft+left/2.4), int(yupleft+top/2.4)),
                              (int(xupleft+right/2.4), int(yupleft+bottom/2.4)), (0, 255, 0), 2)
                cv2.imshow("Frame:face", self.framebgrsmall)
                cv2.waitKey(3)


    def startnode(self):
        rospy.init_node('listener', anonymous=True)
        rospy.Subscriber("/" + self.namespaceofcamera + "/qhd/image_color", Image, self.processing_rgb)
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
