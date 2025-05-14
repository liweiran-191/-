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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
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
    QTreeWidget *tree;
    QLabel *zhanshi;
    QWidget *layoutWidget;
    QHBoxLayout *howtoshow;
    QPushButton *changeinui;
    QPushButton *uishow;
    QWidget *layoutWidget1;
    QHBoxLayout *base;
    QLabel *label;
    QLabel *basename;
    QScrollArea *biao;
    QWidget *scrollAreaWidgetContents;
    QTableView *biaodetail;
    QTextEdit *insertsql;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1035, 690);
        MainWindow->setMinimumSize(QSize(1035, 690));
        MainWindow->setMaximumSize(QSize(1035, 690));
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"/* \345\205\250\345\261\200\346\240\267\345\274\217 */\n"
"QWidget {\n"
"    color: #E0F7FA;\n"
"    font-family: \"Segoe UI\", Arial, sans-serif;\n"
"}\n"
"\n"
"QMainWindow {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1A237E, stop:1 #0D47A1);\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: rgba(0, 229, 255, 0.1);\n"
"    color: #E0F7FA;\n"
"    border: 2px solid #00E5FF;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 229, 255, 0.2);\n"
"    box-shadow: 0 0 8px rgba(0, 229, 255, 0.5);\n"
"}\n"
"\n"
"QTreeView::item:hover { \n"
"    background-color: rgba(0, 229, 255, 0.15);\n"
"    border: 1px solid #00E5FF;\n"
"}\n"
"\n"
"QTableView {\n"
"    background: transparent;\n"
"    gridline-color: rgba(0, 229, 255, 0.3);\n"
"    border: 2px solid #00E5FF;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #1A237E;\n"
"    color: #E0F7FA;"
                        "\n"
"    padding: 4px;\n"
"    border: 1px solid #00E5FF;\n"
"}\n"
"\n"
"QMenuBar {\n"
"    background-color: #1E2A38;\n"
"    border-bottom: 1px solid #2C3E50;\n"
"    color: #E0E0E0;\n"
"}\n"
"\n"
"QStatusBar {\n"
"    background-color: #1E2A38;\n"
"    border-top: 1px solid #2C3E50;\n"
"    color: #E0E0E0;\n"
"}\n"
"\n"
"QTreeView::item {\n"
"    padding: 6px;\n"
"    border-radius: 4px;\n"
"    border: 1px solid transparent;\n"
"}\n"
"\n"
"QTreeView::item:selected {\n"
"    background-color: rgba(0, 229, 255, 0.3);\n"
"    border-color: #00E5FF;\n"
"}\n"
"\n"
"QStatusBar {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #1A237E, stop:1 #0D47A1);\n"
"    border-top: 2px solid #00E5FF;\n"
"    color: #E0F7FA;\n"
"}\n"
"QTreeView::item:selected {\n"
"    background-color: #2980B9;\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"QTreeView::item:hover {\n"
"    background-color: #34495E;\n"
"}\n"
""));
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
        showsqldo->setGeometry(QRect(260, 20, 771, 271));
        tree = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(tree);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        tree->setObjectName("tree");
        tree->setGeometry(QRect(0, 0, 261, 651));
        zhanshi = new QLabel(centralwidget);
        zhanshi->setObjectName("zhanshi");
        zhanshi->setGeometry(QRect(550, 300, 291, 20));
        zhanshi->setBaseSize(QSize(5, 5));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(true);
        zhanshi->setFont(font);
        zhanshi->setStyleSheet(QString::fromUtf8("color: #3498DB; \n"
"background-color: transparent;\n"
"text-shadow: 1px 1px 2px rgba(0, 0, 0, 0.5);"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(390, 0, 191, 20));
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
        layoutWidget1->setGeometry(QRect(260, 0, 131, 21));
        base = new QHBoxLayout(layoutWidget1);
        base->setObjectName("base");
        base->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");

        base->addWidget(label);

        basename = new QLabel(layoutWidget1);
        basename->setObjectName("basename");

        base->addWidget(basename);

        biao = new QScrollArea(centralwidget);
        biao->setObjectName("biao");
        biao->setGeometry(QRect(260, 20, 771, 271));
        biao->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 769, 269));
        biaodetail = new QTableView(scrollAreaWidgetContents);
        biaodetail->setObjectName("biaodetail");
        biaodetail->setGeometry(QRect(0, 0, 771, 271));
        biao->setWidget(scrollAreaWidgetContents);
        insertsql = new QTextEdit(centralwidget);
        insertsql->setObjectName("insertsql");
        insertsql->setGeometry(QRect(260, 330, 771, 321));
        insertsql->setStyleSheet(QString::fromUtf8("background-color: #263238;\n"
"border: 1px solid #3498DB;\n"
"border-radius: 5px;\n"
"color: #E0E0E0;\n"
"padding: 5px;\n"
"font-family: \"Consolas\", monospace;\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1035, 21));
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
        centralwidget->setStyleSheet(QCoreApplication::translate("MainWindow", "QWidget#centralwidget {\n"
"    background-color: #192231;\n"
"    border: 1px solid #2C3E50;\n"
"}", nullptr));
        showsqldo->setStyleSheet(QCoreApplication::translate("MainWindow", "border: 2px solid #3498DB; \n"
"background-color: #1F2B38;\n"
"border-radius: 5px;\n"
"color: #E0E0E0;", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = tree->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "databses", nullptr));

        const bool __sortingEnabled = tree->isSortingEnabled();
        tree->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = tree->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\345\255\220\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem1->child(3);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        tree->setSortingEnabled(__sortingEnabled);

        tree->setStyleSheet(QCoreApplication::translate("MainWindow", "border: 2px solid #3498DB; \n"
"background-color: #1F2B38; \n"
"padding: 2px;\n"
"border-radius: 5px;\n"
"color: #E0E0E0;\n"
"\n"
"QTreeView::item { \n"
"    padding: 4px; \n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QTreeView::item:selected { \n"
"    background-color: #2980B9; \n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"QTreeView::item:hover { \n"
"    background-color: #34495E; \n"
"}", nullptr));
        zhanshi->setText(QCoreApplication::translate("MainWindow", "\347\273\210\347\253\257\357\274\232\350\257\267\350\276\223\345\205\245sql\350\257\255\345\217\245", nullptr));
        changeinui->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton {\n"
"    background-color: #2980B9;\n"
"    color: white;\n"
"    border-radius: 4px;\n"
"    padding: 2px 8px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #3498DB;\n"
"    box-shadow: 0 2px 5px rgba(0, 0, 0, 0.3);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1A5276;\n"
"}", nullptr));
        changeinui->setText(QCoreApplication::translate("MainWindow", "\345\233\276\345\275\242\350\241\250", nullptr));
        uishow->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton {\n"
"    background-color: #16A085;\n"
"    color: white;\n"
"    border-radius: 4px;\n"
"    padding: 2px 8px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1ABC9C;\n"
"    box-shadow: 0 2px 5px rgba(0, 0, 0, 0.3);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #0E6655;\n"
"}", nullptr));
        uishow->setText(QCoreApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
        label->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #3498DB;\n"
"font-weight: bold;", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\346\225\260\346\215\256\345\272\223\357\274\232", nullptr));
        basename->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #1ABC9C;\n"
"font-weight: bold;\n"
"padding: 2px 5px;\n"
"background-color: rgba(26, 188, 156, 0.2);\n"
"border-radius: 3px;\n"
"border: 1px solid #1ABC9C;", nullptr));
        basename->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menubar->setStyleSheet(QCoreApplication::translate("MainWindow", "QMenuBar::item {\n"
"    background-color: transparent;\n"
"    padding: 4px 8px;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #2980B9;\n"
"    color: white;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: #1E2A38;\n"
"    border: 1px solid #2C3E50;\n"
"    padding: 5px;\n"
"    color: #E0E0E0;\n"
"}\n"
"\n"
"QMenu::item {\n"
"    padding: 5px 30px 5px 20px;\n"
"    border-radius: 3px;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #2980B9;\n"
"    color: white;\n"
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
