#ifndef STUDENTMENU_H
#define STUDENTMENU_H

#include "studentgrade.h"

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <studentinfo.h>

namespace Ui {
class StudentMenu;
}

class StudentMenu : public QDialog
{
    Q_OBJECT

public:
    explicit StudentMenu(QWidget *parent = nullptr);
    ~StudentMenu();

    void setUsername(const QString &newUsername);
    void showUsername();

    void setToken(const QByteArray &newToken);

private slots:
    void on_btnInfo_clicked();
    void getInfoSlot(QNetworkReply *reply);
    void getGradeSlot(QNetworkReply *reply);

    void on_btnGrade_clicked();

private:
    Ui::StudentMenu *ui;
    QString username;
    QByteArray token;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    StudentInfo *objectStudentInfo;
    StudentGrade *objectStudentGrade;
};

#endif // STUDENTMENU_H
