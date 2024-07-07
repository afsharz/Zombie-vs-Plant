#ifndef PLANT_H
#define PLANT_H
#include <QObject>
#include <QPoint>
#include <QGraphicsPixmapItem>

class Plant : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Plant(QPointF pos , int _health , int _FiringRate , int _AttackPower);
    void Decreasinghealth(int attackpowerzombie);
    void Set_Position(QPointF pos);
    int get_health();
    enum Type{boomerang,non_boomerang};
public slots:
    void shut();
    //func health
    //func attack
    //~Plant();
protected :
    int health;
    int FiringRate;
    int AttackPower;
    QPair<int,int> position;

};

#endif // PLANT_H
