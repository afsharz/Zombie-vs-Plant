#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <QObject>
#include <QPoint>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
class home;
class Zombie
:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Zombie(QPointF _pos ,int _health,int _FirsfutMovementDelay,
           int _MovementDelay,int _AttackPower, int _FirstTimeBwAttack,
            int _TimeBwAttack,home *adrs);
    void Decreasinghealth(int attackpowerplant);
    void Set_Position(QPointF pos);
    int get_health();
    void setHomeFlag(bool flag);
    ~Zombie();
protected :
    QTimer* timer , *attack;
    int health;
    int AttackPower;
    double FirstTimeBwAttack;
    double TimeBwAttack;
    int FirstMovementDelay;
    int MovementDelay;
    QPair<int,int> position;
    home *HomeAdrs;
public slots :
    virtual void Movement();
    void Attack(QGraphicsItem* item);
    void setBlockFlag();

};

#endif // ZOMBIE_H
