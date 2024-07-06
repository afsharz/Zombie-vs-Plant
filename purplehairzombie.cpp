#include "purplehairzombie.h"

PurpleHairZombie::PurpleHairZombie(QPointF pos)
    :Zombie(pos,4000,1,1,75,0.5,0.5)
{
    setPixmap(QPixmap(":/new/prefix1/purple hair zombie_transparent.png"));
    setScale(0.1);
    setPos(pos);
    show();
}
