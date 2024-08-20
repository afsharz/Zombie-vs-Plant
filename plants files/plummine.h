#ifndef PLUMMINE_H
#define PLUMMINE_H
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTransform>
#include "zombie.h"
#include "plant.h"

class PlumMine : public Plant
{
public:
    PlumMine(QPointF pos , QGraphicsScene * _scene,home *adrs);
private:
    QGraphicsScene * scene;
public slots:
    void HandlePlumMine();
    void deleteObject();
};

#endif // PLUMMINE_H
