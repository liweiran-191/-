#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include <QDialog.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    login loginWindow;
    MainWindow w;
    loginWindow.show();

    // w.show();
    return a.exec();
}
