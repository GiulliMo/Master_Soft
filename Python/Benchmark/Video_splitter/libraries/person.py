
## @class Person
# Fuer jede erkannte Person wird ein Objekt dieser Klasse erstellt
class person:

    def __init__(self):
        # Name
        self.name = ""
        # Timestamp
        self.timestamp = 0.0
        # Gesichtsmerkmale
        self.face = []
        # Koordinaten fuer Interessenbereich fuer das Gesicht
        self.facerect = []
        # Koordinaten fuer Rechteck um erkannten Objekt
        self.rect = []
        # Name der Kamera, die das Objekt als letztes gesehen hat
        self.camera = ""
        self.xcenterpospixel = 0
        self.ycenterpospixel = 0
        # Distanz zum erkannten Objekt
        self.distance = 0
        # Lokale Koordinaten gemessen von der Kamera
        self.localcoordinates = []

    def getrect(self):
        return self.rect

    def getface(self):
        return self.face

    def getxcenterpospixel(self):
        return self.xcenterpospixel

    def getinformation(self, newold):
        print(newold + " Person mit dem Namen " + self.name + " erkannt!\nDie direkte Distanz betraegt " + str(self.distance) + "m.\nAlso " + str(self.localcoordinates[1]) + "m geradeaus und " + str(self.localcoordinates[0]) + "m nach links.")

