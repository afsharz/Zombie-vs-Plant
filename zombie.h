#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <QObject>
#include <QPoint>
#include <QGraphicsPixmapItem>
class Zombie
:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Zombie(int h,int fmd,int md,int ap,int tba);
    virtual ~Zombie()=0;
private:
    //QPoint *position;
    int health;
    int attackPower;
    int timeBwAttack;
    int firstMovementDelay;
    int MovementDelay;
    int price;
};

#endif // ZOMBIE_H
