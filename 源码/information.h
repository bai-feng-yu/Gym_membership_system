#ifndef INFORMATION_H
#define INFORMATION_H

#include <QWidget>

namespace Ui
{
    class information;
}

//information类用于对用户信息的相关操作
class information : public QWidget
{
    Q_OBJECT

public:
    explicit information(QWidget *parent = nullptr);
    ~information();
    void showdata();                    //展示数据信息

private slots:
    void on_pushButton_7_clicked();     //退出会员
    void on_correct_clicked();          //修改基本信息
    void on_correctpassword_clicked();  //修改密码

private:
    Ui::information *ui;
};

#endif // INFORMATION_H
