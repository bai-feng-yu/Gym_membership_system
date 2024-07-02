#ifndef CUSTOMER_H
#define CUSTOMER_H
#include"QString"

//customer类用于封装会员信息
class customer
{
public:
    customer();
    QString name;           //用户姓名
    QString sex;            //性别
    QString password;       //密码
    QString kind;           //健身卡种类
    QString money;          //余额
    QString id;             //会员号
    QString time;           //健身卡到期时间
    QString level;          //会员等级
    QString idnumber;       //身份证号
    QString phonenumber;    //电话号

    float sale(int level);  //判断折扣函数
};

#endif // CUSTOMER_H
