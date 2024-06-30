#include "home.h"
#include "qgraphicsscene.h"
#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include "peashooter.h"
#include "two_peashooter.h"
#include "plummine.h"
#include "walnut.h"
#include "jalapeno.h"
#include "boomerang.h"
#include <QTimer>
home::home(QPointF pos, qreal w, qreal h)
    : QGraphicsRectItem(pos.x(),pos.y(), w, h){
    setPen(QPen(Qt::transparent));
    setBrush(QBrush(Qt::transparent));
    setZValue(1);  /// Ensure it's drawn above the background
    //setAcceptHoverEvents(true);
    //setAcceptDrops(true);
    show();
}

void home::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug()<<"i know there is a hover enter event";
    highlight();
    QGraphicsRectItem::hoverEnterEvent(event);
}

void home::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setBrush(QBrush(Qt::transparent));

}

void home::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug()<<"i know there is a drag enter event";
    highlight();
    QGraphicsRectItem::dragEnterEvent(event);
}

void home::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    hide();
}

void home::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    hide();
    PeaShooter test;
    test.setPos(event->scenePos());
}

void home::highlight()
{
setBrush(QBrush(QColor(255, 0, 0, 100)));
}

void home::unhighlight()
{
    setPen(QPen(Qt::transparent));
    setBrush(QBrush(Qt::transparent));
}

void home::dropPlant(QString plantType)
{
    if(plantType=="PeaShooter")
    {
        PeaShooter *p=new PeaShooter;
        scene()->addItem(p);
        p->setPos(position);
        plantList.push_back(p);
    }
    else if(plantType=="TwoPeashooter")
    {
        Two_PeaShooter *p=new Two_PeaShooter;
        scene()->addItem(p);
        p->setPos(position);
        plantList.push_back(p);
    }
    else if(plantType=="Walnut")
    {
        Walnut *p=new Walnut;
        scene()->addItem(p);
        p->setPos(position);
       plantList.push_back(p);
    }
    else if(plantType=="PlumMine")
    {
        PlumMine *p=new PlumMine;
        scene()->addItem(p);
        p->setPos(position);
        plantList.push_back(p);
    }
    else if(plantType=="Jalapeno")
    {
        Jalapeno *p= new Jalapeno;
        scene()->addItem(p);
        p->setPos(position);
        plantList.push_back(p);
    }
    else if(plantType=="Boomerang")
    {
        Boomerang *p= new Boomerang;
        scene()->addItem(p);
        p->setPos(position);
       plantList.push_back(p);
    }
}

void home::setVectorP(QVector<Plant *> _plantList)
{
    plantList=_plantList;
}


