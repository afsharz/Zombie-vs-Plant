#ifndef PLANT_H
#define PLANT_H
#include <QObject>
#include <QPoint>
#include <QGraphicsPixmapItem>

class Plant : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Plant(int _health , int _FiringRate , int _AttackPower);
    void Decreasinghealth(int attackpowerzombie);
    //func health
    //func attack
    //~Plant();
private :
    int health;
    int FiringRate;
    int AttackPower;

};

#endif // PLANT_H
