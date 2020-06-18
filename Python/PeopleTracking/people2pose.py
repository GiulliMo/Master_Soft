from scipy.misc import bytescale
import math
import tf
import threading
from geometry_msgs.msg import PoseStamped

from centroidtracker import CentroidTracker
from imutils.object_detection import non_max_suppression
import face_recognition
import numpy as np
import argparse
import imutils
import cv2
import cv2 as cv
import rospy
import sys
import time
from sensor_msgs.msg import Image, PointCloud2
import sensor_msgs.point_cloud2 as pc2
from cv_bridge import CvBridge, CvBridgeError


## @class Person
# Fuer jede erkannte Person wird ein Objekt dieser Klasse erstellt
class Person:

    def __init__(self):
        ## @var face
        # Gesichtsmerkmale
        self.face = []
        ## @var facerect
        # Koordinaten fuer Interessenbereich fuer das Gesicht
        self.facerect = []
        ## @var rect
        # Koordinaten fuer Rechteck um erkannten Objekt
        self.rect = []
        ## @var camera
        # Name der Kamera, die das Objekt als letztes gesehen hat
        self.camera = ""
        self.xcenterpospixel = 0
        self.ycenterpospixel = 0
        ## @var distance
        # Distanz zum erkannten Objekt
        self.distance = 0
        ## @var localcoordinates
        # Lokale Koordinaten gemessen von der Kamera
        self.localcoordinates = []

    def getrect(self):
        return self.rect

    def getface(self):
        return self.face

    def getxcenterpospixel(self):
        return self.xcenterpospixel


class PeopleRec:
    def __init__(self, namespaceoffrontcamera="", namespaceofbackcamera="", maxdetectionsbeforetrack=5):
        ## @var lock
        # Fuer eventuelles sperren von Threads
        self.lock = threading.Lock()
        ## @var listofpersons
        # Liste aller bekannten Personen
        self.listofpersons = []
        # self.net = cv2.dnn.readNetFromCaffe("deploy.prototxt", "res10_300x300_ssd_iter_140000.caffemodel")
        self.trackers = cv2.MultiTracker_create()
        self.tfbroadcaster = tf.TransformBroadcaster()
        self.hog = cv2.HOGDescriptor()
        self.hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())
        self.net = cv2.dnn.readNetFromCaffe("MobileNetSSD_deploy.prototxt.txt", "MobileNetSSD_deploy.caffemodel")
        self.namespaceoffrontcamera = namespaceoffrontcamera
        self.namespaceofrearcamera = namespaceofbackcamera
        self.bridgefront = CvBridge()
        self.bridgeback = CvBridge()
        self.listofroi = []
        self.listener = []
        self.knownfaces = []
        self.unknownfaces = []
        self.pointcloudmsg = 0
        self.frontframebgrsmall = np.array(0)
        self.rearframebgrsmall = np.array(0)
        self.frontimagebgrqhd = np.array(0)
        self.rearimagebgrqhd = np.array(0)
        """
        self.OPENCV_OBJECT_TRACKERS = {
            "kcf": cv2.TrackerKCF_create,
            "boosting": cv2.TrackerBoosting_create,
            "mil": cv2.TrackerMIL_create,
            "tld": cv2.TrackerTLD_create,
            "medianflow": cv2.TrackerMedianFlow_create,
            "mosse": cv2.TrackerMOSSE_create
        }
        """

    ## Callback der vorderen Kamera.
    # Ohne sneak waere die informationsquelle der eingehenden Daten nicht bekannt.
    # Zur Ersparnis von Rechenzeit werden die Bilder so klein wie moeglich gehalten. Sobald ein Objekt detetktiert
    # wird, dass einer Peron aehnelt, wird die Methode zur Erkennung losgetreten.
    # @param[in] msg Nachricht der Kamera
    def processingqhdfront(self, msg):
            try:
                sneak = "front"
                # print threading.current_thread()
                self.frontimagebgrqhd = self.bridgefront.imgmsg_to_cv2(msg, "bgr8")
                self.frontframebgrsmall = imutils.resize(self.frontimagebgrqhd, width=min(400, self.frontimagebgrqhd.shape[1]))
                #detections = self.getdetections(framebgrsmall)
                #detections = self.trycnn(framebgrsmall)
                #self.managepeople(detections, frontimagebgrqhd, framebgrsmall, sneak)
            except CvBridgeError as e:
                print(e)

    ## Callback der vorderen Kamera.
    # Ohne sneak waere die informationsquelle der eingehenden Daten nicht bekannt.
    # Zur Ersparnis von Rechenzeit werden die Bilder so klein wie moeglich gehalten. Sobald ein Objekt detetktiert
    # wird, dass einer Peron aehnelt, wird die Methode zur Erkennung losgetreten.
    # @param[in] msg Nachricht der Kamera
    def processingqhdback(self, msg):
        try:
            # start = time.time()
            sneak = "back"
            # print threading.current_thread()
            self.rearimagebgrqhd = self.bridgeback.imgmsg_to_cv2(msg, "bgr8")
            self.rearframebgrsmall = imutils.resize(self.rearimagebgrqhd, width=min(400, self.rearimagebgrqhd.shape[1]))
            #detections = self.getdetections(framebgrsmall)
            #detections = self.trycnn(framebgrsmall)
            #self.managepeople(detections, rearimagebgrqhd, framebgrsmall, sneak)
            # self.showpeople(sneak, framebgrsmall)
            # print time.time() - start

        except CvBridgeError as e:
            print(e)

    def trycnn(self, framebgrsmall, sneak):
        """
        CLASSES und COLORS auslagern
        """
        start = time.time()
        CLASSES = ["background", "aeroplane", "bicycle", "bird", "boat",
                   "bottle", "bus", "car", "cat", "chair", "cow", "diningtable",
                   "dog", "horse", "motorbike", "person", "pottedplant", "sheep",
                   "sofa", "train", "tvmonitor"]
        IGNORE = set(["background", "aeroplane", "bicycle", "bird", "boat",
                   "bottle", "bus", "car", "cat", "chair", "cow", "diningtable",
                   "dog", "horse", "motorbike", "pottedplant", "sheep",
                   "sofa", "train", "tvmonitor"])
        COLORS = np.random.uniform(0, 255, size=(len(CLASSES), 3))
        (h, w) = framebgrsmall.shape[:2]
        blob = cv2.dnn.blobFromImage(cv2.resize(framebgrsmall, (300, 300)),
                                     0.007843, (300, 300), 127.5)
        bbox = []
        self.net.setInput(blob)
        detections = self.net.forward()
        for i in np.arange(0, detections.shape[2]):
            # extract the confidence (i.e., probability) associated with
            # the prediction
            confidence = detections[0, 0, i, 2]
            # filter out weak detections by ensuring the `confidence` is
            # greater than the minimum confidence
            if confidence > 0.7:
                # extract the index of the class label from the
                # `detections`
                idx = int(detections[0, 0, i, 1])
                # if the predicted class label is in the set of classes
                # we want to ignore then skip the detection
                if CLASSES[idx] in IGNORE:
                    continue
                # compute the (x, y)-coordinates of the bounding box for
                # the object
                box = detections[0, 0, i, 3:7] * np.array([w, h, w, h])
                (startX, startY, endX, endY) = box.astype("int")
                bbox.append((startX, startY, endX, endY))
                # draw the prediction on the frame
                label = "{}: {:.2f}%".format(CLASSES[idx],
                                             confidence * 100)
                cv2.rectangle(framebgrsmall, (startX, startY), (endX, endY),
                              (255, 0, 255), 2)
                y = startY - 15 if startY - 15 > 15 else startY + 15
                cv2.putText(framebgrsmall, label, (startX, y),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 255), 2)
        cv2.imshow(sneak, framebgrsmall) #Bild eventuell extra abspeichern
        key = cv2.waitKey(1) & 0xFF
        end = time.time() - start
        print("Das CNN hat " + str(end) +"s benoetigt.")
        return bbox

    ## Prueft, ob erkannte Objekte Menschen sind.
    # @param[in] detections Liste von allen erkannten Objekten als Rechteck mit 4 gegebenen Punkten
    # @param[in] imagebgrqhd QHD Bild der Kamera
    # @param[in] framebgrsmall 400x225 Bild der Kamera
    # @param[in] sneak Info ueber Datenherkunft
    def managepeople(self, detections, imagebgrqhd, framebgrsmall, sneak):

        for (xupleft, yupleft, xbellowright, ybellowright) in detections:
            """
            Fuer jedes menschaehnliche Objekt versuche im Interessenbereich ein Gesicht zu erkennen
            """
            incomingface = self.getface(xupleft, yupleft, xbellowright, ybellowright, imagebgrqhd)
            if incomingface is not None:
                """
                Alle Informationen der eingehenden, erkannten Person werden aktualisiert
                """
                knownperson = Person()
                knownperson.rect = [incomingface[0], incomingface[1], incomingface[2], incomingface[3]]
                knownperson.face = incomingface[8]
                knownperson.camera = sneak
                knownperson.facerect = [incomingface[4], incomingface[5], incomingface[6], incomingface[7]]
                knownperson.xcenterpospixel, knownperson.ycenterpospixel, knownperson.distance = self.getdistance(
                    incomingface[0], incomingface[1], incomingface[2], incomingface[3], self.pointcloudmsg)
                knownperson.localcoordinates = self.getxycoordinates(knownperson.xcenterpospixel, framebgrsmall,
                                                                     knownperson.distance)
                print self.getxycoordinates(knownperson.xcenterpospixel, framebgrsmall,
                                            knownperson.distance)
                """
                Wenn der Index des Gesichts gleich der Laenge der Liste der bekannten Personen ist wird eine 
                Person hinzugefuegt. Anderenfalls aktualisiere eine bestehende Person. 
                """
                if len(self.listofpersons) == incomingface[9]:
                    self.listofpersons.append(knownperson)
                else:
                    self.listofpersons[incomingface[9]] = knownperson

        print "Es wurde(n) bisher " + str(len(self.listofpersons)) + " Person(en) registriert"

    def processing_hd(self, msg):
        try:
            imagebgrhd = self.bridge.imgmsg_to_cv2(msg, "bgr8")

            return imagebgrhd
        except CvBridgeError as e:
            print(e)

    def callback_pointcloud(self, msg):
        self.pointcloudmsg = msg

    def getdetections(self, framebgrsmall, sneak):
        start = time.time()
        (rects, weights) = self.hog.detectMultiScale(framebgrsmall, winStride=(4, 4), padding=(0, 0), scale=1.05)
        rects = np.array([[x, y, x + w, y + h] for (x, y, w, h) in rects])
        detections = non_max_suppression(rects, probs=None, overlapThresh=0.65)
        for detection in detections:
            cv2.rectangle(framebgrsmall, (detection[0], detection[1]), (detection[2], detection[3]),
                          (255, 0, 255), 2)

        end = time.time() - start
        cv2.imshow(sneak, framebgrsmall)
        key = cv2.waitKey(1) & 0xFF
        print("Das HOG hat " + str(end) + "s benoetigt.")
        return detections

    def getdistance(self, xupleft, yupleft, xbellowright, ybellowright, pointcloudmsg):
        shrinkfactor = 7
        xcenter = xupleft + (xbellowright - xupleft) / 2
        ycenter = yupleft + (ybellowright - yupleft) / 2
        xsmallrectupleft = xupleft + (xcenter - xupleft) * (shrinkfactor - 1) / shrinkfactor
        ysmallrectupleft = yupleft + (ycenter - yupleft) * (shrinkfactor - 1) / shrinkfactor
        xsmallrectbellowright = xcenter + (xbellowright - xcenter) / shrinkfactor
        ysmallrectbellowright = ycenter + (ybellowright - ycenter) / shrinkfactor
        listofroi = []
        pc_list = []
        depthsum = 0
        for row in range(int(ysmallrectupleft * 4.8), int(ysmallrectbellowright * 4.8)):
            for column in range(int(xsmallrectupleft * 4.8), int(xsmallrectbellowright * 4.8)):
                listofroi.append([int(column), int(row)])

        pc = pc2.read_points(pointcloudmsg, skip_nans=True, field_names=("x", "y", "z"), uvs=listofroi)
        for p in pc:
            pc_list.append([p[0], p[1], p[2]])

        for (x, y, z) in pc_list:
            depthsum += z

        if len(pc_list) != 0:
            depthaverage = depthsum / len(pc_list)
            return xcenter, ycenter, depthaverage
            # print(depthaverage, len(self.pc_list))

    def getface(self, xupleft, yupleft, xbellowright, ybellowright, image):
        if len(image) == 540:
            factor = 2.4
        elif len(image) == 1080:
            factor = 4.8
        else:
            factor = 1

        """
        ROI der Person wird an das Gesicht angepasst, um Rechenzeit zu sparen.
        """
        #facexupleft = int((xupleft + ((xbellowright - xupleft) / 4)) * factor)
        facexupleft = int(xupleft * factor)
        #faceyupleft = int((yupleft + ((ybellowright - yupleft) / 10)) * factor)
        faceyupleft = int(yupleft * factor)
        #facexbottomright = int((xbellowright - ((xbellowright - xupleft) / 4)) * factor)
        facexbottomright = int(xbellowright * factor)
        #faceybottomright = int((yupleft + ((ybellowright - yupleft) / 4)) * factor)
        faceybottomright = int((yupleft + ((ybellowright - yupleft) / 2)) * factor)
        imagecut = image[faceyupleft:faceybottomright, facexupleft:facexbottomright]
        rgb = cv2.cvtColor(imagecut, cv2.COLOR_BGR2RGB)
        boxes = face_recognition.face_locations(rgb)
        print(boxes)
        """
        Fuer jedes erkannte Gesicht wird geprueft, ob es bekannt ist. Wenn nicht wird ein neues hinzugefuegt
        und wenn die Liste aller bekannten Gesichter leer ist wird das erste Gesicht sofort hinzugefuegt.  
        """

        for (top, right, bottom, left) in boxes:
            face = face_recognition.face_encodings(rgb, boxes)[0]
            isknown = face_recognition.compare_faces(self.knownfaces, face, 0.5)
            print(isknown)
            if not isknown:
                self.knownfaces.append(face)
                isknown.append(True)
                print("Neues Gesicht mit der ID" + str(len(self.knownfaces) - 1) + " hinzugefuegt")
            for index, element in enumerate(isknown):
                print(index)
                # isknown[index] = False #spaeter loeschen
                if isknown[index]:
                    print("ID " + str(index) + " wurde erkannt")
                    return xupleft, yupleft, xbellowright, ybellowright, top, right, bottom, left, face, index;

                elif index + 1 == len(isknown):
                    self.checkunknownfaces(face)
                    return None

    def checkunknownfaces(self, face, toknownfacesthreshold=3):
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

            print("Unb. Gesicht wurde " + str(count + 1) + " Mal erkannt")

    ## Veroeffentlicht die Position der zuletzt gesehenen Person
    # @todo Veroeffentlichen der globalen Koordinaten
    def publishposition(self):
        if self.listofpersons:
            lastperson = self.listofpersons[-1]
            try:
                (trans, rot) = self.listener.lookupTransform('/map', '/cam_' + lastperson.camera, rospy.Time(0))
                msg = PoseStamped()
                msg.header.frame_id = "cam_" + lastperson.camera
                msg.pose.position.y = -lastperson.localcoordinates[0]
                msg.pose.position.x = lastperson.localcoordinates[1]
                msg.header.stamp = rospy.Time.now()
                self.publisher.publish(msg)

            except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
                print("No tf message received...")

    def getxycoordinates(self, xcenter, framebgrsmall, depthaverage):
        fovhorizontal = 80
        fovhorizontaldegree = fovhorizontal * (math.pi / 180)
        pixelhorizontal = len(framebgrsmall[1])
        focallength = pixelhorizontal / (2 * math.tan(fovhorizontaldegree / 2))
        xpospersonlocal = ((xcenter - (pixelhorizontal / 2)) / focallength) * depthaverage
        ypospersonlocal = math.sqrt(depthaverage ** 2 - xpospersonlocal ** 2)

        return [xpospersonlocal, ypospersonlocal]
        # print(self.xposperson, self.yposperson)

    def startnode(self):
        rospy.init_node('listener', anonymous=True)
        self.listener = tf.TransformListener()
        self.publisher = rospy.Publisher('people', PoseStamped, queue_size=10)
        if self.namespaceoffrontcamera != "":
            rospy.Subscriber("/" + self.namespaceoffrontcamera + "/qhd/image_color", Image, self.processingqhdfront)
            rospy.Subscriber("/" + self.namespaceoffrontcamera + "/hd/points", PointCloud2, self.callback_pointcloud)

        if self.namespaceofrearcamera != "":
            rospy.Subscriber("/" + self.namespaceofrearcamera + "/qhd/image_color", Image, self.processingqhdback)
            rospy.Subscriber("/" + self.namespaceofrearcamera + "/hd/points", PointCloud2, self.callback_pointcloud)

        # self.publisher = rospy.Publisher('/tracked_people/pose', PoseStamped, queue_size=10)

        try:
            rospy.sleep(4)
            # rospy.spin()
            while not rospy.is_shutdown():
                """
                Hier kann man seriell arbeiten
                """
                start = time.time()
                if self.namespaceoffrontcamera != "":
                    detectionsfront = self.trycnn(self.frontframebgrsmall, "front")
                    print(detectionsfront)
                    self.managepeople(detectionsfront, self.frontimagebgrqhd, self.frontframebgrsmall, "front")

                if self.namespaceofrearcamera != "":
                    detectionsrear = self.trycnn(self.rearframebgrsmall, "back")
                    print(detectionsrear)
                    self.managepeople(detectionsrear, self.rearimagebgrqhd, self.rearframebgrsmall, "back")

                self.publishposition()
                end = time.time() - start
                print("Die letzte Iteration dauerte " + str(end) + "s.")
            print("\nShutdown...")

        except KeyboardInterrupt:
            print("Shutting down")
        cv.destroyAllWindows()
        cv2.destroyAllWindows()


if __name__ == '__main__':
    pt = PeopleRec("kinect2", "kinect1")
    pt.startnode()
