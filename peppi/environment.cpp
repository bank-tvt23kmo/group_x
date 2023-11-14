#include "environment.h"

Environment::Environment()
{

}

QString Environment::getBaseUrl()
{
    return "http://localhost:3000";
    //return "https://group-x.onrender.com";
    //return "http://ipv4.fiddler:3000";
}
