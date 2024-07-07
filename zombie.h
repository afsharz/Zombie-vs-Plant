#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <QObject>
#include <QPoint>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
class Zombie
:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Zombie(QPointF _pos ,int _health,int _FirsfutMovementDelay,int _MovementDelay,int _AttackPower, int _FirstTimeBwAttack, int _TimeBwAttack);
    void Decreasinghealth(int attackpowerplant);
    void Set_Position(QPointF pos);
    int get_health();
    //~Zombie();

private:
    int health;
    int AttackPower;
    int FirstTimeBwAttack;
    int TimeBwAttack;
    int FirstMovementDelay;
    int MovementDelay;
    QPair<int,int> position;
    QTimer* timer , *attack;
public slots :
    void Movement();
    void Attack(QGraphicsItem* item);
};

#endif // ZOMBIE_H
