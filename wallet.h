#ifndef WALLET_H
#define WALLET_H
#include <QGraphicsTextItem>

class Wallet : public QGraphicsTextItem
{
public:
    Wallet( int flag , QGraphicsTextItem * parent=0);
    void Increasing();
    void Decreasing(int HowMany);
    int Get_Money();
private :
    int Money;
};

#endif // WALLET_H
