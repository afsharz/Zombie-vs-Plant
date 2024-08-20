#include "plant.h"
#include "bullet.h"
#include <QGraphicsScene>
#include "home.h"
Plant::Plant(QPointF _pos , int _health , int _FiringRate , int _AttackPower,home *adrs) : health(_health) ,
    FiringRate(_FiringRate) , AttackPower(_AttackPower) ,HomeAdrs(adrs){
    adrs->setFlag(true);
    Set_Position(_pos);
}

void Plant::Decreasinghealth(int attackpowerzombie)
{
    if(health - attackpowerzombie < 0)
        health = 0;
    else
        health -= attackpowerzombie;
}

void Plant::Set_Position(QPointF pos)
{
    if(pos.y()<105){
        position.second=1;
    }
    else if(pos.y()>=105 && pos.y()<178){
        position.second=2;
    }
    else if(pos.y()>=178 && pos.y()<255){
        position.second=3;
    }
    else if(pos.y()>=255 && pos.y()<328){
        position.second=4;
    }
    else if(pos.y()>= 328 && pos.y()<398){
        position.second=5;
    }
    else if(pos.y()>=398){
        position.second=6;
    }
    if(pos.x()<196){
        position.first=1;
    }
    else if(pos.x()>=196 && pos.x()<273){
        position.first=2;
    }
    else if(pos.x()>=273 && pos.x()<350){
        position.first=3;
    }
    else if(pos.x()>=350 && pos.x()<427){
        position.first=4;
    }
    else if(pos.x()>=427 && pos.x()<504){
        position.first=5;
    }
    else if(pos.x()>=504 && pos.x()<581){
        position.first=6;
    }
    else if(pos.x()>=581 && pos.x()<658){
        position.first=7;
    }
    else if(pos.x()>=658 && pos.x()<735){
        position.first=8;
    }
    else if(pos.x()>=735 && pos.x()<812){
        position.first=9;
    }
    else if(pos.x()>=812 && pos.x()<889){
        position.first=10;
    }
    else if(pos.x()>=889 && pos.x()<966){
        position.first=11;
    }
    else if(pos.x()>=966 && pos.x()<1043){
        position.first=12;
    }
}

int Plant::get_health(){return health;}


void Plant::setHomeAdrs(home *adrs)
{
    HomeAdrs=adrs;
}

void Plant::shut()
{
    bullet *pea=new bullet(AttackPower,Plant::non_boomerang,pos());
    scene()->addItem(pea);
}

Plant::~Plant()
{
    HomeAdrs->setFlag(false);
}
