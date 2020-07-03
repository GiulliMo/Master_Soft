
## @class Person
# Fuer jede erkannte Person wird ein Objekt dieser Klasse erstellt
class person:

    def __init__(self):
        ## @var face
        # Gesichtsmerkmale
        self.face = []
        ## @var facerect
        # Koordinaten fuer Interessenbereich fuer das Gesicht
        self.facerect = []
        ## @var rect
        # Koordinaten fuer Rechteck um erkannten Objekt
        self.rect = []
        ## @var camera
        # Name der Kamera, die das Objekt als letztes gesehen hat
        self.camera = ""
        self.xcenterpospixel = 0
        self.ycenterpospixel = 0
        ## @var distance
        # Distanz zum erkannten Objekt
        self.distance = 0
        ## @var localcoordinates
        # Lokale Koordinaten gemessen von der Kamera
        self.localcoordinates = []

    def getrect(self):
        return self.rect

    def getface(self):
        return self.face

    def getxcenterpospixel(self):
        return self.xcenterpospixel
