#include "peashooter.h"

PeaShooter::PeaShooter(QPointF pos) : Plant(200 , 1 , 15) {
    setPixmap(QPixmap(":/new/prefix1/peashooter transparent.png"));
    setScale(0.1);
    setPos(pos);
    show();
}
