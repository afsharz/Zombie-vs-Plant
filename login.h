#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QCryptographicHash>
#include <QCoreApplication>
#include <QDialog>
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QString>
#include "registeration.h"
#include "userinfo.h"

namespace Ui {
class LogIn;
}

class LogIn : public QDialog
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = nullptr);
    ~LogIn();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LogIn *ui;
    registeration *rg;
    QString username;
    UserInfo *user;
};

#endif // LOGIN_H
