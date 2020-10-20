import pickle

class dataoperations:
    def __init__(self):
        pass

    def savedata(self, listofpersons):
        with open('data.pkl', 'wb') as output:
            pickle.dump(listofpersons, output, pickle.HIGHEST_PROTOCOL)

    def getdata(self):
        list = []
        try:
            with open('data.pkl', 'rb') as input:
                list = pickle.load(input)

        except EOFError:
            print("Empty File")

        for person in list:
            print(person.name)
            print(person.localcoordinates)
        return list