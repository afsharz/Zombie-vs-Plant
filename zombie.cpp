#include "zombie.h"

Zombie::Zombie(QPointF _pos ,int _health,int _FirstMovementDelay,int _MovementDelay,int _AttackPower, int _FirstTimeBwAttack, int _TimeBwAttack)
    :health(_health),FirstMovementDelay(_FirstMovementDelay),
    MovementDelay(_MovementDelay),AttackPower(_AttackPower),
    FirstTimeBwAttack(_FirstTimeBwAttack) , TimeBwAttack(_TimeBwAttack)
// first initialze list for each type of zombie all attributs
{
    Set_Position(_pos);
    // setpixmap()
    //setpos->at first
}

void Zombie::Decreasinghealth(int attackpowerplant)
{
    health -= attackpowerplant;
}

void Zombie::Set_Position(QPointF pos)
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

