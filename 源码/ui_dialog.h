/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QLineEdit *erpassword;
    QLabel *label_3;
    QLineEdit *ername;
    QCheckBox *checkBox_2;
    QPushButton *erpass;
    QLabel *label_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(1000, 660);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/image/titleimage.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 70, 561, 91));
        label->setStyleSheet(QString::fromUtf8("font: 48pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        erpassword = new QLineEdit(Dialog);
        erpassword->setObjectName("erpassword");
        erpassword->setGeometry(QRect(410, 370, 281, 51));
        erpassword->setStyleSheet(QString::fromUtf8("font: 15pt \"\351\273\221\344\275\223\";"));
        erpassword->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(260, 370, 171, 51));
        label_3->setStyleSheet(QString::fromUtf8("font: 20pt \"\346\245\267\344\275\223\";"));
        ername = new QLineEdit(Dialog);
        ername->setObjectName("ername");
        ername->setGeometry(QRect(410, 280, 281, 51));
        ername->setStyleSheet(QString::fromUtf8("font: 24pt \"\351\273\221\344\275\223\";"));
        checkBox_2 = new QCheckBox(Dialog);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(630, 450, 91, 23));
        erpass = new QPushButton(Dialog);
        erpass->setObjectName("erpass");
        erpass->setGeometry(QRect(340, 500, 281, 51));
        erpass->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 270, 161, 61));
        label_2->setStyleSheet(QString::fromUtf8("font: 20pt \"\346\245\267\344\275\223\";"));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\345\201\245\350\272\253\346\210\277\344\274\232\345\221\230\347\263\273\347\273\237", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "\345\221\230\345\267\245\345\257\206\347\240\201", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Dialog", "\345\217\257\350\247\206\345\257\206\347\240\201", nullptr));
        erpass->setText(QCoreApplication::translate("Dialog", "\347\231\273\345\275\225", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "\345\221\230\345\267\245\345\247\223\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
