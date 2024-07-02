#include "wallet.h"
#include <QFont>

Wallet::Wallet( int flag , QGraphicsTextItem * parent) : QGraphicsTextItem(parent) , Money(0) {
    //draw money
    if(flag)
        setPlainText(QString("Suns : ") + QString::number(Money));
    else
        setPlainText(QString("Brains : ") + QString::number(Money));
    setDefaultTextColor((Qt::white));
    setFont(QFont("times" , 16));
}

void Wallet:: Increasing() { Money+=25 ;}

void Wallet:: Decreasing(int HowMany) { Money-=HowMany; }

int Wallet:: Get_Money() { return Money; }
