import detections
import cv2


class benchmark:
    def __init__(self, filename):
        self.image = cv2.imread(filename)
        self.detections = detections.detections()

    def run(self):
        c = 0
        while c <= 10:
            self.detections.getdetectionsbycnn(self.image, "front")
            self.detections.getdetectionsbyhog(self.image, "front")
            self.detections.getdetectionsbytflite(self.image)
            self.detections.getdetectionsbytfliteruntime(self.image)
            c += 1


if __name__ == '__main__':
    benchmark = benchmark("standingpeople.jpg")
    benchmark.run()
