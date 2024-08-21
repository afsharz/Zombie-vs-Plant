#ifndef MENU_H
#define MENU_H
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QGridLayout>
#include <QCoreApplication>
#include <QCryptographicHash>
#include "userinfo.h"
class Menu :public QWidget
{
public:
    Menu(UserInfo* _userinfo);
    void newItems();
    void DesignWindow();
private :
    QLabel *backgroundLabel;
    QPushButton *Exit;
    QPushButton *Game;
    QPushButton *History;
    QPushButton *EditInfo;
    QPushButton* Back;
    QPushButton* Save;
    QPushButton* Start;
    QListWidget* showhistory;
    QLineEdit* Username;
    QLineEdit* Name;
    QLineEdit* Mobile;
    QLineEdit* Address;
    QLineEdit* Password;
    QLineEdit* IP;
    UserInfo* userinfo;
public slots :
    void game();
    void history();
    void editinfo();
    void exit();
    void back();
    void save();
    void start();

};

#endif // MENU_H
