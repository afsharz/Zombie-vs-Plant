#include "card.h"
#include "home.h"
#define c1r1 QPointF(1200,220)
Card::Card(QGraphicsScene *scene,QString _Type)
    :scene (scene),Type(_Type)
{
    pre=nullptr;
}

Card::~Card()
{
    delete transparent;
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragStartPosition = event->pos();
        QPointF newPos = mapToScene(event->pos() - dragStartPosition);
        transparent=new QGraphicsPixmapItem();
        transparent->setPixmap(QPixmap(":/new/prefix1/peashooter transparent.png"));
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
            if (h)
            {
                h->highlight();
                if(pre && pre!=h)
                {
                    pre->unhighlight();
                }
                pre=h;
            }
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

