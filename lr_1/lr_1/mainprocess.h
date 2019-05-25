#ifndef MAINPROCESS_H
#define MAINPROCESS_H

#define FILEINPUT 10
#define ROTATE 20
#define SCALE 30
#define MOVE 40
#define CLEAN 50
#define FREE 60

#define OK 0
#define INVALIDFILE -1

#include "mainwindow.h"

typedef union {
    const char *filename;
    float koefs[3];
} action;

typedef struct {
    float x;
    float y;
    float z;
} vertex;

typedef struct {
    int index_b;
    int index_e;
} edge;

typedef struct {
    int number_of_verts;
    int number_of_edges;
    vertex *vert_array;
    edge *edge_array;
} model;

int main_process(action *cur_action, int action_code, QGraphicsScene *scene);

#endif // MAINPROCESS_H
