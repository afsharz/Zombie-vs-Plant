#ifndef ASTRONAUTZOMBIE_H
#define ASTRONAUTZOMBIE_H
#include "zombie.h"
class AstronautZombie
:public Zombie
{
public:
    AstronautZombie(QPointF pos,home *adrs);
};

#endif // ASTRONAUTZOMBIE_H
