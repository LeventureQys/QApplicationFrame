/********************************************************************************
** Form generated from reading UI file 'CarClient.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARCLIENT_H
#define UI_CARCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CarClientClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *btn_controll;
    QPushButton *btn_stop;
    QPushButton *btn_start;
    QPushButton *btn_release;
    QPlainTextEdit *txt;

    void setupUi(QMainWindow *CarClientClass)
    {
        if (CarClientClass->objectName().isEmpty())
            CarClientClass->setObjectName(QString::fromUtf8("CarClientClass"));
        CarClientClass->resize(600, 400);
        centralWidget = new QWidget(CarClientClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btn_controll = new QPushButton(widget);
        btn_controll->setObjectName(QString::fromUtf8("btn_controll"));

        gridLayout_2->addWidget(btn_controll, 0, 0, 1, 1);

        btn_stop = new QPushButton(widget);
        btn_stop->setObjectName(QString::fromUtf8("btn_stop"));

        gridLayout_2->addWidget(btn_stop, 4, 0, 1, 1);

        btn_start = new QPushButton(widget);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));

        gridLayout_2->addWidget(btn_start, 2, 0, 1, 1);

        btn_release = new QPushButton(widget);
        btn_release->setObjectName(QString::fromUtf8("btn_release"));

        gridLayout_2->addWidget(btn_release, 1, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        txt = new QPlainTextEdit(centralWidget);
        txt->setObjectName(QString::fromUtf8("txt"));

        gridLayout->addWidget(txt, 0, 1, 1, 1);

        CarClientClass->setCentralWidget(centralWidget);

        retranslateUi(CarClientClass);

        QMetaObject::connectSlotsByName(CarClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *CarClientClass)
    {
        CarClientClass->setWindowTitle(QCoreApplication::translate("CarClientClass", "CarClient", nullptr));
        btn_controll->setText(QCoreApplication::translate("CarClientClass", "\346\216\247\345\210\266\344\270\262\345\217\243", nullptr));
        btn_stop->setText(QCoreApplication::translate("CarClientClass", "\345\201\234\350\275\246", nullptr));
        btn_start->setText(QCoreApplication::translate("CarClientClass", "\345\274\200\350\275\246", nullptr));
        btn_release->setText(QCoreApplication::translate("CarClientClass", "\346\224\276\345\274\200\344\270\262\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CarClientClass: public Ui_CarClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARCLIENT_H
