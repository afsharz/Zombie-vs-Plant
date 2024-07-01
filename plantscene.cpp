#include "plantscene.h"
#include <QBrush>
#include <home.h>
#include "plantstore.h"
#define ROWS 6
#define COLS 12
PlantScene::PlantScene()
{
    scene=new QGraphicsScene;
    QImage image(":/new/prefix1/field.png");
    scene->setBackgroundBrush(QBrush(QImage(":/new/prefix1/field.png")));
    QGraphicsView * view = new QGraphicsView(scene);
    view->setBackgroundBrush(QColor(0, 0, 0));
    QGraphicsPixmapItem *bg=new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(bg);
    initializeGrid();
    scene->setSceneRect(0,0,1080,502);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(1090,1000);
    PlantStore *p=new PlantStore(scene);
    view->scene()->addItem(p->two_peashooter);
    view->scene()->addItem(p->peashooter);
    view->scene()->addItem(p->walnut);
    view->scene()->addItem(p->jalapeno);
    view->scene()->addItem(p->boomerang);
    view->scene()->addItem(p->plumMine);
    view->show();

}


void PlantScene::initializeGrid()
{
    qreal cellWidth = 71;
    qreal cellHeight = 60;
    qreal startX = 117;
    qreal startY = 40;

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            home *h = new home(QPointF(startX + col * cellWidth,
                                    startY + row * cellHeight),
                                  cellWidth, cellHeight);
            h->setVectorP(&plants);
            scene->addItem(h);
            homes.push_back(h);
        }
    }
}
