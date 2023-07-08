/********************************************************************************
** Form generated from reading UI file 'detective.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTIVE_H
#define UI_DETECTIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_detectiveClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *detectiveClass)
    {
        if (detectiveClass->objectName().isEmpty())
            detectiveClass->setObjectName("detectiveClass");
        detectiveClass->resize(871, 562);
        centralWidget = new QWidget(detectiveClass);
        centralWidget->setObjectName("centralWidget");
        detectiveClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(detectiveClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 871, 17));
        detectiveClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(detectiveClass);
        mainToolBar->setObjectName("mainToolBar");
        detectiveClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(detectiveClass);
        statusBar->setObjectName("statusBar");
        detectiveClass->setStatusBar(statusBar);

        retranslateUi(detectiveClass);

        QMetaObject::connectSlotsByName(detectiveClass);
    } // setupUi

    void retranslateUi(QMainWindow *detectiveClass)
    {
        detectiveClass->setWindowTitle(QCoreApplication::translate("detectiveClass", "detective", nullptr));
    } // retranslateUi

};

namespace Ui {
    class detectiveClass: public Ui_detectiveClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTIVE_H
