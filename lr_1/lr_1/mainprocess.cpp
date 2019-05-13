#include <stdio.h>
#include "mainprocess.h"
#include "functions.h"

void main_process(action *cur_action, int action_code) {
    printf("%d\n", action_code);
    printf("%s\n", cur_action->filename);
    parse_file(cur_action->filename);
}
