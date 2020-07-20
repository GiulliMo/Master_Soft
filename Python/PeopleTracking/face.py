import face_recognition
import cv2


class face:
    def __init__(self):
        self.knownfaces = []
        self.unknownfaces = []

    ## Ordnet Gesichter zu
    def getface(self, xupleft, yupleft, xbellowright, ybellowright, image):

        # ROI der Person wird zur Ersparnis der Rechenzeit an das Gesicht angepasst
        # facexupleft = int((xupleft + ((xbellowright - xupleft) / 4)) * factor)
        facexupleft = int(xupleft)
        # faceyupleft = int((yupleft + ((ybellowright - yupleft) / 10)) * factor)
        faceyupleft = int(yupleft)
        # facexbottomright = int((xbellowright - ((xbellowright - xupleft) / 4)) * factor)
        facexbellowright = int((xbellowright - ((xbellowright - xupleft) * 0.66)))
        # faceybottomright = int((yupleft + ((ybellowright - yupleft) / 4)) * factor)
        faceybellowright = int(ybellowright)
        imagecut = image[facexupleft:facexbellowright, faceyupleft:faceybellowright]
        cv2.imshow("cut", imagecut)  # Bild eventuell extra abspeichern
        key = cv2.waitKey(1) & 0xFF
        rgb = cv2.cvtColor(imagecut, cv2.COLOR_BGR2RGB)
        #print(facexupleft)
        #print(faceyupleft)
        #print(facexbottomright)
        #print(faceybottomright)
        boxes = face_recognition.face_locations(rgb)

        # Fuer jedes erkannte Gesicht wird geprueft, ob es bekannt ist. Wenn nicht wird ein neues hinzugefuegt
        # und wenn die Liste aller bekannten Gesichter leer ist wird das erste Gesicht sofort hinzugefuegt.

        for (top, right, bottom, left) in boxes:
            # Speichere das Gesicht in der Bbox. Wenn kein Gesicht dann None.
            face = face_recognition.face_encodings(rgb, boxes)[0]
            # Gehoert das eingehende Gesicht zu
            isknown = face_recognition.compare_faces(self.knownfaces, face, 0.5)
            print(isknown)
            # Das erste Gesicht wird sofort abgespeichert
            if not isknown:
                self.knownfaces.append(face)
                isknown.append(True)
                print("Neues Gesicht mit der ID" + str(len(self.knownfaces) - 1) + " hinzugefuegt")
            # Checke alle Gesichter ob und welches erkennt wurde, wenn nicht, gehoert es zu den unbekannten?
            for index, element in enumerate(isknown):
                if isknown[index]:
                    print("ID " + str(index) + " wurde erkannt")
                    return xupleft, yupleft, xbellowright, ybellowright, top, right, bottom, left, face, index;

                elif index + 1 == len(isknown):
                    self.checkunknownfaces(face)
                    return None


    def checkunknownfaces(self, face, toknownfacesthreshold=3):
        print("Unbekanntes Gesicht wird geprueft...")
        # Wenn kein unbekanntes Gesicht vorhanden fuege es hinzu
        if not self.unknownfaces:
            self.unknownfaces.append(face)

        count = 0
        isunknown = face_recognition.compare_faces(self.unknownfaces, face, 0.5)
        print(isunknown)
        for index, element in enumerate(isunknown):
            # Wenn eingehendes Gesicht zu unbekannten Gesichtern passt zaehle hoch
            if isunknown[index]:
                count += 1
            # Wenn nicht zaehle runter
            else:
                count = 0
            # Wenn das Gesicht oft genug erkannt wurde fuege es zu bekannten Gesichtern hinzugit status
            if count == toknownfacesthreshold:
                self.knownfaces.append(face)
                print("Neues Gesicht mit der ID " + str(len(self.knownfaces) - 1) + " hinzugefuegt")
                break
            # Wenn keins der unbekannten Gesichter dem eingehenden Gesicht aehnelt, erweitere die Liste
            if index + 1 == len(isunknown):
                self.unknownfaces.append(face)
            # Wenn das Gesicht oft genug erkannt worden ist, loesche es von den unbekannten Geischtern
            if index + 1 == toknownfacesthreshold:
                self.unknownfaces.remove(self.unknownfaces[0])

            print("Unb. Gesicht wurde " + str(count + 1) + " Mal erkannt")