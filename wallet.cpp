#include "wallet.h"
#include <QFont>

Wallet::Wallet( int _flag , QGraphicsTextItem * parent) : QGraphicsTextItem(parent) , Money(0) , flag(_flag) {
    //draw money
    if(flag)
        setPlainText(QString("Suns : ") + QString::number(Money));
    else
        setPlainText(QString("Brains : ") + QString::number(Money));
    setDefaultTextColor((Qt::white));
    setFont(QFont("times" , 16));
}

void Wallet:: Increasing() {
    Money+=25;
    if(flag)
        setPlainText(QString("Suns : ") + QString::number(Money));
    else
        setPlainText(QString("Brains : ") + QString::number(Money));
    setDefaultTextColor((Qt::white));
    setFont(QFont("times" , 16));
}

void Wallet:: Decreasing(int HowMany) {
    Money-=HowMany;
    if(flag)
        setPlainText(QString("Suns : ") + QString::number(Money));
    else
        setPlainText(QString("Brains : ") + QString::number(Money));
    setDefaultTextColor((Qt::white));
    setFont(QFont("times" , 16));
}

int Wallet:: Get_Money() { return Money; }
