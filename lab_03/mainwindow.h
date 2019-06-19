#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lift.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_floor_1_clicked();
    void on_floor_2_clicked();
    void on_floor_3_clicked();
    void on_floor_4_clicked();
    void on_floor_5_clicked();
    void on_floor_6_clicked();

private:
    Ui::MainWindow *ui;
    lift Mylift;
};

#endif // MAINWINDOW_H
