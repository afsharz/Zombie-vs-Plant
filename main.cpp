#include "client.h".h"
#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogIn w;
    w.show();
    Client c("test");
    return a.exec();
}
