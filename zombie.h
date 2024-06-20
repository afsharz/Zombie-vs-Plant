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
    Zombie(int _health,int _FirsfutMovementDelay,int _MovementDelay,int _AttackPower, int _FirstTimeBwAttack, int _TimeBwAttack);
    void Decreasinghealth(int attackpowerplant);
    virtual void Movement()=0;
    ~Zombie();

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
