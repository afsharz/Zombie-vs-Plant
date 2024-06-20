#ifndef PLANTSCENE_H
#define PLANTSCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QVector>
#include "zombie.h"
#include "plant.h"

class PlantScene
:public QGraphicsView
{
public:
    PlantScene();

private :
    QGraphicsScene *scene;
    QVector<Zombie*> zombies;
    QVector<Plant*> plants;
};

#endif // PLANTSCENE_H
