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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *download_but;
    QPushButton *rotate_but;
    QPushButton *scale_but;
    QPushButton *move_but;
    QPushButton *clean_but;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1200, 800);
        MainWindow->setMinimumSize(QSize(1200, 700));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(25, 25, 650, 650));
        graphicsView->setMinimumSize(QSize(500, 500));
        download_but = new QPushButton(centralWidget);
        download_but->setObjectName(QStringLiteral("download_but"));
        download_but->setGeometry(QRect(700, 30, 421, 91));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        download_but->setFont(font);
        download_but->setCursor(QCursor(Qt::PointingHandCursor));
        rotate_but = new QPushButton(centralWidget);
        rotate_but->setObjectName(QStringLiteral("rotate_but"));
        rotate_but->setGeometry(QRect(700, 160, 421, 91));
        rotate_but->setFont(font);
        rotate_but->setCursor(QCursor(Qt::PointingHandCursor));
        scale_but = new QPushButton(centralWidget);
        scale_but->setObjectName(QStringLiteral("scale_but"));
        scale_but->setGeometry(QRect(700, 290, 421, 91));
        scale_but->setFont(font);
        scale_but->setCursor(QCursor(Qt::PointingHandCursor));
        move_but = new QPushButton(centralWidget);
        move_but->setObjectName(QStringLiteral("move_but"));
        move_but->setGeometry(QRect(700, 410, 421, 91));
        move_but->setFont(font);
        move_but->setCursor(QCursor(Qt::PointingHandCursor));
        clean_but = new QPushButton(centralWidget);
        clean_but->setObjectName(QStringLiteral("clean_but"));
        clean_but->setGeometry(QRect(700, 540, 421, 91));
        clean_but->setFont(font);
        clean_but->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 17));
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
        download_but->setText(QApplication::translate("MainWindow", "\320\267\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        rotate_but->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        scale_but->setText(QApplication::translate("MainWindow", "\320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        move_but->setText(QApplication::translate("MainWindow", "\320\277\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        clean_but->setText(QApplication::translate("MainWindow", "\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
