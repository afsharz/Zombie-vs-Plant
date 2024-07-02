#ifndef ASTRONAUTZOMBIE_H
#define ASTRONAUTZOMBIE_H
#include "zombie.h"
class AstronautZombie
:public Zombie
{
public:
    AstronautZombie(QPointF pos);
    void Movement();
};

#endif // ASTRONAUTZOMBIE_H
