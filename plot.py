import cv2
import numpy as np
import matplotlib.pyplot as plt
import csv

SIZE = 4000


#Re = []
#Im = []
M = []

with open('000.csv', 'r') as File:
    Lines = csv.reader(File)

    for row in Lines:
        #Re.append(row[0])
        #Im.append(row[1])
        M.append(row[0])

def RgbColormap(v):
    if (v % 8) == 0:
        return(227, 27, 16)
    if (v % 8) == 1:
        return(66, 233, 245)
    if (v % 8) == 2:
        return(245, 144, 66)
    if (v % 8) == 3:
        return(22, 73, 168)
    if (v % 8) == 4:
        return(8, 16, 227)
    if (v % 8) == 5:
        return(0, 0, 0)
    if (v % 8) == 6:
        return(5, 238, 242)
    if (v % 8) == 7:
        return(5, 242, 40)



image = np.zeros((SIZE, SIZE, 3), dtype=np.uint8)

i = 0
j = 0
m_index = 0

while i < SIZE:
    j = 0
    while j < SIZE:
        v = int(M[m_index])
        image[i][j] = RgbColormap(v)
        m_index = m_index + 1
        j = j + 1
    i = i + 1

#convert image array to bjr image
cv2.imwrite('plotx5.jpg', image)




