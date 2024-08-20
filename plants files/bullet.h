#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTransform>
#include "plant.h"
#include "zombie.h"

class bullet
:public  QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet(int _power,Plant:: Type t,QPointF _pos);
    ~bullet();
private slots:
    void move();
private:
    int power;
    bool IsBoomerang;
    QTimer *timer;
    QVector<Zombie*> HaveHit;

};

#endif // BULLET_H
