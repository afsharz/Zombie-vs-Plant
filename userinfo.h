#ifndef USERINFO_H
#define USERINFO_H
#include <QFile>
#include <QString>
#include <QObject>
class registeration;
class UserInfo
:public QObject
{
public:
    UserInfo(registeration *r=NULL);
    ~UserInfo();
    enum state{ weak,medium,strong};
    QString getName();
    QString getUsername();
    QString getPassword();
    QString getEmail();
    QString getMobile();
    void set_Name(QString _name);
    void set_Username(QString _username);
    void set_Mobile(QString _mobile);
    void set_Password(QString _password);
    void set_Address(QString _address);
    void setQfile();
    QFile* getQFile();
public slots:
    void setName(QString _name);
    void setUsername(QString _username);
    void setMobile(QString _mobile);
    void setPassword(QString _password);
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
    QFile* PlayerFile=NULL;
};

#endif // USERINFO_H
