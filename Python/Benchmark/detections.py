import time
import numpy as np
import cv2
import tensorflow
import imutils
from imutils.object_detection import non_max_suppression
from tflite_runtime.interpreter import Interpreter as tflruntime

class detections:
    def __init__(self):
        self.net = cv2.dnn.readNetFromCaffe("MobileNetSSD_deploy.prototxt.txt", "MobileNetSSD_deploy.caffemodel")
        self.hog = cv2.HOGDescriptor()
        self.hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())

    def getdetectionsbyhog(self, image, sneak):
        image = imutils.resize(image, width=min(400, image.shape[1]))
        start = time.time()
        # Erstellung der Boundingbox
        (rects, weights) = self.hog.detectMultiScale(image, winStride=(4, 4), padding=(0, 0), scale=1.05)
        rects = np.array([[x, y, x + w, y + h] for (x, y, w, h) in rects])
        end = time.time() - start
        # Fuer sich ueberschneidende Rechtecke unterdruecke diese
        detections = non_max_suppression(rects, probs=None, overlapThresh=0.65)
        # Zur Visualisierung der erkannten Objekte
        for detection in detections:
            cv2.rectangle(image, (detection[0], detection[1]), (detection[2], detection[3]),
                          (255, 0, 255), 2)

        cv2.imwrite('HOG.jpg', image)
        # cv2.imshow(sneak, framebgrsmall)
        # key = cv2.waitKey(1) & 0xFF
        print("HOG= " + str(end))
        return detections, image

    def getdetectionsbycnn(self, image, sneak):
        CLASSES = ["background", "aeroplane", "bicycle", "bird", "boat",
                   "bottle", "bus", "car", "cat", "chair", "cow", "diningtable",
                   "dog", "horse", "motorbike", "person", "pottedplant", "sheep",
                   "sofa", "train", "tvmonitor"]
        IGNORE = set(["background", "aeroplane", "bicycle", "bird", "boat",
                      "bottle", "bus", "car", "cat", "chair", "cow", "diningtable",
                      "dog", "horse", "motorbike", "pottedplant", "sheep",
                      "sofa", "train", "tvmonitor"])
        (h, w) = image.shape[:2]
        blob = cv2.dnn.blobFromImage(cv2.resize(image, (300, 300)),
                                     0.007843, (300, 300), 127.5)
        bbox = []
        start = time.time()
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
                # Erstellung der Boundingbox
                box = detections[0, 0, i, 3:7] * np.array([w, h, w, h])

                (startX, startY, endX, endY) = abs(box.astype("int"))
                bbox.append((startX, startY, endX, endY))
                label = "{}: {:.2f}%".format(CLASSES[idx],
                                             confidence * 100)
                cv2.rectangle(image, (startX, startY), (endX, endY),
                              (255, 0, 255), 2)
                y = startY - 15 if startY - 15 > 15 else startY + 15
                cv2.putText(image, label, (startX, y),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 255), 2)
        cv2.imwrite('caffe.jpg', image)
        #cv2.imshow(sneak, image) #Bild eventuell extra abspeichern
        #key = cv2.waitKey(1000) & 0xFF
        print("Caffee= " + str(end))
        return bbox, image

    def getdetectionsbytflite(self, image):
        interpreter = tensorflow.lite.Interpreter(model_path="detect.tflite")
        interpreter.allocate_tensors()

        # Get input and output tensors.
        input_details = interpreter.get_input_details()
        output_details = interpreter.get_output_details()

        # Test the model on random input data.
        input_shape = input_details[0]['shape']
        input_data = np.array(cv2.resize(image, (300, 300)), dtype=np.uint8)
        #cv2.imshow("test", cv2.resize(framebgrsmall, (300, 300)))
        #key = cv2.waitKey(1) & 0xFF

        input = np.reshape(input_data, [input_shape[0], input_shape[1], input_shape[2], input_shape[3]])
        start = time.time()
        interpreter.set_tensor(input_details[0]['index'], input)

        interpreter.invoke()
        print("TfLite= " + str(time.time() - start))
        # get output tensor
        boxes = interpreter.get_tensor(output_details[0]['index'])
        labels = interpreter.get_tensor(output_details[1]['index'])
        scores = interpreter.get_tensor(output_details[2]['index'])
        boxes = non_max_suppression(boxes, scores)
        num = interpreter.get_tensor(output_details[3]['index'])

        for i in range(boxes.shape[1]):
            if scores[0, i] > 0.5:
                box = boxes[0, i, :]
                x0 = int(box[1] * image.shape[1])
                y0 = int(box[0] * image.shape[0])
                x1 = int(box[3] * image.shape[1])
                y1 = int(box[2] * image.shape[0])
                box = box.astype(np.int)
                cv2.rectangle(image, (x0, y0), (x1, y1), (255, 0, 0), 2)
                cv2.rectangle(image, (x0, y0), (x0 + 100, y0 - 30), (255, 0, 0), -1)
                cv2.putText(image,
                            str(int(labels[0, i])),
                            (x0, y0),
                            cv2.FONT_HERSHEY_SIMPLEX,
                            1,
                            (255, 255, 255),
                            2)

        cv2.imwrite('tflite.jpg', image)
        #cv2.imshow('image', img_org)
        #key = cv2.waitKey(1)

    def getdetectionsbytfliteruntime(self, image):
        # labels = self.load_labels("labelmap.txt")
        image = imutils.resize(image, width=min(400, image.shape[1]))
        interpretertflr = tflruntime("detect.tflite")

        interpretertflr.allocate_tensors()
        input_details = interpretertflr.get_input_details()
        output_details = interpretertflr.get_output_details()

        img = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        img = cv2.resize(img, (300, 300))
        img = img.reshape(1, img.shape[0], img.shape[1], img.shape[2])

        # set input tensor
        start = time.time()
        interpretertflr.set_tensor(input_details[0]['index'], img)

        # run
        interpretertflr.invoke()
        print("TFLite Runtime: " + str(time.time() - start))
        # get output tensor
        boxes = interpretertflr.get_tensor(output_details[0]['index'])
        labels = interpretertflr.get_tensor(output_details[1]['index'])
        scores = interpretertflr.get_tensor(output_details[2]['index'])
        num = interpretertflr.get_tensor(output_details[3]['index'])

        for i in range(boxes.shape[1]):
            if scores[0, i] > 0.5:
                box = boxes[0, i, :]
                x0 = int(box[1] * image.shape[1])
                y0 = int(box[0] * image.shape[0])
                x1 = int(box[3] * image.shape[1])
                y1 = int(box[2] * image.shape[0])
                box = box.astype(np.int)
                cv2.rectangle(image, (x0, y0), (x1, y1), (255, 0, 0), 2)
                cv2.rectangle(image, (x0, y0), (x0 + 100, y0 - 30), (255, 0, 0), -1)
                cv2.putText(image,
                            str(int(labels[0, i])),
                            (x0, y0),
                            cv2.FONT_HERSHEY_SIMPLEX,
                            1,
                            (255, 255, 255),
                            2)

        cv2.imwrite('tfliteruntime.jpg', image)
        #cv2.imshow('image', img_org)
        #key = cv2.waitKey(1)
