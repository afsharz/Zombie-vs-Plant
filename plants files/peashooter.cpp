#include "peashooter.h"
#include <QTimer>

PeaShooter::PeaShooter(QPointF pos,home *adrs) : Plant(pos , 200 , 1 , 15,adrs)
{
    setPixmap(QPixmap(":/new/prefix1/peashooter transparent.png"));
    setScale(0.1);
    setPos(pos);
    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(shut()));
    timer->start(FiringRate*1000);
    show();
}
