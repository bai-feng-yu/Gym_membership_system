/********************************************************************************
** Form generated from reading UI file 'customer.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMER_H
#define UI_CUSTOMER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customer
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_4;
    QLabel *label_6;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *tid;
    QLabel *tname;
    QLabel *tsex;
    QLabel *tidnumber;
    QLabel *tphonenumber;
    QLabel *ttime;
    QLabel *tlevel;
    QWidget *tab;
    QTabWidget *tabWidget_2;
    QWidget *tab_7;
    QPushButton *correct;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_18;
    QLineEdit *lname;
    QLabel *label_19;
    QLineEdit *lsex;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_20;
    QLineEdit *lidnumber;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_21;
    QLineEdit *lphonenumber;
    QWidget *tab_8;
    QPushButton *correctpassword;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_22;
    QLineEdit *oldpassword;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_23;
    QLineEdit *newpasword;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_30;
    QLineEdit *rnewpassword;
    QWidget *tab_2;
    QTableView *history;
    QWidget *tab_13;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *customer)
    {
        if (customer->objectName().isEmpty())
            customer->setObjectName("customer");
        customer->resize(1002, 660);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/image/titleimage.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        customer->setWindowIcon(icon);
        tabWidget = new QTabWidget(customer);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 991, 641));
        tabWidget->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        layoutWidget = new QWidget(tab_4);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(290, 60, 142, 473));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        verticalLayout->addWidget(label_7);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName("label_9");

        verticalLayout->addWidget(label_9);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName("label_12");

        verticalLayout->addWidget(label_12);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);

        layoutWidget1 = new QWidget(tab_4);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(470, 60, 291, 471));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tid = new QLabel(layoutWidget1);
        tid->setObjectName("tid");

        verticalLayout_2->addWidget(tid);

        tname = new QLabel(layoutWidget1);
        tname->setObjectName("tname");

        verticalLayout_2->addWidget(tname);

        tsex = new QLabel(layoutWidget1);
        tsex->setObjectName("tsex");

        verticalLayout_2->addWidget(tsex);

        tidnumber = new QLabel(layoutWidget1);
        tidnumber->setObjectName("tidnumber");

        verticalLayout_2->addWidget(tidnumber);

        tphonenumber = new QLabel(layoutWidget1);
        tphonenumber->setObjectName("tphonenumber");

        verticalLayout_2->addWidget(tphonenumber);

        ttime = new QLabel(layoutWidget1);
        ttime->setObjectName("ttime");

        verticalLayout_2->addWidget(ttime);

        tlevel = new QLabel(layoutWidget1);
        tlevel->setObjectName("tlevel");

        verticalLayout_2->addWidget(tlevel);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(10, 10, 961, 601));
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        correct = new QPushButton(tab_7);
        correct->setObjectName("correct");
        correct->setGeometry(QRect(520, 430, 151, 41));
        layoutWidget2 = new QWidget(tab_7);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(270, 80, 401, 321));
        verticalLayout_5 = new QVBoxLayout(layoutWidget2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_18 = new QLabel(layoutWidget2);
        label_18->setObjectName("label_18");

        horizontalLayout->addWidget(label_18);

        lname = new QLineEdit(layoutWidget2);
        lname->setObjectName("lname");

        horizontalLayout->addWidget(lname);

        label_19 = new QLabel(layoutWidget2);
        label_19->setObjectName("label_19");

        horizontalLayout->addWidget(label_19);

        lsex = new QLineEdit(layoutWidget2);
        lsex->setObjectName("lsex");

        horizontalLayout->addWidget(lsex);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_20 = new QLabel(layoutWidget2);
        label_20->setObjectName("label_20");

        horizontalLayout_3->addWidget(label_20);

        lidnumber = new QLineEdit(layoutWidget2);
        lidnumber->setObjectName("lidnumber");

        horizontalLayout_3->addWidget(lidnumber);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_21 = new QLabel(layoutWidget2);
        label_21->setObjectName("label_21");

        horizontalLayout_4->addWidget(label_21);

        lphonenumber = new QLineEdit(layoutWidget2);
        lphonenumber->setObjectName("lphonenumber");

        horizontalLayout_4->addWidget(lphonenumber);


        verticalLayout_5->addLayout(horizontalLayout_4);

        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        correctpassword = new QPushButton(tab_8);
        correctpassword->setObjectName("correctpassword");
        correctpassword->setGeometry(QRect(562, 397, 131, 41));
        layoutWidget3 = new QWidget(tab_8);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(240, 100, 452, 251));
        verticalLayout_7 = new QVBoxLayout(layoutWidget3);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_22 = new QLabel(layoutWidget3);
        label_22->setObjectName("label_22");

        horizontalLayout_2->addWidget(label_22);

        oldpassword = new QLineEdit(layoutWidget3);
        oldpassword->setObjectName("oldpassword");

        horizontalLayout_2->addWidget(oldpassword);


        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_23 = new QLabel(layoutWidget3);
        label_23->setObjectName("label_23");

        horizontalLayout_5->addWidget(label_23);

        newpasword = new QLineEdit(layoutWidget3);
        newpasword->setObjectName("newpasword");

        horizontalLayout_5->addWidget(newpasword);


        verticalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_30 = new QLabel(layoutWidget3);
        label_30->setObjectName("label_30");

        horizontalLayout_6->addWidget(label_30);

        rnewpassword = new QLineEdit(layoutWidget3);
        rnewpassword->setObjectName("rnewpassword");

        horizontalLayout_6->addWidget(rnewpassword);


        verticalLayout_7->addLayout(horizontalLayout_6);

        tabWidget_2->addTab(tab_8, QString());
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        history = new QTableView(tab_2);
        history->setObjectName("history");
        history->setGeometry(QRect(30, 10, 941, 581));
        tabWidget->addTab(tab_2, QString());
        tab_13 = new QWidget();
        tab_13->setObjectName("tab_13");
        textBrowser = new QTextBrowser(tab_13);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(140, 30, 681, 541));
        tabWidget->addTab(tab_13, QString());

        retranslateUi(customer);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(customer);
    } // setupUi

    void retranslateUi(QWidget *customer)
    {
        customer->setWindowTitle(QCoreApplication::translate("customer", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("customer", "\344\274\232\345\221\230\345\217\267\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("customer", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("customer", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("customer", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("customer", "\347\224\265\350\257\235\345\217\267\347\240\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("customer", "\350\277\220\345\212\250\346\227\266\351\225\277\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("customer", "\344\274\232\345\221\230\347\255\211\347\272\247\357\274\232", nullptr));
        tid->setText(QString());
        tname->setText(QString());
        tsex->setText(QString());
        tidnumber->setText(QString());
        tphonenumber->setText(QString());
        ttime->setText(QString());
        tlevel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("customer", "\344\270\252\344\272\272\344\277\241\346\201\257\346\237\245\347\234\213", nullptr));
        correct->setText(QCoreApplication::translate("customer", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        label_18->setText(QCoreApplication::translate("customer", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_19->setText(QCoreApplication::translate("customer", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_20->setText(QCoreApplication::translate("customer", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", nullptr));
        label_21->setText(QCoreApplication::translate("customer", "\347\224\265\350\257\235\345\217\267\347\240\201\357\274\232", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QCoreApplication::translate("customer", "\345\237\272\346\234\254\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        correctpassword->setText(QCoreApplication::translate("customer", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        label_22->setText(QCoreApplication::translate("customer", "\346\227\247\345\257\206\347\240\201\357\274\232", nullptr));
        label_23->setText(QCoreApplication::translate("customer", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        newpasword->setText(QString());
        label_30->setText(QCoreApplication::translate("customer", "\346\226\260\345\257\206\347\240\201\347\241\256\350\256\244\357\274\232", nullptr));
        rnewpassword->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QCoreApplication::translate("customer", "\345\257\206\347\240\201\344\277\256\346\224\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("customer", "\344\270\252\344\272\272\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("customer", "\346\266\210\350\264\271\345\216\206\345\217\262\346\237\245\350\257\242", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("customer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\346\245\267\344\275\223'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> \345\201\245\350\272\253\346\210\277\344\274\232\345\221\230\346\224\277\347\255\226</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1.\344\270\200\346\254\241\346\200\247\345\205\205\345\200\274200\345\205\203\344\273\245\344\270\212\345\215\263\345\217\257\346\210\220"
                        "\344\270\272\344\274\232\345\221\230\343\200\202</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2.\346\257\217\346\266\210\350\264\271100\345\205\203\357\274\214\344\274\232\345\221\230\347\255\211\347\272\247\344\270\212\345\215\207\344\270\200\347\272\247\343\200\20210\347\272\247\345\210\26050\347\272\247\345\217\257\344\272\253\345\217\2279\346\212\230\344\274\230\346\203\240\357\274\21450\347\272\247\345\210\260100\347\272\247\345\217\257\344\272\253\345\217\2278\346\212\230\344\274\230\346\203\240\343\200\202100\347\272\247\344\273\245\344\270\212\344\272\253\345\217\2276\346\212\230\344\274\230\346\203\240\343\200\202</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3.\351\232\217\346\227\266\345\217\257\344\273\245\351\200\200\345\207\272\344\274\232\345\221\230\357\274\214\345\271\266\345\217\257\351\200\200"
                        "\345\233\236\345\205\250\351\203\250\344\275\231\351\242\235\357\274\214\344\275\206\347\255\211\347\272\247\344\270\215\350\275\254\347\247\273\344\270\215\344\277\235\347\225\231\343\200\202\351\200\200\345\207\272\344\274\232\345\221\230\350\257\267\345\210\260\345\211\215\345\217\260\345\221\230\345\267\245\345\244\204\350\277\233\350\241\214\343\200\202</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">4.\351\200\200\345\207\272\344\274\232\345\221\230\345\220\216\357\274\214\346\266\210\350\264\271\345\216\206\345\217\262\344\273\215\347\204\266\344\274\232\344\277\235\347\225\231\343\200\202</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_13), QCoreApplication::translate("customer", "\344\274\232\345\221\230\346\224\277\347\255\226\346\237\245\347\234\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customer: public Ui_customer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMER_H
