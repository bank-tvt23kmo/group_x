#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnLogin_clicked()
{
    QString username=ui->textUsername->text();
    QString password=ui->textPassword->text();
    QJsonObject jsonObj;
    jsonObj.insert("username",username);
    jsonObj.insert("password",password);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());

}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    if(response_data.length()<2){
        qDebug()<<"Palvelin ei vastaa";
    }
    else{
        if(response_data=="-4078"){
            qDebug()<<"Virhe tietokanta yhteydessä";
        }
        else {
            if(response_data!="false" && response_data.length()>20){
                qDebug()<<"Login Ok";
            }
            else{
                qDebug()<<"Väärä salasana";
            }
        }
    }
    reply->deleteLater();
    postManager->deleteLater();
}



