#ifndef ZOMBIESTORE_H
#define ZOMBIESTORE_H
#include <QGraphicsPixmapItem>
#include "card.h"
#include "wallet.h"
#include <QVector>

class ZombieStore
{
public:
    ZombieStore(QGraphicsScene *scene , Wallet* _wallet );

    //private:
    Card *regularzombie;
    Card *bucketheadzombie;
    Card *leafheadzombie;
    Card *tallzombie;
    Card *astronautzombie;
    Card *purplehairzombie;
    QGraphicsScene *scene;
    Wallet* wallet;
};

#endif // ZOMBIESTORE_H

