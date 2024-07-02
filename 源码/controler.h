#ifndef CONTROLER_H
#define CONTROLER_H

#include <QWidget>
#include<QRadioButton>

namespace Ui
{
    class controler;
}

//controler类用于实现有关会员的大部分操作
class controler : public QWidget
{
    Q_OBJECT

public:
    explicit controler(QWidget *parent = nullptr);
    ~controler();

private slots:

    void on_newerset_clicked();             //员工登记

    void on_newerset_2_clicked();           //员工信息删除

    void on_eepass_clicked();               //会员登录管理信息

    void on_pushButton_clicked();           //新会员信息登记

    void on_pushButton_2_clicked();         //刷新财政收入表格

    void on_pushButton_3_clicked();         //会员用会员卡消费

    void on_pushButton_4_clicked();         //会员卡充钱

    void on_pushButton_5_clicked();         //会员用现金消费

    void on_pushButton_6_clicked();         //会员续费

    void on_pushButton_7_clicked();         //用户进入健身房打卡

    void on_pushButton_8_clicked();         //打开密码与会员号找回窗口

    void on_pushButton_9_clicked();

private:
    Ui::controler *ui;
};

//employee类用于封装员工信息
class employee
{
public:
    QString name;       //员工姓名
    QString password;   //员工密码
};

#endif // CONTROLER_H
