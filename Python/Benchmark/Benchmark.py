import detections
import cv2


class benchmark:
    def __init__(self):
        self.detections = detections.detections()

    def run(self, filename):
        c = 0
        while c <= 10:
            imagehog, imagetfl, imagecf, imagetflr = cv2.imread(filename)
            self.detections.getdetectionsbycnn(imagecf, "front")
            self.detections.getdetectionsbyhog(imagehog, "front")
            self.detections.getdetectionsbytflite(imagetfl)
            self.detections.getdetectionsbytfliteruntime(imagetflr)
            c += 1


if __name__ == '__main__':
    benchmark = benchmark()
    benchmark.run("standingpeople.jpg")
