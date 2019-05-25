#include <stdio.h>
#include "mainprocess.h"
#include "functions.h"

model init_model(void) {
    model cur_model;
    cur_model.edge_array = NULL;
    cur_model.vert_array = NULL;
    cur_model.number_of_edges = 0;
    cur_model.number_of_verts = 0;
    return cur_model;
}

int main_process(action *cur_action, int action_code, QGraphicsScene *scene) {
    static model cur_model = init_model();
    int rc = OK;
    if (action_code == FILEINPUT) {
        rc = parse_file(cur_action->filename, &cur_model);
    }
    else if (action_code == ROTATE) {
        rc = rotate_model(cur_action->koefs, &cur_model);
    }
    else if (action_code == SCALE) {
        rc = scale_model(cur_action->koefs, &cur_model);
    }
    else if (action_code == MOVE) {
        rc = move_model(cur_action->koefs, &cur_model);
    }
    else if (action_code == FREE) {
        free_model(&cur_model);
    }
    if (cur_model.edge_array != NULL) {
        draw_model(cur_model, scene);
    }
    return rc;
}
