import time

import numpy
import numpy as np
import cv2
import tensorflow
import imutils
from imutils.object_detection import non_max_suppression
#from tflite_runtime.interpreter import Interpreter as tflruntime

class detections:
    def __init__(self, model):
        self.net = cv2.dnn.readNetFromCaffe("MobileNetSSD_deploy.prototxt.txt", "MobileNetSSD_deploy.caffemodel")
        self.hog = cv2.HOGDescriptor()
        self.hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())
        self.labels = self.load_labels("./labels/" + model + "labels.txt")
        self.ignorelabels = self.load_labels("./labels/" + model + "ignorelabels.txt")

    def getdetectionsbyhog(self, image, sneak):
        imagesmall = imutils.resize(image, width=min(400, image.shape[1]))
        start = time.time()
        # Erstellung der Boundingbox
        (rects, weights) = self.hog.detectMultiScale(imagesmall, winStride=(4, 4), padding=(0, 0), scale=1.05)
        rects = np.array([[y, x, y + h, x + w] for (x, y, w, h) in rects])
        end = time.time() - start
        # Fuer sich ueberschneidende Rechtecke unterdruecke diese
        detections = non_max_suppression(rects, probs=None, overlapThresh=0.65)
        bboxlist = []
        for i in range(len(detections)):

            # Erstellung der Boundingbox
            box = numpy.asarray(detections[i])
            print(box)
            box[0] = int(box[0] * (float(image.shape[0]) / imagesmall.shape[0]))
            box[1] = int(box[1] * (float(image.shape[1]) / imagesmall.shape[1]))
            box[2] = int(box[2] * (float(image.shape[0]) / imagesmall.shape[0]))
            box[3] = int(box[3] * (float(image.shape[1]) / imagesmall.shape[1]))

            for i in range(0, 1):
                for b in range(0, 3):
                    if box[b] < 0:
                        box[b] = 0

                    if box[b] > image.shape[i]:
                        box[b] = image.shape[i]
            box = box.astype(numpy.int)
            bboxlist.append(box)
            bbox = numpy.asarray(bboxlist)
            bbox = self.non_max_suppression(bbox, 0.65)
            label = "Person"
            cv2.rectangle(image, (box[1], box[0]), (box[3], box[2]),
                          (255, 0, 255), 2)
            y = box[0] - 15 if box[0] - 15 > 15 else box[0] + 15
            cv2.putText(image, label, (box[1], y),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 255), 2)
        cv2.imshow(sneak, image)
        key = cv2.waitKey(1) & 0xFF
        print("HOG= " + str(end))
        return detections, image

    def getdetectionsbycnn(self, image, sneak):
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
                if self.labels[idx] in self.ignorelabels:
                    continue
                # Erstellung der Boundingbox
                box = detections[0, 0, i, 3:7] * np.array([w, h, w, h])

                (startX, startY, endX, endY) = abs(box.astype("int"))
                bbox.append((startX, startY, endX, endY))
                label = "{}: {:.2f}%".format(self.labels[idx],
                                             confidence * 100)
                cv2.rectangle(image, (startX, startY), (endX, endY),
                              (255, 0, 255), 2)
                y = startY - 15 if startY - 15 > 15 else startY + 15
                cv2.putText(image, label, (startX, y),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 255), 2)

        cv2.imshow(sneak, image) #Bild eventuell extra abspeichern
        key = cv2.waitKey(1) & 0xFF
        print("Caffee= " + str(end))
        return bbox, image

    def getdetectionsbytflite(self, image, sneak):
        (h, w) = image.shape[:2]
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
        detectedlabels = interpreter.get_tensor(output_details[1]['index'])
        scores = interpreter.get_tensor(output_details[2]['index'])
        num = interpreter.get_tensor(output_details[3]['index'])
        bboxlist = []
        bbox = numpy.array([])
        scorelist = []

        for i in range(boxes.shape[1]):
            # Ab der gegebenen Konfidenz wird das Objekt beruecksichtigt
            confidence = scores[0, i]
            if confidence > 0.65:
                scorelist.append(confidence)
                # Index der Detection
                idx = int(detectedlabels[0, i])
                # Wenn Klassen erkannt wurden, die auf der Ignore-Liste stehen, ignoriere
                if self.labels[idx] in self.ignorelabels:
                    continue
                # Erstellung der Boundingbox
                box = numpy.asarray(boxes[0, i, :])
                factor = 0.1
                box[1] = int(box[1] * image.shape[1] * (1 - factor))
                box[0] = int(box[0] * image.shape[0] * (1 - factor))
                box[3] = int(box[3] * image.shape[1] * (1 + factor))
                box[2] = int(box[2] * image.shape[0] + (1 + factor))
                for i in range(0, 1):
                    for b in range(0, 3):
                        if box[b] < 0:
                            box[b] = 0

                        if box[b] > image.shape[i]:
                            box[b] = image.shape[i]
                box = box.astype(numpy.int)
                bboxlist.append(box)
                bbox = numpy.asarray(bboxlist)
                bbox = self.non_max_suppression(bbox, 0.65)
                label = "{}: {:.2f}%".format(self.labels[idx],
                                             confidence * 100)
                cv2.rectangle(image, (box[1], box[0]), (box[3], box[2]),
                              (255, 0, 255), 2)
                y = box[0] - 15 if box[0] - 15 > 15 else box[0] + 15
                cv2.putText(image, label, (box[1], y),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 255), 2)

        cv2.imshow(sneak, image)
        key = cv2.waitKey(1)
        return bbox, image

    def getdetectionsbytfliteruntime(self, image, sneak):
        # labels = self.load_labels("tflitelabels.txt")
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

    def load_labels(self, path):
        """Loads the labels file. Supports files with or without index numbers."""
        with open(path, 'r') as f:
            labels = f.read().splitlines()

        return labels

    #  Felzenszwalb et al.
    def non_max_suppression(self, boxes, overlapThresh):
        # if there are no boxes, return an empty list
        if len(boxes) == 0:
            return []
        # initialize the list of picked indexes
        pick = []
        # grab the coordinates of the bounding boxes
        x1 = boxes[:, 0]
        y1 = boxes[:, 1]
        x2 = boxes[:, 2]
        y2 = boxes[:, 3]
        # compute the area of the bounding boxes and sort the bounding
        # boxes by the bottom-right y-coordinate of the bounding box
        area = (x2 - x1 + 1) * (y2 - y1 + 1)
        idxs = numpy.argsort(y2)
        # keep looping while some indexes still remain in the indexes
        # list
        while len(idxs) > 0:
            # grab the last index in the indexes list, add the index
            # value to the list of picked indexes, then initialize
            # the suppression list (i.e. indexes that will be deleted)
            # using the last index
            last = len(idxs) - 1
            i = idxs[last]
            pick.append(i)
            suppress = [last]
            # loop over all indexes in the indexes list
            for pos in xrange(0, last):
                # grab the current index
                j = idxs[pos]
                # find the largest (x, y) coordinates for the start of
                # the bounding box and the smallest (x, y) coordinates
                # for the end of the bounding box
                xx1 = max(x1[i], x1[j])
                yy1 = max(y1[i], y1[j])
                xx2 = min(x2[i], x2[j])
                yy2 = min(y2[i], y2[j])
                # compute the width and height of the bounding box
                w = max(0, xx2 - xx1 + 1)
                h = max(0, yy2 - yy1 + 1)
                # compute the ratio of overlap between the computed
                # bounding box and the bounding box in the area list
                overlap = float(w * h) / area[j]
                # if there is sufficient overlap, suppress the
                # current bounding box
                if overlap > overlapThresh:
                    suppress.append(pos)
            # delete all indexes from the index list that are in the
            # suppression list
            idxs = np.delete(idxs, suppress)
        # return only the bounding boxes that were picked
        return boxes[pick]
