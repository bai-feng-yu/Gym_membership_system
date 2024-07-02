/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_help
{
public:
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QWidget *help)
    {
        if (help->objectName().isEmpty())
            help->setObjectName("help");
        help->resize(801, 530);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/image/titleimage.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        help->setWindowIcon(icon);
        help->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\256\213\344\275\223\";"));
        pushButton = new QPushButton(help);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(170, 340, 181, 51));
        widget = new QWidget(help);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(100, 110, 301, 191));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName("lineEdit_3");

        horizontalLayout_3->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_3);

        widget1 = new QWidget(help);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(480, 140, 211, 131));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(widget1);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        label_5 = new QLabel(widget1);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_6 = new QLabel(widget1);
        label_6->setObjectName("label_6");

        horizontalLayout_5->addWidget(label_6);

        label_7 = new QLabel(widget1);
        label_7->setObjectName("label_7");

        horizontalLayout_5->addWidget(label_7);


        verticalLayout_2->addLayout(horizontalLayout_5);


        retranslateUi(help);

        QMetaObject::connectSlotsByName(help);
    } // setupUi

    void retranslateUi(QWidget *help)
    {
        help->setWindowTitle(QCoreApplication::translate("help", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("help", "\344\277\241\346\201\257\346\211\276\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("help", "\345\247\223\345\220\215:    ", nullptr));
        label_2->setText(QCoreApplication::translate("help", "\350\272\253\344\273\275\350\257\201\345\217\267:", nullptr));
        label_3->setText(QCoreApplication::translate("help", "\347\224\265\350\257\235\345\217\267\347\240\201:", nullptr));
        label_4->setText(QCoreApplication::translate("help", "\344\274\232\345\221\230\345\217\267\357\274\232", nullptr));
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("help", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class help: public Ui_help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
