#include "plantscene.h"
#include <QBrush>
#include "plantstore.h"
PlantScene::PlantScene()
{
    scene=new QGraphicsScene;
    QImage image(":/new/prefix1/field.png");
  //  scene->setBackgroundBrush(QBrush(QImage(":/new/prefix1/field.png")));
    QGraphicsView * view = new QGraphicsView(scene);
    QGraphicsPixmapItem *bg=new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(bg);
    scene->setSceneRect(0,0,1080,502);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(1090,800);
    PlantStore *p=new PlantStore;
    view->scene()->addItem(p->two_peashooter);
    view->show();
}
