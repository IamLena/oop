#ifndef DEFINES_H
#define DEFINES_H

#include <QObject>
#include <QTimer>
#include <QTextEdit>
#include "iostream"

#define FLOORS 6
#define PASSTIME 200
#define INIT 1

enum cabinState {
    MOVING, STOP
};
enum direction {
    DOWN = -1,
    NONE = 0,
    UP = +1
};

#endif // DEFINES_H
