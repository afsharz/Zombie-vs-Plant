#include "plummine.h"

PlumMine::PlumMine(QPointF pos  , QGraphicsScene * _scene) : Plant(pos , 0 ,0 , 500) , scene(_scene){
    setPixmap(QPixmap(":/new/prefix1/plum mine_transparent.png"));
    setScale(0.07);
    QTimer* changetimer = new QTimer(this);
    connect(changetimer, &QTimer::timeout, this, &PlumMine::HandlePlumMine);
    changetimer->start(500);

    qreal cellWidth = 77;
    qreal cellHeight = 70;
    qreal startX= 119 + (this->position.first-2)*77 , startY = 36 + (this->position.second-2)*70;

    if(pos.y()>=105 && pos.y()<178){
        startY -= 4;
    }
    else if(pos.y()>=398){
        startY -= 4;
    }
    QList<QGraphicsItem*> itemList = scene->items();
    for (QGraphicsItem* item : itemList) {

        if (item->pos().y()>=startY &&  item->pos().y()<=startY+3*cellHeight && item->pos().x()>=startX &&  item->pos().x()<startX+3*cellWidth) {

            if (typeid(*item)==typeid(Zombie))
            {
                dynamic_cast<Zombie*>(item)->Decreasinghealth(500);
            }
        }
    }
    show();
    QTimer* deleteTimer = new QTimer(this);
    connect(deleteTimer, &QTimer::timeout, this, &PlumMine::deleteObject);
    deleteTimer->start(2000);
}

void PlumMine::HandlePlumMine()
{
    setPixmap(QPixmap(":/new/prefix1/Layer 2.png"));
    setScale(0.1);
}

void PlumMine::deleteObject() {
    deleteLater();
}
