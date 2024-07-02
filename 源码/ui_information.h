/********************************************************************************
** Form generated from reading UI file 'information.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATION_H
#define UI_INFORMATION_H

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

class Ui_information
{
public:
    QTabWidget *tabWidget_2;
    QWidget *tab_7;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label;
    QLabel *label_21;
    QWidget *layoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QLabel *tid;
    QLabel *tname;
    QLabel *tsex;
    QLabel *tidnumber;
    QLabel *tphonenumber;
    QLabel *ttime;
    QLabel *tlevel;
    QLabel *tkind;
    QLabel *tmoney;
    QWidget *tab_8;
    QTabWidget *tabWidget_3;
    QWidget *tab_9;
    QWidget *layoutWidget_7;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_34;
    QLineEdit *lname;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lsex;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lidnumber;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_37;
    QLineEdit *lphonenumber;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *correct;
    QPushButton *pushButton_7;
    QWidget *tab_10;
    QPushButton *correctpassword;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_39;
    QLineEdit *newpassword;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_40;
    QLineEdit *rnewpassword;
    QWidget *tab_11;
    QTableView *tableView;
    QWidget *tab_13;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *information)
    {
        if (information->objectName().isEmpty())
            information->setObjectName("information");
        information->resize(1003, 661);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/image/titleimage.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        information->setWindowIcon(icon);
        tabWidget_2 = new QTabWidget(information);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(10, 10, 991, 641));
        tabWidget_2->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";"));
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        layoutWidget_5 = new QWidget(tab_7);
        layoutWidget_5->setObjectName("layoutWidget_5");
        layoutWidget_5->setGeometry(QRect(290, 50, 198, 501));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_5);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_27 = new QLabel(layoutWidget_5);
        label_27->setObjectName("label_27");

        verticalLayout_5->addWidget(label_27);

        label_28 = new QLabel(layoutWidget_5);
        label_28->setObjectName("label_28");

        verticalLayout_5->addWidget(label_28);

        label_29 = new QLabel(layoutWidget_5);
        label_29->setObjectName("label_29");

        verticalLayout_5->addWidget(label_29);

        label_30 = new QLabel(layoutWidget_5);
        label_30->setObjectName("label_30");

        verticalLayout_5->addWidget(label_30);

        label_31 = new QLabel(layoutWidget_5);
        label_31->setObjectName("label_31");

        verticalLayout_5->addWidget(label_31);

        label_32 = new QLabel(layoutWidget_5);
        label_32->setObjectName("label_32");

        verticalLayout_5->addWidget(label_32);

        label_33 = new QLabel(layoutWidget_5);
        label_33->setObjectName("label_33");

        verticalLayout_5->addWidget(label_33);

        label = new QLabel(layoutWidget_5);
        label->setObjectName("label");

        verticalLayout_5->addWidget(label);

        label_21 = new QLabel(layoutWidget_5);
        label_21->setObjectName("label_21");

        verticalLayout_5->addWidget(label_21);

        layoutWidget_6 = new QWidget(tab_7);
        layoutWidget_6->setObjectName("layoutWidget_6");
        layoutWidget_6->setGeometry(QRect(470, 50, 291, 501));
        verticalLayout_6 = new QVBoxLayout(layoutWidget_6);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        tid = new QLabel(layoutWidget_6);
        tid->setObjectName("tid");

        verticalLayout_6->addWidget(tid);

        tname = new QLabel(layoutWidget_6);
        tname->setObjectName("tname");

        verticalLayout_6->addWidget(tname);

        tsex = new QLabel(layoutWidget_6);
        tsex->setObjectName("tsex");

        verticalLayout_6->addWidget(tsex);

        tidnumber = new QLabel(layoutWidget_6);
        tidnumber->setObjectName("tidnumber");

        verticalLayout_6->addWidget(tidnumber);

        tphonenumber = new QLabel(layoutWidget_6);
        tphonenumber->setObjectName("tphonenumber");

        verticalLayout_6->addWidget(tphonenumber);

        ttime = new QLabel(layoutWidget_6);
        ttime->setObjectName("ttime");

        verticalLayout_6->addWidget(ttime);

        tlevel = new QLabel(layoutWidget_6);
        tlevel->setObjectName("tlevel");

        verticalLayout_6->addWidget(tlevel);

        tkind = new QLabel(layoutWidget_6);
        tkind->setObjectName("tkind");

        verticalLayout_6->addWidget(tkind);

        tmoney = new QLabel(layoutWidget_6);
        tmoney->setObjectName("tmoney");

        verticalLayout_6->addWidget(tmoney);

        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        tabWidget_3 = new QTabWidget(tab_8);
        tabWidget_3->setObjectName("tabWidget_3");
        tabWidget_3->setGeometry(QRect(0, 0, 961, 601));
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        layoutWidget_7 = new QWidget(tab_9);
        layoutWidget_7->setObjectName("layoutWidget_7");
        layoutWidget_7->setGeometry(QRect(270, 50, 401, 311));
        verticalLayout_7 = new QVBoxLayout(layoutWidget_7);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName("horizontalLayout_27");
        label_34 = new QLabel(layoutWidget_7);
        label_34->setObjectName("label_34");

        horizontalLayout_27->addWidget(label_34);

        lname = new QLineEdit(layoutWidget_7);
        lname->setObjectName("lname");

        horizontalLayout_27->addWidget(lname);


        verticalLayout_7->addLayout(horizontalLayout_27);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget_7);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        lsex = new QLineEdit(layoutWidget_7);
        lsex->setObjectName("lsex");

        horizontalLayout_2->addWidget(lsex);


        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget_7);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        lidnumber = new QLineEdit(layoutWidget_7);
        lidnumber->setObjectName("lidnumber");

        horizontalLayout_3->addWidget(lidnumber);


        verticalLayout_7->addLayout(horizontalLayout_3);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName("horizontalLayout_29");
        label_37 = new QLabel(layoutWidget_7);
        label_37->setObjectName("label_37");

        horizontalLayout_29->addWidget(label_37);

        lphonenumber = new QLineEdit(layoutWidget_7);
        lphonenumber->setObjectName("lphonenumber");

        horizontalLayout_29->addWidget(lphonenumber);


        verticalLayout_7->addLayout(horizontalLayout_29);

        layoutWidget = new QWidget(tab_9);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(270, 420, 401, 38));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        correct = new QPushButton(layoutWidget);
        correct->setObjectName("correct");

        horizontalLayout->addWidget(correct);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName("pushButton_7");

        horizontalLayout->addWidget(pushButton_7);

        tabWidget_3->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        correctpassword = new QPushButton(tab_10);
        correctpassword->setObjectName("correctpassword");
        correctpassword->setGeometry(QRect(562, 397, 131, 41));
        widget = new QWidget(tab_10);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(240, 160, 452, 171));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName("horizontalLayout_31");
        label_39 = new QLabel(widget);
        label_39->setObjectName("label_39");

        horizontalLayout_31->addWidget(label_39);

        newpassword = new QLineEdit(widget);
        newpassword->setObjectName("newpassword");
        newpassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_31->addWidget(newpassword);


        verticalLayout->addLayout(horizontalLayout_31);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName("horizontalLayout_32");
        label_40 = new QLabel(widget);
        label_40->setObjectName("label_40");

        horizontalLayout_32->addWidget(label_40);

        rnewpassword = new QLineEdit(widget);
        rnewpassword->setObjectName("rnewpassword");
        rnewpassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_32->addWidget(rnewpassword);


        verticalLayout->addLayout(horizontalLayout_32);

        tabWidget_3->addTab(tab_10, QString());
        tabWidget_2->addTab(tab_8, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName("tab_11");
        tableView = new QTableView(tab_11);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 951, 571));
        tableView->setLineWidth(1);
        tableView->verticalHeader()->setMinimumSectionSize(37);
        tableView->verticalHeader()->setDefaultSectionSize(37);
        tableView->verticalHeader()->setHighlightSections(true);
        tabWidget_2->addTab(tab_11, QString());
        tab_13 = new QWidget();
        tab_13->setObjectName("tab_13");
        textBrowser = new QTextBrowser(tab_13);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(100, 40, 771, 541));
        tabWidget_2->addTab(tab_13, QString());

        retranslateUi(information);

        tabWidget_2->setCurrentIndex(3);
        tabWidget_3->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(information);
    } // setupUi

    void retranslateUi(QWidget *information)
    {
        information->setWindowTitle(QCoreApplication::translate("information", "Form", nullptr));
        label_27->setText(QCoreApplication::translate("information", "\344\274\232\345\221\230\345\217\267\357\274\232", nullptr));
        label_28->setText(QCoreApplication::translate("information", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_29->setText(QCoreApplication::translate("information", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_30->setText(QCoreApplication::translate("information", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", nullptr));
        label_31->setText(QCoreApplication::translate("information", "\347\224\265\350\257\235\345\217\267\347\240\201\357\274\232", nullptr));
        label_32->setText(QCoreApplication::translate("information", "\345\201\245\350\272\253\345\215\241\345\210\260\346\234\237\346\227\245\357\274\232", nullptr));
        label_33->setText(QCoreApplication::translate("information", "\344\274\232\345\221\230\347\255\211\347\272\247\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("information", "\344\274\232\345\221\230\350\272\253\344\273\275\357\274\232", nullptr));
        label_21->setText(QCoreApplication::translate("information", "\344\275\231\351\242\235\357\274\210\345\205\203\357\274\211\357\274\232", nullptr));
        tid->setText(QString());
        tname->setText(QString());
        tsex->setText(QString());
        tidnumber->setText(QString());
        tphonenumber->setText(QString());
        ttime->setText(QString());
        tlevel->setText(QString());
        tkind->setText(QString());
        tmoney->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QCoreApplication::translate("information", "\344\270\252\344\272\272\344\277\241\346\201\257\346\237\245\347\234\213", nullptr));
        label_34->setText(QCoreApplication::translate("information", "\345\247\223\345\220\215\357\274\232   ", nullptr));
        label_2->setText(QCoreApplication::translate("information", "\346\200\247\345\210\253:    ", nullptr));
        label_3->setText(QCoreApplication::translate("information", "\350\272\253\344\273\275\350\257\201\345\217\267:", nullptr));
        label_37->setText(QCoreApplication::translate("information", "\347\224\265\350\257\235\345\217\267\347\240\201:", nullptr));
        correct->setText(QCoreApplication::translate("information", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        pushButton_7->setText(QCoreApplication::translate("information", "\351\200\200\345\207\272\344\274\232\345\221\230", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_9), QCoreApplication::translate("information", "\345\237\272\346\234\254\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        correctpassword->setText(QCoreApplication::translate("information", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        label_39->setText(QCoreApplication::translate("information", "\346\226\260\345\257\206\347\240\201\357\274\232    ", nullptr));
        newpassword->setText(QString());
        label_40->setText(QCoreApplication::translate("information", "\346\226\260\345\257\206\347\240\201\347\241\256\350\256\244\357\274\232", nullptr));
        rnewpassword->setText(QString());
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_10), QCoreApplication::translate("information", "\345\257\206\347\240\201\344\277\256\346\224\271", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QCoreApplication::translate("information", "\344\270\252\344\272\272\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_11), QCoreApplication::translate("information", "\346\266\210\350\264\271\345\216\206\345\217\262\346\237\245\350\257\242", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("information", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'\346\245\267\344\275\223'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> \345\201\245\350\272\253\346\210\277\344\274\232\345\221\230\346\224\277\347\255\226\347\256\200\344\273\213</p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-le"
                        "ft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1.\345\234\250\346\234\254\345\201\245\350\272\253\346\210\277\345\212\236\347\220\206\346\234\210\345\215\241\343\200\201\345\255\243\345\215\241\346\210\226\345\271\264\345\215\241\345\215\263\345\217\257\346\210\220\344\270\272\344\274\232\345\221\230\343\200\202</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:6pt;\"> </span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2.\344\274\232\345\221\230\345\215\241\345\217\257\344\273\245\345\255\230\345\205\245\351\222\261\343\200\202\344\275\277\347\224\250\344\274\232\345\221\230\345\215\241\344\270\255\347\232\204\351\222\261\350\264\255\344\271\260\345\225\206\345\223\201\357\274\214\345\217\257\344\272\253\345\217\2279.5\346\212\230\344\274\230\346\203\240\343\200\202\351\231"
                        "\244\351\235\236\351\200\200\345\207\272\344\274\232\345\221\230\357\274\214\345\255\230\345\205\245\344\274\232\345\221\230\345\215\241\344\270\255\347\232\204\351\222\261\344\270\215\344\272\210\351\200\200\350\277\230\343\200\202</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:6pt;\"> </span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3.\346\257\217\346\266\210\350\264\271100\345\205\203\357\274\214\344\274\232\345\221\230\347\255\211\347\272\247\344\270\212\345\215\207\344\270\200\347\272\247\343\200\202\345\234\250\350\264\255\344\271\260\344\273\273\346\204\217\345\225\206\345\223\201\346\210\226\346\234\215\345\212\241\346\227\266\357\274\214\344\274\232\345\221\23010\347\272\247\345\210\26030\347\272\247\345\217\257\344\272\253\345\217\2279\346\212\230\344\274\230\346\203\240\357"
                        "\274\21431\347\272\247\345\210\26070\347\272\247\345\217\257\344\272\253\345\217\2278.5\346\212\230\344\274\230\346\203\240,71\347\272\247\345\210\260100\347\272\247\344\272\253\345\217\2278\346\212\230\344\274\230\346\203\240\357\274\214101\347\272\247\345\217\212\344\273\245\344\270\212\344\272\253\345\217\2277\346\212\230\344\274\230\346\203\240\343\200\202\346\263\250\346\204\217\357\274\214\345\246\202\347\254\246\345\220\210\347\233\270\345\272\224\346\235\241\344\273\266\357\274\214\346\255\244\345\244\204\346\212\230\346\211\243\345\217\257\344\273\245\344\270\216\347\254\2542\346\235\241\344\270\255\346\211\200\350\256\276\346\212\230\346\211\243\345\217\240\345\212\240\343\200\202</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:6pt;\"> </span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-inde"
                        "nt:0px;\">3.\351\232\217\346\227\266\345\217\257\344\273\245\351\200\200\345\207\272\344\274\232\345\221\230\357\274\214\344\275\206\347\255\211\347\272\247\344\270\215\350\275\254\347\247\273\344\270\215\344\277\235\347\225\231\343\200\202\351\231\244\351\235\236\344\274\232\345\221\230\350\272\253\344\275\223\346\203\205\345\206\265\346\201\266\345\214\226\346\227\240\346\263\225\344\272\253\345\217\227\347\233\270\345\205\263\346\234\215\345\212\241\346\210\226\346\200\200\345\255\225\347\255\211\345\205\266\344\273\226\346\236\201\347\211\271\346\256\212\346\203\205\345\206\265\357\274\214\351\200\200\345\215\241\346\210\226\351\200\200\345\207\272\344\274\232\345\221\230\344\270\215\344\274\232\351\200\200\351\231\244\345\211\251\344\275\231\344\272\253\345\217\227\344\274\232\345\221\230\346\234\215\345\212\241\347\232\204\346\227\266\351\227\264\347\232\204\345\212\236\345\215\241\350\264\271\347\224\250\343\200\202\351\200\200\345\207\272\344\274\232\345\221\230\345\220\216\357\274\214\344\274\232\345\221"
                        "\230\345\215\241\344\270\255\347\232\204\344\275\231\351\242\235\345\217\257\344\273\245\351\200\200\350\277\230\357\274\214\346\266\210\350\264\271\345\216\206\345\217\262\344\273\215\347\204\266\344\274\232\344\277\235\347\225\231\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:6pt;\"> </span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">4.\344\274\232\345\221\230\346\235\203\347\233\212\345\217\252\350\203\275\347\224\261\344\274\232\345\221\230\346\234\254\344\272\272\344\272\253\345\217\227\343\200\202\345\217\257\344\273\245\350\275\254\350\256\251\344\274\232\345\221\230\357\274\214\344\275\206\351\234\200\344\274\232\345\221\230\346\234\254\344\272\272\345\257\273\346\211\276\346\204\277\346\204\217\346\216\245\345\217\227\350\275\254\350\256\251\347\232\204\344\272\272\357\274\214\345\271"
                        "\266\347\224\261\345\205\266\344\270\255\344\270\200\346\226\271\346\217\220\344\276\233\350\275\254\350\256\251\350\264\27150\345\205\203\343\200\202</p></body></html>", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_13), QCoreApplication::translate("information", "\344\274\232\345\221\230\346\224\277\347\255\226\347\256\200\344\273\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class information: public Ui_information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATION_H
