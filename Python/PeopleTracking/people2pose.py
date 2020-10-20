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

class PeopleRec:
    def __init__(self, namespaceoffrontcamera="", namespaceofrearcamera="", maxdetectionsbeforetrack=5):
        # Liste aller bekannten Personen
        self.listofpersons = []
        self.tfbroadcaster = transform.TransformBroadcaster()
        self.namespaceoffrontcamera = namespaceoffrontcamera
        self.namespaceofrearcamera = namespaceofrearcamera
        self.bridgefront = CvBridge()
        self.bridgeback = CvBridge()
        self.listofroi = []
        self.listener = []
        self.pointcloudmsg = 0
        self.frontframebgrsmall = np.array(0)
        self.rearframebgrsmall = np.array(0)
        self.frontimagebgrqhd = np.array(0)
        self.rearimagebgrqhd = np.array(0)
        self.detections = detections("tflite")
        self.face = face()
        self.talk = talk()
        self.dataoperations = dataoperations()
        self.slowdown = True


    # Callback der vorderen Kamera
    def processingqhdfront(self, msg):
        try:
            sneak = "front"
            self.frontimagebgrqhd = self.bridgefront.imgmsg_to_cv2(msg, "bgr8")

        except CvBridgeError as e:
            print(e)

    # Callback der hinteren Kamera.
    def processingqhdrear(self, msg):
        try:
            sneak = "back"
            self.rearimagebgrqhd = self.bridgeback.imgmsg_to_cv2(msg, "bgr8")

        except CvBridgeError as e:
            print(e)

    # Callback der SD-PointCloud
    def callback_pointcloud(self, msg):
        self.pointcloudmsg = msg

    #
    def managepeople(self, detections, imagebgrqhd, sneak):
        framebgrsmall = imutils.resize(imagebgrqhd, width=min(400, imagebgrqhd.shape[1]))

        for (xupleft, yupleft, xbellowright, ybellowright) in detections:
            """
            Fuer jedes menschenaehnliche Objekt versuche im Interessenbereich ein Gesicht zu erkennen
            """
            incomingface = self.face.getface(xupleft, yupleft, xbellowright, ybellowright, imagebgrqhd, self.listofpersons)

            if incomingface is not None:
                # Alle Informationen der eingehenden, erkannten Person werden aktualisiert
                knownperson = ppl()
                knownperson.name = ""
                knownperson.timestamp = time.time()
                knownperson.rect = [incomingface[0], incomingface[1], incomingface[2], incomingface[3]]
                knownperson.face = incomingface[8]
                knownperson.camera = sneak
                knownperson.facerect = [incomingface[4], incomingface[5], incomingface[6], incomingface[7]]
                knownperson.xcenterpospixel, knownperson.ycenterpospixel, knownperson.distance = self.getdistance(
                    incomingface[0], incomingface[1], incomingface[2], incomingface[3], self.pointcloudmsg, sneak)
                knownperson.localcoordinates = self.getxycoordinates(knownperson.xcenterpospixel, framebgrsmall,
                                                                     knownperson.distance)
                #print(self.getxycoordinates(knownperson.xcenterpospixel, framebgrsmall, knownperson.distance))

                # Wenn der Index des Gesichts gleich der Laenge der Liste der bekannten Personen ist wird eine
                # Person hinzugefuegt. Anderenfalls aktualisiere eine bestehende Person.
                if len(self.listofpersons) == incomingface[9]:
                    self.talk.newperson()
                    knownperson.name = raw_input("Name: ")
                    if knownperson.name == "":
                        break
                    self.talk.regcompleted(knownperson.name)
                    self.listofpersons.append(knownperson)
                    knownperson.getinformation("Neue")
                else:
                    knownperson.face = self.listofpersons[incomingface[9]].face
                    knownperson.name = self.listofpersons[incomingface[9]].name
                    self.listofpersons[incomingface[9]] = knownperson
                    knownperson.getinformation("Bekannte")

        print("Es wurde(n) bisher " + str(len(self.listofpersons)) + " Person(en) registriert")

    # Messung der absoluten Distanz von der Kamera zur Person
    def getdistance(self, xupleft, yupleft, xbellowright, ybellowright, pointcloudmsg, sneak):
        # Kleines Rechteck wird erstellt und aus der der HD-PointCloud geschnitten. Dabei ist factor der verkleinerungsfaktor.
        factor = 4
        xcenter = xupleft + (xbellowright - xupleft) / 2
        ycenter = yupleft + (ybellowright - yupleft) / 2
        xsmallrectupleft = int(xcenter - ((xcenter - xupleft) / factor))
        ysmallrectupleft = int(ycenter - ((ycenter - yupleft) / factor))
        xsmallrectbellowright = int(xcenter + ((xbellowright - xcenter) / factor))
        ysmallrectbellowright = int(ycenter + ((ybellowright - ycenter) / factor))
        listofroi = []
        pc_list = []
        depthsum = 0

        # Region of interest in Form einer Liste fuer eventuelle spaetere Umstrukturierung
        for column in range(int(ysmallrectupleft*0.5333), int(ysmallrectbellowright*0.5333)):
            for row in range(int(xsmallrectupleft*0.7851), int(xsmallrectbellowright*0.7851)):
                listofroi.append([int(column), int(row)])
        if sneak == "front":
            cv2.rectangle(self.frontimagebgrqhd, (ysmallrectupleft, xsmallrectupleft), (ysmallrectbellowright, xsmallrectbellowright), (255, 0, 0), 2)
            cv2.imshow("roi", self.frontimagebgrqhd)
        if sneak == "back":
            cv2.rectangle(self.rearimagebgrqhd, (ysmallrectupleft, xsmallrectupleft), (ysmallrectbellowright, xsmallrectbellowright), (255, 0, 0), 2)
            cv2.imshow("roi", self.rearimagebgrqhd)
        key = cv2.waitKey(1000)

        # print(type(pointcloudmsg))
        # Alle relevanten (NaNs werden aussortiert) Points werden aus der anliegenden PointCloud gezogen
        pc = pc2.read_points(pointcloudmsg, skip_nans=True, field_names=("x", "y", "z"), uvs=listofroi)
        for p in pc:
            pc_list.append([p[0], p[1], p[2]])

        # Alle Tiefen werden aufsummiert
        for (x, y, z) in pc_list:
            depthsum += z

        #Mittelwert wird gebildet und zusammen mit den entsprechenden Pixelkoordinaten ausgegeben
        if len(pc_list) != 0:
            depthaverage = depthsum / len(pc_list)
            print(depthaverage, xcenter, ycenter)
            return xcenter, ycenter, depthaverage


    ## Veroeffentlicht die Position der zuletzt gesehenen Person
    def publishposition(self):
        if self.listofpersons:
            for index, person in enumerate(self.listofpersons):
                if index == 0:
                    lastperson = person
                if person.timestamp > lastperson.timestamp:
                    lastperson = person
            try:
                # Auslesen des aktuellen Standorts der Kameras im Bezug zum Kartenkoordinatensystem
                (trans, rot) = self.listener.lookupTransform('/map', '/cam_' + lastperson.camera, rospy.Time(0))
                # Erstellen der ausgehenden Nachricht
                msg = PoseStamped()
                msg.header.frame_id = "cam_" + lastperson.camera
                msg.pose.position.y = -lastperson.localcoordinates[0]
                msg.pose.position.x = lastperson.localcoordinates[1]
                msg.header.stamp = rospy.Time.now()
                self.xypublisher.publish(msg)
            # Wenn Fehler auf der Seite der ROS Software bestehen, fange diese ab
            except (transform.LookupException, transform.ConnectivityException, transform.ExtrapolationException):
                print("No tf message received...")

    # Berechnung der lokalen X/Y-Koordinaten gemessen von der jeweiligen Kamera zum Objekt mithilfe der
    # intrinsischen Kamerainformationen
    def getxycoordinates(self, xcenter, framebgrsmall, depthaverage):
        # print(xcenter)
        fovhorizontal = 70
        fovhorizontaldegree = fovhorizontal * (math.pi / 180)
        pixelhorizontal = 960
        # print(pixelhorizontal)
        focallength = pixelhorizontal / (2 * math.tan(fovhorizontaldegree / 2))
        # xpospersonlocal = ((xcenter - (pixelhorizontal / 2)) / focallength) * depthaverage
        xpospersonlocal = ((xcenter - (pixelhorizontal / 2))*depthaverage) / math.sqrt(focallength ** 2 + (xcenter - (pixelhorizontal / 2)) ** 2)
        # print(xpospersonlocal)
        ypospersonlocal = math.sqrt(depthaverage ** 2 - xpospersonlocal ** 2)

        return [xpospersonlocal, ypospersonlocal]
        # print(self.xposperson, self.yposperson)

    ## Zusammensetzung des Knotens. Alle rospy.-Befehle werden seriell bearbeitet. Die in der While-Schleife
    ## befindlichen Befehle werden widerrum seriell barbeitet.
    def startnode(self):
        self.listofpersons = self.dataoperations.getdata()
        rospy.init_node('listener', anonymous=True)
        self.listener = transform.TransformListener()
        self.xypublisher = rospy.Publisher('people', PoseStamped, queue_size=10)

        if self.namespaceoffrontcamera != "":
            rospy.Subscriber("/" + self.namespaceoffrontcamera + "/qhd/image_color", Image, self.processingqhdfront)
            # rospy.Subscriber("/" + self.namespaceoffrontcamera + "/sd/points", PointCloud2, self.callback_pointcloud)

        if self.namespaceofrearcamera != "":
            rospy.Subscriber("/" + self.namespaceofrearcamera + "/qhd/image_color", Image, self.processingqhdrear)
            rospy.Subscriber("/" + self.namespaceofrearcamera + "/sd/points", PointCloud2, self.callback_pointcloud)
        # self.publisher = rospy.Publisher('/tracked_people/pose', PoseStamped, queue_size=10)

        try:
            rospy.sleep(4)
            # rospy.spin()
            while not rospy.is_shutdown():
                # Hier kann man seriell arbeiten
                if self.slowdown == True:
                    time.sleep(0.01)
                start = time.time()

                if self.namespaceoffrontcamera != "":
                    detectionsfront, imagefront = self.detections.getdetectionsbytflite(self.frontimagebgrqhd, "front")
                    #print(detectionsfront)
                    self.managepeople(detectionsfront, self.frontimagebgrqhd, "front")

                if self.namespaceofrearcamera != "":
                    detectionsrear, imagerear = self.detections.getdetectionsbytflite(self.rearimagebgrqhd, "back")
                    #print(detectionsrear)
                    self.managepeople(detectionsrear, self.rearimagebgrqhd, "back")

                self.talk.greet(self.listofpersons)
                if len(detectionsrear) == 0 and len(detectionsfront) == 0:
                    self.slowdown = True
                else:
                    self.slowdown = False

                self.publishposition()
                end = time.time() - start

                # print("Die letzte Iteration dauerte " + str(end) + "s.")
            print("\nShutdown...")
            self.dataoperations.savedata(self.listofpersons)

        except KeyboardInterrupt:
            print("\nShutting down")

        cv2.destroyAllWindows()


if __name__ == '__main__':
    pt = PeopleRec("kinect2", "kinect1")
    pt.startnode()
