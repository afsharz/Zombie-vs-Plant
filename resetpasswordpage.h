#ifndef RESETPASSWORDPAGE_H
#define RESETPASSWORDPAGE_H
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include "userinfo.h"
#include "login.h"
class ResetPasswordPage : public QWidget
{
    Q_OBJECT
public:
    explicit ResetPasswordPage(LogIn *PrvPage);
   // ResetPasswordPage(LogIn *PrvPage);
    void newItems();
    void DesignWindow();
    void showPasswordState(UserInfo::state state);
    void showUnacceptablePwd(bool IsTrue);
    ~ResetPasswordPage();
    //enum state{weak,medium,strong};
public slots:
    void checkinfo ();
    void BackBtnClicked();
    void checkSecurity(QString pass);
private :
    LogIn *PrvPage;
    QLabel *backgroundLabel;
    QGridLayout *layout;
    QLabel *lblWrongNum;
    QLabel *errorNumber;
    QLabel *PasswordState;
    QLabel *UnacceptablePass;
    QLineEdit *ledUsername;
    QLineEdit *ledNumber;
    QLineEdit *ledPass;
    QLineEdit *ledConfirmPass;
    QPushButton *btnBack;
    QPushButton *btnReset;
    QWidget *layoutContainer;
    UserInfo *user;
    QRegularExpression *vpass;

    bool isPassValid;
signals:
};

#endif // RESETPASSWORDPAGE_H
