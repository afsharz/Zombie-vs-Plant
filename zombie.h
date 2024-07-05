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
    Zombie(QPointF _pos ,int _health,int _FirsfutMovementDelay,int _MovementDelay,int _AttackPower, int _FirstTimeBwAttack, int _TimeBwAttack);
    void Decreasinghealth(int attackpowerplant);
    void Set_Position(QPointF pos);
    //virtual void Movement()=0;
    //~Zombie();

private:
    //QPoint *position;
    int health;
    int AttackPower;
    int FirstTimeBwAttack;
    int TimeBwAttack;
    int FirstMovementDelay;
    int MovementDelay;
    QPair<int,int> position;
};

#endif // ZOMBIE_H
