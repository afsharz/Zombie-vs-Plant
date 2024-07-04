#include "two_peashooter.h"
#include <QTimer>
Two_PeaShooter::Two_PeaShooter(QPointF pos) : Plant(200 , 1 , 40)
{
    setPixmap(QPixmap(":/new/prefix1/two_peashooter_transparent.png"));
    setScale(0.07);
    setPos(pos);
    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(shut()));
    timer->start(FiringRate*1000);
    show();
}
