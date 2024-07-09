#ifndef ZOMBIESCENE_H
#define ZOMBIESCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QVector>
#include <QBrush>
#include <QTimer>
#include "zombie.h"
#include "home.h"
#include "plant.h"
#include "wallet.h"
#include "brain.h"

class ZombieScene
    :public QGraphicsView
{
    Q_OBJECT
public:
    ZombieScene();
    void Game();
    void initializeGrid();
    QVector<Zombie*> getZombies();
    QGraphicsScene* getScene();
private :
    QGraphicsScene *scene;
    QVector<Zombie*> zombies;
    QVector<Plant*> plants;
    QVector<home*> homes;
    Wallet* wallet;
    QTimer* GameTimer;
public slots :
    void Brain_Maker();
    void AddedToVecc(QString type);
    void PlantWin();
    void ZombieWin();
signals :
    void AddedToVector(QString type);
    void Zombiewin();
    void Plantwin();
};

#endif // ZOMBIESCENE_H
