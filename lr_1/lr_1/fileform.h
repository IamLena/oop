#ifndef FILEFORM_H
#define FILEFORM_H

#include <QDialog>

namespace Ui {
class fileform;
}

class fileform : public QDialog
{
    Q_OBJECT

public:
    explicit fileform(QWidget *parent = 0);
    ~fileform();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::fileform *ui;
};

#endif // FILEFORM_H
