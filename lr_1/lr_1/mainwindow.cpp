#include "mainwindow.h"
#include "mainprocess.h"
#include "functions.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    action free;
    main_process(&free, FREE, scene);
    delete ui;
}

void MainWindow::on_download_but_clicked()
{
    action file_input;

    QString filename = ui->lineEdit->text();
    QByteArray ba = filename.toLocal8Bit();

    file_input.filename = ba.data();
    if (main_process(&file_input, FILEINPUT, scene) != OK) {
        QMessageBox msgBox;
        msgBox.setText("Некорректное имя файла или его содержание.");
        msgBox.exec();
    }
}

void MainWindow::on_scale_but_clicked()
{
    action scale;

    QString xkoef = ui->x_scale->text();
    QString ykoef = ui->y_scale->text();
    QString zkoef = ui->z_scale->text();

    bool ok1 = true, ok2 = true, ok3 = true;
    scale.koefs[0] = xkoef.toDouble(&ok1);
    scale.koefs[1] = ykoef.toDouble(&ok2);
    scale.koefs[2] = zkoef.toDouble(&ok3);

    if (ok1 && ok2 && ok3) {
        main_process(&scale, SCALE, scene);
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Некорректный ввод.");
        msgBox.exec();
    }

}

void MainWindow::on_scale_but_2_clicked()
{
    action move;

    QString xkoef = ui->x_scale_2->text();
    QString ykoef = ui->y_scale_2->text();
    QString zkoef = ui->z_scale_2->text();

    bool ok1 = true, ok2 = true, ok3 = true;
    move.koefs[0] = xkoef.toDouble(&ok1);
    move.koefs[1] = ykoef.toDouble(&ok2);
    move.koefs[2] = zkoef.toDouble(&ok3);

    if (ok1 && ok2 && ok3) {
         main_process(&move, MOVE, scene);
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Некорректный ввод.");
        msgBox.exec();
    }
}

void MainWindow::on_scale_but_3_clicked()
{
    action rotate;

    QString xkoef = ui->x_scale_3->text();
    QString ykoef = ui->y_scale_3->text();
    QString zkoef = ui->z_scale_3->text();

    bool ok1 = true, ok2 = true, ok3 = true;
    rotate.koefs[0] = xkoef.toDouble(&ok1);
    rotate.koefs[1] = ykoef.toDouble(&ok2);
    rotate.koefs[2] = zkoef.toDouble(&ok3);

    if (ok1 && ok2 && ok3) {
         main_process(&rotate, ROTATE, scene);
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Некорректный ввод.");
        msgBox.exec();
    }
}

void MainWindow::on_clean_but_clicked()
{
    scene->clear();
    ui->graphicsView->items().clear();
}
