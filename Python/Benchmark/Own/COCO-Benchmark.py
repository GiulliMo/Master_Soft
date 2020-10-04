
import cv2
import os
from libraries.detections import *



class benchmark:
    def __init__(self):
        self.detections = detections("tflite")
        self.scores = []
        self.people = []


    def run(self):
        try:
            d=0
            c = 0
            time = 0
            while True:
                print(c)
                if os.path.isfile("D:/Projektordner/cocodata/splitted_train2017/person_annotations_split_test_adaptedfromtrain2017/" + str(
                            c).zfill(12) + ".txt") == True:
                    print("jo")
                    img = cv2.imread(
                        "D:/Projektordner/cocodata/person_train2017/" + str(
                            c).zfill(12) + ".jpg")
                  #  print(c)
                    # bboxes, a = self.detections.getdetectionsbytflite(image, str(c))
<<<<<<< HEAD
                    bboxes, a, confidence, elapsedtime = self.detections.getdetectionsbyhog(img, "Image: " + str(c))
                    #f = open("results/annotations/" + str(c).zfill(12) + ".txt", "w+")
=======
                    bboxes, a, confidence, elapsedtime = self.detections.getdetectionsbyownnet(img, "Image: " + str(c))
                   # f = open("results/annotations/" + str(c).zfill(12) + ".txt", "w+")
>>>>>>> 08d46a53b84a7cf23b3bafe352e7d1506de8b05a
                    annotationcounter = 0
                   # print(bboxes)
                    time += elapsedtime
<<<<<<< HEAD
                    print(time)
                    #for bbox in bboxes:
                   #     f.write("pedestrian 0.0 0 -1 " + str(bbox[0]) + " " + str(bbox[1]) + " " + str(bbox[2]) + " " + str(bbox[3]) + " -1 -1 -1 -1 -1 -1 -1 " + str(confidence[annotationcounter]) + "\n")
                   #     annotationcounter += 1
                    #if len(bboxes) == 0:
                   #     f.write("")
=======
                  #  print(time)
                  #  for bbox in bboxes:
                  #      f.write("pedestrian 0.0 0 -1 " + str(bbox[0]) + " " + str(bbox[1]) + " " + str(bbox[2]) + " " + str(bbox[3]) + " -1 -1 -1 -1 -1 -1 -1 " + str(confidence[annotationcounter]) + "\n")
                  #      annotationcounter += 1
                  #  if len(bboxes) == 0:
                  #      f.write("")
>>>>>>> 08d46a53b84a7cf23b3bafe352e7d1506de8b05a

                    #cv2.imwrite("results/images/" + str(c) + ".jpg", a)
                    d = d + 1
                    c = c + 1
                    #time.sleep(0.5)
                else:
                    if c == 600000:
                        print(str(time/float(d)))
                        break
                    else:
                        c = c + 1

        except(IOError):
            print("Failed")



if __name__ == '__main__':
    benchmark = benchmark()
    benchmark.run()
