#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    registeration *rg;
};
#endif // MAINWINDOW_H
