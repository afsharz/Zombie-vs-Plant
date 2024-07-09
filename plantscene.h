#ifndef PLANTSCENE_H
#define PLANTSCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QVector>
#include <QBrush>
#include <QTimer>
#include "home.h"
#include "plantstore.h"
#include "zombie.h"
#include "plant.h"
#include "wallet.h"
#include "sun.h"

class PlantScene
:public QGraphicsView
{
    Q_OBJECT
public:
    PlantScene();
    void initializeGrid();
    QVector<Plant*> getPlants();
    QGraphicsScene *getScene();
    void Game();
private :
    QGraphicsScene *scene;
    QVector<Zombie*> zombies;
    QVector<Plant*> plants;
    QVector<home*> homes;
    Wallet* wallet;
    QTimer* GameTimer;
public slots :
    void Sun_Maker();
    void AddedToVecc();
    void PlantWin();
    void ZombieWin();
signals :
    void AddedToVector();
    void Zombiewin();
    void Plantwin();
};

#endif // PLANTSCENE_H
