#include "bullet.h"

#define length_of_move 5
bullet::bullet(int _power,Plant:: Type t,QPointF _pos)
    : power(_power)
{
    switch (t)
    {
    case Plant::boomerang:
    { IsBoomerang=true;
        break;
    }
    case Plant::non_boomerang:
    {
        IsBoomerang=false;
        break;
    }
    }
    setPos(_pos);
    setPixmap(QPixmap(":/new/prefix1/pea.jpg.png"));
    setScale(0.2);
    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(30);
    show();

}

bullet::~bullet()
{
    delete timer;
}

void bullet::move()
{
    QList<QGraphicsItem*> list= collidingItems();
    for ( auto x: list)
    {
        Zombie* zombie = dynamic_cast<Zombie*>(x);
        if (zombie) {
            if(HaveHit.count(zombie)==0){
                zombie->Decreasinghealth(power);
                HaveHit.push_back(zombie);
                if (zombie->get_health() == 0) {
                    // zombie health is zero, remove it from the scene
                    scene()->removeItem(zombie);
                    zombie->deleteLater();
                }
                if (!IsBoomerang)
                {
                    scene()->removeItem(this);
                    this->deleteLater();
                    return;
                }
            }
        }  
    }

    if(x()+this->boundingRect().width()>0)
        this->setPos(x()+length_of_move,y());
    else if(x()+this->boundingRect().width()<=0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
