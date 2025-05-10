/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *actiongithub;
    QWidget *centralwidget;
    QGraphicsView *showsqldo;
    QPlainTextEdit *insertsql;
    QTreeWidget *tree;
    QLabel *label_3;
    QWidget *widget;
    QHBoxLayout *howtoshow;
    QPushButton *changeinui;
    QPushButton *uishow;
    QWidget *widget1;
    QHBoxLayout *base;
    QLabel *label;
    QLabel *basename;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(801, 513);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        actiongithub = new QAction(MainWindow);
        actiongithub->setObjectName("actiongithub");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        showsqldo = new QGraphicsView(centralwidget);
        showsqldo->setObjectName("showsqldo");
        showsqldo->setGeometry(QRect(170, 20, 631, 241));
        insertsql = new QPlainTextEdit(centralwidget);
        insertsql->setObjectName("insertsql");
        insertsql->setGeometry(QRect(170, 280, 631, 201));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(true);
        font.setStrikeOut(false);
        insertsql->setFont(font);
        insertsql->setFocusPolicy(Qt::FocusPolicy::TabFocus);
        tree = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        tree->setHeaderItem(__qtreewidgetitem);
        tree->setObjectName("tree");
        tree->setGeometry(QRect(0, 0, 171, 481));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(400, 260, 291, 20));
        label_3->setBaseSize(QSize(5, 5));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(true);
        label_3->setFont(font1);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(300, 0, 191, 20));
        howtoshow = new QHBoxLayout(widget);
        howtoshow->setObjectName("howtoshow");
        howtoshow->setContentsMargins(0, 0, 0, 0);
        changeinui = new QPushButton(widget);
        changeinui->setObjectName("changeinui");

        howtoshow->addWidget(changeinui);

        uishow = new QPushButton(widget);
        uishow->setObjectName("uishow");

        howtoshow->addWidget(uishow);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(170, 0, 111, 21));
        base = new QHBoxLayout(widget1);
        base->setObjectName("base");
        base->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName("label");

        base->addWidget(label);

        basename = new QLabel(widget1);
        basename->setObjectName("basename");

        base->addWidget(basename);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 801, 18));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addSeparator();
        menu_2->addAction(actiongithub);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\346\225\260\346\215\256\345\272\223", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        actiongithub->setText(QCoreApplication::translate("MainWindow", "github", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\273\210\347\253\257\357\274\232\350\257\267\350\276\223\345\205\245sql\350\257\255\345\217\245", nullptr));
        changeinui->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\275\242\350\241\250", nullptr));
        uishow->setText(QCoreApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\346\225\260\346\215\256\345\272\223\357\274\232", nullptr));
        basename->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
