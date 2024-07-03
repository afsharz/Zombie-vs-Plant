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
    void Game();
 //void mousePressEvent(QGraphicsSceneMouseEvent *event);
private :
    QGraphicsScene *scene;
    QVector<Zombie*> zombies;
    QVector<Plant*> plants;
    QVector<home*> homes;
    Wallet* wallet;
public slots :
    void Sun_Maker();
};

#endif // PLANTSCENE_H
