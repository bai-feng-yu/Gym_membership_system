#include "information.h"
#include "ui_information.h"
#include "connection.h"
#include"customer.h"
#include"QSqlTableModel"
#include<QDateTime>

extern QString sendid;          //用于接收登录会员的会员号

information::information(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::information)
{
    ui->setupUi(this);
    this->setWindowTitle("信息查询与修改界面");
    this->setFixedSize(1000,660);
    data::Connection();         //连接数据库

    information::showdata() ;   //展示基本信息数据

    //可视化数据库
    QSqlTableModel *model = new QSqlTableModel(this);                   //创建操作对象

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->setMinimumSectionSize(100);      //设置宽高自适应
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //设置不可在页面上修改数据

    model->setTable(sendid);            //匹配、显示数据库

    model->setHeaderData(0, Qt::Horizontal, "序号");
    model->setHeaderData(1, Qt::Horizontal, "操作时间");
    model->setHeaderData(2, Qt::Horizontal, "金额（元）");                  //设置列标题

    ui->tableView->setModel(model);
    model->select();
}

information::~information()
{
    delete ui;
    data::closeConnection();            //关闭数据库
}


//退出会员
void information::on_pushButton_7_clicked()
{
    //连接数据库并创建操作对象
    QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");

    //查询余额
    QString checkmoney=tr("SELECT money,level FROM customers WHERE id = '%1'").arg(sendid);
    QSqlQuery query2(checkmoney);
    query2.next();
    QString money = query2.value("money").toString();

    //弹出对话框再次确认是否退出会员
    QMessageBox box;
    box.setText("确认退出会员吗？");
    box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int ret=box.exec();
    switch(ret)
    {
    case QMessageBox::Yes:
        {
            QSqlQuery query3=QSqlQuery(database);

            //删除表
            QString deleteline=tr("delete from customers where id='%1'").arg(sendid);

            QDateTime now=QDateTime::currentDateTime();               //用于接收时间
            QString strtime = now.toString("yyyy-MM-dd hh:mm:ss");    //格式化时间

            //更新收入表
            QString update=tr("insert into income(time,money)"
                                "values('%1','%2')")
                                 .arg(strtime,"-"+money);

            if(query3.exec(deleteline)&&query3.exec(update))     //返回删除成功信息
            {
                QMessageBox::information(this,"提示","退出会员成功！需要返还会员"+money+"元",QMessageBox::Ok);
            }

            break;
        }

    case QMessageBox::No:
        {
            QMessageBox::information(this,"提示","退出会员失败！",QMessageBox::Ok);
            break;
        }
    }

}

//修改基本信息
void information::on_correct_clicked()
{
    customer cus;
    //对应获取修改后输入栏内容
    cus.name=ui->lname->text();
    cus.phonenumber=ui->lphonenumber->text();
    cus.sex=ui->lsex->text();
    cus.idnumber=ui->lidnumber->text();

    if(cus.name.isEmpty())
    {
        QMessageBox::information(this,"提示","请输入姓名",QMessageBox::Ok);
        ui->lname->setFocus();
    }
    else if(cus.phonenumber.isEmpty())
    {
        QMessageBox::information(this,"提示","请输入电话号码",QMessageBox::Ok);
        ui->lphonenumber->setFocus();
    }
    else if(cus.sex.isEmpty())
    {
        QMessageBox::information(this,"提示","请输入性别",QMessageBox::Ok);
        ui->lsex->setFocus();
    }
    else if(cus.idnumber.isEmpty())
    {
        QMessageBox::information(this,"提示","请输入身份证号码",QMessageBox::Ok);
        ui->lidnumber->setFocus();
    }
    else if(cus.phonenumber.length()!=11)        //考虑输入手机号格式不对的情况
    {
        QMessageBox::information(this,"提示","请输入格式正确的手机号",QMessageBox::Ok);
        ui->lphonenumber->setFocus();
    }
    else if(cus.idnumber.length()!=18)
    {
        QMessageBox::information(this, "请重新输入","请输入正确格式的身份证号，谢谢！",QMessageBox::Ok);
        ui->lidnumber->setFocus();
    }
    else
    {
        QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");     //连接数据库
        QSqlQuery query=QSqlQuery(database);

        QString update=tr("update customers set name ='%1',phonenumber='%2',sex='%3',idnumber='%4' where id='%5'")
                            .arg(cus.name,cus.phonenumber,cus.sex,cus.idnumber,sendid);                               //更新数据

        if(query.exec(update))      //判断修改是否成功
        {
            QMessageBox::information(this,"提示","修改成功！",QMessageBox::Ok);
            information::showdata();
        }
    }
}

//展示个人基本信息的函数
void information::showdata()
{
    //查询基本信息
    QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");
    QString str =tr("select * from customers where id = '%1' ").arg(sendid);    //查询
    QSqlQuery query=QSqlQuery(str); //创建操作对象
    query.next();                   //指针下移到第一个数据

    //显示基本信息
    ui->tid->setText(sendid);
    ui->tname->setText(query.value("name").toString());
    ui->tsex->setText(query.value("sex").toString());
    ui->tidnumber->setText(query.value("idnumber").toString());
    ui->tphonenumber->setText(query.value("phonenumber").toString());
    ui->tmoney->setText(query.value("money").toString());
    ui->tlevel->setText(query.value("level").toString());
    ui->ttime->setText(query.value("time").toString());
    ui->lname->setText(query.value("name").toString());
    ui->lphonenumber->setText(query.value("phonenumber").toString());
    ui->tkind->setText(query.value("kind").toString());
    ui->lidnumber->setText(query.value("idnumber").toString());
    ui->lsex->setText(query.value("sex").toString());
}

//修改密码
void information::on_correctpassword_clicked()
{
    //从输入框中获取相应信息
    QString newpassword=ui->newpassword->text();
    QString rnewpassword=ui->rnewpassword->text();

    if(newpassword.isEmpty())
    {
        QMessageBox::information(this,"提示","请输入新密码",QMessageBox::Ok);
        ui->newpassword->setFocus();
    }
    else if(newpassword.length()<5)        //判断密码长度，防止使用强度太低的密码
    {
        QMessageBox::information(this, "请重新输入密码","密码强度过弱，请输入5个字符以上的密码，谢谢！",QMessageBox::Ok);
        ui->newpassword->setFocus();
    }
    else if(rnewpassword.isEmpty())
    {
        QMessageBox::information(this,"提示","请再次输入新密码",QMessageBox::Ok);
        ui->rnewpassword->setFocus();
    }
    else if(newpassword != rnewpassword)
    {
        QMessageBox::information(this,"提示","两次输入的新密码不一致",QMessageBox::Ok);
        ui->rnewpassword->setFocus();
    }
    else
    {
        QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");     //连接数据库
        QSqlQuery query=QSqlQuery(database);

        QString update=tr("update customers set password='%1' where id='%2'")
                            .arg(newpassword,sendid);                               //更新数据

        if(query.exec(update))      //判断修改是否成功
        {
            QMessageBox::information(this,"提示","修改成功！",QMessageBox::Ok);
            information::showdata();

            //清除输入数据
            ui->newpassword->clear();
            ui->rnewpassword->clear();
        }
    }
}
