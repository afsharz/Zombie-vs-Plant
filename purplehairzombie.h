#ifndef PURPLEHAIRZOMBIE_H
#define PURPLEHAIRZOMBIE_H
#include "zombie.h"
class PurpleHairZombie
:public Zombie
{
public:
    PurpleHairZombie(QPointF pos,home *adrs);
    void Movement();
};

#endif // PURPLEHAIRZOMBIE_H
