#include "plant.h"
#include "bullet.h"
#include <QGraphicsScene>
Plant::Plant(int _health , int _FiringRate , int _AttackPower) :health(_health) ,
    FiringRate(_FiringRate) , AttackPower(_AttackPower) {}

void Plant::Decreasinghealth(int attackpowerzombie)
{
    health -= attackpowerzombie;
}

void Plant::shut()
{
    bullet *pea=new bullet(AttackPower,Plant::non_boomerang,pos());
    scene()->addItem(pea);
}

