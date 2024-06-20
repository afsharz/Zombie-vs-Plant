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
    Zombie(int _health,int _FirstMovementDelay,int _MovementDelay,int _AttackPower, int _FirstTimeBwAttack, int _TimeBwAttack);
    //virtual ~Zombie()=0; //error

private:
    //QPoint *position;
    int health;
    int AttackPower;
    int FirstTimeBwAttack;
    int TimeBwAttack;
    int FirstMovementDelay;
    int MovementDelay;
    int price;
};

#endif // ZOMBIE_H
