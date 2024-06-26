#include "zombiestore.h"

ZombieStore::ZombieStore() {
    regularzombie=new QGraphicsPixmapItem;
    bucketheadzombie=new QGraphicsPixmapItem;
    leafheadzombie=new QGraphicsPixmapItem;
    tallzombie=new QGraphicsPixmapItem;
    astronautzombie=new QGraphicsPixmapItem;
    purplehairzombie=new QGraphicsPixmapItem;

    regularzombie->setPixmap(QPixmap(":/new/prefix1/regular zombie.jpg"));
    regularzombie->setPos(750,-120);
    regularzombie->setScale(0.1);

    bucketheadzombie->setPixmap(QPixmap(":/new/prefix1/Bucket head zombie.jpg"));
    bucketheadzombie->setPos(750,-225);
    bucketheadzombie->setScale(0.1);

    leafheadzombie->setPixmap(QPixmap(":/new/prefix1/leaf hair zombie.jpg"));
    leafheadzombie->setPos(860,-225);
    leafheadzombie->setScale(0.1);

    tallzombie->setPixmap(QPixmap(":/new/prefix1/tall zombie.jpg"));
    tallzombie->setPos(860,-120);
    tallzombie->setScale(0.1);

    astronautzombie->setPixmap(QPixmap(":/new/prefix1/astronaut zombie.jpg"));
    astronautzombie->setPos(970,-225);
    astronautzombie->setScale(0.1);

    purplehairzombie->setPixmap(QPixmap(":/new/prefix1/purple hair zombie.jpg"));
    purplehairzombie->setPos(970,-120);
    purplehairzombie->setScale(0.1);
}

