#include "plantscene.h"
#include "peashooter.h"
#include "regularzombie.h"
#define ROWS 6
#define COLS 12
PlantScene::PlantScene()
{
    setWindowTitle("Plant Side");
     setWindowIcon(QIcon(QPixmap(":/new/prefix1/picon.png")));
    timer = new QLabel("3:30" , this);
    timer->setStyleSheet("color: white;");
    QFont fontNum("Berlin Sans FB Demi" , 20 ,  false);
    timer->setFont(fontNum);
    timer->move(750,-120);
    timer->setFixedSize(150,30);
    timer->show();
    GameTimer = new QTimer;
    GameTimer->setInterval(1000);
    //connect(GameTimer , SIGNAL(timeout()) , this , SLOT(PlantWin()));
    connect(GameTimer , SIGNAL(timeout()) , this , SLOT(UpdateTimer()));
    GameTimer->start();

    wallet = new Wallet(1);
    wallet->setPos(500 , -40);

    scene=new QGraphicsScene;
    QImage image(":/new/prefix1/field.png");

    QGraphicsView * view = new QGraphicsView(scene);
    view->setBackgroundBrush(QColor(0, 0, 0));

    QGraphicsPixmapItem *bg=new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(bg);

    initializeGrid();
    scene->setSceneRect(0,0,1080,502);
    //view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   // view->setFixedSize(1090,1000);
    PlantStore *p=new PlantStore(scene , wallet);
    view->scene()->addItem(p->two_peashooter);
    view->scene()->addItem(p->peashooter);
    view->scene()->addItem(p->walnut);
    view->scene()->addItem(p->jalapeno);
    view->scene()->addItem(p->boomerang);
    view->scene()->addItem(p->plumMine);
    view->scene()->addItem(wallet);
    Game();
    view->show();


}

void PlantScene::initializeGrid()
{
    qreal cellWidth = 77;
    qreal cellHeight = 73;
    qreal startX = 125;
    qreal startY = 36;

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            home *h = new home(QPointF(startX + col * cellWidth,
                                    startY + row * cellHeight),
                                  cellWidth, cellHeight, scene , wallet);
            h->setVectorP(&plants);
            scene->addItem(h);
            homes.push_back(h);
            connect(h, &home::AddedToVec, this, &PlantScene::AddedToVecc);
            connect(h,&home::zombiewin,this,&PlantScene::ZombieWin);
        }
    }
}

QVector<Plant *> PlantScene::getPlants()
{
    return plants;
}

QGraphicsScene *PlantScene::getScene(){return scene;}

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

void PlantScene::AddedToVecc(QString type)
{
    emit AddedToVector(type);
}

void PlantScene::PlantWin()
{
    emit Plantwin();
}

void PlantScene::ZombieWin()
{
    emit Zombiewin();
}

void PlantScene::UpdateTimer()
{
    static int minutes = 3;
    static int seconds = 30;
    seconds--;
    if(seconds<0){
        minutes--;
        seconds = 59;
    }
    if(minutes < 0 ){
        //PlantWin();
    }
    else{
        timer->setText(QString::number(minutes) + ":" + QString::number(seconds).rightJustified(2,'0'));
    }
}
