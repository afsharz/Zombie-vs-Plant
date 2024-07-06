#include "zombie.h"
#include "plant.h"

Zombie::Zombie(QPointF _pos ,int _health,int _FirstMovementDelay,int _MovementDelay,int _AttackPower, int _FirstTimeBwAttack, int _TimeBwAttack)
    :health(_health),FirstMovementDelay(_FirstMovementDelay),
    MovementDelay(_MovementDelay),AttackPower(_AttackPower),
    FirstTimeBwAttack(_FirstTimeBwAttack) , TimeBwAttack(_TimeBwAttack)
// first initialze list for each type of zombie all attributs
{
    Set_Position(_pos);
    timer = new QTimer(this);
    QObject::connect(timer , SIGNAL(timeout()) , this , SLOT(Movement()));
    timer->start(FirstMovementDelay*1000);
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
    //should check
    QList<QGraphicsItem*> itemList = scene()->items();
    for (QGraphicsItem* item : itemList) {
        if (typeid(*item)==typeid(Plant))
        {
            qreal distance = QLineF(currentPos, item->pos()).length();
            if(distance<50){
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
    if(this->pos().x()<=110){
        deleteLater();
        //zombies win
    }
}

void Zombie::Attack(QGraphicsItem* item)
{
    Plant* plant = dynamic_cast<Plant*>(item);
    if (plant) {
        plant->Decreasinghealth(this->AttackPower);
        if (plant->get_health() == 0) {
            // Plant health is zero, remove it from the scene
            scene()->removeItem(plant);
            plant->deleteLater();
            delete plant;
            timer->start();
        }
    }
}

