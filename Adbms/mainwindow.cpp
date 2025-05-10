#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet(QStringLiteral("background: #E6F7FF;"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
