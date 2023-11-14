#ifndef MYLOGIN_H
#define MYLOGIN_H

#include "MyLogin_global.h"
#include <LoginUi.h>
#include <QObject>

class MYLOGIN_EXPORT MyLogin: public QObject
{
    Q_OBJECT

public:
    MyLogin();
    ~MyLogin();
    void openUI();

    QByteArray getLoginResponse() const;

private slots:
    void loginReadySLOT();

private:
    QByteArray loginResponse;
    LoginUi *objectLoginUi;

signals:
    void loginReadySignal();
};

#endif // MYLOGIN_H
