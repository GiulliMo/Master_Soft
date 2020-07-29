
import cv2
from libraries.detections import *



class benchmark:
    def __init__(self):
        self.detections = detections("caffee")
        self.scores = []
        self.people = []


    def run(self):
        c = 40


        while c <= 20599:
            if c < 10:
                print(c)
                image = cv2.imread("Dataset/Images/00000" + str(c) + ".jpg")
                detnum = self.extractdetections("Dataset/Annotations/00000" + str(c) + ".jpg.txt")
            elif c >= 10 and c < 100:
                print(c)
                image = cv2.imread("Dataset/Images/0000" + str(c) + ".jpg")
                detnum = self.extractdetections("Dataset/Annotations/0000" + str(c) + ".jpg.txt")
            elif c >= 100 and c < 1000:
                print(c)
                image = cv2.imread("Dataset/Images/000" + str(c) + ".jpg")
                detnum = self.extractdetections("Dataset/Annotations/000" + str(c) + ".jpg.txt")
            elif c >= 1000 and c < 10000:
                print(c)
                image = cv2.imread("Dataset/Images/00" + str(c) + ".jpg")
                detnum = self.extractdetections("Dataset/Annotations/00" + str(c) + ".jpg.txt")

            else:
                print(c)
                image = cv2.imread("Dataset/Images/0" + str(c) + ".jpg")
                detnum = self.extractdetections("Dataset/Annotations/0" + str(c) + ".jpg.txt")


            if image is not None:
                #self.detections.getdetectionsbyhog(image, "Fudan" + str(c))
                #bboxes, a = self.detections.getdetectionsbytflite(image, str(c))
                bboxes, a = self.detections.getdetectionsbycnn(image, "Fudan" + str(c))
                #self.detections.getdetectionsbytfliteruntime(imagetflr, sneak)


            if detnum != 0:
                diff = detnum - len(bboxes)
                score = float(diff)/float(detnum)
                self.scores.append(score)
                self.people.append(detnum)

            c += 1
        sumpeople = 0
        for person in self.people:
            sumpeople = sumpeople + person

        peopleperframe = float(sumpeople)/float(len(self.people))
        print("Insgesamt waren " + str(int(sumpeople)) + " Personen auf " + str(len(self.people)) + " Bildern zu sehen.")
        print("Also " + str(peopleperframe) + " Personen pro Bild.")
        sum = 0
        for score in self.scores:
            sum = sum + score
        finalscore = float(sum) / float(len(self.scores))
        print("Score: " + str(finalscore))

    def extractdetections(self,filename):
        try:
            F = open(filename, 'r')
            d = int(F.readline())
        except(IOError):
            print("No Annotation")
            d = 0

        return d


if __name__ == '__main__':
    benchmark = benchmark()
    benchmark.run()
