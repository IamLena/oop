from math import cos, sin, pi

center = [0, 0, 0]
radius = 250
d = radius
n = 20

xc = center[0]
yc = center[1]
zc = center[2]

vertices = []
faces = []

def calcX(index, radius):
    return xc + radius * cos(2 * pi * index / n)
def calcY(index, radius):
    return yc + radius * sin(2 * pi * index / n)

def getPrism(h):
    for i in range (n):
        vertices.append('{:f}, {:f}, {:f}'.format(calcX(i, d), calcY(i, d), zc + d))

    for i in range (n):
        vertices.append('{:f}, {:f}, {:f}'.format(calcX(i, d), calcY(i, d), zc - d))

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
        vertices.append('{:f}, {:f}, {:f}'.format(calcX(i, d), calcY(i, d), zc + d))

    face = ''
    for i in range (n - 1):
        face += '{:d}, '.format(i)
    face += '{:d}'.format(n - 1)
    faces.append(face)
    # from ome to all
    # for i in range (1, n):
    #     if (i == n - 1):
    #         faces.append('{:d}, {:d}, {:d}'.format(0, i , 1))
    #     else:
    #         faces.append('{:d}, {:d}, {:d}'.format(0, i, 1))
    #conus
    for i in range (1, n + 1):
        if (i == n):
            faces.append('{:d}, {:d}, {:d}'.format(0, i , 1))
        else:
            faces.append('{:d}, {:d}, {:d}'.format(0, i, i + 1))

def getSandClock(h):
    vertices.append('{:f}, {:f}, {:f}'.format(0, 0, zc - d))
    j = 0
    for r in range(10, d, h):
        print(r)
        for i in range (n):
            vertices.append('{:f}, {:f}, {:f}'.format(calcX(i, r), calcY(i, r), zc + r))
        
        face = ''
        for i in range (1, n):
            face += '{:d}, '.format(i + j * n)
        face += '{:d}'.format(n + j * n)
        faces.append(face)
        j += 1
        
    for r in range(d, 10, -h):
        print(r)
        for i in range (n):
            vertices.append('{:f}, {:f}, {:f}'.format(calcX(i, r), calcY(i, r), zc - r))
        
        face = ''
        for i in range (1, n):
            face += '{:d}, '.format(i + j * n)
        face += '{:d}'.format(n + j * n)
        faces.append(face)
        j += 1

    vertices.append('{:f}, {:f}, {:f}'.format(0, 0, zc + d))


def getSadClockCross(h):
    vertices.append('{:f}, {:f}, {:f}'.format(0, 0, zc + d))
    
    j = 0
    for r in range(zc + d, zc - d, -h):
        print(r)
        for i in range (n):
            vertices.append('{:f}, {:f}, {:f}'.format(calcX(i, r), calcY(i, r), r))
        
        face = ''
        for i in range (1, n):
            face += '{:d}, '.format(i + j * n)
        face += '{:d}'.format(n + j * n)
        faces.append(face)
        j += 1
    vertices.append('{:f}, {:f}, {:f}'.format(0, 0, zc - d))

def getSphere(h):
    vertices.append('{:f}, {:f}, {:f}'.format(0, 0, zc + d))
    
    j = 0
    for r in range(10, d, h):
        print(r)
        for i in range (n):
            vertices.append('{:f}, {:f}, {:f}'.format(calcX(i, r), calcY(i, r), zc + d - r))
        
        face = ''
        for i in range (1, n):
            face += '{:d}, '.format(i + j * n)
        face += '{:d}'.format(n + j * n)
        faces.append(face)
        j += 1

    for r in range(d, 10, -h):
        print(r)
        for i in range (n):
            vertices.append('{:f}, {:f}, {:f}'.format(calcX(i, r), calcY(i, r), zc - d + r))
        
        face = ''
        for i in range (1, n):
            face += '{:d}, '.format(i + j * n)
        face += '{:d}'.format(n + j * n)
        faces.append(face)
        j += 1


    vertices.append('{:f}, {:f}, {:f}'.format(0, 0, zc - d))
    lastIndex = len(vertices) - 1
    for i in range (1, n / 2 + 1):
        face = '{:d}, '.format(0)
        for j in range (2 * d / h - 1):
            face += '{:d}, '.format(i + j * n)

        face += '{:d}, '.format(lastIndex)

        for j in range (2 * d / h - 2):
            face += '{:d}, '.format(i + (2 * d / h - 2) * n + n/2 - j * n)

        face += '{:d}'.format(i + (2 * d / h - 2) * n + n/2 - (2 * d / h - 2) * n)

        faces.append(face)
        j += 1

    

getSadClockCross(10)
#getSphere(30)
# getPrism(1)
# getPiramid()

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