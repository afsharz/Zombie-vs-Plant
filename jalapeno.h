#ifndef JALAPENO_H
#define JALAPENO_H
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTransform>
#include "zombie.h"
#include "plant.h"
#define ROWS 6
#define COLS 12

class Jalapeno : public Plant
{
public:
    Jalapeno(QPointF pos , QGraphicsScene * _scene);
    QGraphicsRectItem* redRectangle;
private:
    QGraphicsScene * scene;
public slots :
    void deleteObjectAndRectangle();
};

#endif // JALAPENO_H
