#include "plantscene.h"
#include <QBrush>
#include "plantstore.h"
PlantScene::PlantScene()
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
    PlantStore *p=new PlantStore;
    view->scene()->addItem(p->two_peashooter);
    view->scene()->addItem(p->peashooter);
    view->scene()->addItem(p->walnut);
    view->scene()->addItem(p->jalapeno);
    view->scene()->addItem(p->boomerang);
    view->scene()->addItem(p->plumMine);
    view->show();
}
