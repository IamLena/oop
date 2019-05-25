/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *clean_but;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLineEdit *x_scale_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLineEdit *y_scale_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QLineEdit *z_scale_2;
    QPushButton *scale_but_2;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_12;
    QLineEdit *x_scale_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_13;
    QLineEdit *y_scale_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_14;
    QLineEdit *z_scale_3;
    QPushButton *scale_but_3;
    QLabel *label_15;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *download_but;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *x_scale;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *y_scale;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *z_scale;
    QPushButton *scale_but;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1548, 998);
        MainWindow->setMinimumSize(QSize(1200, 700));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(15, 125, 841, 701));
        graphicsView->setMinimumSize(QSize(500, 500));
        clean_but = new QPushButton(centralWidget);
        clean_but->setObjectName(QStringLiteral("clean_but"));
        clean_but->setGeometry(QRect(120, 840, 651, 91));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        clean_but->setFont(font);
        clean_but->setCursor(QCursor(Qt::PointingHandCursor));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(890, 400, 561, 262));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        verticalLayout_4->addWidget(label_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        QFont font1;
        font1.setPointSize(20);
        label_8->setFont(font1);

        horizontalLayout_6->addWidget(label_8);

        x_scale_2 = new QLineEdit(layoutWidget);
        x_scale_2->setObjectName(QStringLiteral("x_scale_2"));
        x_scale_2->setFont(font1);

        horizontalLayout_6->addWidget(x_scale_2);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);

        horizontalLayout_7->addWidget(label_9);

        y_scale_2 = new QLineEdit(layoutWidget);
        y_scale_2->setObjectName(QStringLiteral("y_scale_2"));
        y_scale_2->setFont(font1);

        horizontalLayout_7->addWidget(y_scale_2);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        horizontalLayout_8->addWidget(label_10);

        z_scale_2 = new QLineEdit(layoutWidget);
        z_scale_2->setObjectName(QStringLiteral("z_scale_2"));
        z_scale_2->setFont(font1);

        horizontalLayout_8->addWidget(z_scale_2);


        verticalLayout_4->addLayout(horizontalLayout_8);

        scale_but_2 = new QPushButton(layoutWidget);
        scale_but_2->setObjectName(QStringLiteral("scale_but_2"));
        scale_but_2->setFont(font);
        scale_but_2->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_4->addWidget(scale_but_2);

        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(890, 670, 560, 262));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        verticalLayout_5->addWidget(label_11);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_12 = new QLabel(layoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font1);

        horizontalLayout_9->addWidget(label_12);

        x_scale_3 = new QLineEdit(layoutWidget_2);
        x_scale_3->setObjectName(QStringLiteral("x_scale_3"));
        x_scale_3->setFont(font1);

        horizontalLayout_9->addWidget(x_scale_3);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_13 = new QLabel(layoutWidget_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);

        horizontalLayout_10->addWidget(label_13);

        y_scale_3 = new QLineEdit(layoutWidget_2);
        y_scale_3->setObjectName(QStringLiteral("y_scale_3"));
        y_scale_3->setFont(font1);

        horizontalLayout_10->addWidget(y_scale_3);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_14 = new QLabel(layoutWidget_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font1);

        horizontalLayout_11->addWidget(label_14);

        z_scale_3 = new QLineEdit(layoutWidget_2);
        z_scale_3->setObjectName(QStringLiteral("z_scale_3"));
        z_scale_3->setFont(font1);

        horizontalLayout_11->addWidget(z_scale_3);


        verticalLayout_5->addLayout(horizontalLayout_11);

        scale_but_3 = new QPushButton(layoutWidget_2);
        scale_but_3->setObjectName(QStringLiteral("scale_but_3"));
        scale_but_3->setFont(font);
        scale_but_3->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_5->addWidget(scale_but_3);

        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(140, 10, 421, 101));
        QFont font2;
        font2.setPointSize(32);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(false);
        font2.setWeight(75);
        label_15->setFont(font2);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(890, 20, 561, 88));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setFont(font1);

        horizontalLayout->addWidget(lineEdit);

        download_but = new QPushButton(widget);
        download_but->setObjectName(QStringLiteral("download_but"));
        download_but->setFont(font);
        download_but->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(download_but);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(890, 130, 561, 262));
        verticalLayout_3 = new QVBoxLayout(widget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        verticalLayout_3->addWidget(label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);

        x_scale = new QLineEdit(widget1);
        x_scale->setObjectName(QStringLiteral("x_scale"));
        x_scale->setFont(font1);

        horizontalLayout_3->addWidget(x_scale);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout_4->addWidget(label_5);

        y_scale = new QLineEdit(widget1);
        y_scale->setObjectName(QStringLiteral("y_scale"));
        y_scale->setFont(font1);

        horizontalLayout_4->addWidget(y_scale);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(widget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_5->addWidget(label_6);

        z_scale = new QLineEdit(widget1);
        z_scale->setObjectName(QStringLiteral("z_scale"));
        z_scale->setFont(font1);

        horizontalLayout_5->addWidget(z_scale);


        verticalLayout_3->addLayout(horizontalLayout_5);

        scale_but = new QPushButton(widget1);
        scale_but->setObjectName(QStringLiteral("scale_but"));
        scale_but->setFont(font);
        scale_but->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_3->addWidget(scale_but);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1548, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        clean_but->setText(QApplication::translate("MainWindow", "\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270 (\320\262\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\321\217)", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\262\320\264\320\276\320\273\321\214 \320\276\321\201\320\270 x:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\262\320\264\320\276\320\273\321\214 \320\276\321\201\320\270 y:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\320\262\320\264\320\276\320\273\321\214 \320\276\321\201\320\270 z:", nullptr));
        scale_but_2->setText(QApplication::translate("MainWindow", "OK", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214 (\320\262\320\262\320\265\320\264\320\270\321\202\320\265 \321\203\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260)", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\262\320\276\320\272\321\200\321\203\320\263 \320\276\321\201\320\270 x:", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\320\262\320\276\320\272\321\200\321\203\320\263 \320\276\321\201\320\270 y:", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\320\262\320\276\320\272\321\200\321\203\320\263 \320\276\321\201\320\270 z:", nullptr));
        scale_but_3->setText(QApplication::translate("MainWindow", "OK", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\320\262\321\214\321\216\320\265\321\200 3d \320\274\320\276\320\264\320\265\320\273\320\270", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260:", nullptr));
        download_but->setText(QApplication::translate("MainWindow", "OK", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\272\320\276\320\265\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 x:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\272\320\276\320\265\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 y:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\272\320\276\320\265\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 z:", nullptr));
        scale_but->setText(QApplication::translate("MainWindow", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
