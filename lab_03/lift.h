#ifndef LIFT_H
#define LIFT_H

#include "controller.h"
#include "cabin.h"
#include "doors.h"

class lift : public QObject
{
    Q_OBJECT
public:
    lift();
    void set_textEdit(QTextEdit *t);
    void add_target(int floor);
signals:
public slots:
private:
    QTextEdit *message;
    controller m_controller;
    cabin m_cabin;
    doors m_doors;
};

#endif // LIFT_H
