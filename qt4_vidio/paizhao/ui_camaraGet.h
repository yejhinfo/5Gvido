/********************************************************************************
** Form generated from reading UI file 'camaraGet.ui'
**
** Created: Wed Dec 23 16:50:43 2020
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMARAGET_H
#define UI_CAMARAGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_camaraGet
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *open;
    QPushButton *pic;
    QPushButton *closeCam;
    QPushButton *connect;
    QLineEdit *lineEditPort;
    QLineEdit *lineEditip;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *camaraGet)
    {
        if (camaraGet->objectName().isEmpty())
            camaraGet->setObjectName(QString::fromUtf8("camaraGet"));
        camaraGet->resize(766, 519);
        label = new QLabel(camaraGet);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 331, 391));
        label_2 = new QLabel(camaraGet);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(440, 40, 291, 341));
        open = new QPushButton(camaraGet);
        open->setObjectName(QString::fromUtf8("open"));
        open->setGeometry(QRect(150, 430, 98, 27));
        pic = new QPushButton(camaraGet);
        pic->setObjectName(QString::fromUtf8("pic"));
        pic->setGeometry(QRect(320, 430, 98, 27));
        closeCam = new QPushButton(camaraGet);
        closeCam->setObjectName(QString::fromUtf8("closeCam"));
        closeCam->setGeometry(QRect(530, 430, 98, 27));
        connect = new QPushButton(camaraGet);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setGeometry(QRect(610, 140, 93, 28));
        lineEditPort = new QLineEdit(camaraGet);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setGeometry(QRect(610, 20, 113, 21));
        lineEditip = new QLineEdit(camaraGet);
        lineEditip->setObjectName(QString::fromUtf8("lineEditip"));
        lineEditip->setGeometry(QRect(610, 60, 113, 21));
        label_3 = new QLabel(camaraGet);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(510, 30, 72, 15));
        label_4 = new QLabel(camaraGet);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(510, 70, 72, 15));

        retranslateUi(camaraGet);

        QMetaObject::connectSlotsByName(camaraGet);
    } // setupUi

    void retranslateUi(QWidget *camaraGet)
    {
        camaraGet->setWindowTitle(QApplication::translate("camaraGet", "Widget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("camaraGet", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("camaraGet", "TextLabel", 0, QApplication::UnicodeUTF8));
        open->setText(QApplication::translate("camaraGet", "Open", 0, QApplication::UnicodeUTF8));
        pic->setText(QApplication::translate("camaraGet", "Pic", 0, QApplication::UnicodeUTF8));
        closeCam->setText(QApplication::translate("camaraGet", "CloseCam", 0, QApplication::UnicodeUTF8));
        connect->setText(QApplication::translate("camaraGet", "connect", 0, QApplication::UnicodeUTF8));
        lineEditPort->setText(QApplication::translate("camaraGet", "27783", 0, QApplication::UnicodeUTF8));
        lineEditip->setText(QApplication::translate("camaraGet", "103.46.128.45", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("camaraGet", "prot", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("camaraGet", "ip", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class camaraGet: public Ui_camaraGet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMARAGET_H
