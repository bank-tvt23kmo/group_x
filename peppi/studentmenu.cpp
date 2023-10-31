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

void StudentMenu::on_btnInfo_clicked()
{
    QString site_url="http://localhost:3000/student/"+username;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getInfoSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void StudentMenu::getInfoSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    //qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString fname=json_obj["fname"].toString();
    QString lname=json_obj["lname"].toString();
    objectStudentInfo=new StudentInfo(this);
    objectStudentInfo->setFname(fname);
    objectStudentInfo->setLname(lname);
    objectStudentInfo->showStudentData();
    objectStudentInfo->show();
    //qDebug()<<fname;
    reply->deleteLater();
    getManager->deleteLater();
}

