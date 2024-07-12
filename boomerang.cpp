#include "boomerang.h"
#include "bullet.h"
#include <QGraphicsScene>

Boomerang::Boomerang(QPointF pos,home *adrs) : Plant(pos , 200 , 1 , 30,adrs)
{
    setPixmap(QPixmap(":/new/prefix1/boomrang_transparent.png"));
    setScale(0.2);
    setPos(pos);
    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(shut()));
    timer->start(FiringRate*1000);
    show();

}

void Boomerang::shut()
{
        bullet *pea=new bullet(AttackPower,Plant::boomerang,pos());
        scene()->addItem(pea);
}


