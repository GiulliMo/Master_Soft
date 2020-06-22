
import math
import tf
import threading
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
    def __init__(self, namespaceoffrontcamera="", namespaceofrearcamera="", maxdetectionsbeforetrack=5):
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
        self.namespaceofrearcamera = namespaceofrearcamera
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
                self.frontimagebgrqhd = self.bridgefront.imgmsg_to_cv2(msg, "bgr8")
                self.frontframebgrsmall = imutils.resize(self.frontimagebgrqhd, width=min(400, self.frontimagebgrqhd.shape[1]))

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
            self.rearimagebgrqhd = self.bridgeback.imgmsg_to_cv2(msg, "bgr8")
            self.rearframebgrsmall = imutils.resize(self.rearimagebgrqhd, width=min(400, self.rearimagebgrqhd.shape[1]))
            # print time.time() - start

        except CvBridgeError as e:
            print(e)

    def getdetectionsbyhog(self, framebgrsmall, sneak):
        start = time.time()
        # Erstellung der Boundingbox
        (rects, weights) = self.hog.detectMultiScale(framebgrsmall, winStride=(4, 4), padding=(0, 0), scale=1.05)
        rects = np.array([[x, y, x + w, y + h] for (x, y, w, h) in rects])
        end = time.time() - start
        # Fuer sich ueberschneidende Rechtecke unterdruecke diese
        detections = non_max_suppression(rects, probs=None, overlapThresh=0.65)
        # Zur Visualisierung der erkannten Objekte
        for detection in detections:
            cv2.rectangle(framebgrsmall, (detection[0], detection[1]), (detection[2], detection[3]),
                          (255, 0, 255), 2)

        # cv2.imshow(sneak, framebgrsmall)
        # key = cv2.waitKey(1) & 0xFF
        print("Das HOG hat " + str(end) + "s benoetigt.")
        return detections, framebgrsmall

    def getdetectionsbycnn(self, framebgrsmall, sneak):
        start = time.time()
        CLASSES = ["background", "aeroplane", "bicycle", "bird", "boat",
                   "bottle", "bus", "car", "cat", "chair", "cow", "diningtable",
                   "dog", "horse", "motorbike", "person", "pottedplant", "sheep",
                   "sofa", "train", "tvmonitor"]
        IGNORE = set(["background", "aeroplane", "bicycle", "bird", "boat",
                   "bottle", "bus", "car", "cat", "chair", "cow", "diningtable",
                   "dog", "horse", "motorbike", "pottedplant", "sheep",
                   "sofa", "train", "tvmonitor"])
        (h, w) = framebgrsmall.shape[:2]
        blob = cv2.dnn.blobFromImage(cv2.resize(framebgrsmall, (300, 300)),
                                     0.007843, (300, 300), 127.5)
        bbox = []
        self.net.setInput(blob)
        detections = self.net.forward()
        end = time.time() - start
        for i in np.arange(0, detections.shape[2]):
            # Konfidenz berechnen
            confidence = detections[0, 0, i, 2]
            # Ab der gegebenen Konfidenz wird das Objekt beruecksichtigt
            if confidence > 0.7:
                # Index der Detection
                idx = int(detections[0, 0, i, 1])
                # Wenn Klassen erkannt wurden, die auf der Ignore-Liste stehen, ignoriere
                if CLASSES[idx] in IGNORE:
                    continue
                #Erstellung der Boundingbox
                box = detections[0, 0, i, 3:7] * np.array([w, h, w, h])
                (startX, startY, endX, endY) = abs(box.astype("int"))
                bbox.append((startX, startY, endX, endY))
                label = "{}: {:.2f}%".format(CLASSES[idx],
                                             confidence * 100)
                cv2.rectangle(framebgrsmall, (startX, startY), (endX, endY),
                              (255, 0, 255), 2)
                y = startY - 15 if startY - 15 > 15 else startY + 15
                cv2.putText(framebgrsmall, label, (startX, y),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 255), 2)
        #cv2.imshow(sneak, framebgrsmall) #Bild eventuell extra abspeichern
        #key = cv2.waitKey(1) & 0xFF
        print("Das CNN hat " + str(end) +"s benoetigt.")
        return bbox, framebgrsmall

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

        cv2.imshow(sneak, framebgrsmall)
        key = cv2.waitKey(1) & 0xFF
        print "Es wurde(n) bisher " + str(len(self.listofpersons)) + " Person(en) registriert"

    def processing_hd(self, msg):
        try:
            imagebgrhd = self.bridge.imgmsg_to_cv2(msg, "bgr8")
            return imagebgrhd

        except CvBridgeError as e:
            print(e)

    def callback_pointcloud(self, msg):
        self.pointcloudmsg = msg

    def getdistance(self, xupleft, yupleft, xbellowright, ybellowright, pointcloudmsg):

        #Kleines Rechteck wird erstellt und aus der der HD-PointCloud geschnitten

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

        #Region of interest in Form einer Liste fuer eventuelle spaetere Umstrukturierung

        for row in range(int(ysmallrectupleft * 4.8), int(ysmallrectbellowright * 4.8)):
            for column in range(int(xsmallrectupleft * 4.8), int(xsmallrectbellowright * 4.8)):
                listofroi.append([int(column), int(row)])

        #Alle relevanten (NaNs werden aussortiert) Points werden aus der anliegenden PointCloud gezogen

        pc = pc2.read_points(pointcloudmsg, skip_nans=True, field_names=("x", "y", "z"), uvs=listofroi)
        for p in pc:
            pc_list.append([p[0], p[1], p[2]])

        #Alle Tiefen werden aufsummiert

        for (x, y, z) in pc_list:
            depthsum += z

        #Mittelwert wird gebildet und zusammen mit den entsprechenden Pixelkoordinaten ausgegeben

        if len(pc_list) != 0:
            depthaverage = depthsum / len(pc_list)
            return xcenter, ycenter, depthaverage
            # print(depthaverage, len(self.pc_list))

    ## Ordnet Gesichter zu
    def getface(self, xupleft, yupleft, xbellowright, ybellowright, image):

        # Groesse des Bildes wird erkannt und der Faktor der Umrechnung entsprechend angepasst

        if len(image) == 540:
            factor = 2.4
        elif len(image) == 1080:
            factor = 4.8
        else:
            factor = 1

        # ROI der Person wird zur Ersparnis der Rechenzeit an das Gesicht angepasst
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

        # Fuer jedes erkannte Gesicht wird geprueft, ob es bekannt ist. Wenn nicht wird ein neues hinzugefuegt
        # und wenn die Liste aller bekannten Gesichter leer ist wird das erste Gesicht sofort hinzugefuegt.

        for (top, right, bottom, left) in boxes:
            # Speichere das Gesicht in der Bbox. Wenn kein Gesicht dann None.
            face = face_recognition.face_encodings(rgb, boxes)[0]
            # Gehoert das eingehende Gesicht zu
            isknown = face_recognition.compare_faces(self.knownfaces, face, 0.5)
            print(isknown)
            # Das erste Gesicht wird sofort abgespeichert
            if not isknown:
                self.knownfaces.append(face)
                isknown.append(True)
                print("Neues Gesicht mit der ID" + str(len(self.knownfaces) - 1) + " hinzugefuegt")
            # Checke alle Gesichter ob und welches erkennt wurde, wenn nicht, gehoert es zu den unbekannten?
            for index, element in enumerate(isknown):
                print(index)
                if isknown[index]:
                    print("ID " + str(index) + " wurde erkannt")
                    return xupleft, yupleft, xbellowright, ybellowright, top, right, bottom, left, face, index;

                elif index + 1 == len(isknown):
                    self.checkunknownfaces(face)
                    return None

    def checkunknownfaces(self, face, toknownfacesthreshold=3):
        print("Unbekanntes Gesicht wird geprueft...")
        # Wenn kein unbekanntes Gesicht vorhanden fuege es hinzu
        if not self.unknownfaces:
            self.unknownfaces.append(face)

        count = 0
        isunknown = face_recognition.compare_faces(self.unknownfaces, face, 0.4)
        print(isunknown)
        for index, element in enumerate(isunknown):
            # Wenn eingehendes Gesicht zu unbekannten Gesichtern passt zaehle hoch
            if isunknown[index]:
                count += 1
            # Wenn nicht zaehle runter
            else:
                count = 0
            # Wenn das Gesicht oft genug erkannt wurde fuege es zu bekannten Gesichtern hinzugit status
            if count == toknownfacesthreshold:
                self.knownfaces.append(face)
                print("Neues Gesicht mit der ID " + str(len(self.knownfaces) - 1) + " hinzugefuegt")
                break
            # Wenn keins der unbekannten Gesichter dem eingehenden Gesicht aehnelt, erweitere die Liste
            if index + 1 == len(isunknown):
                self.unknownfaces.append(face)
            # Wenn das Gesicht oft genug erkannt worden ist, loesche es von den unbekannten Geischtern
            if index + 1 == toknownfacesthreshold:
                self.unknownfaces.remove(self.unknownfaces[0])

            print("Unb. Gesicht wurde " + str(count + 1) + " Mal erkannt")

    ## Veroeffentlicht die Position der zuletzt gesehenen Person
    # @todo Veroeffentlichen der globalen Koordinaten
    # @todo Veroeffentlichen der zuletzt gesehen Person nicht der zuletzt hinzugefuegten Person
    def publishposition(self):
        if self.listofpersons:
            lastperson = self.listofpersons[-1]
            try:
                # Auslesen des aktuellen Standorts der Kameras im Bezug zum Kartenkoordinatensystem
                (trans, rot) = self.listener.lookupTransform('/map', '/cam_' + lastperson.camera, rospy.Time(0))
                # Erstellen der ausgehenden Nachricht
                msg = PoseStamped()
                msg.header.frame_id = "cam_" + lastperson.camera
                msg.pose.position.y = -lastperson.localcoordinates[0]
                msg.pose.position.x = lastperson.localcoordinates[1]
                msg.header.stamp = rospy.Time.now()
                self.publisher.publish(msg)
            # Wenn Fehler auf der Seite der ROS Software bestehen, fange diese ab
            except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
                print("No tf message received...")

    ## Berechnung der lokalen X/Y-Koordinaten gemessen von der jeweiligen Kamera zum Objekt mithilfe der
    ## intrinsischen Kamerainformationen
    def getxycoordinates(self, xcenter, framebgrsmall, depthaverage):
        fovhorizontal = 80
        fovhorizontaldegree = fovhorizontal * (math.pi / 180)
        pixelhorizontal = len(framebgrsmall[1])
        focallength = pixelhorizontal / (2 * math.tan(fovhorizontaldegree / 2))
        xpospersonlocal = ((xcenter - (pixelhorizontal / 2)) / focallength) * depthaverage
        ypospersonlocal = math.sqrt(depthaverage ** 2 - xpospersonlocal ** 2)

        return [xpospersonlocal, ypospersonlocal]
        # print(self.xposperson, self.yposperson)

    ## Zusammensetzung des Knotens. Alle rospy.-Befehle werden seriell bearbeitet. Die in der While-Schleife
    ## befindlichen Befehle werden widerrum seriell barbeitet.

    def startnode(self):
        rospy.init_node('listener', anonymous=True)
        self.listener = tf.TransformListener()
        self.publisher = rospy.Publisher('people', PoseStamped, queue_size=10)
        rospy.Subscriber("/" + self.namespaceoffrontcamera + "/hd/points", PointCloud2, self.callback_pointcloud)
        if self.namespaceoffrontcamera != "":
            rospy.Subscriber("/" + self.namespaceoffrontcamera + "/qhd/image_color", Image, self.processingqhdfront)

        if self.namespaceofrearcamera != "":
            rospy.Subscriber("/" + self.namespaceofrearcamera + "/qhd/image_color", Image, self.processingqhdback)

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
                    detectionsfront, imagefront = self.getdetectionsbycnn(self.frontframebgrsmall, "front")
                    print(detectionsfront)
                    self.managepeople(detectionsfront, self.frontimagebgrqhd, imagefront, "front")

                if self.namespaceofrearcamera != "":
                    detectionsrear, imagerear = self.getdetectionsbycnn(self.rearframebgrsmall, "back")
                    print(detectionsrear)
                    self.managepeople(detectionsrear, self.rearimagebgrqhd, imagerear, "back")

                self.publishposition()
                end = time.time() - start
                print("Die letzte Iteration dauerte " + str(end) + "s.")
            print("\nShutdown...")

        except KeyboardInterrupt:
            print("\nShutting down")

        cv2.destroyAllWindows()


if __name__ == '__main__':
    pt = PeopleRec("kinect2", "kinect1")
    pt.startnode()
