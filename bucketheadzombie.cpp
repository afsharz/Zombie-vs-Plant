#include "bucketheadzombie.h"

BucketHeadZombie::BucketHeadZombie(QPointF pos)
    :Zombie(1050,2,2,50,1,1)
{
    setPixmap(QPixmap(":/new/prefix1/Bucket head zombie_trasparent.png"));
    setScale(0.1);
    setPos(pos);
    show();
}
