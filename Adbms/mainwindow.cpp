#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("DBMS 7.0");
    // 设置主窗口样式
    this->setStyleSheet(QStringLiteral("background: #E6F2FF;"));
    ui->biao->setVisible(0);
    loadDatabaseTree();  // 新增初始化调用
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_changeinui_clicked()
{
    ui->biao->setVisible(1);
}


void MainWindow::on_uishow_clicked()
{
   ui->biao->setVisible(0);
}


void MainWindow::loadDatabaseTree()
{
    ui->tree->clear();
    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->tree);
    rootItem->setText(0, "我的数据库");

    for (const std::string &dbName : UserManager::getUser().dbnames) {
        QTreeWidgetItem *childItem = new QTreeWidgetItem(rootItem);
        childItem->setText(0, QString::fromStdString(dbName));
    }
    ui->tree->expandAll();
}

