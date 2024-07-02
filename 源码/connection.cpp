#include"connection.h"

void data::createConnection()   //初始化创建数据库连接
{
    QSqlDatabase database;                              //创建操作对象
    database = QSqlDatabase::addDatabase("QSQLITE");    //添加数据库驱动
    database.setDatabaseName("MyDataBase.db");          //设置数据库名称
    database.setHostName("127.0.0.1");
    database.open();                 //打开数据库

    QSqlQuery sqlQuery;              //创建操作对象

    //创建客户数据表
    QString customers = QString("create table customers ("
                                "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                "name text not null,"
                                "sex text not null,"
                                "password text not null,"
                                "idnumber text not null,"
                                "phonenumber int not null,"
                                "kind text,"
                                "money int,"
                                "level int,"
                                "time text)");
    sqlQuery.exec(customers);

    //创建员工数据表
    QString employees = QString("create table employees ("
                                "name text not null,"
                                "password text not null)");   
    sqlQuery.exec(employees);

    //创建收入数据表
    QString income = QString("create table income ("
                                "time text not null,"
                                "money text not null)");
    sqlQuery.exec(income);

    //为每一列标题添加绑定值
    sqlQuery.prepare("INSERT INTO employees (name,password) "
                     "VALUES (:name, :password)");
    sqlQuery.prepare("INSERT INTO customers (name,sex,password,idnumber,phonenumber,money,level,time) "
                     "VALUES (:name,:sex,:password,:idnumber,:phonenumber,:money,:level,:time)");
    sqlQuery.prepare("INSERT INTO income(time,money) "
                     "VALUES (:time,:money)");
}

void data::Connection()             //连接数据库
{
    QSqlDatabase database= QSqlDatabase::database("qt_sql_default_connection");
    database.open();                //打开数据库
}

void data::closeConnection()        //关闭数据库
{
    QSqlDatabase database = QSqlDatabase::database("qt_sql_default_connection");
    database.close();               //关闭数据库
}
