#include "jalapeno.h"
#include <QThread>
#include <QPen>
#include <QBrush>
#include "home.h"

Jalapeno::Jalapeno(QPointF pos , QGraphicsScene * _scene,home *adrs) : Plant(pos , 0 ,0 , 300,adrs) , scene(_scene) {
    setPixmap(QPixmap(":/new/prefix1/jalapino_transparent.png"));
    setScale(0.07);
    redRectangle = new QGraphicsRectItem;
    qreal cellWidth = 77;
    qreal cellHeight = 70;
    qreal startX=119 , startY = 36 + (this->position.second-1)*72;

    if(pos.y()>=105 && pos.y()<178){
        startY -= 4;
    }
    else if(pos.y()>=398){
        startY -= 2;
    }
    redRectangle->setRect(QRectF(startX, startY, 12*cellWidth, cellHeight));
    QColor semiTransparentRed(255, 0, 0, 127);
    redRectangle->setBrush(semiTransparentRed);
    scene->addItem(redRectangle);
    show();
    QList<QGraphicsItem*> itemList = scene->items();
    for (QGraphicsItem* item : itemList) {

        if (item->pos().y()>=startY && item->pos().y()<=startY+cellHeight ) {
            Zombie* zombie = dynamic_cast<Zombie*>(item);
            if (zombie) {
                zombie->Decreasinghealth(300);
                if (zombie->get_health() == 0) {
                    // zombie health is zero, remove it from the scene
                    scene->removeItem(zombie);
                    zombie->deleteLater();
                    delete zombie;
                }
            }
        }
    }
    show();

    QTimer* deleteTimer = new QTimer(this);
    connect(deleteTimer, &QTimer::timeout, this, &Jalapeno::deleteObjectAndRectangle);
    deleteTimer->start(1000); // 1000 ms (1 second) delay
}

void Jalapeno::deleteObjectAndRectangle() {
    scene->removeItem(redRectangle);
    delete redRectangle;
    deleteLater();
}
