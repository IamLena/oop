#include <stdio.h>
#include "mainprocess.h"
#include "functions.h"

model* parse_file(const char *filename) {
    FILE* file = open_file(filename);
    if (file) {
        //model cur_model = get_model(file);
        close_file(file);
        //return cur_model;
        return NULL;
    }
    close_file(file);
    return NULL;
}

FILE *open_file(char* filename) {
    FILE *modelFile;
    modelFile = fopen(filename, "r");
    return modelFile;
}

void close_file(FILE* file) {
    fclose(file);
}

model *get_model(FILE *f) {
    model cur_model;
    float v1;
    printf("The contents of %s file are:\n", filename);
    if (fscanf(f, "%f")) {

    }
    //char ch;
    //while((ch = fgetc(modelFile)) != EOF)
        //{printf("%c", ch);}
