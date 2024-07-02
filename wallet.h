#ifndef WALLET_H
#define WALLET_H
#include <QGraphicsTextItem>

class Wallet : public QGraphicsTextItem
{
public:

    Wallet( int _flag , QGraphicsTextItem * parent=0);

    void Increasing();
    void Decreasing(int HowMany);
    int Get_Money();
private :
    int Money;
    int flag;

};

#endif // WALLET_H
