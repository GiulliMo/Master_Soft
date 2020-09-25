# python3
#
# Copyright 2019 The TensorFlow Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
"""Example using TF Lite to detect objects with the Raspberry Pi camera."""

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
import matplotlib.image as mpimg
import re
import time
import numpy
import numpy as np
import tensorflow
import cv2
from PIL import Image
#from tflite_runtime.interpreter import Interpreter

CAMERA_WIDTH = 640
CAMERA_HEIGHT = 480


def load_labels(path):
  """Loads the labels file. Supports files with or without index numbers."""
  with open(path, 'r') as f:
    labels = f.read().splitlines()

  return labels


def set_input_tensor(interpreter, image):
  """Sets the input tensor."""
  tensor_index = interpreter.get_input_details()[0]['index']
  input_tensor = interpreter.tensor(tensor_index)()[0]
  input_tensor[:, :] = image


def get_output_tensor(interpreter, index):
  """Returns the output tensor at the given index."""
  output_details = interpreter.get_output_details()[index]
  tensor = np.squeeze(interpreter.get_tensor(output_details['index']))
  return tensor


def detect_objects(interpreter, image, threshold):
  """Returns a list of detection results, each a dictionary of object info."""
  start_time = time.time()
  set_input_tensor(interpreter, image)
  interpreter.invoke()
  elapsed_ms = time.time() - start_time
  print(elapsed_ms)
  # Get all output details
  boxes = get_output_tensor(interpreter, 0)
  classes = get_output_tensor(interpreter, 1)
  scores = get_output_tensor(interpreter, 2)
  count = int(get_output_tensor(interpreter, 3))
  results = []
  for i in range(count):
    if scores[i] >= threshold:
      result = {
          'bounding_box': boxes[i],
          'class_id': classes[i],
          'score': scores[i]
      }
      results.append(result)
  return results


def annotate_objects(annotator, results, labels):
  """Draws the bounding box and label for each object in the results."""
  for obj in results:
    # Convert the bounding box figures from relative coordinates
    # to absolute coordinates based on the original resolution
    ymin, xmin, ymax, xmax = obj['bounding_box']
    xmin = int(xmin * CAMERA_WIDTH)
    xmax = int(xmax * CAMERA_WIDTH)
    ymin = int(ymin * CAMERA_HEIGHT)
    ymax = int(ymax * CAMERA_HEIGHT)

    # Overlay the box, label, and score on the camera preview
    annotator.bounding_box([xmin, ymin, xmax, ymax])
    annotator.text([xmin, ymin],
                   '%s\n%.2f' % (labels[obj['class_id']], obj['score']))


def main():
  try:
    c = 0
    while True:
      print(c)
      labels = load_labels("labels/tflitelabels.txt")
      ignorelabels = load_labels("labels/tfliteignorelabels.txt")
      interpreter = tensorflow.lite.Interpreter("nets/detect.tflite")
      interpreter.allocate_tensors()
      print(interpreter)
      _, input_height, input_width, _ = interpreter.get_input_details()[0]['shape']
      image=mpimg.imread("Dataset/" + str(c) + ".jpg")
      img = Image.fromarray(image)
      image2 = img.convert('RGB').resize((input_width, input_height), Image.ANTIALIAS)
      #results = detect_objects(interpreter, image2, 0.4)
      boxes = get_output_tensor(interpreter, 0)
      detectedlabels = get_output_tensor(interpreter, 1)
      print(detectedlabels)
      print(boxes)
      scores = get_output_tensor(interpreter, 2)
      #num = self.interpretercocossdmobilev1.get_tensor(output_details[3]['index'])
      bboxlist = []
      bbox = numpy.array([])
      scorelist = []


      for i in range(boxes.shape[1]):
        # Ab der gegebenen Konfidenz wird das Objekt beruecksichtigt
        confidence = scores[i]
        if confidence > 0.4:
          #print("h")
          # Index der Detection
          idx = int(detectedlabels[i])
          # Wenn Klassen erkannt wurden, die auf der Ignore-Liste stehen, ignoriere
          if labels[idx] in ignorelabels:
            continue
          print(labels[idx])
          scorelist.append(confidence)
          # Erstellung der Boundingbox
          box = numpy.asarray(boxes[ i, :])
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
          # bbox = self.non_max_suppression(bbox, 0.65)
          #label = "{}: {:.2f}%".format(self.labels[idx],
           #                            confidence * 100)
          cv2.rectangle(image, (box[0], box[1]), (box[2], box[3]),
                        (255, 0, 255), 2)
          y = box[1] - 15 if box[1] - 15 > 15 else box[1] + 15
          cv2.putText(image, str(confidence), (box[0], y),
                      cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 255), 2)
      cv2.imwrite('results/images/' + str(c) + '.jpg', image)
      cv2.imshow("b", image)
      key = cv2.waitKey(1)
      f = open("results/annotations/" + str(c) + ".txt", "w+")
      annotationcounter = 0
      for boxes in bbox:
        print("Pedestrian 0.0 0 -1 " + str(boxes[0]) + " " + str(boxes[1]) + " " + str(boxes[2]) + " " + str(boxes[3]) + " -1 -1 -1 -1 -1 -1 -1 " + str(scorelist[annotationcounter]) + "\n")
        f.write("Pedestrian 0.0 0 -1 " + str(boxes[0]) + " " + str(boxes[1]) + " " + str(boxes[2]) + " " + str(boxes[3]) + " -1 -1 -1 -1 -1 -1 -1 " + str(scorelist[annotationcounter]) + "\n")
        annotationcounter += 1
      if len(bboxlist) == 0:
        f.write("")
      c += 1
      time.sleep(0.01)
  except(IOError):
    print("Failed")


if __name__ == '__main__':
  main()