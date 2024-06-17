#ifndef USERINFO_H
#define USERINFO_H

#include <QString>
#include <QObject>
class registeration;
class UserInfo
:public QObject
{
public:
    UserInfo(registeration *r);
    ~UserInfo();
    enum state{ weak,medium,strong};
public slots:
    void setName(QString _name);
    void setUsername(QString _username);
    void setMobile(QString _mobile);
    void serPassword(QString _password);
    void setAddress(QString _address);


private:
    QString name;
    QString username ;
    QString mobile ;
    QString password ;
    QString address ;
    registeration *reg;
    QRegularExpression *vemail;
    QRegularExpression *vmobile;
    QRegularExpression *vpass;
};

#endif // USERINFO_H
