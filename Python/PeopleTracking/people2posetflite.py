import pickle
import math
import tensorflow
import tf as transform
import threading
from geometry_msgs.msg import PoseStamped
from imutils.object_detection import non_max_suppression
import face_recognition
import numpy as np
import imutils
from tflite_runtime.interpreter import Interpreter
import cv2
import rospy
import time
import PIL
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
                self.frontimagebgrqhd = self.bridgefront.imgmsg_to_cv2(msg, "rgb8")
                self.frontframebgrsmall = imutils.resize(self.frontimagebgrqhd, width=min(400, self.frontimagebgrqhd.shape[1]))

            except CvBridgeError as e:
                print(e)

    ## Callback der vorderen Kamera.
    # Ohne sneak waere die informationsquelle der eingehenden Daten nicht bekannt.
    # Zur Ersparnis von Rechenzeit werden die Bilder so klein wie moeglich gehalten. Sobald ein Objekt detetktiert
    # wird, dass einer Peron aehnelt, wird die Methode zur Erkennung losgetreten.
    # @param[in] msg Nachricht der Kamera
    def processingqhdrear(self, msg):
        try:
            # start = time.time()
            sneak = "back"
            self.rearimagebgrqhd = self.bridgeback.imgmsg_to_cv2(msg, "rgb8")
            self.rearframebgrsmall = imutils.resize(self.rearimagebgrqhd, width=min(400, self.rearimagebgrqhd.shape[1]))
            # print time.time() - start

        except CvBridgeError as e:
            print(e)

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
            if confidence > 0.6:
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

    def getdetectionsbytflite(self, framebgrsmall):
        """
        print("Input = " + str(framebgrsmall.shape))
        interpreter = tensorflow.lite.Interpreter(model_path="detect.tflite")
        interpreter.allocate_tensors()
        
        # Get input and output tensors.
        input_details = interpreter.get_input_details()
        output_details = interpreter.get_output_details()

        # Test the model on random input data.
        input_shape = input_details[0]['shape']
        input_data = np.array(cv2.resize(framebgrsmall, (300, 300)), dtype=np.uint8)
        cv2.imshow("test", cv2.resize(framebgrsmall, (300, 300)))
        key = cv2.waitKey(1) & 0xFF
        start = time.time()
        print(input_data.shape)
        input = np.reshape(input_data, [input_shape[0], input_shape[1], input_shape[2], input_shape[3]])
        print(input[0])
        interpreter.set_tensor(input_details[0]['index'], input)

        interpreter.invoke()

        # The function `get_tensor()` returns a copy of the tensor data.
        # Use `tensor()` in order to get a pointer to the tensor.
        output_data = interpreter.get_tensor(output_details[2]['index'])
        ou = interpreter.get_tensor(output_details[1]['index'])
        print("Tflite time = " + str(time.time() - start))
        print(output_data)
        print(ou)
        """

        #labels = self.load_labels("labelmap.txt")
        img_org = framebgrsmall
        interpreter = Interpreter("detect.tflite")
        interpreter.allocate_tensors()
        input_details = interpreter.get_input_details()
        output_details = interpreter.get_output_details()

        img = cv2.cvtColor(framebgrsmall, cv2.COLOR_BGR2RGB)
        img = cv2.resize(img, (300, 300))
        img = img.reshape(1, img.shape[0], img.shape[1], img.shape[2])

        # set input tensor
        interpreter.set_tensor(input_details[0]['index'], img)

        # run
        interpreter.invoke()

        # get outpu tensor
        boxes = interpreter.get_tensor(output_details[0]['index'])
        labels = interpreter.get_tensor(output_details[1]['index'])
        scores = interpreter.get_tensor(output_details[2]['index'])
        num = interpreter.get_tensor(output_details[3]['index'])

        for i in range(boxes.shape[1]):
            if scores[0, i] > 0.5:
                box = boxes[0, i, :]
                x0 = int(box[1] * img_org.shape[1])
                y0 = int(box[0] * img_org.shape[0])
                x1 = int(box[3] * img_org.shape[1])
                y1 = int(box[2] * img_org.shape[0])
                box = box.astype(np.int)
                cv2.rectangle(img_org, (x0, y0), (x1, y1), (255, 0, 0), 2)
                cv2.rectangle(img_org, (x0, y0), (x0 + 100, y0 - 30), (255, 0, 0), -1)
                cv2.putText(img_org,
                            str(int(labels[0, i])),
                            (x0, y0),
                            cv2.FONT_HERSHEY_SIMPLEX,
                            1,
                            (255, 255, 255),
                            2)

        cv2.imwrite('output.jpg', img_org)
        cv2.imshow('image', img_org)
        key = cv2.waitKey(1)

    def load_labels(self, path):
        with open(path, 'r') as f:
            return {i: line.strip() for i, line in enumerate(f.readlines())}

    def set_input_tensor(self, interpreter, image):
        tensor_index = interpreter.get_input_details()[0]['index']
        input_tensor = interpreter.tensor(tensor_index)()[0]
        input_tensor[:, :] = image

    def classify_image(self, interpreter, image, top_k=1):
        """Returns a sorted array of classification results."""
        self.set_input_tensor(interpreter, image)
        interpreter.invoke()
        output_details = interpreter.get_output_details()[0]
        output = np.squeeze(interpreter.get_tensor(output_details['index']))

        # If the model is quantized (uint8 data), then dequantize the results
        if output_details['dtype'] == np.uint8:
            scale, zero_point = output_details['quantization']
            output = scale * (output - zero_point)

        ordered = np.argpartition(-output, top_k)
        return [(i, output[i]) for i in ordered[:top_k]]

    def startnode(self):
       # self.getdata()
        rospy.init_node('listener', anonymous=True)
        self.publisher = rospy.Publisher('people', PoseStamped, queue_size=10)
        if self.namespaceoffrontcamera != "":
            rospy.Subscriber("/" + self.namespaceoffrontcamera + "/qhd/image_color", Image, self.processingqhdfront)

        if self.namespaceofrearcamera != "":
            rospy.Subscriber("/" + self.namespaceofrearcamera + "/qhd/image_color", Image, self.processingqhdrear)

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
                    #detectionsfront, imagefront = self.getdetectionsbycnn(self.frontframebgrsmall, "front")
                    #print(detectionsfront)
                    self.getdetectionsbytflite(self.frontimagebgrqhd)


                if self.namespaceofrearcamera != "":
                    #detectionsrear, imagerear = self.getdetectionsbycnn(self.rearframebgrsmall, "back")
                    #print(detectionsrear)
                    print("Ende der Schleife")



                end = time.time() - start
                print("Die letzte Iteration dauerte " + str(end) + "s.")
            print("\nShutdown...")
         #   self.savedata()

        except KeyboardInterrupt:
            print("\nShutting down")
            self.savedata()

        cv2.destroyAllWindows()


if __name__ == '__main__':
    pt = PeopleRec("kinect2", "kinect1")
    pt.startnode()
