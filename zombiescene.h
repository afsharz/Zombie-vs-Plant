#ifndef ZOMBIESCENE_H
#define ZOMBIESCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QVector>
#include "zombie.h"
#include "plant.h"

class ZombieScene
    :public QGraphicsView
{
public:
    ZombieScene();

private :
    QGraphicsScene *scene;
    QVector<Zombie*> zombies;
    QVector<Plant*> plants;
};

#endif // ZOMBIESCENE_H
