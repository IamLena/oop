#ifndef MAINPROCESS_H
#define MAINPROCESS_H

#define FILEINPUT 10
#define ROTATE 20
#define SCALE 30
#define MOVE 40
#define CLEAN 50

typedef union {
    const char *filename;
} action;

typedef struct {
    float x;
    float y;
    float z;
} vetrex;

typedef struct {
    int index_b;
    int index_e;
} edge;

typedef struct {
    vetrex *array;
    edge *array;
} model;

void main_process(action *cur_action, int action_code);

#endif // MAINPROCESS_H
