import cv2
import numpy as np

# define co-ordinates
SIZE = 4000
zoom = 666
offset_Real = -1.9416171784159214980185320931463369
offset_Imag = -0.0002292152534783858749515779689806
image = np.zeros((SIZE, SIZE, 3), dtype=np.uint8)

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

object_d = {'x': 0, 'y': 0, 'z': 0}

# define the range of the complex plane
for i in range(SIZE):
    for j in range(SIZE):
        y = (2 * i)/ SIZE;  ##gives a range from 0 to 2
        y = y - 1.0     ##centres about origin
        y = y / zoom   ##magnifies coordinates
        y = y + offset_Imag   ##moves centre of magnification

        x = (2 * j)/ SIZE       ##gives a range from 0 to 2
        x = x - 1.0     #centres about origin
        x = x / zoom        ##magnifies coordinates
        x = x + offset_Real       ##moves centre of magnification

        c = complex(x, y)
        z = 0.0

        for v in range(1, 100):
            z = z**2 + c
            if (z.real*z.real + z.imag*z.imag) >= 4:
                break

        image[j][i] = RgbColormap(v)

#convert image array to bjr image
cv2.imwrite('mandelbrot2.jpg', image)





