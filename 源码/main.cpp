#include <QApplication>
#include "dialog.h"
#include<QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog wd;
    wd.show();          //显示员工登录界面
    return a.exec();    //等待返回值使页面保留
}
