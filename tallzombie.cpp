#include "tallzombie.h"

TallZombie::TallZombie(QPointF pos,home *adrs)
    :Zombie(pos,500,1,1,30,1,1,adrs)
{
    setPixmap(QPixmap(":/new/prefix1/tall zombie_transparent.png"));
    setScale(0.1);
    setPos(pos);
    //setHomeFlag(true);
    show();
}
