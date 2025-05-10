#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDialog.h>

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_newuser_clicked()
{

}


void login::on_olduser_pressed()
{

}

