/********************************************************************************
** Form generated from reading UI file 'QtLab3.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTLAB3_H
#define UI_QTLAB3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtLab3Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtLab3Class)
    {
        if (QtLab3Class->objectName().isEmpty())
            QtLab3Class->setObjectName(QString::fromUtf8("QtLab3Class"));
        QtLab3Class->resize(600, 400);
        menuBar = new QMenuBar(QtLab3Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtLab3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtLab3Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtLab3Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtLab3Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtLab3Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtLab3Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtLab3Class->setStatusBar(statusBar);

        retranslateUi(QtLab3Class);

        QMetaObject::connectSlotsByName(QtLab3Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtLab3Class)
    {
        QtLab3Class->setWindowTitle(QCoreApplication::translate("QtLab3Class", "QtLab3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtLab3Class: public Ui_QtLab3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTLAB3_H
