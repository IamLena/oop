#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "defines.h"

class controller : public QObject
{
    Q_OBJECT
private:
    bool targets[FLOORS];
    int targetsNum;
    QTextEdit *message;

public:
    controller();
    void set_textEdit(QTextEdit *t);

signals:
    void target_is_set(int floor);
public slots:
    void achieved_floor(int floor);
    void add_target(int floor);
private:
    int findTarget();
};

#endif // CONTROLLER_H
