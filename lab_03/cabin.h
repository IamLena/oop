#ifndef CABIN_H
#define CABIN_H
#include "defines.h"

class cabin : public QObject
{
    Q_OBJECT
private:
    cabinState state;
    direction dir;
    QTimer passTime;
    int curFloor;
    int target;
    QTextEdit *message;

public:
    cabin();
    void set_textEdit(QTextEdit *t);
signals:
    void achivedTarget(int floor);
public slots:
    void set(int target);
    void moveNextFloor();

private:
    void cabin_set_target(int floor);
    void setDir();
};

#endif // CABIN_H
