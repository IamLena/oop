#include "controller.h"

controller::controller()
{
    for (int i = 0; i < FLOORS; i ++) {
        targets[i] = false;
    }
    targetsNum = 0;
}

void controller::set_textEdit(QTextEdit *t) {
    message = t;
}

void controller::achieved_floor(int floor) {
    targets[floor - 1] = false;
    targetsNum --;
    std::cout << targetsNum << targets[floor - 1] << floor << std::endl;
    if (targetsNum != 0) {
        int target = findTarget();
        emit target_is_set(target);
    }
    else {
        QString str = "Лифт приехал";
        message->append(str);
    }
}

void controller::add_target(int floor) {
    if (targets[floor - 1] == false) {
        targets[floor - 1] = true;
        targetsNum ++;
    }
    std::cout << targetsNum << targets[floor - 1] << floor << std::endl;
    int target = findTarget();
    emit target_is_set(target);
}

int controller::findTarget() {
    for (int i = 0; i < FLOORS; i++) {
        if (targets[i]) {
            return i + 1;
        }
    }
}
