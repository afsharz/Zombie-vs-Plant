#include "userinfo.h"
#include "registeration.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>

UserInfo::UserInfo(registeration *r)
    :reg(r) , PlayerFile(NULL)
{
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
        mobile=_mobile;
    }
    delete match;
}

void UserInfo::setPassword(QString _password)
{
    int count=0;
    QRegularExpressionMatch *match=new QRegularExpressionMatch();
    *match=vpass->match(_password);
    if(!match->hasMatch())
        reg->showUnacceptablePwd(true);
    else
    {
        reg->showUnacceptablePwd(false);
        password=_password;
    }
    QRegularExpression *state=new QRegularExpression("\\W+");
    *match=state->match(_password);
    if(match->hasMatch()) count++;
    state->setPattern("[A-Z]+");
    *match=state->match(_password);
    if(match->hasMatch()) count++;
    state->setPattern("[a-z]+");
    *match=state->match(_password);
    if(match->hasMatch()) count++;
    state->setPattern("\\d+");
    *match=state->match(_password);
    if(match->hasMatch()) count++;
    state->setPattern("^.{10}");
    *match=state->match(_password);
    if(match->hasMatch()) count++;
    switch(count)
    {
    case 0:
    {
        reg->showPasswordState(weak);
        break;
    }
    case 1:
    {
        reg->showPasswordState(weak);
        break;
    }
    case 2:
    {
        reg->showPasswordState(medium);
        break;
    }
    case 3:
    {
        reg->showPasswordState(medium);
        break;
    }
    case 4:
    {
        reg->showPasswordState(strong);
        break;
    }
    case 5:
    {
        reg->showPasswordState(strong);
        break;
    }

    }

    delete state;
    delete match;

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



QString UserInfo::getName(){return name;}
QString UserInfo::getUsername(){ return username;}
QString UserInfo::getPassword(){return password;}
QString UserInfo::getEmail(){return address;}
QString UserInfo::getMobile(){return mobile;}
void UserInfo::set_Name(QString _name){name=_name;}
void UserInfo::set_Username(QString _username){username=_username;}
void UserInfo::set_Mobile(QString _mobile){mobile=_mobile;}
void UserInfo::set_Password(QString _password){password=_password;}
void UserInfo::set_Address(QString _address){address=_address;;}
void UserInfo::set_Qfile()
{
    qDebug() << "Im here";
    QString filename = username + "history.txt";
    PlayerFile = new QFile(filename);
}

QFile *UserInfo::get_QFile() {return PlayerFile;}

void UserInfo::setName(QString _name){name = _name;}

void UserInfo::setUsername(QString _username){username = _username;}
