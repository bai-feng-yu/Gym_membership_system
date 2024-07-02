#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Dialog;
}
QT_END_NAMESPACE

//dialog类用于登陆页面的相关操作
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_erpass_clicked();           //员工登录
    void on_checkBox_2_clicked();       //显示密码

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
