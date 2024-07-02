#include "zombiescene.h"
#include <QBrush>
#include "zombiestore.h"
#define ROWS 6
#define COLS 12
ZombieScene::ZombieScene ()
{
    scene=new QGraphicsScene;
    QImage image(":/new/prefix1/field.png");
    //  scene->setBackgroundBrush(QBrush(QImage(":/new/prefix1/field.png")));
    QGraphicsView * view = new QGraphicsView(scene);
    view->setBackgroundBrush(QColor(0, 0, 0));
    QGraphicsPixmapItem *bg=new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(bg);
    initializeGrid();
    scene->setSceneRect(0,0,1080,502);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(1090,1000);
    ZombieStore *p=new ZombieStore(scene);
    view->scene()->addItem(p->regularzombie);
    view->scene()->addItem(p->bucketheadzombie);
    view->scene()->addItem(p->leafheadzombie);
    view->scene()->addItem(p->tallzombie);
    view->scene()->addItem(p->astronautzombie);
    view->scene()->addItem(p->purplehairzombie);
    wallet = new Wallet(0);
    wallet->setPos(500 , -40);
    view->scene()->addItem(wallet);
    Game();
    view->show();
}

void ZombieScene::Game()
{
    QTimer* timer = new QTimer(this);
    QObject::connect(timer , SIGNAL(timeout()) , this , SLOT(Brain_Maker()));
    timer->start(5000);
}
void ZombieScene::initializeGrid()
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
            h->setVectorZ(&zombies);
            scene->addItem(h);
            homes.push_back(h);
        }
    }

}


void ZombieScene::Brain_Maker()
{
    Brain* brain = new Brain(scene , wallet);
    scene->addItem(brain);
    brain->show();
    if(brain)
        QTimer::singleShot(3500, brain, &QObject::deleteLater); // it deletes the brain after 3.5 seconds if player doesn't clicked on it
}
