#ifndef LOGINUI_H
#define LOGINUI_H

#include <QObject>
#include <QDialog>
#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class LoginUi;
}

class LoginUi : public QDialog
{
    Q_OBJECT

public:
    explicit LoginUi(QWidget *parent = nullptr);
    ~LoginUi();

    QByteArray getHttpResponse() const;

private slots:
    void on_btnLogin_clicked();
    void httpRequestSLOT(QNetworkReply*);

private:
    Ui::LoginUi *ui;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString username;
    QByteArray httpResponse;

signals:
    void httpResponseReadySignal();
};

#endif // LOGINUI_H
