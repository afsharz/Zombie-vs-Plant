#include "zombie.h"
#include "walnut.h"
#include "plant.h"
#include "home.h"
#include "jalapeno.h"
#include "plummine.h"

Zombie::Zombie(QPointF _pos ,int _health,int _FirstMovementDelay,int _MovementDelay,
               int _AttackPower, int _FirstTimeBwAttack, int _TimeBwAttack,home *adrs)
    :health(_health),FirstMovementDelay(_FirstMovementDelay),
    MovementDelay(_MovementDelay),AttackPower(_AttackPower),
    FirstTimeBwAttack(_FirstTimeBwAttack) , TimeBwAttack(_TimeBwAttack),HomeAdrs(adrs)
// first initialze list for each type of zombie all attributs
{
    Set_Position(_pos);
    timer = new QTimer(this);
    HomeAdrs->setFlag(true);
    QObject::connect(timer , SIGNAL(timeout()) , this , SLOT(Movement()));
    timer->start(FirstMovementDelay*1000);
    QTimer freeflagtime;
    freeflagtime.singleShot(1500,this,SLOT(setBlockFlag()));
    connect(this,&Zombie::ZombieWin,HomeAdrs,&home::ZomWin);
}
//should check
void Zombie::Decreasinghealth(int attackpowerplant)
{
    if(health - attackpowerplant < 0)
        health = 0;
    else
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

int Zombie::get_health(){return health;}

void Zombie::Movement()
{
    QPointF currentPos = this->pos();

    QList<QGraphicsItem*> itemList = scene()->items();
    for (QGraphicsItem* item : itemList) {
        Plant* plant = dynamic_cast<Plant*>(item);
        if (plant && typeid(*item)!=typeid(Jalapeno) && typeid(*item)!=typeid(PlumMine) )
        {
            qreal distanceX = currentPos.x() - item->pos().x();
            qreal distanceY = qAbs(currentPos.y() - item->pos().y());
            if(distanceX < 100 && distanceY < 50){
                timer->stop();
                attack = new QTimer(this);
                QObject::connect(attack, &QTimer::timeout, this, [this, item]{ Attack(item); });
                attack->start(FirstTimeBwAttack*1000);
            }
        }
    }

    currentPos.setX(currentPos.x() - 39);
    Set_Position(pos());
    this->setPos(currentPos);
    if(this->health<=100){
        this->FirstMovementDelay = MovementDelay;
    }
    if(this->pos().x()<=110)
    {
        emit ZombieWin();
        //deleteLater();
        //zombies win
        delete this;

    }
}

void Zombie::Attack(QGraphicsItem* item)
{
    Plant* plant = dynamic_cast<Plant*>(item);
    if (plant) {
        plant->Decreasinghealth(this->AttackPower);
        this->FirstTimeBwAttack = TimeBwAttack;
        if (plant->get_health() == 0) {
            // Plant health is zero, remove it from the scene
            scene()->removeItem(plant);
            plant->deleteLater();
            delete plant;
            attack->stop();
            //we should delete plant from vector
            timer->start();
        }
    }
}

void Zombie::setBlockFlag()
{
    HomeAdrs->setFlag(false);
}

Zombie::~Zombie()
{
    HomeAdrs->setFlag(false);
    //delete attack;
    //delete timer;
}

