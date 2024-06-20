#include "plant.h"

Plant::Plant(int _health , int _FiringRate , int _AttackPower) :health(_health) ,
    FiringRate(_FiringRate) , AttackPower(_AttackPower) {}

void Plant::Decreasinghealth(int attackpowerzombie)
{
    health -= attackpowerzombie;
}

