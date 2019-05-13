#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fileform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_download_but_clicked()
{
    //call file input
    //process data
    fileform form;
    form.setModal(true);
    form.exec();
}


