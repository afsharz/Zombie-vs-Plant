#include "astronautzombie.h"

AstronautZombie::AstronautZombie(QPointF pos)
    :Zombie(pos,500,1,0.5,20,1,0.5)
{
    setPixmap(QPixmap(":/new/prefix1/astronaut zombie_transparent.png"));
    setScale(0.1);
    setPos(pos);
    show();
}
