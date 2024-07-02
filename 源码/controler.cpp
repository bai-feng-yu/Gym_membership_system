#include "controler.h"
#include "ui_controler.h"
#include"connection.h"
#include"information.h"
#include"customer.h"
#include"help.h"
#include"QDateTime"
#include"QDate"
#include"QSqlTableModel"

QString sendid;  //用于给信息查询窗口传值

void setfalse(QRadioButton* a);     //声明取消radiobutton选中函数

controler::controler(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::controler)
{
    ui->setupUi(this);
    this->setWindowTitle("员工操作界面");     //设置界面属性
    this->setFixedSize(1000,660);

    data::Connection();                     //连接数据库

    //可视化数据库
    QSqlTableModel *model = new QSqlTableModel(this);                           //创建操作对象

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->setMinimumSectionSize(100);              //设置宽高自适应
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);          //设置不可在页面上修改数据

    model->setTable("income");//连接对应表

    model->setHeaderData(0, Qt::Horizontal, "操作时间");
    model->setHeaderData(1, Qt::Horizontal, "充值金额（元）");     //设置列标题
    ui->tableView->setModel(model);                              //显示数据
    model->select();
}

controler::~controler()
{
    delete ui;
    data::closeConnection();                //关闭数据库
}

//-------------------------------------------员工管理板块-------------------------------------------------------//

//员工登记
void controler::on_newerset_clicked()
{
    employee emp;
    //对应获取输入栏内容，name:员工姓名，password：员工登陆密码，surepassword:管理员工专用密码
    emp.name = ui->newername->text();
    emp.password = ui->newerpassword->text();
    QString rpassword=ui->newerpassword_2->text();
    QString surepassword = ui->newerpassword_3->text();

    if(emp.name.isEmpty())                  //先判断输入异常
    {
        QMessageBox::information(this, "请输入姓名","请先输入姓名，谢谢！",QMessageBox::Ok);
        ui->newername->setFocus();
    }
    else if(emp.password.isEmpty())
    {
        QMessageBox::information(this, "请输入密码","请先输入员工密码，谢谢！",QMessageBox::Ok);
        ui->newerpassword->setFocus();
    }
    else if(emp.password.length()<5)
    {
        QMessageBox::information(this, "请重新输入密码","密码强度过弱，请输入5个字符以上的密码，谢谢！",QMessageBox::Ok);
        ui->newerpassword->setFocus();
    }
    else if(rpassword.isEmpty())
    {
        QMessageBox::information(this, "请再次输入密码","请再次确认密码，谢谢！",QMessageBox::Ok);
        ui->newerpassword_2->setFocus();
    }
    else if(surepassword.isEmpty())
    {
        QMessageBox::information(this, "请输入密码","请先输入管理员工专用操作密码，谢谢！",QMessageBox::Ok);
        ui->newerpassword_3->setFocus();
    }
    else if(rpassword!=emp.password)
    {
        QMessageBox::information(this, "请输入相同密码","两次密码不相同！",QMessageBox::Ok);
        ui->newerpassword_2->setFocus();
    }
    else if(surepassword!="654321")
    {
        QMessageBox::information(this, "请输入密码","请输入正确的管理员工专用操作密码，谢谢！",QMessageBox::Ok);
        ui->newerpassword_3->setFocus();
    }
    else
    {
        QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");
        QSqlQuery query=QSqlQuery(database);
        QString str=tr("insert into employees(name,password)"
                        "values('%1','%2')").arg(emp.name,emp.password);

        if(query.exec(str))     //判断是否成功
        {
            QMessageBox::information(this, "创建成功","创建成功",QMessageBox::Ok);
            ui->newername->clear();
            ui->newerpassword->clear();
            ui->newerpassword_2->clear();
            ui->newerpassword_3->clear();
        }
        else
        {
            QMessageBox::information(this, "创建失败","创建失败，请检查数据库连接",QMessageBox::Ok);
        }
    }
}

//员工信息删除
void controler::on_newerset_2_clicked()
{
    employee emp;
    //对应获取输入栏内容，name:员工姓名，password：员工登陆密码，surepassword:管理员工专用密码
    emp.name = ui->newername->text();
    emp.password = ui->newerpassword->text();
    QString surepassword = ui->newerpassword_3->text();

    if(emp.name.isEmpty())                      //先判断输入异常
    {
        QMessageBox::information(this, "请输入姓名","请先输入姓名，谢谢！",QMessageBox::Ok);
        ui->newername->setFocus();
    }
    else if(emp.password.isEmpty())
    {
        QMessageBox::information(this, "请输入密码","请先输入密码，谢谢！",QMessageBox::Ok);
        ui->newerpassword->setFocus();
    }
    else if(surepassword.isEmpty())
    {
        QMessageBox::information(this, "请输入密码","请先输入管理员工专用操作密码，谢谢！",QMessageBox::Ok);
        ui->newerpassword_3->setFocus();
    }
    else if(surepassword!="654321")
    {
        QMessageBox::information(this, "请输入密码","请输入正确的管理员工专用操作密码，谢谢！",QMessageBox::Ok);
        ui->newerpassword_3->setFocus();
    }
    else                //输入无异常
    {
        //判断输入的姓名与密码是否匹配
        QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");
        QSqlQuery query=QSqlQuery(database);

        QString str =tr("select * from employees where name = '%1' and password = '%2'").arg(emp.name,emp.password);

        query.exec(str);

        if(!query.next())       //姓名或密码错误
        {
            QMessageBox::information(this,"提示","删除失败，请检查姓名与密码是否正确",QMessageBox::Ok);
            ui->newerpassword->clear();
            ui->newerpassword->setFocus();
        }
        else                    //查询到姓名与密码匹配，进行删除
        {
            QString str2=tr("delete from employees where name='%1' and password='%2'")
                            .arg(emp.name,emp.password);

            if(query.exec(str2))
            {
                QMessageBox::information(this, "提示","删除成功",QMessageBox::Ok);
                ui->newername->clear();
                ui->newerpassword->clear();
                ui->newerpassword_2->clear();
                ui->newerpassword_3->clear();
            }
            else
            {
                QMessageBox::information(this, "提示","删除失败，请检查数据库连接",QMessageBox::Ok);
            }
        }
    }
}

//------------财政数据板块--------------//

//刷新表格
void controler::on_pushButton_2_clicked()
{
    QSqlTableModel *model = new QSqlTableModel(this);       //创建操作对象

    //设置显示数据表的宽高，与数据适应
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->setMinimumSectionSize(100);

    // 对应、显示数据
    model->setTable("income");

    model->setHeaderData(0, Qt::Horizontal, "操作时间");
    model->setHeaderData(1, Qt::Horizontal, "充值金额（元）");                  //设置列标题
    ui->tableView->setModel(model);
    model->select();
}

//统计数据
void controler::on_pushButton_9_clicked()
{
//总收入计算
    float sum=0;        //用于记录总收入

    //查询数据
    QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");
    QString calculate=tr("select * from income");
    QSqlQuery query(calculate);

    //遍历数据
    while(query.next())
    {
        float money=query.value("money").toFloat();
        sum+=money;
    }

    ui->label_27->setText(QString::number(sum,'f',2));//展示

//近一月收入计算
    float monthmoney=0;              //用于接收上月收入
    QDateTime now=QDateTime::currentDateTime();
    QDateTime lastmonth=now.addMonths(-1);      //获取上月时间

    QString calculate1=tr("select * from income");  //查询数据
    QSqlQuery query1(calculate1);

    //遍历数据
    while(query1.next())
    {
        QDateTime time=query1.value("time").toDateTime();

        if(time>lastmonth)
        {
            float money=query1.value("money").toFloat();
            monthmoney+=money;
        }
    }

    ui->label_29->setText(QString::number(monthmoney,'f',2));//展示

//近一周收入
    float weekmoney=0;              //用于接收上周收入
    QDateTime lastweek=now.addDays(-7);      //获取上周时间

    QString calculate2=tr("select * from income");  //查询数据
    QSqlQuery query2(calculate2);

    //遍历数据
    while(query2.next())
    {
        QDateTime time=query2.value("time").toDateTime();
        if(time>lastweek)
        {
            float money=query2.value("money").toFloat();
            weekmoney+=money;
        }
    }

    ui->label_31->setText(QString::number(weekmoney,'f',2));//展示
}

//---------------------------------------会员管理------------------------------------------------------//

//---用户进入健身房打卡板块---//
void controler::on_pushButton_7_clicked()
{
    customer cus;
    //获取输入信息
    cus.id=ui->lineEdit_9->text();
    cus.password=ui->lineEdit_12->text();

    if(cus.id.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入姓名，谢谢！",QMessageBox::Ok);
        ui->lineEdit_9->setFocus();
    }
    else if(cus.password.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入密码，谢谢！",QMessageBox::Ok);
        ui->lineEdit_12->setFocus();
    }
    else            //已输入信息，开始匹配
    {
        //查询会员号与密码
        QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");
        QSqlQuery query=QSqlQuery(database);
        QString str =tr("select * from customers where id = '%1' and password = '%2'").arg(cus.id,cus.password);
        query.exec(str);


        if(!query.next())       //会员号与密码错误
        {
            QMessageBox::information(this, "提示","输入信息有误！",QMessageBox::Ok);
        }
        else                    //信息正确，检测健身卡是否到期
        {
            cus.time=query.value("time").toString();            //接收到期时间
            QDateTime ltime = QDateTime::fromString(cus.time, "yyyy-MM-dd hh:mm:ss");  //转换类型，便于比较
            QDateTime now=QDateTime::currentDateTime();         //获取当前时间

            if(ltime>now)
            {
                QMessageBox::information(this, "提示","打卡成功，可以进入健身房！<br>"
                                                     "该用户的健身卡到期时间为："+cus.time+"<br>"
                                                     "如果快到期可提醒续费",QMessageBox::Ok);

            }
            else
            {
                QMessageBox::information(this, "提示","该用户的健身卡已到期，请先续费<br>"
                                                     "到期时间为："+cus.time+"<br>",QMessageBox::Ok);
            }
            ui->lineEdit_9->clear();
            ui->lineEdit_12->clear();
        }
    }
}

//----------新会员信息登记板块------------//
void controler::on_pushButton_clicked()
{
    customer cus;

    //获取输入信息，name:姓名，sex:性别，password:密码，idnumber:身份证号，phonenumber:电话号，money:存入的钱，TF:是否同意协议。
    cus.name = ui->lineEdit_3->text();
    cus.sex = ui->lineEdit->text();
    cus.password = ui->lineEdit_26->text();
    cus.idnumber = ui->lineEdit_4->text();
    cus.phonenumber=ui->lineEdit_7->text();
    cus.money=ui->lineEdit_2->text();
    QString TF=ui->lineEdit_6->text();

    QString tip;        //用于记录办卡信息
    bool ok;            //用于转变输入数据类型
    int intmoney=cus.money.toInt(&ok);    //intmoney用于记录充入的钱
    QDateTime now=QDateTime::currentDateTime();   //用于接收时间
    QDateTime ddl;      //创造操作对象，接收到期时间

    if(cus.name.isEmpty())              //输入异常
    {
        QMessageBox::information(this, "提示","请先输入姓名，谢谢！",QMessageBox::Ok);
        ui->lineEdit_3->setFocus();
    }
    else if(cus.sex.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入性别，谢谢！",QMessageBox::Ok);
        ui->lineEdit->setFocus();
    }
    else if(cus.password.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入密码，谢谢！",QMessageBox::Ok);
        ui->lineEdit_26->setFocus();
    }
    else if(cus.password.length()<5)        //判断密码长度，防止使用强度太低的密码
    {
        QMessageBox::information(this, "请重新输入密码","密码强度过弱，请输入5个字符以上的密码，谢谢！",QMessageBox::Ok);
        ui->lineEdit_26->setFocus();
    }
    else if(cus.idnumber.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入身份证号码，谢谢！",QMessageBox::Ok);
        ui->lineEdit_4->setFocus();
    }
    else if(cus.idnumber.length()!=18)
    {
        QMessageBox::information(this, "请重新输入","请输入正确格式的身份证号，谢谢！",QMessageBox::Ok);
        ui->lineEdit_4->setFocus();
    }
    else if(cus.phonenumber.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入电话号码，谢谢！",QMessageBox::Ok);
        ui->lineEdit_7->setFocus();
    }
    else if(cus.phonenumber.length()!=11)
    {
        QMessageBox::information(this, "请重新输入","请输入正确格式的电话号，谢谢！",QMessageBox::Ok);
        ui->lineEdit_7->setFocus();
    }
    else if(cus.money.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入初始充钱量，谢谢！",QMessageBox::Ok);
        ui->lineEdit_2->setFocus();
    }
    else if(ui->radioButton->isChecked()==false&&ui->radioButton_2->isChecked()==false&&ui->radioButton_3->isChecked()==false)
    {
        QMessageBox::information(this, "提示","注册会员至少需要选择办理一种类型的卡",QMessageBox::Ok);
    }
    else if(TF.isEmpty())
    {
        QMessageBox::information(this, "提示","请输入是否同意会员协议，谢谢！",QMessageBox::Ok);
        ui->lineEdit_6->setFocus();
    }
    else if(TF != "是")
    {
        QMessageBox::information(this, "提示","不同意会员协议无法注册，谢谢！",QMessageBox::Ok);
        ui->lineEdit_6->setFocus();
    }
    else if(ui->radioButton->isChecked()==true&&intmoney<2000)      //充钱不足
    {
        QMessageBox::information(this, "提示","注册年卡会员至少需要充值2000元以上",QMessageBox::Ok);
        ui->lineEdit_2->setFocus();
    }
    else if(ui->radioButton_2->isChecked()==true&&intmoney<500)     //充钱不足
    {
        QMessageBox::information(this, "提示","注册季卡会员至少需要充值500元以上",QMessageBox::Ok);
        ui->lineEdit_2->setFocus();
    }
    else if(ui->radioButton_3->isChecked()==true&&intmoney<200)     //充钱不足
    {
        QMessageBox::information(this, "提示","注册月卡会员至少需要充值200元以上",QMessageBox::Ok);
        ui->lineEdit_2->setFocus();
    }
    else        //所有输入信息都符合要求，开始正式登记
    {
        //判断办卡类型并扣除相应钱
        if (ui->radioButton->isChecked()==true)
        {
            cus.kind="年卡会员";
            intmoney-=2000;
            cus.level=QString::number(20);
            tip="本次为扣除注册年卡会员费用2000元后的余额";

            ddl=now.addMonths(12);
            cus.time=ddl.toString("yyyy-MM-dd hh:mm:ss");
        }
        else if (ui->radioButton_2->isChecked()==true)
        {
            cus.kind="季卡会员";
            intmoney-=500;
            cus.level=QString::number(5);
            tip="本次为扣除注册季卡会员费用500元后的余额";

            ddl=now.addMonths(3);
            cus.time=ddl.toString("yyyy-MM-dd hh:mm:ss");
        }
        else if (ui->radioButton_3->isChecked()==true)
        {
            cus.kind="月卡会员";
            intmoney-=200;
            cus.level=QString::number(2);
            tip="本次为扣除注册月卡会员费用200元后的余额";

            ddl=now.addMonths(1);
            cus.time=ddl.toString("yyyy-MM-dd hh:mm:ss");
        }

        QString qmoney= QString::number(intmoney);   //转变数据类型，用于将剩余钱数插入数据库

        //插入新用户数据
        QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");
        QSqlQuery query=QSqlQuery(database);
        QString str=tr("insert into customers(name,password,sex,idnumber,phonenumber,money,kind,level,time)"
                        "values('%1','%2','%3','%4','%5','%6','%7','%8','%9')")
                        .arg(cus.name,cus.password,cus.sex,cus.idnumber,cus.phonenumber,qmoney,cus.kind,cus.level,cus.time);

        if(query.exec(str))
        {
            //搜索id，用来向客户显示并创建消费历史表
            QString myid=tr("SELECT id FROM customers WHERE name = '%1'").arg(cus.name);
            QSqlQuery query=QSqlQuery(myid);

            query.last();     //考虑重名情况,移动指针指向最后一个记录

            QString thisid = query.value("id").toString();  //记录id

            //创建消费历史表
            QString history = QString("create table '%1' ("
                                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                      "time text not null,"
                                      "history text not null,"
                                      "tip text)")
                                      .arg(thisid);

            if(query.exec(history))     //创建历史消费表成功，则记录第一笔办卡消费
            {

                QDateTime dateTime= QDateTime::currentDateTime();               //获取系统当前的时间
                QString strtime = dateTime.toString("yyyy-MM-dd hh:mm:ss");    //格式化时间

                QSqlQuery query=QSqlQuery(database);
                //向该历史消费表插入第一笔充值
                QString begin=QString("insert into '%1'(time,history,tip)"
                                      "values('%2','%3','%4')")
                                      .arg(thisid,strtime,"+"+qmoney,tip);
                //向收入表插入数据
                QString income=tr("insert into income(time,money)"
                                    "values('%1','%2')")
                                     .arg(strtime,cus.money);

                if(query.exec(begin)&&query.exec(income))   //插入数据成功，则显示成功并展示会员码
                {
                    QMessageBox::information(this, "创建成功","会员创建成功，会员码为："+thisid,QMessageBox::Ok);
                    ui->label_76->setText(thisid);

                    //清理续费输入的信息
                    ui->lineEdit_3->clear();
                    ui->lineEdit->clear();
                    ui->lineEdit_26->clear();
                    ui->lineEdit_4->clear();
                    ui->lineEdit_7->clear();
                    ui->lineEdit_2->clear();
                    ui->lineEdit_6->clear();
                    setfalse(ui->radioButton);
                    setfalse(ui->radioButton_2);
                    setfalse(ui->radioButton_3);
                }
            }
        }
        else
        {
            QMessageBox::information(this, "创建失败","创建失败",QMessageBox::Ok);
        }
    }
}

//--------------管理信息板块--------------//

//会员登录管理信息
void controler::on_eepass_clicked()
{
    //获取输入信息
    QString id = ui->eename->text();
    QString password = ui->eepassword->text();

    if(id.isEmpty())         //先判断异常输入
    {
        QMessageBox::information(this, "请输入姓名","请先输入姓名再登陆，谢谢！",QMessageBox::Ok);
        ui->eename->setFocus();
    }
    else if(password.isEmpty())
    {
        QMessageBox::information(this, "请输入密码","请先输入密码再登陆，谢谢！",QMessageBox::Ok);
        ui->eepassword->setFocus();
    }
    else                        //输入无异常，判断会员号与密码是否正确
    {
        //查询会员号与密码
        QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");
        QSqlQuery query=QSqlQuery(database);
        QString str =tr("select * from customers where id = '%1' and password = '%2'").arg(id,password);
        query.exec(str);

        if(!query.next())       //会员号与密码错误
        {
            QMessageBox::information(this,"提示","用户名或密码错误！",QMessageBox::Ok);
            ui->eepassword->clear();
            ui->eepassword->setFocus();
        }
        else                    //会员号与密码正确
        {
            QMessageBox::information(this,"提示","登陆成功！",QMessageBox::Ok);

            sendid=id;                          //给信息查询窗口传值

            information *w=new information;     //给信息查询窗口创建一个对象
            w ->show();                         //信息查询窗口显示出来

            ui->eepassword->clear();            //清理登录信息
            ui->eename->clear();
        }
    }
}

//密码与会员号找回
void controler::on_pushButton_8_clicked()
{
    help *w=new help;
    w->show();
}

//-------------续费充钱板块-------------//

//会员续费
void controler::on_pushButton_6_clicked()
{
    customer cus;

    //获取输入内容
    cus.id=ui->lineEdit_14->text();
    cus.password=ui->lineEdit_16->text();
    cus.money=ui->lineEdit_15->text();

    bool ok;                                //用于转变输入数据类型
    int intmoney=cus.money.toInt(&ok);      //intmoney用于记录充入的钱
    QString tip;                            //用于获取充钱备注信息
    QDateTime now=QDateTime::currentDateTime();                 //用于现在接收时间
    QString strtime = now.toString("yyyy-MM-dd hh:mm:ss");      //格式化时间
    QDateTime ddl;                          //创造操作对象，接收到期时间

    if(cus.id.isEmpty())                    //输入异常
    {
        QMessageBox::information(this, "提示","请先输入会员号，谢谢！",QMessageBox::Ok);
        ui->lineEdit_14->setFocus();
    }
    else if(cus.password.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入密码，谢谢！",QMessageBox::Ok);
        ui->lineEdit_16->setFocus();
    }
    else if(cus.money.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入充入金额，谢谢！",QMessageBox::Ok);
        ui->lineEdit_15->setFocus();
    }
    else if(intmoney<0)
    {
        QMessageBox::information(this, "提示","充入金额不能小于零，谢谢！",QMessageBox::Ok);
        ui->lineEdit_15->setFocus();
    }
    else if(ui->radioButton_10->isChecked()==false&&ui->radioButton_11->isChecked()==false&&ui->radioButton_12->isChecked()==false)
    {
        QMessageBox::information(this, "提示","注册会员至少需要选择办理一种类型的卡",QMessageBox::Ok);
    }
    else        //输入信息符合要求，开始匹配密码与会员号
    {
        //查询会员号与密码
        QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");
        QSqlQuery query=QSqlQuery(database);
        QString str =tr("select * from customers where id = '%1' and password = '%2'").arg(cus.id,cus.password);
        query.exec(str);

        if(!query.next())       //会员号与密码错误
        {
            QMessageBox::information(this,"提示","会员号或密码错误！",QMessageBox::Ok);
            ui->lineEdit_16->clear();
            ui->lineEdit_16->setFocus();
        }
        else                    //会员号与密码正确，开始续费操作
        {
            //查询获取原本余额
            QString str1 =tr("select * from customers where id = '%1'" ).arg(cus.id);
            query.exec(str1);
            query.next();
            float saving=query.value("money").toFloat();   //原本余额

            float sum=saving+intmoney;                   //计算得可用金额

            //获得折扣
            cus.level=query.value("level").toString();      //获取用户等级
            float intlevel=cus.level.toFloat(&ok);          //转换类型
            float sale=cus.sale(intlevel)*0.95;             //计算折扣

            if(ui->radioButton_10->isChecked()==true&&sum<2000*sale)      //充钱不足
            {
                QMessageBox::information(this, "提示","您还需要再充值"+QString::number(-sum+2000*sale)+"元",QMessageBox::Ok);
                ui->lineEdit_15->setFocus();
            }
            else if(ui->radioButton_11->isChecked()==true&&sum<500*sale)  //充钱不足
            {
                QMessageBox::information(this, "提示","您还需要再充值"+QString::number(-sum+500*sale)+"元",QMessageBox::Ok);
                ui->lineEdit_15->setFocus();
            }
            else if(ui->radioButton_12->isChecked()==true&&sum<200*sale)  //充钱不足
            {
                QMessageBox::information(this, "提示","您还需要再充值"+QString::number(-sum+200*sale)+"元",QMessageBox::Ok);
                ui->lineEdit_15->setFocus();
            }
            else   //money足够
            {
                //先判断此次续费有效期的起止时间
                //搜索上一次到期时间
                QString lasttime=tr("SELECT time FROM customers WHERE id = '%1'").arg(cus.id);
                QSqlQuery query1=QSqlQuery(lasttime);
                query1.next();     //下移指针到搜索到的记录

                QDateTime ltime = QDateTime::fromString(query.value("time").toString(), "yyyy-MM-dd hh:mm:ss");  //记录上一次到期时间
                QDateTime start;        //用来接受较大值

                //比较得到续费后健身卡到期时间
                if(ltime>now)
                {
                    start=ltime;
                }
                else
                {
                    start=now;
                }

                float extra;            //用于接收余额
                float fee;              //接收本次花销
                //判断办卡类型并扣除相应钱
                if (ui->radioButton_10->isChecked()==true)
                {
                    extra=sum-sale*2000;                           //计算余额
                    cus.kind="年卡会员";                            //会员种类
                    fee=2000*sale;                //续费所用金额
                    cus.level=QString::number(20+intlevel);        //计算升级后的等级
                    tip="本次为扣除注册年卡会员费用"+QString::number(fee)+"元后的余额";   //消费历史备注

                    ddl=start.addMonths(12);                        //计算下一次到期时间
                    cus.time=ddl.toString("yyyy-MM-dd hh:mm:ss");   //转换数据类型
                }
                else if (ui->radioButton_11->isChecked()==true)
                {
                    extra=sum-sale*500;
                    cus.kind="季卡会员";
                    fee=500*sale;
                    cus.level=QString::number(5+intlevel);
                    tip="本次为扣除注册季卡会员费用"+QString::number(fee)+"元后的余额";

                    ddl=start.addMonths(3);
                    cus.time=ddl.toString("yyyy-MM-dd hh:mm:ss");
                }
                else if (ui->radioButton_12->isChecked()==true)
                {
                    extra=sum-sale*500;
                    cus.kind="月卡会员";
                    fee=200*sale;
                    cus.level=QString::number(2+intlevel);
                    tip="本次为扣除注册月卡会员费用"+QString::number(fee)+"元后的余额";

                    ddl=start.addMonths(1);
                    cus.time=ddl.toString("yyyy-MM-dd hh:mm:ss");
                }

                //更新用户数据
                QString update=tr("update customers set kind='%1',money='%2',time='%3',level='%4' where id='%5'")
                                     .arg(cus.kind,QString::number(extra),cus.time,cus.level,cus.id);

                //确定是否花费了会员卡余额
                float thisextra=intmoney-fee;
                QString history;        //用于接收消费历史信息
                if(thisextra>=0)
                {
                    history="+"+QString::number(thisextra);
                }
                else
                {
                    history=QString::number(thisextra);
                }

                //历史消费表插入充值
                QString add=QString("insert into '%1'(time,history,tip)"
                                      "values('%2','%3','%4')")
                                  .arg(cus.id,strtime,history,tip);

                //向收入表插入数据
                QString income=tr("insert into income(time,money)"
                                        "values('%1','%2')")
                                        .arg(strtime,cus.money);

                if(query.exec(add)&&query.exec(income)&&query.exec(update))   //续费成功
                {
                    QMessageBox::information(this, "续费成功","续费成功，<br><br>"
                                               "该用户已续费为"+cus.kind+"<br><br>"+
                                               "下一次到期时间为"+cus.time+"<br><br>"+
                                               "本次该用户享受了"+QString::number(sale*10)+"折服务<br><br>"
                                               "本次续费花费"+QString::number(fee)+"元<br><br>"+
                                               "该用户当前会员等级为"+cus.level+"<br><br>"+
                                               "会员卡余额为"+QString::number(extra)+"元",QMessageBox::Ok);

                    //清理续费输入的信息
                    ui->lineEdit_14->clear();
                    ui->lineEdit_15->clear();
                    ui->lineEdit_16->clear();
                    setfalse(ui->radioButton_10);
                    setfalse(ui->radioButton_11);
                    setfalse(ui->radioButton_12);
                }
                else
                {
                    QMessageBox::information(this, "充值失败","充值失败，请检查数据库连接",QMessageBox::Ok);
                }
            }
        }
    }
}

//会员卡充钱
void controler::on_pushButton_4_clicked()
{
    customer cus;
    //对应获取输入栏内容
    cus.id=ui->lineEdit_11->text();
    cus.password=ui->lineEdit_17->text();
    QString money=ui->lineEdit_10->text();

    bool ok;                            //用于转变输入数据类型
    int intmoney=money.toInt(&ok);      //intmoney用于记录充入的钱

    if(cus.id.isEmpty())                //检测输入异常
    {
        QMessageBox::information(this, "提示","请先输入会员号，谢谢！",QMessageBox::Ok);
        ui->lineEdit_5->setFocus();
    }
    else if(cus.password.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入密码，谢谢！",QMessageBox::Ok);
        ui->lineEdit_8->setFocus();
    }
    else if(money.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入充值金额，谢谢！",QMessageBox::Ok);
        ui->lineEdit_10->setFocus();
    }
    else if(intmoney<0)
    {
        QMessageBox::information(this, "提示","充值金额不能小于零，谢谢！",QMessageBox::Ok);
        ui->lineEdit_10->setFocus();
    }
    else                    //输入无基本问题，开始判断会员号与密码是否匹配
    {
        //查询会员号与密码
        QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");
        QSqlQuery query=QSqlQuery(database);
        QString str =tr("select * from customers where id = '%1' and password = '%2'").arg(cus.id,cus.password);
        query.exec(str);

        if(!query.next())       //会员号与密码错误
        {
            QMessageBox::information(this,"提示","会员号或密码错误！",QMessageBox::Ok);
            ui->lineEdit_17->clear();
            ui->lineEdit_17->setFocus();
        }
        else                    //会员号与密码正确，开始续费操作
        {
            int saving=query.value("money").toInt();                //获取余额
            cus.money=QString::number(saving+intmoney);             //计算充钱后余额
            QDateTime now=QDateTime::currentDateTime();             //用于接收时间
            QString strtime = now.toString("yyyy-MM-dd hh:mm:ss");  //格式化时间

            //更新用户数据
            QString update=tr("update customers set money='%1'where id='%2'")
                                 .arg(cus.money,cus.id);

            //历史消费表插入充值
            QString add=QString("insert into '%1'(time,history)"
                                "values('%2','%3')")
                                .arg(cus.id,strtime,"+"+money);

            //向收入表插入数据
            QString income=tr("insert into income(time,money)"
                              "values('%1','%2')")
                              .arg(strtime,money);

            if(query.exec(update)&&query.exec(add)&&query.exec(income))
            {
                QMessageBox::information(this, "充值成功","充值成功，<br>"
                                               "该用户已充入"+money+"元<br>"+
                                               "会员卡余额为"+cus.money+"元",QMessageBox::Ok);
                ui->lineEdit_11->clear();
                ui->lineEdit_17->clear();
                ui->lineEdit_10->clear();
            }
            else
            {
                QMessageBox::information(this, "充值失败","充值失败，请检查数据库连接",QMessageBox::Ok);
            }
        }
    }
}

//会员用会员卡消费
void controler::on_pushButton_3_clicked()
{
    customer cus;
    //对应获取输入栏内容
    cus.id=ui->lineEdit_5->text();
    cus.password=ui->lineEdit_20->text();
    QString spend=ui->lineEdit_8->text();   //用于记录花销

    bool ok;                                //用于转变输入数据类型
    int intmoney=spend.toInt(&ok);          //intmoney用于记录消费的钱
    float floatmoney=float(intmoney);       //用于判断等级增加

    if(cus.id.isEmpty())        //输入异常判断
    {
        QMessageBox::information(this, "提示","请先输入会员号，谢谢！",QMessageBox::Ok);
        ui->lineEdit_5->setFocus();
    }
    else if(cus.password.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入密码，谢谢！",QMessageBox::Ok);
        ui->lineEdit_20->setFocus();
    }
    else if(spend.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入花销，谢谢！",QMessageBox::Ok);
        ui->lineEdit_8->setFocus();
    }
    else if(intmoney<0)
    {
        QMessageBox::information(this, "提示","请输入正数，谢谢！",QMessageBox::Ok);
        ui->lineEdit_8->setFocus();
    }
    else        //输入正常，开始匹配用户名与密码
    {
        //查询会员号与密码
        QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");
        QSqlQuery query=QSqlQuery(database);
        QString str =tr("select * from customers where id = '%1' and password = '%2'").arg(cus.id,cus.password);
        query.exec(str);

        if(!query.next())       //会员号与密码错误
        {
            QMessageBox::information(this,"提示","会员号或密码错误！",QMessageBox::Ok);
            ui->lineEdit_20->clear();
            ui->lineEdit_20->setFocus();
        }
        else                    //会员号与密码正确，开始计算
        {
            float saving=query.value("money").toFloat();    //获取会员卡余额
            float level=query.value("level").toFloat();     //获取会员级别
            float sale=cus.sale(level);                     //获取折扣

            float f=level+floatmoney/100;                   //计算升级后的级别
            cus.level=QString::number(f,'f',2);             //转换level类型存储

            float truespend=sale*0.95*floatmoney;           //计算得折后花销
            float extra=saving-floatmoney;                  //计算余额

            if(extra<0)        //余额不足
            {
                QMessageBox::information(this,"提示","会员卡余额不足，需要充入"+
                                        QString::number(truespend-saving)+"元后再消费",QMessageBox::Ok);
            }
            else               //余额够
            {
                QDateTime now=QDateTime::currentDateTime();             //用于接收时间
                QString strtime = now.toString("yyyy-MM-dd hh:mm:ss");  //格式化时间
                cus.money=QString::number(extra);

                QSqlQuery query=QSqlQuery(database);
                //更新用户数据
                QString update=tr("update customers set money='%1',level='%2' where id='%3'")
                                     .arg(cus.money,cus.level,cus.id);

                //历史消费表插入充值
                QString add=QString("insert into '%1'(time,history)"
                                    "values('%2','%3')")
                                  .arg(cus.id,strtime,"-"+QString::number(truespend));

                if(query.exec(update)&&query.exec(add))                 //插入数据成功
                {
                    QMessageBox::information(this,"提示","消费成功，本次实际支付了"+QString::number(truespend)+"元<br><br>"+
                                                        "享受折扣"+QString::number(sale*10*0.95)+"折<br><br>"+
                                                        "会员卡余额"+cus.money+"元<br><br>"+
                                                        "会员等级升为"+cus.level+"级",QMessageBox::Ok);
                }
                else
                {
                    QMessageBox::information(this, "提示","删除失败，请检查数据库连接",QMessageBox::Ok);
                }
            }
            //清理输入数据
            ui->lineEdit_5->clear();
            ui->lineEdit_8->clear();
            ui->lineEdit_20->clear();
        }
    }
}

//会员用现金消费
void controler::on_pushButton_5_clicked()
{
    customer cus;
    //对应获取输入栏内容
    cus.id=ui->lineEdit_5->text();
    cus.password=ui->lineEdit_20->text();
    QString spend=ui->lineEdit_8->text();   //用于记录花销

    bool ok;                                //用于转变输入数据类型
    int intmoney=spend.toInt(&ok);          //intmoney用于记录消费的钱
    float floatmoney=float(intmoney);       //用于判断等级增加

    if(cus.id.isEmpty())        //输入异常判断
    {
        QMessageBox::information(this, "提示","请先输入会员号，谢谢！",QMessageBox::Ok);
        ui->lineEdit_5->setFocus();
    }
    else if(cus.password.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入密码，谢谢！",QMessageBox::Ok);
        ui->lineEdit_20->setFocus();
    }
    else if(spend.isEmpty())
    {
        QMessageBox::information(this, "提示","请先输入花销，谢谢！",QMessageBox::Ok);
        ui->lineEdit_8->setFocus();
    }
    else if(intmoney<0)
    {
        QMessageBox::information(this, "提示","请输入正数，谢谢！",QMessageBox::Ok);
        ui->lineEdit_8->setFocus();
    }
    else        //输入正常，开始匹配用户名与密码
    {
        //查询会员号与密码
        QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");
        QSqlQuery query=QSqlQuery(database);
        QString str =tr("select * from customers where id = '%1' and password = '%2'").arg(cus.id,cus.password);
        query.exec(str);

        if(!query.next())       //会员号与密码错误
        {
            QMessageBox::information(this,"提示","会员号或密码错误！",QMessageBox::Ok);
            ui->lineEdit_20->clear();
            ui->lineEdit_20->setFocus();
        }
        else                    //会员号与密码正确，开始计算
        {
            float level=query.value("level").toFloat();     //获取会员级别
            float sale=cus.sale(level);                     //获取折扣

            float f=level+floatmoney/100;                   //计算升级后的级别
            cus.level=QString::number(f,'f',2);             //转换level类型存储
            float truespend=sale*floatmoney;                //计算得折后花销

            QDateTime now=QDateTime::currentDateTime();             //用于接收时间
            QString strtime = now.toString("yyyy-MM-dd hh:mm:ss");  //格式化时间

            QSqlQuery query=QSqlQuery(database);                    //创建数据库操作对象

            //更新用户数据
            QString update=tr("update customers set level='%1' where id='%2'")
                              .arg(cus.level,cus.id);

            //历史消费表插入充值
            QString add=QString("insert into '%1'(time,history,tip)"
                                "values('%2','%3','%4')")
                                .arg(cus.id,strtime,"-"+QString::number(truespend),"本次为现金直接支付");

            //向收入表插入数据
            QString income=tr("insert into income(time,money)"
                                "values('%1','%2')")
                                 .arg(strtime,QString::number(truespend));

            if(query.exec(update)&&query.exec(add)&&query.exec(income))                 //插入数据成功
            {
                QMessageBox::information(this,"提示","消费成功，本次消费"+QString::number(truespend)+"元<br><br>"+
                                              "享受折扣"+QString::number(sale*10)+"折<br><br>"+
                                              "会员等级升为"+cus.level+"级",QMessageBox::Ok);
                //清理输入内容
                ui->lineEdit_5->clear();
                ui->lineEdit_8->clear();
                ui->lineEdit_20->clear();
            }
            else
            {
                QMessageBox::information(this, "提示","请检查数据库连接",QMessageBox::Ok);
            }
        }
    }
}

//定义取消radio button按钮选中函数
void setfalse(QRadioButton* a)
{
    a->setAutoExclusive(false);           //取消互斥
    a->setChecked(false);                 //取消选中
    a->setAutoExclusive(true);            //恢复互斥
}
