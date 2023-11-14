#include "mylogin.h"

MyLogin::MyLogin()
{
}

void MyLogin::openUI()
{
    LoginUi objectLoginUi;
    objectLoginUi.exec();
}
