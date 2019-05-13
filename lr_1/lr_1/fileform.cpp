#include "fileform.h"
#include "ui_fileform.h"
#include "mainprocess.h"

fileform::fileform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fileform)
{
    ui->setupUi(this);
}

fileform::~fileform()
{
    delete ui;
}

void fileform::on_buttonBox_accepted()
{
    QString filename = ui->lineEdit->text();
    QByteArray ba = filename.toLocal8Bit();

    action file_input;
    file_input.filename = ba.data();
    main_process(&file_input, FILEINPUT);
}
