#ifndef WALLET_H
#define WALLET_H
#include <QGraphicsTextItem>
#include <QVector>
#include <QtAlgorithms>
#include "card.h"

class Wallet : public QGraphicsTextItem
{
public:

    Wallet( int _flag , QGraphicsTextItem * parent=0);
    void Increasing();
    void Decreasing(int HowMany);
    int Get_Money();
    void Set_QVec(QVector<Card*> _QVec);
private :
    int Money;
    int flag;
    QVector<Card*> QVec;
};

#endif // WALLET_H
