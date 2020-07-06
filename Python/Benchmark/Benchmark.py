import detections
import cv2


class benchmark:
    def __init__(self):
        self.detections = detections.detections()

    def run(self, filename):
        c = 0
        while c <= 10:
            imagecaf = cv2.imread(filename)
            imagehog = cv2.imread(filename)
            self.detections.getdetectionsbycnn(imagecaf, "front")
            self.detections.getdetectionsbyhog(imagehog, "front")
            #self.detections.getdetectionsbytflite(image)
            #self.detections.getdetectionsbytfliteruntime(image)
            c += 1


if __name__ == '__main__':
    benchmark = benchmark()
    benchmark.run("standingpeople.jpg")
