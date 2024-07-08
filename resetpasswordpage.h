#ifndef RESETPASSWORDPAGE_H
#define RESETPASSWORDPAGE_H
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include "userinfo.h"
class ResetPasswordPage : public QWidget
{
    Q_OBJECT
public:
    explicit ResetPasswordPage(QWidget *parent = nullptr);
    void newItems();
    void DesignWindow();
        ~ResetPasswordPage();
public slots:
        void checkinfo ();
    void BackBtnClicked();
private :
    QLabel *backgroundLabel;
    QGridLayout *layout;
    QLabel *lblUsername;
    QLabel *lblNumber;
    QLabel *lblPass;
    QLabel *lblConfirmPass;
    QLabel *lblWrongNum;
    QLabel *errorNumber;
    QLineEdit *ledUsername;
    QLineEdit *ledNumber;
    QLineEdit *ledPass;
    QLineEdit *ledConfirmPass;
    QPushButton *btnBack;
    QPushButton *btnReset;
    QWidget *layoutContainer;
    UserInfo *user;
signals:
};

#endif // RESETPASSWORDPAGE_H
