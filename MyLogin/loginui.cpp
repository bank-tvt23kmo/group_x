#include "loginui.h"
#include "ui_loginui.h"

LoginUi::LoginUi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginUi)
{
    ui->setupUi(this);
}

LoginUi::~LoginUi()
{
    delete ui;
}


void LoginUi::on_btnLogin_clicked()
{
    username=ui->textUsername->text();
    QString password=ui->textPassword->text();
    QJsonObject jsonObj;
    jsonObj.insert("username",username);
    jsonObj.insert("password",password);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(httpRequestSLOT(QNetworkReply*)));

    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
}

void LoginUi::httpRequestSLOT(QNetworkReply *reply)
{
    qDebug()<<"httpRequestSLOT";
    response_data=reply->readAll();
    if(response_data.length()<2){
        qDebug()<<"Palvelin ei vastaa";
        ui->labelInfo->setText("Palvelin ei vastaa");
    }
    else{
        if(response_data=="-4078"){
            qDebug()<<"Virhe tietokanta yhteydessä";
            ui->labelInfo->setText("Virhe tietokanta yhteydessä");
        }
        else {
            if(response_data!="false" && response_data.length()>20){
                qDebug()<<"Login Ok";
                httpResponse="Bearer "+response_data;
                emit httpResponseReadySignal();
            }
            else{
                qDebug()<<"Väärä salasana";
                ui->labelInfo->setText("Tunnus ja salasana eivät täsmää");
                ui->textUsername->clear();
                ui->textPassword->clear();
            }
        }
    }
    reply->deleteLater();
    postManager->deleteLater();
}

QByteArray LoginUi::getHttpResponse() const
{
    return httpResponse;
}

