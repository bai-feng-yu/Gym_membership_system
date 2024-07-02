#ifndef HELP_H
#define HELP_H

#include <QWidget>

namespace Ui
{
    class help;
}

//help类用于找回密码与会员号的相关操作
class help : public QWidget
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = nullptr);
    ~help();

private slots:
    void on_pushButton_clicked();   //找回密码与会员号

private:
    Ui::help *ui;
};

#endif // HELP_H
