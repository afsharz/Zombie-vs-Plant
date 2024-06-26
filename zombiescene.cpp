#include "zombiescene.h"
#include <QBrush>
#include "zombiestore.h"
ZombieScene::ZombieScene ()
{
    scene=new QGraphicsScene;
    QImage image(":/new/prefix1/field.png");
    //  scene->setBackgroundBrush(QBrush(QImage(":/new/prefix1/field.png")));
    QGraphicsView * view = new QGraphicsView(scene);
    view->setBackgroundBrush(QColor(0, 0, 0));
    QGraphicsPixmapItem *bg=new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(bg);
    scene->setSceneRect(0,0,1080,502);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(1090,1000);
    ZombieStore *p=new ZombieStore;
    view->scene()->addItem(p->regularzombie);
    view->scene()->addItem(p->bucketheadzombie);
    view->scene()->addItem(p->leafheadzombie);
    view->scene()->addItem(p->tallzombie);
    view->scene()->addItem(p->astronautzombie);
    view->scene()->addItem(p->purplehairzombie);
    view->show();
}
