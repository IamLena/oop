#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Mylift.set_textEdit(ui->message);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_floor_1_clicked()
{
    Mylift.add_target(1);
}

void MainWindow::on_floor_2_clicked()
{
    Mylift.add_target(2);
}

void MainWindow::on_floor_3_clicked()
{
    Mylift.add_target(3);
}

void MainWindow::on_floor_4_clicked()
{
    Mylift.add_target(4);
}

void MainWindow::on_floor_5_clicked()
{
    Mylift.add_target(5);
}

void MainWindow::on_floor_6_clicked()
{
    Mylift.add_target(6);
}
