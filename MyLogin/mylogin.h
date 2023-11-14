#ifndef MYLOGIN_H
#define MYLOGIN_H

#include "MyLogin_global.h"
#include <LoginUi.h>
#include <QObject>

class MYLOGIN_EXPORT MyLogin
{
public:
    MyLogin();
    void openUI();

private slots:
    void loginReadySLOT();

signals:
    void loginReadySignal();

private:
    QString loginResponse;
    LoginUi *objectLoginUi;
};

#endif // MYLOGIN_H
