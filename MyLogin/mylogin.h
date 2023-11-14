#ifndef MYLOGIN_H
#define MYLOGIN_H

#include "MyLogin_global.h"
#include <QObject>

class MYLOGIN_EXPORT MyLogin
{
public:
    MyLogin();

private slots:
    void loginReadySLOT();

signals:
    void loginReadySignal();

private:
    QString loginResponse;
};

#endif // MYLOGIN_H
