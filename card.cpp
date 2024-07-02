#include "card.h"
#include "home.h"
#define c1r1 QPointF(1200,220)
Card::Card(QGraphicsScene *scene,QString _Type)
    :scene (scene),Type(_Type)
{
    pre=nullptr;
}


void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragStartPosition = event->pos();
        QPointF newPos = mapToScene(event->pos() - dragStartPosition);
        transparent=new QGraphicsPixmapItem();


        if(Type=="PeaShooter")
        transparent->setPixmap(QPixmap(":/new/prefix1/peashooter transparent.png"));
        else if(Type=="TwoPeashooter")
            transparent->setPixmap(QPixmap(":/new/prefix1/two_peashooter_transparent.png"));
        else if(Type=="Walnut")
            transparent->setPixmap(QPixmap(":/new/prefix1/walnut_transparent.png"));
        else if(Type=="PlumMine")
            transparent->setPixmap(QPixmap(":/new/prefix1/plum mine_transparent.png"));
        else if(Type=="Jalapeno")
            transparent->setPixmap(QPixmap(":/new/prefix1/jalapino_transparent.png"));
        else if(Type=="Boomerang")
            transparent->setPixmap(QPixmap(":/new/prefix1/boomrang_transparent.png"));
        else if (Type=="regularzombie")
            transparent->setPixmap(QPixmap(":/new/prefix1/regular zombie_transparent.png"));
        else if (Type=="bucketheadzombie")
            transparent->setPixmap(QPixmap(":/new/prefix1/Bucket head zombie_trasparent.png"));
        else if (Type=="leafheadzombie")
        transparent->setPixmap(QPixmap(":/new/prefix1/leaf hair zombie_transparent.png"));
        else if (Type=="tallzombie")
            transparent->setPixmap(QPixmap(":/new/prefix1/tall zombie_transparent.png"));
        else if (Type=="astronautzombie")
        transparent->setPixmap(QPixmap(":/new/prefix1/astronaut zombie_transparent.png"));
        else if (Type=="purplehairzombie")
            transparent->setPixmap(QPixmap(":/new/prefix1/purple hair zombie_transparent.png"));
        scene->addItem(transparent);
        transparent->setPos(newPos);
        transparent->setScale(0.1);
    }
    //QGraphicsPixmapItem::mousePressEvent(event);
}
void Card::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        QPointF newPos = mapToScene(event->pos() - dragStartPosition);
        //QPointF newPos = event->scenePos();
        transparent->setPos(newPos);

        // Find items under the cursor
        QList<QGraphicsItem*> items = scene->items(newPos);
        for (QGraphicsItem* item : items) {
            home* h = dynamic_cast<home*>(item);
            //if (h)
            //{
                //h->highlight();
                //if(pre && pre!=h)
                //{
                    //pre->unhighlight();
                //}
               //pre=h;
            //}
        }

    }
    QGraphicsPixmapItem::mouseMoveEvent(event);
}
void Card::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    delete transparent;
    QPointF newPos = event->scenePos();
    QList<QGraphicsItem*> items = scene->items(newPos);
    for (QGraphicsItem* item : items) {
        home* h = dynamic_cast<home*>(item);
        if (h)
        {
            h->unhighlight();
            h->dropPlant(Type);
        }
    }
}
Card::~Card()
{
    delete transparent;
}

