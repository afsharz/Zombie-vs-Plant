#ifndef ZOMBIESTORE_H
#define ZOMBIESTORE_H
#include <QGraphicsPixmapItem>
#include <card.h>

class ZombieStore
{
public:
    ZombieStore(QGraphicsScene *scene);

    //private:
    Card *regularzombie;
    Card *bucketheadzombie;
    Card *leafheadzombie;
    Card *tallzombie;
    Card *astronautzombie;
    Card *purplehairzombie;
    QGraphicsScene *scene;
};

#endif // ZOMBIESTORE_H

