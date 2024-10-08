#ifndef PLANTSCENE_H
#define PLANTSCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QVector>
#include <QBrush>
#include <QLabel>
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
        QGraphicsView * view;
    PlantScene(QString CompetitorName);
    void initializeGrid();
    QVector<Plant*> getPlants();
    QGraphicsScene *getScene();
    void Game();
    void setTimer();
    void setCompetitorName(QString CompetitorName);
    void closeWindow();
    ~PlantScene();
private :

    QGraphicsScene *scene;
    QVector<Zombie*> zombies;
    QVector<Plant*> plants;
    QVector<home*> homes;
    Wallet* wallet;
    QTimer* GameTimer;
    QGraphicsTextItem* timer;
    QGraphicsTextItem* CompetitorName;
public slots :
    void Sun_Maker();
    void AddedToVecc(QString type);
    void ZombieWin();
    void UpdateTimer();
    void PlantWin();
signals :
    void AddedToVector(QString type);
    void Zombiewin();
    void Plantwin();
};

#endif // PLANTSCENE_H
