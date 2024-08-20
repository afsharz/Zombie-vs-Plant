#ifndef REGISTERATION_H
#define REGISTERATION_H

#include <QDialog>
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QCoreApplication>
#include <QCryptographicHash>
#include <QLabel>
#include "userinfo.h"

namespace Ui {
class registeration;
}

class registeration : public QDialog
{
    Q_OBJECT

public:
    explicit registeration(QWidget *parent = nullptr);
    ~registeration();
    void designWindow();
    void showInvalidEmailError(bool IsTrue);
    void showInvalidMoblieError(bool IsTrue);
    void showUnacceptablePwd(bool IsTrue);
    void showPasswordState(UserInfo::state state);
    void adjustWidgetPositions(int offset);
private slots:
    void on_pushButton_4_clicked();
private:
    Ui::registeration *ui;
    UserInfo *user;
    QLabel *InvalidEmailError;
    QLabel *InvalidMobileError;
    QLabel *PasswordState;
    QLabel *UnacceptablePass;
    QList<QWidget*> widgetsBelowEmail;
};

#endif // REGISTERATION_H
