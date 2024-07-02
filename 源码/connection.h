#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

//data类用于数据库操作
class data
{
public:
    static void createConnection();     //初始化创建数据库连接
    static void Connection();           //连接数据库
    static void closeConnection();      //关闭数据库
};

#endif // CONNECTION_H
