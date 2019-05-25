#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <mainwindow.h>
#include "mainprocess.h"
#include "functions.h"
#include "errors.h"

// ------------------------------------------- general funcs --------------------------------------------------------------------
void free_model(model *cur_model) {
    free(cur_model->edge_array);
    free(cur_model->vert_array);
    cur_model->edge_array = NULL;
    cur_model->vert_array = NULL;
    cur_model->number_of_edges = 0;
    cur_model->number_of_verts = 0;
}

void print_vert_array(vertex *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%f %f %f\n", array[i].x, array[i].y, array[i].z);
    }
}

void print_edge_array(edge *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%i %i\n", array[i].index_b, array[i].index_e);
    }
}

// ------------------------------------------- file parsing --------------------------------------------------------------------

FILE *open_file(const char* filename) {
    FILE *modelFile;
    modelFile = fopen(filename, "r");
    return modelFile;
}

void close_file(FILE* file) {
    fclose(file);
}

vertex* read_verts(int number_of_vertices, FILE *f) {
    vertex* array = (vertex*)calloc(number_of_vertices, sizeof(vertex));
    if (array) {
        vertex vert;
        for (int i = 0; i < number_of_vertices; i++) {
            if (fscanf(f, "%f%f%f", &vert.x, &vert.y, &vert.z) != 3) {
                free(array);
                array = NULL;
                break;
            }
            else {
                array[i] = vert;
            }
        }
    }
    return array;
}

edge* read_edges(int number_of_edges, FILE *f) {
    edge *array = (edge*)calloc(number_of_edges, sizeof(edge));
    if (array) {
        edge cur_edge;
        for (int i = 0; i < number_of_edges; i++) {
            if (fscanf(f, "%i%i", &cur_edge.index_b, &cur_edge.index_e) != 2) {
                free(array);
                array = NULL;
                break;
            }
            else {
                array[i] = cur_edge;
            }
        }
    }
    return array;
}

int read_data(model *cur_model, int number_of_edges, int number_of_vertices, FILE *f) {
    vertex *vert_array = read_verts(number_of_vertices, f);
    if (vert_array) {
        edge *edge_array = read_edges(number_of_edges, f);
        if (edge_array) {
            free_model(cur_model);
            cur_model->edge_array = edge_array;
            cur_model->vert_array = vert_array;
            cur_model->number_of_edges = number_of_edges;
            cur_model->number_of_verts = number_of_vertices;
            return OK;
        }
        else {
            free(vert_array);
        }
    }
    return INVALIDFILE;
}

int get_model(FILE *f, model *cur_model) {
    int number_of_vertices;
    int number_of_edges;
    if (fscanf(f, "%d%d", &number_of_vertices, &number_of_edges) == 2) {
        return read_data(cur_model, number_of_edges, number_of_vertices, f);
    }
    return INVALIDFILE;
}

int parse_file(const char *filename, model* cur_model) {
    FILE* file = open_file(filename);
    if (file) {
        int rc = get_model(file, cur_model);
        close_file(file);
        return rc;
    }
    return INVALIDFILE;
}

// ------------------------------------------- dots operations --------------------------------------------------------------------
vertex scaledot(vertex dot, float *koef) {
    vertex ret;
    ret.x = koef[0] * dot.x;
    ret.y = koef[1] * dot.y;
    ret.z = koef[2] * dot.z;
    return ret;
}

vertex movedot(vertex dot, float *movedata) {
    vertex ret;
    ret.x = dot.x + movedata[0];
    ret.y = dot.y + movedata[1];
    ret.z = dot.z + movedata[2];
    return ret;
}

vertex rotatedot(vertex dot, float *rotatedata) {
    vertex ret;

    float cosX = cos(rotatedata[0] * M_PI/180);
    float sinX = sin(rotatedata[0] * M_PI/180);
    ret.z = cosX * dot.z - sinX * dot.y;
    ret.y = sinX * dot.z + cosX * dot.y;

    dot.z = ret.z;
    dot.y = ret.y;


    float cosY = cos(rotatedata[1] * M_PI/180);
    float sinY = sin(rotatedata[1] * M_PI/180);
    ret.x = cosY * dot.x - sinY * dot.z;
    ret.z = sinY * dot.x + cosY * dot.z;

    dot.z = ret.z;
    dot.x = ret.x;


    float cosZ = cos(rotatedata[2] * M_PI/180);
    float sinZ = sin(rotatedata[2] * M_PI/180);
    ret.x = cosZ * dot.x - sinZ * dot.y;
    ret.y = sinZ * dot.x + cosZ * dot.y;

    dot.x = ret.x;
    dot.y = ret.y;

    return ret;
}

// ------------------------------------------- array operations --------------------------------------------------------------------

void scale_dots_array(vertex *array, int length, float *scaleKoef) {
    for (int i = 0; i < length; i++) {
        array[i] = scaledot(array[i], scaleKoef);
    }
}

void move_dots_array(vertex *array, int length, float *moveData) {
    for (int i = 0; i < length; i++) {
        array[i] = movedot(array[i], moveData);
    }
}

void rotate_dots_array(vertex *array, int length, float *rotateData) {
    for (int i = 0; i < length; i++) {
        array[i] = rotatedot(array[i], rotateData);
    }
}

// ------------------------------------------- model operations --------------------------------------------------------------------

int scale_model(float *scaleKoef, model *cur_model) {
    scale_dots_array(cur_model->vert_array, cur_model->number_of_verts, scaleKoef);
    return OK;
}

int move_model(float *moveData, model *cur_model) {
    move_dots_array(cur_model->vert_array, cur_model->number_of_verts, moveData);
    return OK;
}

int rotate_model(float *rotateData, model *cur_model) {
    rotate_dots_array(cur_model->vert_array, cur_model->number_of_verts, rotateData);
    return OK;
}

void draw_model(model cur_model, QGraphicsScene *scene){
    scene->clear();
    //print_vert_array(cur_model.vert_array, cur_model.number_of_verts);
    //print_edge_array(cur_model.edge_array, cur_model.number_of_edges);

    QPen redPen (Qt::red);
    QPen blackPen (Qt::black);
    blackPen.setWidth(2);

    for (int i = 0; i < cur_model.number_of_edges; i++) {
        int index1 = cur_model.edge_array[i].index_b;
        int index2 = cur_model.edge_array[i].index_e;
        vertex dot1 = cur_model.vert_array[index1];
        vertex dot2 = cur_model.vert_array[index2];
        scene->addLine(dot1.x, dot1.y, dot2.x, dot2.y, blackPen);
    }
}
