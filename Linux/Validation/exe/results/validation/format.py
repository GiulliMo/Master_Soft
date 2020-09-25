import os
import shutil



class benchmark:
    def __init__(self):
        self.scores = []
        self.people = []


    def run(self):
        try:
            d = 0
            c = 0
            while True:
                print(c)
                print(os.path.isfile("data/" + str(
                    c).zfill(12) + ".txt"))
                if os.path.isfile("data/" + str(
                            c).zfill(12) + ".txt") == True:
                    print("jo")
                    os.rename("data/" + str(c).zfill(12) + ".txt", "data/" + str(d) + ".txt")

                    d += 1
                    c = c + 1
                    #time.sleep(0.5)
                else:
                    if c == 600000:
                        break
                    else:
                        c = c + 1

        except(IOError):
            print("Failed")



if __name__ == '__main__':
    benchmark = benchmark()
    benchmark.run()
