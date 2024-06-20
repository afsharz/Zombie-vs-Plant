#ifndef REGULARZOMBIE_H
#define REGULARZOMBIE_H
#include "zombie.h"
class RegularZombie
:public Zombie
{
public:
    RegularZombie();
    void Decreasinghealth();
    void Movement();
};

#endif // REGULARZOMBIE_H
