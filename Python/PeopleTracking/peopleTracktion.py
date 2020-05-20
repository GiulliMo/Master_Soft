from scipy.misc import bytescale
import math
import tf

from centroidtracker import CentroidTracker
from imutils.object_detection import non_max_suppression
import face_recognition
import numpy as np
import argparse
import imutils
import cv2
import rospy
import sys
import time
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
        self.imagebgrqhd = np.empty(0)
        self.imagebgrhd = np.empty(0)
        self.xcenter = 0
        self.ycenter = 0
        self.xposperson = 0
        self.yposperson = 0
        self.depthaverage = 0
        self.mindepth = rospy.get_param("/" + namespaceofcamera + "_bridge/min_depth")
        self.maxdepth = rospy.get_param("/" + namespaceofcamera + "_bridge/max_depth")
        self.listofroi = []
        self.listener = []
        self.pc_list = []
        self.knownfaces = []
        self.unknownfaces = []
        self.pointcloudmsg = 0
        self.OPENCV_OBJECT_TRACKERS = {
            "kcf": cv2.TrackerKCF_create,
            "boosting": cv2.TrackerBoosting_create,
            "mil": cv2.TrackerMIL_create,
            "tld": cv2.TrackerTLD_create,
            "medianflow": cv2.TrackerMedianFlow_create,
            "mosse": cv2.TrackerMOSSE_create
        }

    def processing_qhd(self, msg):
        try:
            self.imagebgrqhd = self.bridge.imgmsg_to_cv2(msg, "bgr8")
            self.framebgrsmall = imutils.resize(self.imagebgrqhd, width=min(400, self.imagebgrqhd.shape[1]))
            # self.orig = self.framebgrsmall.copy()
            cv2.imshow("QHD frame of " + self.namespaceofcamera, self.framebgrsmall)
            cv2.waitKey(3)
            # start = time.time()
            self.getdetections()
            self.getbodyid()
            self.getdistance()
            self.getfaceid()
            self.gettransforms()
            self.getxycoordinates()
            # ende = time.time()
            # print(str(ende - start))
        except CvBridgeError as e:
            print(e)

    def processing_hd(self, msg):
        try:
            self.imagebgrhd = self.bridge.imgmsg_to_cv2(msg, "bgr8")
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
        (rects, weights) = self.hog.detectMultiScale(self.framebgrsmall, winStride=(4, 4), padding=(8, 8), scale=1.05)

        for (x, y, w, h) in rects:
            cv2.rectangle(self.orig, (x, y), (x + w, y + h), (0, 0, 255), 2)

        rects = np.array([[x, y, x + w, y + h] for (x, y, w, h) in rects])
        self.detections = non_max_suppression(rects, probs=None, overlapThresh=0.65)

    def getbodyid(self):
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

    def getdistance(self):
        for (xupleft, yupleft, xbellowright, ybellowright) in self.detections:
            shrinkfactor = 7
            self.xcenter = xupleft + (xbellowright - xupleft) / 2
            self.ycenter = yupleft + (ybellowright - yupleft) / 2
            #print(self.xcenter, self.ycenter)
            xsmallrectupleft = xupleft + (self.xcenter - xupleft) * (shrinkfactor - 1) / shrinkfactor
            ysmallrectupleft = yupleft + (self.ycenter - yupleft) * (shrinkfactor - 1) / shrinkfactor
            xsmallrectbellowright = self.xcenter + (xbellowright - self.xcenter) / shrinkfactor
            ysmallrectbellowright = self.ycenter + (ybellowright - self.ycenter) / shrinkfactor
            self.listofroi = []
            self.pc_list = []
            depthsum = 0
            for row in range(int(ysmallrectupleft * 4.8), int(ysmallrectbellowright * 4.8)):
                for column in range(int(xsmallrectupleft * 4.8), int(xsmallrectbellowright * 4.8)):
                    # cv2.circle(self.framebgrsmall, (column, row), 2, (255, 255, 0), -1) # Debug
                    self.listofroi.append([int(column), int(row)])

            pc = pc2.read_points(self.pointcloudmsg, skip_nans=True, field_names=("x", "y", "z"), uvs=self.listofroi)
            for p in pc:
                self.pc_list.append([p[0], p[1], p[2]])

            for (x, y, z) in self.pc_list:
                depthsum += z

            if len(self.pc_list) != 0:
                self.depthaverage = depthsum / len(self.pc_list)
                #print(depthaverage, len(self.pc_list))

            cv2.circle(self.framebgrsmall, (xupleft, yupleft), 2, (0, 0, 0), -1)
            cv2.circle(self.framebgrsmall, (xbellowright, ybellowright), 2, (0, 0, 0), -1)
            cv2.rectangle(self.framebgrsmall, (xsmallrectupleft, ysmallrectupleft),
                          (xsmallrectbellowright, ysmallrectbellowright), (0, 255, 0), 2)

        cv2.imshow("Rects used for distance measuring. " + self.namespaceofcamera, self.framebgrsmall)
        cv2.waitKey(3)

    def getfaceid(self):
        image = self.imagebgrqhd
        if len(image) == 540:
            factor = 2.4
        elif len(image) == 1080:
            factor = 4.8
        for (xupleft, yupleft, xbellowright, ybellowright) in self.detections:
            # print(int(xupleft * factor), int(yupleft * factor), int(xbellowright * factor), int((yupleft + ((ybellowright - yupleft) / 3)) * factor), factor)
            """
            ROI der Person wird an das Gesicht angepasst, um Rechenzeit zu sparen.
            """
            facexupleft = int((xupleft + ((xbellowright - xupleft) / 4)) * factor)
            faceyupleft = int((yupleft + ((ybellowright - yupleft) / 10)) * factor)
            facexbottomright = int((xbellowright - ((xbellowright - xupleft) / 4)) * factor)
            faceybottomright = int((yupleft + ((ybellowright - yupleft) / 4)) * factor)
            # imagecut = image[int(yupleft * factor):int((yupleft + ((ybellowright - yupleft) / 3)) * factor), int(xupleft * factor):int(xbellowright * factor)]
            imagecut = image[faceyupleft:faceybottomright, facexupleft:facexbottomright]
            cv2.imshow("QHD recognized faces of " + self.namespaceofcamera, imagecut)
            cv2.waitKey(3)
            rgb = cv2.cvtColor(imagecut, cv2.COLOR_BGR2RGB)
            boxes = face_recognition.face_locations(rgb)
            # print(boxes)
            """
            Fuer jedes erkannte Gesicht wird geprueft, ob es bekannt ist. Wenn nicht wird ein neues hinzugefuegt
            und wenn die Liste aller bekannten Gesichter leer ist wird das erste Gesicht sofort hinzugefuegt.  
            """
            for (top, right, bottom, left) in boxes:
                face = face_recognition.face_encodings(rgb, boxes)[0]
                isknown = face_recognition.compare_faces(self.knownfaces, face, 0.5)
                if isknown == []:
                    self.knownfaces.append(face)
                    print("Neues Gesicht mit der ID" + str(len(self.knownfaces) - 1) + " hinzugefuegt")

                for index, element in enumerate(isknown):
                    # print(index, isknown[index], element, len(isknown))

                    if isknown[index] == True:
                        print("ID " + str(index) + " wurde erkannt")
                        text = "ID " + str(index)
                        cv2.putText(self.framebgrsmall, text, (int(facexupleft / factor), int(faceyupleft / factor)),
                                    cv2.FONT_HERSHEY_SIMPLEX, 0.5,
                                    (0, 255, 0), 2)
                        break

                    elif index + 1 == len(isknown):
                        # self.knownfaces.append(face)
                        self.checkunknownfaces(face)

                cv2.rectangle(self.framebgrsmall, (int(facexupleft / factor), int(faceyupleft / factor)),
                              (int(facexbottomright / factor), int(faceybottomright / factor)), (0, 255, 0), 2)
                cv2.imshow("QHD frame of last seen face", self.framebgrsmall)
                cv2.waitKey(3)

    def checkunknownfaces(self, face, toknownfacesthreshold=5):
        print("Unbekanntes Gesicht wird geprueft...")

        if not self.unknownfaces:
            self.unknownfaces.append(face)

        count = 0
        isunknown = face_recognition.compare_faces(self.unknownfaces, face, 0.4)
        print(isunknown)
        for index, element in enumerate(isunknown):
            if isunknown[index]:
                count += 1

            else:
                count = 0

            if count == toknownfacesthreshold:
                self.knownfaces.append(face)
                print("Neues Gesicht mit der ID " + str(len(self.knownfaces) - 1) + " hinzugefuegt")
                break

            if index + 1 == len(isunknown):
                self.unknownfaces.append(face)

            if index + 1 == toknownfacesthreshold:
                self.unknownfaces.remove(self.unknownfaces[0])

            print("Unb. Gesicht wurde " + str(count) + " Mal erkannt")

    def gettransforms(self):
        try:
            (trans, rot) = self.listener.lookupTransform('/map', '/cam_front', rospy.Time(0))
            #print(trans, rot)
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            print("No tf message received...")

    def getxycoordinates(self):
        fovhorizontal = 75
        fovhorizontaldegree = fovhorizontal*(math.pi/180)
        pixelhorizontal = len(self.framebgrsmall[1])
        focallength = pixelhorizontal / (2 * math.tan(fovhorizontaldegree/2))
        self.xposperson = ((self.xcenter-(pixelhorizontal/2))/focallength) * self.depthaverage
        self.yposperson = math.sqrt(self.depthaverage**2 - self.xposperson**2)
        print(self.xposperson, self.yposperson)

    def startnode(self):
        rospy.init_node('listener', anonymous=True)
        rospy.Subscriber("/" + self.namespaceofcamera + "/qhd/image_color", Image, self.processing_qhd)
        self.listener = tf.TransformListener()
        # rospy.Subscriber("/" + self.namespaceofcamera + "/hd/image_color", Image, self.processing_hd)
        rospy.Subscriber("/" + self.namespaceofcamera + "/hd/points", PointCloud2, self.callback_pointcloud)
        # rospy.Subscriber("/" + self.namespaceofcamera + "/qhd/image_depth_rect", Image, self.callback_depth)
        # rospy.Subscriber("/" + self.namespaceofcamera + "/hd/points", PointCloud2, self.callback_pointcloud)
        try:
            rospy.spin()
            print("\nShutdown...")

        except KeyboardInterrupt:
            print("Shutting down")
        cv2.destroyAllWindows()


if __name__ == '__main__':
    pt = PeopleTracktion("kinect2")
    pt.startnode()
