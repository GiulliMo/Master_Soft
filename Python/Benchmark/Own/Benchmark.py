
#! /usr/bin/python3
import os
from libraries.detections import *



class benchmark:
    def __init__(self):
        self.detections = detections("tflite")
        self.scores = []
        self.people = []


    def run(self):
        try:
            c = 0
            elapsed_time = 0
            while True:
                img = cv2.imread("Dataset/" + str(c) + ".jpg")
                if os.path.isfile("Dataset/" + str(c) + ".jpg") == True:
                    print(c)
                    # bboxes, a = self.detections.getdetectionsbytflite(image, str(c))
                    bboxes, a, confidence, etime = self.detections.getdetectionsbyownnet(img, "Image: " + str(c))
                    f = open("results/annotations/" + str(c) + ".txt", "w+")
                    annotationcounter = 0
                    print(bboxes)
                    for bbox in bboxes:
                        f.write("Pedestrian 0.0 0 -1 " + str(bbox[0]) + " " + str(bbox[1]) + " " + str(bbox[2]) + " " + str(bbox[3]) + " -1 -1 -1 -1 -1 -1 -1 " + str(confidence[annotationcounter]) + "\n")
                        annotationcounter += 1
                    if len(bboxes) == 0:
                        f.write("")
                    cv2.imwrite("results/images/" + str(c) + ".jpg", a)
                    c = c + 1
                    elapsed_time += etime
                    #time.sleep(0.01)
                else:
                    print(str(elapsed_time/float(c)))
                    break

        except(IOError):
            print("Failed")



if __name__ == '__main__':
    benchmark = benchmark()
    benchmark.run()
