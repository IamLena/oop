#include "lift.h"
#include <QString>
lift::lift()
{
    QObject::connect(&m_controller, SIGNAL(target_is_set(int)), &m_cabin, SLOT(set(int)));
    QObject::connect(&m_cabin, SIGNAL(achivedTarget(int)), &m_controller, SLOT(achieved_floor(int)));
}

void lift::set_textEdit(QTextEdit *t) {
    this->message = t;
    m_controller.set_textEdit(message);
    m_cabin.set_textEdit(message);
}

void lift::add_target(int floor) {
    QString str = "нажата кнопка " + QString::number(floor);
    message->append(str);
    m_controller.add_target(floor);
}
