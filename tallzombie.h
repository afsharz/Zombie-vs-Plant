#ifndef TALLZOMBIE_H
#define TALLZOMBIE_H
#include "zombie.h"
class TallZombie
:public Zombie
{
public:
    TallZombie(QPointF pos,home *adrs);
public slots :
    void Movement();
};

#endif // TALLZOMBIE_H
