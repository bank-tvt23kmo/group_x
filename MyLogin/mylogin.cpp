#include "mylogin.h"

MyLogin::MyLogin()
{
    objectLoginUi=new LoginUi;
}

MyLogin::~MyLogin()
{
    delete objectLoginUi;
    objectLoginUi=nullptr;
}

void MyLogin::openUI()
{
    connect(objectLoginUi, SIGNAL(httpResponseReadySignal()), this, SLOT(loginReadySLOT()) );
    objectLoginUi->exec();
}


void MyLogin::loginReadySLOT()
{
    qDebug()<<"loginReadySLOT";
    loginResponse=objectLoginUi->getHttpResponse();
    qDebug()<<loginResponse;
    emit loginReadySignal();
    objectLoginUi->close();
}

QByteArray MyLogin::getLoginResponse() const
{
    qDebug()<<"getLoginResponse";
    return loginResponse;
}
