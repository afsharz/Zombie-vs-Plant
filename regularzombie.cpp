#include "regularzombie.h"

RegularZombie::RegularZombie(QPointF pos)
    :Zombie(pos,500,1,1,25,1,1)
{
    setPixmap(QPixmap(":/new/prefix1/regular zombie_transparent.png"));
    setScale(0.1);
    setPos(pos);
    show();
}
