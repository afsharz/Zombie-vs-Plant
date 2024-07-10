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
    IsFull=false;
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

void home::dropPlant(QString plantType,bool IsMyCommand)
{
    if(IsFull)
        return;
    if(plantType=="PeaShooter")
    {
        PeaShooter *p=new PeaShooter(position,this);
        p->setHomeAdrs(this);
        p->setScale(0.07);
        scene->addItem(p);
        if(IsMyCommand)
        plantList->push_back(p);
        wallet->Decreasing(50);
    }
    else if(plantType=="TwoPeashooter")
    {
        Two_PeaShooter *p=new Two_PeaShooter(position,this);
        p->setHomeAdrs(this);
        p->setScale(0.07);
        scene->addItem(p);
        p->setPos(position);
        if(IsMyCommand)
        plantList->push_back(p);
        wallet->Decreasing(100);
    }
    else if(plantType=="Walnut")
    {
        Walnut *p=new Walnut(position,this);
        p->setHomeAdrs(this);
        p->setScale(0.08);
        scene->addItem(p);
        p->setPos(position);
        if(IsMyCommand)
        plantList->push_back(p);
        wallet->Decreasing(100);
    }
    else if(plantType=="PlumMine")
    {
        PlumMine *p=new PlumMine(position , scene,this);
        p->setHomeAdrs(this);
        p->setScale(0.07);
        scene->addItem(p);
        p->setPos(position);
        if(IsMyCommand)
        plantList->push_back(p);
        wallet->Decreasing(175);
    }
    else if(plantType=="Jalapeno")
    {
        Jalapeno *p= new Jalapeno(position , scene,this);
        p->setHomeAdrs(this);
        p->setScale(0.07);
        scene->addItem(p);
        p->setPos(position);
        if(IsMyCommand)
        plantList->push_back(p);
        wallet->Decreasing(150);
    }
    else if(plantType=="Boomerang")
    {
        Boomerang *p= new Boomerang(position,this);
        p->setHomeAdrs(this);
        p->setScale(0.23);
        scene->addItem(p);
        p->setPos(position);
        if(IsMyCommand)
        plantList->push_back(p);
        wallet->Decreasing(125);
    }
    if(IsMyCommand)
        emit AddedToVec(plantType);
}

void home::dropZombie(QString zombieType,bool IsMyCommand)
{
    if(IsFull)
        return;
     if (zombieType=="regularzombie")
    {
        RegularZombie *z=new RegularZombie(position,this);
        z->setScale(0.075);
        scene->addItem(z);
        if(IsMyCommand)
        zombieList->push_back(z);
        wallet->Decreasing(100);
    }
    else if (zombieType=="bucketheadzombie")
     {
        BucketHeadZombie *z=new BucketHeadZombie(position,this);
        z->setScale(0.075);
        scene->addItem(z);
        if(IsMyCommand)
        zombieList->push_back(z);
        wallet->Decreasing(200);
     }
    else if (zombieType=="leafheadzombie")
    {
        LeafHeadZombie *z=new LeafHeadZombie(position,this);

        z->setScale(0.075);
        scene->addItem(z);
        if(IsMyCommand)
        zombieList->push_back(z);
        wallet->Decreasing(150);
    }
     else if (zombieType=="tallzombie")
     {
        TallZombie *z=new TallZombie(position,this);
        z->setScale(0.075);
        scene->addItem(z);
        if(IsMyCommand)
        zombieList->push_back(z);
        wallet->Decreasing(150);
     }
    else if (zombieType=="astronautzombie")
    {
        AstronautZombie *z=new AstronautZombie(position,this);

        z->setScale(0.075);
        scene->addItem(z);
        if(IsMyCommand)
        zombieList->push_back(z);
        wallet->Decreasing(200);
    }
    else if (zombieType=="purplehairzombie")
     {
        PurpleHairZombie *z=new PurpleHairZombie(position,this);
        z->setScale(0.07);
        scene->addItem(z);
        if(IsMyCommand)
        zombieList->push_back(z);
        wallet->Decreasing(800);
     }
    if(IsMyCommand)
        emit AddedToVec(zombieType);

}

void home::setVectorP(QVector<Plant *> *_plantList)
{
    plantList=_plantList;
}

void home::setVectorZ(QVector<Zombie *> *_zombieList)
{
    zombieList=_zombieList;
}

void home::setFlag(bool flag)
{
    IsFull=flag;
}

void home::ZomWin()
{
 emit zombiewin();
}
