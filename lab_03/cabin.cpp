#include "cabin.h"
#include "iostream"

cabin::cabin()
{
    QObject::connect(&passTime, SIGNAL(timeout()), this, SLOT(moveNextFloor()));
    state = STOP;
    dir = NONE;
    curFloor = INIT;
    target = INIT;
}

void cabin::set_textEdit(QTextEdit *t) {
    message = t;
}

void cabin::cabin_set_target(int floor) {
    target = floor;
}

void cabin::setDir() {
    QString str;
    std::cout << curFloor << target << std::endl;
    if (curFloor > target) {
        dir = DOWN;
        str = "Лифт начал движение вниз";
    }
    else if (curFloor < target) {
        dir = UP;
        str = "Лифт начал движение вверх";
    }
    else {
        dir = NONE;
        str = "Лифт находится на вызванном этаже";
        emit achivedTarget(target);
    }
    message->append(str);
}

void cabin::set(int target) {
    cabin_set_target(target);
    setDir();
    if (dir != 0) {
        std::cout << dir << std::endl;
        state = MOVING;
        passTime.start(PASSTIME);
    }
}

void cabin::moveNextFloor() {
    if (state == MOVING) {
        curFloor += dir;
        QString str = "Лифт на " + QString::number(curFloor) + " этаже";
        message->append(str);
        if (curFloor != this->target) {
            passTime.start(PASSTIME);
        }
        else
        {
            state = STOP;
            emit achivedTarget(target);
        }
    }
}
