import detections
import cv2


class benchmark:
    def __init__(self):
        self.detections = detections.detections()

    def run(self, filename, sneak):
        c = 0
        while c <= 10:
            imagecaf = cv2.imread(filename)
            imagehog = cv2.imread(filename)
            imagetfl = cv2.imread(filename)
            imagetflr = cv2.imread(filename)

            self.detections.getdetectionsbycnn(imagecaf, sneak)
            self.detections.getdetectionsbyhog(imagehog, sneak)
            self.detections.getdetectionsbytflite(imagetfl, sneak)
            #self.detections.getdetectionsbytfliteruntime(imagetflr, sneak)
            c += 1


if __name__ == '__main__':
    benchmark = benchmark()
    benchmark.run("./pool/standingpeople.jpg", "standing")
    benchmark.run("./pool/sittingpeople.jpg", "sitting")
    benchmark.run("./pool/miscpeople.jpeg", "misc")
