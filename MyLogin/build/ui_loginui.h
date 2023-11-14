/********************************************************************************
** Form generated from reading UI file 'loginui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINUI_H
#define UI_LOGINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginUi
{
public:
    QPushButton *btnLogin;
    QLineEdit *textUsername;
    QLineEdit *textPassword;
    QLabel *labelInfo;

    void setupUi(QDialog *LoginUi)
    {
        if (LoginUi->objectName().isEmpty())
            LoginUi->setObjectName("LoginUi");
        LoginUi->resize(400, 300);
        btnLogin = new QPushButton(LoginUi);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setGeometry(QRect(170, 120, 121, 51));
        textUsername = new QLineEdit(LoginUi);
        textUsername->setObjectName("textUsername");
        textUsername->setGeometry(QRect(90, 50, 113, 22));
        textPassword = new QLineEdit(LoginUi);
        textPassword->setObjectName("textPassword");
        textPassword->setGeometry(QRect(90, 90, 113, 22));
        labelInfo = new QLabel(LoginUi);
        labelInfo->setObjectName("labelInfo");
        labelInfo->setGeometry(QRect(60, 210, 291, 41));

        retranslateUi(LoginUi);

        QMetaObject::connectSlotsByName(LoginUi);
    } // setupUi

    void retranslateUi(QDialog *LoginUi)
    {
        LoginUi->setWindowTitle(QCoreApplication::translate("LoginUi", "Dialog", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginUi", "Login", nullptr));
        labelInfo->setText(QCoreApplication::translate("LoginUi", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginUi: public Ui_LoginUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINUI_H
