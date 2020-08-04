import sys
import os


class DataSet(object):

    def __init__(self):
        self.dir = sys.argv[1]
        self.list = []

    def create_file(self):
        f = open("trainval.txt", "w+")
        for strippedfilename in self.list:
            f.write(strippedfilename)
            f.write("\n")

        print("Success!")


    def create_list(self):
        if self.dir != "":
            try:
                self.dir = sys.argv[1]
                listoffiles = os.listdir(self.dir)
                for filename in listoffiles:
                    filename = filename.rsplit(".", 1)[0]
                    self.list.append(filename)

            except FileNotFoundError:
                print("No valid directory!")

        else:
            print("Please specify a directory!")


    def main(self):
        self.create_list()
        self.create_file()



if __name__ == '__main__':
    dataset = DataSet()
    dataset.main()
