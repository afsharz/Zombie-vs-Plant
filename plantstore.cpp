#include "plantstore.h"

PlantStore::PlantStore() {
    peashooter=new QGraphicsPixmapItem;
    two_peashooter=new QGraphicsPixmapItem;
    walnut=new QGraphicsPixmapItem;
    jalapeno=new QGraphicsPixmapItem;
    boomerang=new QGraphicsPixmapItem;
    plumMine=new QGraphicsPixmapItem;
    two_peashooter->setPixmap(QPixmap(":/new/prefix1/two_peashooter.jpg"));
    two_peashooter->setPos(0,-110);
    two_peashooter->setScale(0.1);
}
