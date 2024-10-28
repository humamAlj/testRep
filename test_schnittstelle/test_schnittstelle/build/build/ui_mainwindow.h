/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLineEdit *URL_line;
    QLabel *label;
    QLineEdit *username_line;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *passW_line;
    QPushButton *startBtn;
    QLineEdit *jobName_line;
    QLabel *jobName_lbl;
    QLabel *status_lbl;
    QPushButton *selectBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 20, 741, 541));
        URL_line = new QLineEdit(groupBox);
        URL_line->setObjectName("URL_line");
        URL_line->setGeometry(QRect(290, 80, 431, 24));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 90, 171, 16));
        username_line = new QLineEdit(groupBox);
        username_line->setObjectName("username_line");
        username_line->setGeometry(QRect(290, 140, 431, 24));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 140, 171, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 210, 171, 16));
        passW_line = new QLineEdit(groupBox);
        passW_line->setObjectName("passW_line");
        passW_line->setGeometry(QRect(290, 200, 431, 24));
        startBtn = new QPushButton(groupBox);
        startBtn->setObjectName("startBtn");
        startBtn->setGeometry(QRect(80, 350, 80, 24));
        jobName_line = new QLineEdit(groupBox);
        jobName_line->setObjectName("jobName_line");
        jobName_line->setGeometry(QRect(290, 260, 431, 24));
        jobName_lbl = new QLabel(groupBox);
        jobName_lbl->setObjectName("jobName_lbl");
        jobName_lbl->setGeometry(QRect(30, 270, 171, 16));
        status_lbl = new QLabel(groupBox);
        status_lbl->setObjectName("status_lbl");
        status_lbl->setGeometry(QRect(190, 480, 551, 20));
        status_lbl->setMinimumSize(QSize(0, 0));
        status_lbl->setMaximumSize(QSize(16777215, 16777215));
        status_lbl->setSizeIncrement(QSize(4, 0));
        status_lbl->setLayoutDirection(Qt::RightToLeft);
        status_lbl->setStyleSheet(QString::fromUtf8(""));
        selectBtn = new QPushButton(groupBox);
        selectBtn->setObjectName("selectBtn");
        selectBtn->setGeometry(QRect(50, 40, 171, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "jenkins URL  :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "username", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "password", nullptr));
        startBtn->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        jobName_lbl->setText(QCoreApplication::translate("MainWindow", "jobName", nullptr));
        status_lbl->setText(QString());
        selectBtn->setText(QCoreApplication::translate("MainWindow", "select project", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
