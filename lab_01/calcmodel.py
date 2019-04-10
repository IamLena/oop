from math import cos, sin, pi

center = [0, 0, 0]
radius = 150
d = radius
n = 20

xc = center[0]
yc = center[1]
zc = center[2]

vertices = []
faces = []

index = 1
def calcX(index):
    return xc + radius * cos(2 * pi * index / n)
def calcY(index):
    return yc + radius * sin(2 * pi * index / n)

def getPrism(h):
    for i in range (n):
        vertices.append('{:f}, {:f}, {:f}'.format(calcX(i), calcY(i), zc + d))

    for i in range (n):
        vertices.append('{:f}, {:f}, {:f}'.format(calcX(i), calcY(i), zc - d))

    face = ''
    for i in range (n - 1):
        face += '{:d}, '.format(i)
    face += '{:d}'.format(n - 1)
    faces.append(face)

    face = ''
    for i in range (n - 1):
        face += '{:d}, '.format(n + i)
    face += '{:d}'.format(2 * n - 1)
    faces.append(face)

    # X h-cross
    # for i in range (n):
    #     if (i == n - 1):
    #         faces.append('{:d}, {:d}, {:d}, {:d}'.format(i, 0, n + i , n))
    #     else:
    #         faces.append('{:d}, {:d}, {:d}, {:d}'.format(i, i + h, n + i , n + i + h))

    # h-next
    for i in range (n):
        if (i == n - 1):
            faces.append('{:d}, {:d}, {:d}, {:d}'.format(i, 0, n, n + i))
        else:
            faces.append('{:d}, {:d}, {:d}, {:d}'.format(i, i + h, n + i + h, n + i))

def getPiramid() :
    vertices.append('{:f}, {:f}, {:f}'.format(0, 0, zc - d))

    for i in range (n):
        vertices.append('{:f}, {:f}, {:f}'.format(calcX(i), calcY(i), zc + d))

    face = ''
    for i in range (n - 1):
        face += '{:d}, '.format(i)
    face += '{:d}'.format(n - 1)
    faces.append(face)
    for i in range (1, n):
        if (i == n - 1):
            faces.append('{:d}, {:d}, {:d}'.format(0, i , 1))
        else:
            faces.append('{:d}, {:d}, {:d}'.format(0, i, 1))

getPiramid()

facLength = len(faces)
vertLength = len(vertices)

f = open("myModel.txt", "w")
f.write('vertices\n')
for i in range(vertLength):
    f.write(vertices[i])
    f.write('\n')
f.write('faces\n')
for i in range(facLength) :
    f.write(faces[i])
    f.write('\n')
f.close()