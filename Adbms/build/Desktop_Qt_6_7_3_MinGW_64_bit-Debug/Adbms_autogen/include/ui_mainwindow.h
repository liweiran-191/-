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
    QWidget *layoutWidget;
    QHBoxLayout *howtoshow;
    QPushButton *changeinui;
    QPushButton *uishow;
    QWidget *layoutWidget1;
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
        QIcon icon;
        icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action->setIcon(icon);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        action_2->setIcon(icon);
        actiongithub = new QAction(MainWindow);
        actiongithub->setObjectName("actiongithub");
        actiongithub->setIcon(icon);
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
        new QTreeWidgetItem(tree);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(tree);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        tree->setObjectName("tree");
        tree->setGeometry(QRect(0, 20, 171, 461));
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
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(300, 0, 191, 20));
        howtoshow = new QHBoxLayout(layoutWidget);
        howtoshow->setObjectName("howtoshow");
        howtoshow->setContentsMargins(0, 0, 0, 0);
        changeinui = new QPushButton(layoutWidget);
        changeinui->setObjectName("changeinui");

        howtoshow->addWidget(changeinui);

        uishow = new QPushButton(layoutWidget);
        uishow->setObjectName("uishow");

        howtoshow->addWidget(uishow);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(170, 0, 131, 21));
        base = new QHBoxLayout(layoutWidget1);
        base->setObjectName("base");
        base->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");

        base->addWidget(label);

        basename = new QLabel(layoutWidget1);
        basename->setObjectName("basename");

        base->addWidget(basename);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 801, 21));
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
        MainWindow->setStyleSheet(QCoreApplication::translate("MainWindow", "QMainWindow {\n"
"    background-color: #E6F2FF;\n"
"}\n"
"\n"
"QMenuBar {\n"
"    background-color: #D4E6F9;\n"
"    border-bottom: 1px solid #A9C6E8;\n"
"}\n"
"\n"
"QStatusBar {\n"
"    background-color: #D4E6F9;\n"
"    border-top: 1px solid #A9C6E8;\n"
"}", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\346\225\260\346\215\256\345\272\223", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        actiongithub->setText(QCoreApplication::translate("MainWindow", "github", nullptr));
        centralwidget->setStyleSheet(QCoreApplication::translate("MainWindow", "QWidget#centralwidget {\n"
"    background-color: #E6F2FF;\n"
"    border: 1px solid #A9C6E8;\n"
"}", nullptr));
        showsqldo->setStyleSheet(QCoreApplication::translate("MainWindow", "border: 2px solid #7BAAE8; \n"
"background-color: #F0F8FF;", nullptr));
        insertsql->setStyleSheet(QCoreApplication::translate("MainWindow", "border: 2px solid #5B9BD5; \n"
"background-color: #EAF1F9; \n"
"padding: 5px;", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = tree->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "databses", nullptr));

        const bool __sortingEnabled = tree->isSortingEnabled();
        tree->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = tree->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = tree->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\345\255\220\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem2->child(1);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem2->child(2);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem2->child(3);
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        tree->setSortingEnabled(__sortingEnabled);

        tree->setStyleSheet(QCoreApplication::translate("MainWindow", "border: 2px solid #6B9AC7; \n"
"background-color: #E1EEFF; \n"
"padding: 2px;\n"
"QTreeView::item { padding: 2px; }", nullptr));
        label_3->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #3A75C4; \n"
"background-color: transparent;", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\273\210\347\253\257\357\274\232\350\257\267\350\276\223\345\205\245sql\350\257\255\345\217\245", nullptr));
        changeinui->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton {\n"
"    background-color: #6B9AC7;\n"
"    color: white;\n"
"    border-radius: 4px;\n"
"    padding: 2px 8px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8BB8E8;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #4A7CAE;\n"
"}", nullptr));
        changeinui->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\275\242\350\241\250", nullptr));
        uishow->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton {\n"
"    background-color: #5B9BD5;\n"
"    color: white;\n"
"    border-radius: 4px;\n"
"    padding: 2px 8px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #7BAAE8;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #4A7CAE;\n"
"}", nullptr));
        uishow->setText(QCoreApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
        label->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #333333;\n"
"font-weight: bold;", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\346\225\260\346\215\256\345\272\223\357\274\232", nullptr));
        basename->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #0F9D58;\n"
"font-weight: bold;\n"
"padding: 2px;\n"
"background-color: #E8F5E9;\n"
"border-radius: 3px;", nullptr));
        basename->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menubar->setStyleSheet(QCoreApplication::translate("MainWindow", "QMenuBar::item {\n"
"    background-color: transparent;\n"
"    padding: 4px 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #4285F4;\n"
"    color: white;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: #FFFFFF;\n"
"    border: 1px solid #BDBDBD;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QMenu::item {\n"
"    padding: 5px 30px 5px 20px;\n"
"    border-radius: 3px;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #E8F0FE;\n"
"    color: #1A73E8;\n"
"}", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
