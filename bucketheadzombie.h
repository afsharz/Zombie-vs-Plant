#ifndef BUCKETHEADZOMBIE_H
#define BUCKETHEADZOMBIE_H
#include "zombie.h"
class BucketHeadZombie
:public Zombie
{
public:
    BucketHeadZombie(QPointF pos,home *adrs);
    void Movement();
};

#endif // BUCKETHEADZOMBIE_H
