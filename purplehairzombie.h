#ifndef PURPLEHAIRZOMBIE_H
#define PURPLEHAIRZOMBIE_H
#include "zombie.h"
class PurpleHairZombie
:public Zombie
{
public:
    PurpleHairZombie(QPointF pos);
    void Movement();
};

#endif // PURPLEHAIRZOMBIE_H
