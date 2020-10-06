import time
from libraries.dataset import transform_images, load_tfrecord_dataset
import numpy
import numpy as np
import cv2

import tensorflow
import imutils
from imutils.object_detection import non_max_suppression
from libraries.models import (YoloV3, YoloV3Tiny)
from libraries.utils import draw_outputs
from tensorflow import keras
#import tflite_runtime.interpreter as tflite #tflite
from libraries.ssd_mobilenet_utils import preprocess_image_for_tflite


class detections:
    def __init__(self, model):
        self.net = cv2.dnn.readNetFromCaffe("nets/MobileNetSSD_deploy.prototxt.txt", "nets/MobileNetSSD_deploy.caffemodel")
        self.hog = cv2.HOGDescriptor()
        self.hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())
        self.labels = self.load_labels("./labels/" + model + "labels.txt")
        self.ignorelabels = self.load_labels("./labels/" + model + "ignorelabels.txt")
        self.interpretercocossdmobilev1 = tensorflow.lite.Interpreter(model_path="nets/trained_mobilenet_v1_ssd.tflite")
        self.interpreterssdmobilev2 = tensorflow.lite.Interpreter(model_path="nets/ssdlite_mobilenet_v2.tflite")
        self.interpreterownnet = tensorflow.lite.Interpreter(model_path="nets/ownnetv248.tflite")
       # self.interpreterownnet = tflite.Interpreter("nets/ownnetv248.tflite") #tflite

    def getdetectionsbyhog(self, image, sneak):
        if image.shape[0]>=400:
            imagesmall = imutils.resize(image, width=min(400, image.shape[1]))
            print(imagesmall.shape)
            start = time.time()
            # Erstellung der Boundingbox
            (rects, weights) = self.hog.detectMultiScale(imagesmall, winStride=(4, 4), padding=(8, 8), scale=1.05)
            print(rects)
            print(weights)
            rects = np.array([[y, x, y + h, x + w] for (x, y, w, h) in rects])
            end = time.time() - start
            # Fuer sich ueberschneidende Rechtecke unterdruecke diese
            detections = non_max_suppression(rects, probs=None, overlapThresh=0.65)
            bboxlist = []
            scores = []
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
                tight = 20
                box[0], box[1], box[2], box[3] = box[1]+tight, box[0]+tight, box[3]-tight, box[2]-tight
                box = box.astype(numpy.int)
                bboxlist.append(box)
                bbox = numpy.asarray(bboxlist)
                bbox = self.non_max_suppression(bbox, 0.65)
                label = "Person"
                cv2.rectangle(image, (box[0], box[1]), (box[2], box[3]),
                              (255, 0, 255), 2)
                y = box[1] - 15 if box[1] - 15 > 15 else box[1] + 15
                cv2.putText(image, label, (box[0], y),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 255), 2)
                confidence = 1
                scores.append(confidence)
            #cv2.imwrite('./results/images/' + sneak + '.jpg', image)
            #cv2.imshow(sneak, image)
            #key = cv2.waitKey(1) & 0xFF
            print("HOG= " + str(end))

        else:
            detections=[]
            scores=[]
            end=0
        return detections, image, scores, end

    def getdetectionsbyownnet(self, image, sneak):
        self.interpreterownnet.allocate_tensors()
        inp_id = self.interpreterownnet.get_input_details()[0]["index"]
        out_det = self.interpreterownnet.get_output_details()
        out_id0 = out_det[0]["index"]
        out_id1 = out_det[1]["index"]
        out_id2 = out_det[2]["index"]
        out_id3 = out_det[3]["index"] #vermutlich id der detektion

        img = np.reshape(np.array(cv2.resize(image, (300, 300))), [1, 300, 300, 3])
        img = img.astype(np.float32) / 128 - 1
        start = time.time()
        self.interpreterownnet.set_tensor(inp_id, img)
        self.interpreterownnet.invoke()
        etime = time.time() - start

        boxes = self.interpreterownnet.get_tensor(out_id0)
        classes = self.interpreterownnet.get_tensor(out_id1)
        scores = self.interpreterownnet.get_tensor(out_id2)
        num_det = int(self.interpreterownnet.get_tensor(out_id3))
        #print(boxes)
        #print(classes)
        #print(num_det)
        #num_det = v.get_tensor(out_id3)
        bboxlist = []
        bbox = numpy.array([])
        scorelist = []

        for i in range(num_det):
            # Ab der gegebenen Konfidenz wird das Objekt beruecksichtigt
            confidence = scores[0, i]
            #print(confidence)
            if confidence > 0.0:
                # Index der Detection
                idx = int(classes[0, i])
                # Wenn Klassen erkannt wurden, die auf der Ignore-Liste stehen, ignoriere
                if self.labels[idx] in self.ignorelabels:
                    continue
                #print(self.ignorelabels)
                scorelist.append(confidence)
                # Erstellung der Boundingbox
                box = numpy.asarray(boxes[0, i, :])
                box2 = numpy.empty([1, 4], dtype=float)
                factor = 0.0
                box[1] = box[1] * float(image.shape[1]) * (1.0 - factor)
                box[0] = box[0] * float(image.shape[0]) * (1.0 - factor)
                box[3] = box[3] * float(image.shape[1]) * (1.0 + factor)
                box[2] = box[2] * float(image.shape[0]) + (1.0 + factor)
                box[0], box[1], box[2], box[3] = box[1], box[0], box[3], box[2]
                # print(box)
                for i in range(0, 4):
                    if i == 1 or i == 3:
                        if box[i] < 0:
                            box[i] = 0

                        if box[i] > image.shape[0]:
                            box[i] = image.shape[0]

                    if i == 2 or i == 0:
                        if box[i] < 0:
                            box[i] = 0

                        if box[i] > image.shape[1]:
                            box[i] = image.shape[1]

                #print(box)
                box = box.astype(numpy.int)
                bboxlist.append(box)
                bbox = numpy.asarray(bboxlist)
                #bbox = self.non_max_suppression(bbox, 0.65)
                label = "{}: {:.2f}%".format(self.labels[idx],
                                             confidence * 100)
                cv2.rectangle(image, (box[0], box[1]), (box[2], box[3]),
                              (255, 0, 255), 2)
                y = box[1] - 15 if box[1] - 15 > 15 else box[1] + 15
                cv2.putText(image, str(confidence), (box[0], y),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 255), 2)
        #cv2.imwrite('./results/' + sneak + 'tflite.jpg', image)
        #cv2.imshow(sneak, image)
        #key = cv2.waitKey(1)
        return bbox, image, scorelist, etime
        
    
    def getdetectionsbycnn(self, image, sneak):
        (h, w) = image.shape[:2]
        blob = cv2.dnn.blobFromImage(cv2.resize(image, (300, 300)),
                                     0.007843, (300, 300), 127.5)
        bbox = []
        start = time.time()
        self.net.setInput(blob)
        detections = self.net.forward()
        end = time.time() - start
        scorelist = []
        for i in np.arange(0, detections.shape[2]):
            # Konfidenz berechnen
            confidence = detections[0, 0, i, 2]
            # Ab der gegebenen Konfidenz wird das Objekt beruecksichtigt
            if confidence > 0.0:
                # Index der Detection
                idx = int(detections[0, 0, i, 1])
                # Wenn Klassen erkannt wurden, die auf der Ignore-Liste stehen, ignoriere
                if self.labels[idx] in self.ignorelabels:
                    continue
                scorelist.append(confidence)
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

        #cv2.imshow(sneak, image) #Bild eventuell extra abspeichern
        #key = cv2.waitKey(1) & 0xFF
        #cv2.imwrite('./results/' + sneak + 'Caffee.jpg', image)
        print("Caffee= " + str(end))
        return bbox, image, scorelist

    def getdetectionsbytflite(self, image, sneak):
        (h, w) = image.shape[:2]
        self.interpretercocossdmobilev1.allocate_tensors()

        # Get input and output tensors.
        input_details = self.interpretercocossdmobilev1.get_input_details()
        output_details = self.interpretercocossdmobilev1.get_output_details()

        # Test the model on random input data.
        input_shape = input_details[0]['shape']
        input_data = np.array(cv2.resize(image, (300, 300)), dtype=np.float32)
        #cv2.imshow("test", cv2.resize(framebgrsmall, (300, 300)))
        #key = cv2.waitKey(1) & 0xFF

        input = np.reshape(input_data, [input_shape[0], input_shape[1], input_shape[2], input_shape[3]])
        start = time.time()
        self.interpretercocossdmobilev1.set_tensor(input_details[0]['index'], input)

        self.interpretercocossdmobilev1.invoke()
        etime = time.time() - start
        # get output tensor
        boxes = self.interpretercocossdmobilev1.get_tensor(output_details[0]['index'])
        detectedlabels = self.interpretercocossdmobilev1.get_tensor(output_details[1]['index'])
        scores = self.interpretercocossdmobilev1.get_tensor(output_details[2]['index'])
        num = self.interpretercocossdmobilev1.get_tensor(output_details[3]['index'])
        bboxlist = []
        bbox = numpy.array([])
        scorelist = []

        for i in range(boxes.shape[1]):
            # Ab der gegebenen Konfidenz wird das Objekt beruecksichtigt
            confidence = scores[0, i]
            #print(confidence)
            if confidence > 0.0:
                # Index der Detection
                idx = int(detectedlabels[0, i])
                # Wenn Klassen erkannt wurden, die auf der Ignore-Liste stehen, ignoriere
                if self.labels[idx] in self.ignorelabels:
                    continue
                #print(self.ignorelabels)
                scorelist.append(confidence)
                # Erstellung der Boundingbox
                box = numpy.asarray(boxes[0, i, :])
                box2 = numpy.empty([1, 4], dtype=float)
                factor = 0.0
                box[1] = box[1] * float(image.shape[1]) * (1.0 - factor)
                box[0] = box[0] * float(image.shape[0]) * (1.0 - factor)
                box[3] = box[3] * float(image.shape[1]) * (1.0 + factor)
                box[2] = box[2] * float(image.shape[0]) + (1.0 + factor)
                box[0], box[1], box[2], box[3] = box[1], box[0], box[3], box[2]
                # print(box)
                for i in range(0, 4):
                    if i == 1 or i == 3:
                        if box[i] < 0:
                            box[i] = 0

                        if box[i] > image.shape[0]:
                            box[i] = image.shape[0]

                    if i == 2 or i == 0:
                        if box[i] < 0:
                            box[i] = 0

                        if box[i] > image.shape[1]:
                            box[i] = image.shape[1]

                #print(box)
                box = box.astype(numpy.int)
                bboxlist.append(box)
                bbox = numpy.asarray(bboxlist)
                #bbox = self.non_max_suppression(bbox, 0.65)
                label = "{}: {:.2f}%".format(self.labels[idx],
                                             confidence * 100)
                cv2.rectangle(image, (box[0], box[1]), (box[2], box[3]),
                              (255, 0, 255), 2)
                y = box[1] - 15 if box[1] - 15 > 15 else box[1] + 15
                cv2.putText(image, str(confidence), (box[0], y),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 255), 2)
        #cv2.imwrite('./results/' + sneak + 'tflite.jpg', image)
        #cv2.imshow(sneak, image)
        #key = cv2.waitKey(1)
        return bbox, image, scorelist, etime

    def getdetectionsbytfliteruntime(self, image, sneak):
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
            for pos in range(0, last):
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

    def getdetectionsbyyolov3(self, image, sneak):

        physical_devices = tensorflow.config.experimental.list_physical_devices('GPU')
        for physical_device in physical_devices:
            tensorflow.config.experimental.set_memory_growth(physical_device, True)


        yolo = YoloV3Tiny(classes=80)

        #yolo = YoloV3(classes=80)
        yolo.load_weights('nets/yolov3-tiny.tf').expect_partial()
        #yolo.load_weights('nets/yolov3.tf').expect_partial()


        class_names = [c.strip() for c in open('labels/yolov3labels.txt').readlines()]


        #if None:
        #dataset = load_tfrecord_dataset(
         #   None, 'nets/coco.names',416)
        #dataset = dataset.shuffle(512)
        #img_raw, _label = next(iter(dataset.take(1)))
        #else:
        img_raw = image#tensorflow.image.decode_image(
            #image, channels=3)

        img = tensorflow.expand_dims(img_raw, 0)
        img = transform_images(img, 416)
        start = time.time()
        boxes, scores, classes, nums = yolo(img)
        print(boxes[0])
        print("YoloV3 " + sneak + " = " + str(time.time() - start))
        image = draw_outputs(image, (boxes, scores, classes, nums), class_names)

        #cv2.imshow(sneak, image)
        #key = cv2.waitKey(1)
        return boxes, image, confidence

    def getdetectionsbymobilenetv2(self, image, sneak):
        self.interpreterssdmobilev2.allocate_tensors()

        # Get input and output tensors.
        input_details = self.interpreterssdmobilev2.get_input_details()
        output_details = self.interpreterssdmobilev2.get_output_details()
        image2 = preprocess_image_for_tflite(image, model_image_size=300)
        # Run model: start to detect
        # Sets the value of the input tensor.
        start = time.time()
        self.interpreterssdmobilev2.set_tensor(input_details[0]['index'], image2)
        # Invoke the interpreter.
        self.interpreterssdmobilev2.invoke()
        totaltime = time.time() - start
        #print(totaltime)
        # get results
        boxes = self.interpreterssdmobilev2.get_tensor(output_details[0]['index'])
        detectedlabels = self.interpreterssdmobilev2.get_tensor(output_details[1]['index'])
        scores = self.interpreterssdmobilev2.get_tensor(output_details[2]['index'])
        num = self.interpreterssdmobilev2.get_tensor(output_details[3]['index'])
        #print(detectedlabels)
        #print(boxes)
        boxes, scores, classes = np.squeeze(boxes), np.squeeze(scores), np.squeeze(detectedlabels + 1).astype(np.int32)
        bboxlist = []
        bbox = numpy.array([])
        scorelist = []
        #print(boxes)
        for i in range(boxes.shape[1]):
            # Ab der gegebenen Konfidenz wird das Objekt beruecksichtigt
            confidence = scores[i]
            if confidence > 0.0:
                # Index der Detection
                idx = int(detectedlabels[0, i])
                # Wenn Klassen erkannt wurden, die auf der Ignore-Liste stehen, ignoriere
                if self.labels[idx] in self.ignorelabels:
                    continue
                scorelist.append(confidence)
                # Erstellung der Boundingbox
                box = numpy.asarray(boxes[i, :])
                box2 = numpy.empty([1, 4], dtype=float)
                factor = 0.0
                box[1] = box[1] * float(image.shape[1]) * (1.0 - factor)
                box[0] = box[0] * float(image.shape[0]) * (1.0 - factor)
                box[3] = box[3] * float(image.shape[1]) * (1.0 + factor)
                box[2] = box[2] * float(image.shape[0]) + (1.0 + factor)
                box[0], box[1], box[2], box[3] = box[1], box[0], box[3], box[2]

                for i in range(0, 4):
                    if i == 1 or i == 3:
                        if box[i] < 0:
                            box[i] = 0

                        if box[i] > image.shape[0]:
                            box[i] = image.shape[0]

                    if i == 2 or i == 0:
                        if box[i] < 0:
                            box[i] = 0

                        if box[i] > image.shape[1]:
                            box[i] = image.shape[1]
                box = box.astype(numpy.int)
                bboxlist.append(box)
                bbox = numpy.asarray(bboxlist)
                # bbox = self.non_max_suppression(bbox, 0.65)
                label = "{}: {:.2f}%".format(self.labels[idx],
                                             confidence * 100)
                cv2.rectangle(image, (box[0], box[1]), (box[2], box[3]),
                              (255, 0, 255), 2)
                y = box[1] - 15 if box[1] - 15 > 15 else box[1] + 15
                cv2.putText(image, label, (box[0], y),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 255), 2)
        #cv2.imwrite('./results/' + sneak + 'tflite.jpg', image)
        #cv2.imshow(sneak, image)
        #key = cv2.waitKey(1)
        return bbox, image, scorelist, totaltime
