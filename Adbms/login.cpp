#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "user.h"
#include <QApplication>
#include <QDialog.h>
#include <QFile>
#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QMessageBox>
#include "global.h"
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    setWindowTitle("请登录");
}

login::~login()
{
    delete ui;
}

void login::showInfoDialog() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("错误");
    msgBox.setText("账号不存在！");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

void login::showcreateDialog() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("恭喜");
    msgBox.setText("注册成功！");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}
void login::showDialog() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("错误");
    msgBox.setText("密码错误！");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}
void login::on_newuser_clicked()
{
    //新建User
    std::string account=this->ui->account_edit->text().toStdString();
    std::string password=this->ui->password_edit->text().toStdString();
    User* newuser = new User(account,password);
    this->ui->account_edit->clear();
    this->ui->password_edit->clear();
    login::showcreateDialog();
}

void login::on_olduser_pressed()
{
    std::string account=this->ui->account_edit->text().toStdString();
    std::string password=this->ui->password_edit->text().toStdString();
    //检查user目录下是否存在指定用户名命名的文件夹
    std::filesystem::path userPath=std::filesystem::current_path() / "user";
    if(!std::filesystem::exists(userPath)){
        std::cout << "no user";
        this->ui->account_edit->clear();
        this->ui->password_edit->clear();
        return;
    }

    std::filesystem::path storage_path=userPath / account;
    if(!std::filesystem::exists(storage_path)){
        //说明该用户并未被创建
        login::showInfoDialog();
        //清空账号密码的输入框
        this->ui->account_edit->clear();
        this->ui->password_edit->clear();
        return;
    }
    //进一步检查这个文件夹下面的config.json文件里的password是否为输入的密码
    QFile file(storage_path / "user_config.json");
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (!doc.isNull() && doc.isObject()) {
            QJsonObject rootObj = doc.object();
            QString QPassword = rootObj["password_hash"].toString(); // 读取字段
            if(QPassword.toStdString()==password){

                this->close();
                MainWindow *w = new MainWindow(this);
                w->show();
                qDebug()<<"Log in successly";
                User temp(account,password,storage_path);
                g_user=temp;
            }
            else{
                //跳出弹窗提示密码错误
                login::showDialog();
                this->ui->account_edit->clear();
                this->ui->password_edit->clear();
                std::cout<<"password wrong!";
                return;
            }
        }
    }
}

