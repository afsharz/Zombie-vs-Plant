#ifndef PLANTSTORE_H
#define PLANTSTORE_H
#include <QGraphicsPixmapItem>
#include "card.h"

class PlantStore
{
public:
    PlantStore( QGraphicsScene *scene);
    //void setWallet(/* wallet object*/);
//private:
    Card *peashooter;
    Card *two_peashooter;
    Card *walnut;
    Card *plumMine;
    Card *jalapeno;
    Card *boomerang;
    QGraphicsScene *scene;
};

#endif // PLANTSTORE_H
