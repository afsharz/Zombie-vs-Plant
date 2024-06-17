#include "userinfo.h"
#include "registeration.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>

UserInfo::UserInfo(registeration *r)
    :reg(r)
{
    //
        vemail=new QRegularExpression("\\w+@\\w+\\.\\w+");
        vmobile=new QRegularExpression("09\\d{9}$");
        vpass=new QRegularExpression("^.{8,24}$");
}

UserInfo::~UserInfo()
{
    delete vemail;
    delete vmobile;
    delete vpass;
}

void UserInfo::setMobile(QString _mobile)
{
    QRegularExpressionMatch *match=new QRegularExpressionMatch;
    *match=vmobile->match(_mobile);
    if(!match->hasMatch())
        reg->showInvalidMoblieError(true);
    else {
        reg->showInvalidMoblieError(false);
        address=_mobile;
    }
    delete match;
}

void UserInfo::serPassword(QString _password)
{
    QRegularExpressionMatch *match=new QRegularExpressionMatch;
    *match=vemail->match(_password);
}

void UserInfo::setAddress(QString _address)
{
    QRegularExpressionMatch *match=new QRegularExpressionMatch;
    *match=vemail->match(_address);
    if(!match->hasMatch())
        reg->showInvalidEmailError(true);
      else {
        reg->showInvalidEmailError(false);
            address=_address;
        }
    delete match;
}
