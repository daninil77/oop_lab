/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mybrowser.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *editSearch;
    QPushButton *buttonFind;
    QToolButton *toolButton;
    mybrowser *textBrowser;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *editID;
    QLabel *label_2;
    QLineEdit *editLesson;
    QLabel *label_3;
    QLineEdit *editType;
    QLabel *label_4;
    QLineEdit *editAuditorium;
    QPushButton *buttonAdd;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(925, 629);
        MainWindow->setMaximumSize(QSize(1358, 16777215));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        editSearch = new QLineEdit(centralwidget);
        editSearch->setObjectName(QString::fromUtf8("editSearch"));

        horizontalLayout->addWidget(editSearch);

        buttonFind = new QPushButton(centralwidget);
        buttonFind->setObjectName(QString::fromUtf8("buttonFind"));

        horizontalLayout->addWidget(buttonFind);

        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new mybrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_2->addWidget(label);

        editID = new QLineEdit(centralwidget);
        editID->setObjectName(QString::fromUtf8("editID"));
        editID->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(editID);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        editLesson = new QLineEdit(centralwidget);
        editLesson->setObjectName(QString::fromUtf8("editLesson"));

        horizontalLayout_2->addWidget(editLesson);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        editType = new QLineEdit(centralwidget);
        editType->setObjectName(QString::fromUtf8("editType"));
        editType->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(editType);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        editAuditorium = new QLineEdit(centralwidget);
        editAuditorium->setObjectName(QString::fromUtf8("editAuditorium"));
        editAuditorium->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(editAuditorium);

        buttonAdd = new QPushButton(centralwidget);
        buttonAdd->setObjectName(QString::fromUtf8("buttonAdd"));

        horizontalLayout_2->addWidget(buttonAdd);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 925, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(buttonFind, SIGNAL(clicked()), MainWindow, SLOT(FindLesson()));
        QObject::connect(buttonAdd, SIGNAL(clicked()), MainWindow, SLOT(AddLesson()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        buttonFind->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Lesson:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Auditorium", nullptr));
        buttonAdd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
