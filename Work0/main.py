import matplotlib.pyplot as plot
import matplotlib
import os
matplotlib.use('TkAgg')

filename = "inputTest_AINC2023.txt"
dataT = []
dataY = []
extMaxesIndexes = [0]
extMinsIndexes = [0]

#reads data from file
def reading():
    f = open(filename,'r')
    lines = f.readlines()
    lines.pop(0)
    for line in lines:
        a = line.strip().split(',  ')
        a[0] = float(a[0])
        a[1] = float(a[1])
        dataT.append(a[0])
        dataY.append(a[1])
    f.close()

#serachs extremums values
def extremumsSearch():
    if(dataY[0]>=dataY[1]):
        extMaxesIndexes.append(0)
    else:
        extMinsIndexes.append(0)
    
    if(dataY[len(dataY) - 1]>=dataY[len(dataY) - 2]):
        extMaxesIndexes.append(len(dataY) - 1)
    else:
        extMinsIndexes.append(len(dataY) - 1)
    
    for i in range(1, len(dataY) - 1):
        if(dataY[i] >= dataY[i+1] and dataY[i] >= dataY[i-1]):
            extMaxesIndexes.append(i)
        elif (dataY[i] <= dataY[i+1] and dataY[i] <= dataY[i-1]):
            extMinsIndexes.append(i)

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    reading()
    extremumsSearch()

    print('-----------Максимумы------------------')
    for i in extMaxesIndexes:
        print(dataY[i])

    print()
    print('--------------------------------------')

    print('-----------Минимумы-----------------')
    for i in extMinsIndexes:
        print(dataY[i])

    print()
    print('------------------------------------')


    print("Количество максимумов")
    print(len(extMaxesIndexes))
    print("Количество минимумов")
    print(len(extMinsIndexes))
 

    plot.plot(dataT, dataY, '-b', markevery=extMinsIndexes, marker=8, markerfacecolor='green', markeredgecolor='green')
    plot.plot(dataT, dataY, '-b', markevery=extMaxesIndexes, marker=8, markerfacecolor='red', markeredgecolor='red')
    plot.show()
    input("Нажмите Enter для выхода")
