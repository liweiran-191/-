/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QPushButton *olduser;
    QPushButton *newuser;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *account_edit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *password_edit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(405, 282);
        login->setMinimumSize(QSize(405, 282));
        login->setMaximumSize(QSize(405, 282));
        login->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(login);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        olduser = new QPushButton(centralwidget);
        olduser->setObjectName("olduser");
        olduser->setGeometry(QRect(80, 190, 56, 18));
        newuser = new QPushButton(centralwidget);
        newuser->setObjectName("newuser");
        newuser->setGeometry(QRect(250, 190, 56, 18));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(80, 30, 241, 131));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        account_edit = new QLineEdit(layoutWidget);
        account_edit->setObjectName("account_edit");

        horizontalLayout->addWidget(account_edit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(label);

        password_edit = new QLineEdit(layoutWidget);
        password_edit->setObjectName("password_edit");

        horizontalLayout_2->addWidget(password_edit);


        verticalLayout->addLayout(horizontalLayout_2);

        login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(login);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 405, 18));
        login->setMenuBar(menubar);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName("statusbar");
        login->setStatusBar(statusbar);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "MainWindow", nullptr));
        olduser->setText(QCoreApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        newuser->setText(QCoreApplication::translate("login", "\346\263\250\345\206\214", nullptr));
        label_2->setText(QCoreApplication::translate("login", "      \350\264\246\345\217\267      ", nullptr));
#if QT_CONFIG(tooltip)
        account_edit->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        account_edit->setText(QString());
        label->setText(QCoreApplication::translate("login", "       \345\257\206\347\240\201      ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
