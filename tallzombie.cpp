#include "tallzombie.h"
#include "walnut.h"

TallZombie::TallZombie(QPointF pos,home *adrs)
    :Zombie(pos,500,1,1,30,1,1,adrs)
{
    setPixmap(QPixmap(":/new/prefix1/tall zombie_transparent.png"));
    setScale(0.1);
    setPos(pos);
    //setHomeFlag(true);
    show();
}
void TallZombie::Movement()
{
    QPointF currentPos = this->pos();
    QList<QGraphicsItem*> itemList = scene()->items();
    for (QGraphicsItem* item : itemList) {
        Plant* plant = dynamic_cast<Plant*>(item);
        if (plant && typeid(*item)!=typeid(Walnut))
        {
            qreal distanceX = currentPos.x() - item->pos().x();//QLineF(currentPos, item->pos()).length();
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
    if(this->pos().x()<=110)
    {
        emit ZombieWin();
        //deleteLater();
        //zombies win
        delete this;

    }
}
