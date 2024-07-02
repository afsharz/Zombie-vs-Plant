#include "card.h"
#include "home.h"
#include "QRegularExpression"
#include "QRegularExpressionMatch"
#define c1r1 QPointF(1200,220)
Card::Card(QGraphicsScene *scene,QString _Type)
    :Type(_Type),scene (scene)
{
    pre=nullptr;
}


void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragStartPosition = event->pos();
        QPointF newPos = mapToScene(event->pos() - dragStartPosition);
        transparent=new QGraphicsPixmapItem();
        transparent->setScale(0.1);
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
        {
            transparent->setScale(0.25);
            transparent->setPixmap(QPixmap(":/new/prefix1/boomrang_transparent.png"));
        }
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
            QRegularExpression *t=new QRegularExpression("zombie");
            QRegularExpressionMatch *m=new QRegularExpressionMatch;
            *m=t->match(Type);
            qDebug()<<m->hasMatch();
            if(m->hasMatch())
                h->dropZombie(Type);
            else
                h->dropPlant(Type);
            h->unhighlight();
        }
    }
}
Card::~Card()
{
    delete transparent;
}

