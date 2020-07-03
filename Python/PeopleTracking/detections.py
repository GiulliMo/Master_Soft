import time
import numpy as np
import cv2
import tensorflow
from imutils.object_detection import non_max_suppression


class detections:
    def __init__(self):
        self.net = cv2.dnn.readNetFromCaffe("MobileNetSSD_deploy.prototxt.txt", "MobileNetSSD_deploy.caffemodel")

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
                cv2.rectangle(framebgrsmall, (startX, startY), (endX, endY),
                              (255, 0, 255), 2)
                y = startY - 15 if startY - 15 > 15 else startY + 15
                cv2.putText(framebgrsmall, label, (startX, y),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 255), 2)
        # cv2.imshow(sneak, framebgrsmall) #Bild eventuell extra abspeichern
        # key = cv2.waitKey(1) & 0xFF
        print("Das CNN hat " + str(end) + "s benoetigt.")
        return bbox, framebgrsmall

    def getdetectionsbytflite(self, framebgrsmall):
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

        input = np.reshape(input_data, [input_shape[0], input_shape[1], input_shape[2], input_shape[3]])
        start = time.time()
        interpreter.set_tensor(input_details[0]['index'], input)

        interpreter.invoke()
        print("Tflite time = " + str(time.time() - start))
        # The function `get_tensor()` returns a copy of the tensor data.
        # Use `tensor()` in order to get a pointer to the tensor.
        output_data = interpreter.get_tensor(output_details[2]['index'])
        ou = interpreter.get_tensor(output_details[1]['index'])
