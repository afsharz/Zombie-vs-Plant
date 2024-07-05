#include "home.h"
#include "qgraphicsscene.h"
#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QThread>
#include "peashooter.h"
#include "two_peashooter.h"
#include "plummine.h"
#include "walnut.h"
#include "jalapeno.h"
#include "boomerang.h"
#include "regularzombie.h"
#include "tallzombie.h"
#include "astronautzombie.h"
#include "leafheadzombie.h"
#include "bucketheadzombie.h"
#include "purplehairzombie.h"
#include "wallet.h"
#include <QTimer>

home::home(QPointF pos, qreal w, qreal h , QGraphicsScene * _scene , Wallet* _wallet)
    : QGraphicsRectItem(pos.x(),pos.y(), w, h),position(pos),wallet(_wallet) , scene(_scene){
    setPen(QPen(Qt::transparent));
    setBrush(QBrush(Qt::transparent));
    setZValue(1);  /// Ensure it's drawn above the background
    setAcceptHoverEvents(false);
    setAcceptDrops(true);
    show();
}

void home::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug()<<"i know there is a hover enter event";
    highlight();
    //QGraphicsRectItem::hoverEnterEvent(event);
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
    event->accept();
    //PeaShooter test;
    //test.setPos(event->scenePos());
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
        PeaShooter *p=new PeaShooter(position);
        p->setScale(0.07);
        scene->addItem(p);
        qDebug()<<position;
        plantList->push_back(p);
        wallet->Decreasing(50);
    }
    else if(plantType=="TwoPeashooter")
    {
        Two_PeaShooter *p=new Two_PeaShooter(position);
        p->setScale(0.07);
        scene->addItem(p);
        p->setPos(position);
        plantList->push_back(p);
        wallet->Decreasing(100);
    }
    else if(plantType=="Walnut")
    {
        Walnut *p=new Walnut(position);
        p->setScale(0.08);
        scene->addItem(p);
        p->setPos(position);
        plantList->push_back(p);
        wallet->Decreasing(100);
    }
    else if(plantType=="PlumMine")
    {
        PlumMine *p=new PlumMine(position , scene);
        p->setScale(0.07);
        scene->addItem(p);
        p->setPos(position);
        plantList->push_back(p);
        wallet->Decreasing(175);
    }
    else if(plantType=="Jalapeno")
    {
        Jalapeno *p= new Jalapeno(position , scene);
        p->setScale(0.07);
        scene->addItem(p);
        p->setPos(position);
        plantList->push_back(p);
        wallet->Decreasing(150);
    }
    else if(plantType=="Boomerang")
    {
        Boomerang *p= new Boomerang(position);
        p->setScale(0.23);
        scene->addItem(p);
        p->setPos(position);
        plantList->push_back(p);
       wallet->Decreasing(125);
    }
}

void home::dropZombie(QString zombieType)
{
     if (zombieType=="regularzombie")
    {
        RegularZombie *z=new RegularZombie(position);

        z->setScale(0.075);
        scene->addItem(z);
        qDebug()<<position;
        zombieList->push_back(z);
        wallet->Decreasing(100);
    }
    else if (zombieType=="bucketheadzombie")
     {
         BucketHeadZombie *z=new BucketHeadZombie(position);
         z->setScale(0.075);
         scene->addItem(z);
         qDebug()<<position;
         zombieList->push_back(z);
         wallet->Decreasing(200);
     }
    else if (zombieType=="leafheadzombie")
    {

        LeafHeadZombie *z=new LeafHeadZombie(position);

        z->setScale(0.075);
        scene->addItem(z);
        qDebug()<<position;
        zombieList->push_back(z);
        wallet->Decreasing(150);
    }
     else if (zombieType=="tallzombie")
     {
         TallZombie *z=new TallZombie(position);
         z->setScale(0.075);
         scene->addItem(z);
         qDebug()<<position;
         zombieList->push_back(z);
         wallet->Decreasing(150);
     }
    else if (zombieType=="astronautzombie")
    {
        AstronautZombie *z=new AstronautZombie(position);

        z->setScale(0.075);
        scene->addItem(z);
        qDebug()<<position;
        zombieList->push_back(z);
        wallet->Decreasing(200);
    }
    else if (zombieType=="purplehairzombie")
     {
         PurpleHairZombie *z=new PurpleHairZombie(position);
         z->setScale(0.07);
         scene->addItem(z);
         qDebug()<<position;
         zombieList->push_back(z);
         wallet->Decreasing(800);
     }
}

void home::setVectorP(QVector<Plant *> *_plantList)
{
    plantList=_plantList;
}

void home::setVectorZ(QVector<Zombie *> *_zombieList)
{
    zombieList=_zombieList;
}


