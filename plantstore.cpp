#include "plantstore.h"

PlantStore::PlantStore() {
    peashooter=new QGraphicsPixmapItem;
    two_peashooter=new QGraphicsPixmapItem;
    walnut=new QGraphicsPixmapItem;
    jalapeno=new QGraphicsPixmapItem;
    boomerang=new QGraphicsPixmapItem;
    plumMine=new QGraphicsPixmapItem;

    two_peashooter->setPixmap(QPixmap(":/new/prefix1/two_peashooter.jpg"));
    two_peashooter->setPos(0,-120);
    two_peashooter->setScale(0.1);

    peashooter->setPixmap(QPixmap(":/new/prefix1/pea shooter.jpg"));
    peashooter->setPos(0,-225);
    peashooter->setScale(0.1);

    walnut->setPixmap(QPixmap(":/new/prefix1/walnut.jpg"));
    walnut->setPos(110,-225);
    walnut->setScale(0.1);

    jalapeno->setPixmap(QPixmap(":/new/prefix1/jalapino.jpg"));
    jalapeno->setPos(110,-120);
    jalapeno->setScale(0.1);

    boomerang->setPixmap(QPixmap(":/new/prefix1/boomerang.jpg"));
    boomerang->setPos(220,-225);
    boomerang->setScale(0.292);

    plumMine->setPixmap(QPixmap(":/new/prefix1/plum mine.jpg"));
    plumMine->setPos(220,-120);
    plumMine->setScale(0.1);
}
