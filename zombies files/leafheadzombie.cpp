#include "leafheadzombie.h"

LeafHeadZombie::LeafHeadZombie(QPointF pos,home *adrs)
    :Zombie(pos,800,1,1,25,1,1,adrs)
{
    setPixmap(QPixmap(":/new/prefix1/leaf hair zombie_transparent.png"));
    setScale(0.1);
    setPos(pos);
    show();
}
