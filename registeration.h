#ifndef REGISTERATION_H
#define REGISTERATION_H

#include <QDialog>
#include <QDialog>
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QCoreApplication>
#include <QCryptographicHash>

namespace Ui {
class registeration;
}

class registeration : public QDialog
{
    Q_OBJECT

public:
    explicit registeration(QWidget *parent = nullptr);
    ~registeration();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::registeration *ui;
};

#endif // REGISTERATION_H
