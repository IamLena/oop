#ifndef DOORS_H
#define DOORS_H

#include <QObject>

class doors : public QObject
{
    Q_OBJECT
public:
    explicit doors(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DOORS_H