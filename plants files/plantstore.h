#ifndef PLANTSTORE_H
#define PLANTSTORE_H
#include <QGraphicsPixmapItem>
#include "card.h"
#include "wallet.h"
#include <QVector>

class PlantStore
{
public:
    PlantStore( QGraphicsScene *scene , Wallet* _wallet );
    Card *peashooter;
    Card *two_peashooter;
    Card *walnut;
    Card *plumMine;
    Card *jalapeno;
    Card *boomerang;
    QGraphicsScene *scene;
    Wallet* wallet;
};

#endif // PLANTSTORE_H
