#include "mainwindow.h"
#include "parser.h"
#include "statement.h"
#include "exception.h"
#include "login.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login l;
    l.show();
    MainWindow w;
    // w.show();
    return a.exec();
}


