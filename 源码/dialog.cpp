#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include"connection.h"
#include"controler.h"
#include <QApplication>
#include<QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("登陆界面");
    this->setFixedSize(1000,660);

    data::createConnection();       //初始化数据库
}

Dialog::~Dialog()
{
    delete ui;
    data::closeConnection();       //关闭数据库
}

void Dialog::on_erpass_clicked()    //员工登录
{
    QString name = ui->ername->text();
    QString password = ui->erpassword->text();

    if(name.isEmpty())
    {
        QMessageBox::information(this, "请输入姓名","请先输入姓名再登陆，谢谢！",QMessageBox::Ok);
        ui->ername->setFocus();
    }
    else if(password.isEmpty())
    {
        QMessageBox::information(this, "请输入密码","请先输入密码再登陆，谢谢！",QMessageBox::Ok);
        ui->erpassword->setFocus();
    }
    else if(name=="老板"&&password=="123456")
    {
        QMessageBox::information(this,"提示","登陆成功！",QMessageBox::Ok);
        controler *w=new controler;
        this ->close();
        w ->show();
    }
    else
    {
        QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");
        QSqlQuery query=QSqlQuery(database);
        QString str =tr("select * from employees where name = '%1' and password = '%2'").arg(name,password);

        query.exec(str);

        if(!query.next())
        {
            QMessageBox::information(this,"提示","用户名或密码错误！",QMessageBox::Ok);
            ui->erpassword->clear();
            ui->erpassword->setFocus();
        }
        else
        {
            QMessageBox::information(this,"提示","登陆成功！",QMessageBox::Ok);
            controler *w=new controler;     //给正式窗口创建一个对象
            this ->close();                 //当前窗体关闭
            w ->show();                     //正式窗口显示出来
        }
    }
}

void Dialog::on_checkBox_2_clicked()        //显示密码
{
    if (ui->checkBox_2->isChecked()==true)
    {
        ui->erpassword->setEchoMode(QLineEdit::Normal);
    }
    else if(ui->checkBox_2->isChecked()==false)
    {
        ui->erpassword->setEchoMode(QLineEdit::Password);
    }
}
