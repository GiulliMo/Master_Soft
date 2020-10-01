import json
import random
import numpy as np
import matplotlib.pyplot as plt
import os

filename= "dataset.json"
class_names = ['drive to', 'slam', 'wait for', 'localization', 'stop', 'unknow']

## Flag zur unterscheidung post/pre Training
# wenn true, dann wurde damit trainiert!!
trained_with_random_dataset = True

def saveJsons(dir, data):
    if os.path.exists(dir):
        os.remove(dir)
    with open(dir, 'w') as f:
        json.dump(data, f)

# unterscheidung ob trainiert wurde oder nicht, wenn trainiert wurde sollten daten mit denen
# trainiert wurde analysiert werden
if trained_with_random_dataset:

    with open('data/' + "random_distributed_dataset.json") as json_file:
        random_distributed_dataset = json.load(json_file)

    with open('data/' + "training_data_II.json") as json_file:
        training_data = json.load(json_file)

    with open('data/' + "test_data_II.json") as json_file:
        test_data = json.load(json_file)

    # testen der laengen
    print(len(random_distributed_dataset))
    print(len(training_data))
    print(len(test_data))
    print(int(len(random_distributed_dataset) * 3/4))
else:
    # laden von Trainingsdaten
    with open('data/' + filename) as json_file:
        dataset = json.load(json_file)

    random_distributed_dataset = []
    # daten zufaellig verteilen um bei dem split gleich viele anteile zu haben
    for i in range(len(dataset)):
        num1 = random.randint(0, len(dataset) - 1)
        random_distributed_dataset.append(dataset[num1])
        dataset.pop(num1)

    # fuer training abspeichern
    saveJsons('data/random_distributed_dataset.json', random_distributed_dataset)

    # daten splitten 3 zu 1
    ratio = 3 / 4
    training_data = random_distributed_dataset[0:int(len(random_distributed_dataset) * ratio)]
    test_data = random_distributed_dataset[int(len(random_distributed_dataset) * ratio):len(random_distributed_dataset)]

    saveJsons('data/train_data_II.json', training_data)
    saveJsons('data/test_data_II.json', test_data)

    # testen der laengen
    print(len(random_distributed_dataset))
    print(len(training_data))
    print(len(test_data))

# darstellen der datensätze
numclassesArray = [0, 0, 0, 0, 0, 0]
for test in random_distributed_dataset:
    if test["class"] == 0:
        numclassesArray[0] = numclassesArray[0] +1

    if test["class"] == 1:
        numclassesArray[1] = numclassesArray[1] +1

    if test["class"] == 2:
        numclassesArray[2] = numclassesArray[2] +1

    if test["class"] == 3:
        numclassesArray[3] = numclassesArray[3] +1

    if test["class"] == 4:
        numclassesArray[4] = numclassesArray[4] +1

    if test["class"] == 5:
        numclassesArray[5] = numclassesArray[5] +1

# Create bars
plt.title('Verteilung Gesamter Datensatz')
print(sum(np.divide(numclassesArray, len(random_distributed_dataset))))
bars = plt.bar(np.arange(len(class_names)), np.around(np.divide(numclassesArray, len(random_distributed_dataset)),4))
# Create names on the x-axis
plt.xticks(np.arange(len(class_names)), class_names)
# Show graphic
for bar in bars:
    yval = bar.get_height()
    plt.text(bar.get_x(), yval + .005, yval)

plt.show()

numclassesArray = [0, 0, 0, 0, 0, 0]
for test in test_data:
    if test["class"] == 0:
        numclassesArray[0] = numclassesArray[0] +1

    if test["class"] == 1:
        numclassesArray[1] = numclassesArray[1] +1

    if test["class"] == 2:
        numclassesArray[2] = numclassesArray[2] +1

    if test["class"] == 3:
        numclassesArray[3] = numclassesArray[3] +1

    if test["class"] == 4:
        numclassesArray[4] = numclassesArray[4] +1

    if test["class"] == 5:
        numclassesArray[5] = numclassesArray[5] +1

# Create bars
plt.title('Verteilung Testdaten')
print(sum(np.divide(numclassesArray, len(test_data))))
bars = plt.bar(np.arange(len(class_names)),  np.around(np.divide(numclassesArray, len(test_data)),4))
# Create names on the x-axis
plt.xticks(np.arange(len(class_names)), class_names)
# Show graphic
for bar in bars:
    yval = bar.get_height()
    plt.text(bar.get_x(), yval + .005, yval)
plt.show()

numclassesArrayTrain = [0, 0, 0, 0, 0, 0]
for test in training_data:
    if test["class"] == 0:
        numclassesArrayTrain[0] = numclassesArrayTrain[0] +1
    if test["class"] == 1:
        numclassesArrayTrain[1] = numclassesArrayTrain[1] +1

    if test["class"] == 2:
        numclassesArrayTrain[2] = numclassesArrayTrain[2] +1

    if test["class"] == 3:
        numclassesArrayTrain[3] = numclassesArrayTrain[3] +1

    if test["class"] == 4:
        numclassesArrayTrain[4] = numclassesArrayTrain[4] +1

    if test["class"] == 5:
        numclassesArrayTrain[5] = numclassesArrayTrain[5] +1

# Create bars
plt.title('Verteilung Trainingsdaten')
print(sum(np.divide(numclassesArrayTrain, len(training_data))))
bars = plt.bar(np.arange(len(class_names)),  np.around(np.divide(numclassesArrayTrain, len(training_data)),4))
# Create names on the x-axis
plt.xticks(np.arange(len(class_names)), class_names)
# Show graphic
for bar in bars:
    yval = bar.get_height()
    plt.text(bar.get_x(), yval + .005, yval)
plt.show()
