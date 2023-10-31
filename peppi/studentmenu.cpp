#include "studentmenu.h"
#include "ui_studentmenu.h"

StudentMenu::StudentMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentMenu)
{
    ui->setupUi(this);
}

StudentMenu::~StudentMenu()
{
    delete ui;
}

void StudentMenu::setUsername(const QString &newUsername)
{
    username = newUsername;
}

void StudentMenu::showUsername()
{
    ui->labelUsername->setText(username);
}

void StudentMenu::setToken(const QByteArray &newToken)
{
    token = newToken;
    qDebug()<<token;
}
