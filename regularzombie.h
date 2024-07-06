#ifndef REGULARZOMBIE_H
#define REGULARZOMBIE_H
#include "zombie.h"
class RegularZombie
:public Zombie
{
public:
    RegularZombie(QPointF pos,home *adrs);
    void Decreasinghealth();
    void Movement();
};

#endif // REGULARZOMBIE_H
