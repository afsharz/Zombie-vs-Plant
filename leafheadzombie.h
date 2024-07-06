#ifndef LEAFHEADZOMBIE_H
#define LEAFHEADZOMBIE_H
#include "zombie.h"
class LeafHeadZombie
:public Zombie
{
public:
    LeafHeadZombie(QPointF pos,home *adrs);
    void Movement();
};

#endif // LEAFHEADZOMBIE_H
