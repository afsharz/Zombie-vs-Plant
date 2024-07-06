#include "bullet.h"
#define length_of_move 5
bullet::bullet(int _power,Plant:: Type t,QPointF _pos)
    : power(_power)
{
    switch (t) {
    case Plant::boomerang:
    { IsBoomerang=true;
        break;
    }
    case Plant::non_boomerang:
        IsBoomerang=false;
        break;
    }
    setPos(_pos);
    setPixmap(QPixmap(":/new/prefix1/pea.png"));
    setScale(0.07);
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
    QList<QGraphicsItem*> list= scene()->items(pos());
    for ( auto x: list)
    {
        if (typeid(*x)==typeid(Zombie))
        {
            Zombie* zombie = dynamic_cast<Zombie*>(x);
            if (zombie) {
                zombie->Decreasinghealth(power);
                if (zombie->get_health() == 0) {
                    // zombie health is zero, remove it from the scene
                    scene()->removeItem(zombie);
                    zombie->deleteLater();
                    delete zombie;
                }
            }
            if (!IsBoomerang)
            {
                scene()->removeItem(this);
                delete this;
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
