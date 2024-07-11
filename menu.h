#ifndef MENU_H
#define MENU_H
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QGridLayout>
#include "userinfo.h"
class Menu :public QWidget
{
public:
    Menu(UserInfo* _userinfo);
    void newItems();
    void DesignWindow();
    //~Menu();
private :
    QLabel *backgroundLabel;
    QPushButton *Exit;
    QPushButton *Game;
    QPushButton *History;
    QPushButton *EditInfo;
    QListWidget* showhistory;
    UserInfo* userinfo;
public slots :
    void game();
    void history();
    void editinfo();
    void exit();

};

#endif // MENU_H
