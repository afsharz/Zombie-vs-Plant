#include "peashooter.h"
#include <QTimer>

PeaShooter::PeaShooter(QPointF pos) : Plant(pos , 200 , 1 , 15) {
    setPixmap(QPixmap(":/new/prefix1/peashooter transparent.png"));
    setScale(0.1);
    setPos(pos);
    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(shut()));
    timer->start(FiringRate*1000);
    show();
}
