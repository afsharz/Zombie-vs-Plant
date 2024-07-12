#include "zombiescene.h"
#include <QBrush>
#include "zombiestore.h"
#include <QLabel>

#define ROWS 6
#define COLS 12
ZombieScene::ZombieScene (QString CompetitorName)
{
    scene=new QGraphicsScene;
    QImage image(":/new/prefix1/field.png");
    QGraphicsView * view = new QGraphicsView(scene);
    view->setBackgroundBrush(QColor(0, 0, 0));
    view->setWindowTitle("Zombie Side");
    view->setWindowIcon(QIcon(QPixmap(":/new/prefix1/zicon.png")));
    setTimer();
    setCompetitorName(CompetitorName);
    GameTimer = new QTimer;
    GameTimer->setInterval(1000);
    connect(GameTimer , SIGNAL(timeout()) , this , SLOT(UpdateTimer()));
    GameTimer->start();
    wallet = new Wallet(0);
    wallet->setPos(500 , -40);

    QGraphicsPixmapItem *bg=new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(bg);

    initializeGrid();
    scene->setSceneRect(0,0,1080,502);
   view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(1090,1000);
    ZombieStore *p=new ZombieStore(scene , wallet);
    view->scene()->addItem(p->regularzombie);
    view->scene()->addItem(p->bucketheadzombie);
    view->scene()->addItem(p->leafheadzombie);
    view->scene()->addItem(p->tallzombie);
    view->scene()->addItem(p->astronautzombie);
    view->scene()->addItem(p->purplehairzombie);
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
    qreal startY = 33;

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            home *h = new home(QPointF(startX + col * cellWidth,
                                       startY + row * cellHeight),
                               cellWidth, cellHeight,scene,wallet);
            h->setVectorZ(&zombies);
            scene->addItem(h);
            homes.push_back(h);
            connect(h,&home::AddedToVec, this, &ZombieScene::AddedToVecc);
            connect(h,&home::zombiewin,this,&ZombieScene::ZombieWin);
        }
    }

}

QVector<Zombie *> ZombieScene::getZombies() {return zombies;}

QGraphicsScene *ZombieScene::getScene(){return scene;}

void ZombieScene::setTimer()
{
    timer = new QGraphicsTextItem();
    QRectF bounds(400,-120, 150, 30);  // Set the desired size
    QFont fontNum("Berlin Sans FB Demi" , 20 ,  false);
    scene->addItem(timer);
    timer->setPlainText("3:30");
    timer->setDefaultTextColor(Qt::blue);
    timer->setTextWidth(bounds.width());
    timer->setPos(bounds.topLeft());
    timer->setZValue(3);
    timer->setFont(fontNum);
    timer->show();
}

void ZombieScene::Brain_Maker()
{
    Brain* brain = new Brain(scene , wallet);
    scene->addItem(brain);
    brain->show();
    if(brain)
        QTimer::singleShot(3500, brain, &QObject::deleteLater); // it deletes the brain after 3.5 seconds if player doesn't clicked on it
}

void ZombieScene::AddedToVecc(QString type)
{
    emit AddedToVector(type);
}

void ZombieScene::PlantWin()
{
    emit Plantwin();
}

void ZombieScene::ZombieWin()
{
    emit Zombiewin();
}

void ZombieScene::UpdateTimer()
{
    static int minutes = 0;
    static int seconds = 10;
    seconds--;
    if(minutes==0 && seconds<30)
        timer->setDefaultTextColor(Qt::red);
    if(seconds<0){
        minutes--;
        seconds = 59;
    }
    if(minutes < 0 ){
        PlantWin();
    }
    else{
        timer->setPlainText(QString::number(minutes) + ":" + QString::number(seconds).rightJustified(2,'0'));
    }
}
void ZombieScene::setCompetitorName(QString Name)
{
    CompetitorName= new QGraphicsTextItem();
    QFont fontName("Berlin Sans FB Demi" , 20 ,  false);
    QRectF bounds(200,-160, 150, 30);  // Set the desired size
    QString name="Enemy : ";
    name+=Name;
    scene->addItem(CompetitorName);
    CompetitorName->setFont(fontName);
    CompetitorName->setPlainText(name);
    CompetitorName->setDefaultTextColor(Qt::yellow);
    CompetitorName->setTextWidth(bounds.width());
    CompetitorName->setPos(bounds.topLeft());
    CompetitorName->setZValue(3);
    CompetitorName->show();
}
