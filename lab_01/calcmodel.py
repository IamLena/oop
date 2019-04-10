# var Cube = function (center, size) {
#     this.center = center
#     var d = size / 2;
#     this.vertices = [
#         vertices.append('{:d}, {:d}, {:d}'.format(xc - d, yc- d, zc +d)
#         vertices.append('{:d}, {:d}, {:d}'.format(xc -d, yc -d, zc -d)
#         vertices.append('{:d}, {:d}, {:d}'.format(xc + d, yc -d, zc -d)
#         vertices.append('{:d}, {:d}, {:d}'.format(xc + d, yc -d, zc +d)
#         vertices.append('{:d}, {:d}, {:d}'.format(xc + d, yc + d, zc+ d)
#         vertices.append('{:d}, {:d}, {:d}'.format(xc + d, yc + d, zc - d)
#         vertices.append('{:d}, {:d}, {:d}'.format(xc - d, yc + d, zc - d)
#         vertices.append('{:d}, {:d}, {:d}'.format(xc - d, yc + d, zc + d)
# #     ];
#     this.faces = [
#         0, 1, 2, 3
#         3, 2, 5, 4
#         4, 5, 6, 7
#         7, 6, 1, 0
#         7, 0, 3, 4
#         1, 6, 5, 2
#     ];
# };

center = [0, 0, 0]
size = 300

xc = center[0]
yc = center[1]
zc = center[2]
d = size / 2

#cube:
f = open("myModel.txt", "w")
vertices = []
vertices.append('{:f}, {:f}, {:f}'.format(xc - d, yc- d, zc +d))
vertices.append('{:f}, {:f}, {:f}'.format(xc -d, yc -d, zc -d))
vertices.append('{:f}, {:f}, {:f}'.format(xc + d, yc -d, zc -d))
vertices.append('{:f}, {:f}, {:f}'.format(xc + d, yc -d, zc +d))
vertices.append('{:f}, {:f}, {:f}'.format(xc + d, yc + d, zc+ d))
vertices.append('{:f}, {:f}, {:f}'.format(xc + d, yc + d, zc - d))
vertices.append('{:f}, {:f}, {:f}'.format(xc - d, yc + d, zc - d))
vertices.append('{:f}, {:f}, {:f}'.format(xc - d, yc + d, zc + d))
vertLength = len(vertices)

faces = []

faces.append('{:d}, {:d}, {:d}, {:d}'.format(0, 1, 2, 3))
faces.append('{:d}, {:d}, {:d}, {:d}'.format(3, 2, 5, 4))
faces.append('{:d}, {:d}, {:d}, {:d}'.format(4, 5, 6, 7))
faces.append('{:d}, {:d}, {:d}, {:d}'.format(7, 6, 1, 0))
faces.append('{:d}, {:d}, {:d}, {:d}'.format(7, 0, 3, 4))
faces.append('{:d}, {:d}, {:d}, {:d}'.format(1, 6, 5, 2))
facLength = len(faces)

f.write('vertices\n')
for i in range(vertLength):
    f.write(vertices[i])
    f.write('\n')
f.write('faces\n')
for i in range(facLength) :
    f.write(faces[i])
    f.write('\n')
f.close()