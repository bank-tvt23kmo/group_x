#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "studentmenu.h"

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <MyLogin.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnLogin_clicked();
    void loginSlot (QNetworkReply *reply);

    void on_btnLoginDll_clicked();

    void myLoginResponseSLOT();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;
    StudentMenu *objectStudentMenu;
    QString username;
    QByteArray token;
    MyLogin *objectMyLogin;
};
#endif // MAINWINDOW_H
