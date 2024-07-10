#include <QApplication>
#include "login.h"
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //LogIn w;
   // w.show();
    Client c1("reyhan"),c2("yalda");
    return a.exec();
}
