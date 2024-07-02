#include "help.h"
#include "ui_help.h"
#include "connection.h"
#include "customer.h"

help::help(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::help)
{
    ui->setupUi(this);
    this->setWindowTitle("密码/会员号找回");     //设置界面属性
    this->setFixedSize(800,530);

    data::Connection();                     //连接数据库
}

//信息找回
void help::on_pushButton_clicked()
{
    customer cus;

    //获取输入
    cus.name=ui->lineEdit->text();
    cus.idnumber=ui->lineEdit_2->text();
    cus.phonenumber=ui->lineEdit_3->text();

    if(cus.name.isEmpty())                //检测输入异常
    {
        QMessageBox::information(this, "提示","请先输入姓名，谢谢！",QMessageBox::Ok);
        ui->lineEdit->setFocus();
    }
    else if(cus.idnumber.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入身份证号，谢谢！",QMessageBox::Ok);
        ui->lineEdit_2->setFocus();
    }
    else if(cus.phonenumber.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入电话号码，谢谢！",QMessageBox::Ok);
        ui->lineEdit_3->setFocus();
    }
    else        //基本输入没有问题,开始验证匹配
    {
        QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");
        QSqlQuery query=QSqlQuery(database);
        QString str =tr("select * from customers where name = '%1' and idnumber = '%2' and phonenumber='%3'").arg(cus.name,cus.idnumber,cus.phonenumber);
        query.exec(str);

        if(!query.next())       //会员号与密码错误
        {
            QMessageBox::information(this, "提示","输入信息有误！",QMessageBox::Ok);
            ui->lineEdit->setFocus();
        }
        else                    //验证正确，显示信息
        {
            //借助上面查询得到相应值
            cus.id=query.value("id").toString();
            cus.password=query.value("password").toString();

            //显示值
            ui->label_5->setText(cus.id);
            ui->label_7->setText(cus.password);
            QMessageBox::information(this, "提示","该用户的会员号是:"+cus.id+"<br><br>"+
                                     "密码是："+cus.password,QMessageBox::Ok);
        }
    }
}

help::~help()
{
    delete ui;
    data::closeConnection();//关闭数据库
}
