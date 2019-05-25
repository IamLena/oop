#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "mainprocess.h"
#include "mainwindow.h"

int parse_file(const char *filename, model* cur_model);
int scale_model(float *scaleKoef, model *cur_model);
int move_model(float *moveData, model *cur_model);
int rotate_model(float *rotateData, model *cur_model);
void draw_model(model cur_model, QGraphicsScene *scene);
void free_model(model *cur_model);
#endif // FUNCTIONS_H
