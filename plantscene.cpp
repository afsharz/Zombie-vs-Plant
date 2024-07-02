#include "plantscene.h"
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
    wallet = new Wallet(1);
    wallet->setPos(500 , -40);
    view->scene()->addItem(wallet);
    Game();
    view->show();


}

void PlantScene::initializeGrid()
{
    qreal cellWidth = 77;
    qreal cellHeight = 73;
    qreal startX = 125;
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

void PlantScene::Game()
{
    QTimer* timer = new QTimer(this);
    QObject::connect(timer , SIGNAL(timeout()) , this , SLOT(Sun_Maker()));
    timer->start(5000);
}

void PlantScene::Sun_Maker()
{
    Sun* sun = new Sun(scene , wallet);
    scene->addItem(sun);
    sun->show();
    if(sun)
        QTimer::singleShot(3500, sun, &QObject::deleteLater); // it deletes the sun after 3.5 seconds if player doesn't clicked on it
}
