#ifndef PLANTSCENE_H
#define PLANTSCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QVector>
#include "zombie.h"
#include "plant.h"
#include "home.h"

class PlantScene
:public QGraphicsView
{
public:
    PlantScene();
    void initializeGrid();
 //void mousePressEvent(QGraphicsSceneMouseEvent *event);
private :
    QGraphicsScene *scene;
    QVector<Zombie*> zombies;
    QVector<Plant*> plants;
    QVector<home*> homes;
};

#endif // PLANTSCENE_H
