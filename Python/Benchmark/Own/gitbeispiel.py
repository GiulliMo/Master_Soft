#!/usr/bin/env python3

import tensorflow.lite as lite
import time
import numpy as np
import PIL

image_classes = {1: 'person',
2: 'bicycle',
3: 'car',
4: 'motorcycle',
5: 'airplane',
6: 'bus',
7: 'train',
8: 'truck',
9: 'boat',
10: 'traffic light',
11: 'fire hydrant',
13: 'stop sign',
14: 'parking meter',
15: 'bench',
16: 'bird',
17: 'cat',
18: 'dog',
19: 'horse',
20: 'sheep',
21: 'cow',
22: 'elephant',
23: 'bear',
24: 'zebra',
25: 'giraffe',
27: 'backpack',
28: 'umbrella',
31: 'handbag',
32: 'tie',
33: 'suitcase',
34: 'frisbee',
35: 'skis',
36: 'snowboard',
37: 'sports ball',
38: 'kite',
39: 'baseball bat',
40: 'baseball glove',
41: 'skateboard',
42: 'surfboard',
43: 'tennis racket',
44: 'bottle',
46: 'wine glass',
47: 'cup',
48: 'fork',
49: 'knife',
50: 'spoon',
51: 'bowl',
52: 'banana',
53: 'apple',
54: 'sandwich',
55: 'orange',
56: 'broccoli',
57: 'carrot',
58: 'hot dog',
59: 'pizza',
60: 'donut',
61: 'cake',
62: 'chair',
63: 'couch',
64: 'potted plant',
65: 'bed',
67: 'dining table',
70: 'toilet',
72: 'tv',
73: 'laptop',
74: 'mouse',
75: 'remote',
76: 'keyboard',
77: 'cell phone',
78: 'microwave',
79: 'oven',
80: 'toaster',
81: 'sink',
82: 'refrigerator',
84: 'book',
85: 'clock',
86: 'vase',
87: 'scissors',
88: 'teddy bear',
89: 'hair drier',
90: 'toothbrush'}

ms = lambda: int(round(time.time() * 1000))

model_path = "nets/model.tflite"

is_quant = "quant" in model_path.lower()

def get_mobilenet_input(f, out_size=(300, 300), is_quant=True):
    img = np.array(PIL.Image.open(f).resize(out_size))
    if not(is_quant):
        img = img.astype(np.float32) / 128 - 1
    return np.array([img]) 


def print_coco_label(cl_id, t):
    print("class: {}, label: {}, time: {:,} ms".format(cl_id, image_classes[cl_id], t))


def print_output(inp_files, res):
    boxes, classes, scores, num_det=res
    print(classes)
    print(num_det)
    for i, fname in enumerate(inp_files):
      n_obj = int(num_det[i])

      print("{} - found objects:".format(fname))
      for j in range(n_obj):
        cl_id = int(classes[i][j]) + 1
        label = image_classes[cl_id]
        score = scores[i][j]
        if score < 0.0:
            continue
        box = boxes[i][j]
        print("  ", cl_id, label, score, box)


ip = lite.Interpreter(model_path=model_path)
ip.allocate_tensors()
inp_id = ip.get_input_details()[0]["index"]
out_det = ip.get_output_details()
out_id0 = out_det[0]["index"]
out_id1 = out_det[1]["index"]
out_id2 = out_det[2]["index"]
out_id3 = out_det[3]["index"]

images = ['dataset/3.jpg']

for f in images:
  img = get_mobilenet_input(f, is_quant=is_quant)
  ip.set_tensor(inp_id, img)
  ip.invoke()
  boxes = ip.get_tensor(out_id0)
  classes = ip.get_tensor(out_id1)
  scores = ip.get_tensor(out_id2)
  num_det = ip.get_tensor(out_id3)
  print(boxes)  
  print_output([f], [boxes, classes, scores, num_det])