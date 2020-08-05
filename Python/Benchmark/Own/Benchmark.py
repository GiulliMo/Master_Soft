
import cv2
from libraries.detections import *



class benchmark:
    def __init__(self):
        self.detections = detections("tflite")
        self.scores = []
        self.people = []


    def run(self):
        try:
            c = 0
            while True:
                img = cv2.imread("Dataset/" + str(c) + ".jpg")
                if len(img) != 0:
                    print(c)
                    # bboxes, a = self.detections.getdetectionsbytflite(image, str(c))
                    bboxes, a, confidence = self.detections.getdetectionsbytflite(img, "Image: " + str(c))
                    f = open("results/annotations/" + str(c) + ".txt", "w+")
                    for bbox in bboxes:
                        f.write("Pedestrian 0.0 0 -1 " + str(bbox[0]) + " " + str(bbox[1]) + " " + str(bbox[2]) + " " + str(bbox[3]) + " -1 -1 -1 -1 -1 -1 -1 " + str(confidence))
                    if len(bboxes) == 0:
                        f.write("Unknown 0.0 0 -1 1 1 12 12 -1 -1 -1 -1 -1 -1 -1 1")

                    cv2.imwrite("results/images/" + str(c) + ".jpg", a)

                    c = c + 1
                else:
                    break

        except(IOError):
            print("Failed")



if __name__ == '__main__':
    benchmark = benchmark()
    benchmark.run()
