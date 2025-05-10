#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // 设置主窗口样式
    this->setStyleSheet(QStringLiteral("background: #E6F2FF;"));
    
    // 为各组件添加额外样式，增强界面元素之间的区分度
    ui->showsqldo->setFrameShadow(QFrame::Raised);
    ui->showsqldo->setLineWidth(2);
    
    ui->insertsql->setFrameShadow(QFrame::Raised);
    ui->insertsql->setLineWidth(2);
    
    ui->tree->setFrameShadow(QFrame::Raised);
    ui->tree->setLineWidth(2);
    
    // 设置状态栏样式
    statusBar()->setStyleSheet("QStatusBar{border-top: 2px solid #A9C6E8; padding: 3px; background: #D4E6F9;}");
    statusBar()->showMessage("就绪");
}

MainWindow::~MainWindow()
{
    delete ui;
}
