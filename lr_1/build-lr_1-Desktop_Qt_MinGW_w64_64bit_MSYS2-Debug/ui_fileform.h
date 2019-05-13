/********************************************************************************
** Form generated from reading UI file 'fileform.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEFORM_H
#define UI_FILEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_fileform
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *fileform)
    {
        if (fileform->objectName().isEmpty())
            fileform->setObjectName(QStringLiteral("fileform"));
        fileform->resize(500, 300);
        buttonBox = new QDialogButtonBox(fileform);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(220, 210, 241, 71));
        QFont font;
        font.setPointSize(20);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(fileform);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 100, 431, 51));
        lineEdit->setFont(font);
        label = new QLabel(fileform);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 300, 61));
        label->setFont(font);

        retranslateUi(fileform);
        QObject::connect(buttonBox, SIGNAL(accepted()), fileform, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), fileform, SLOT(reject()));

        QMetaObject::connectSlotsByName(fileform);
    } // setupUi

    void retranslateUi(QDialog *fileform)
    {
        fileform->setWindowTitle(QApplication::translate("fileform", "Dialog", nullptr));
        label->setText(QApplication::translate("fileform", "\320\262\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217 \321\204\320\260\320\271\320\273\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fileform: public Ui_fileform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEFORM_H
