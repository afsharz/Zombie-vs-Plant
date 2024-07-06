#ifndef PLANT_H
#define PLANT_H
#include <QObject>
#include <QPoint>
#include <QGraphicsPixmapItem>

class home;
class Plant : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Plant(QPointF pos , int _health , int _FiringRate , int _AttackPower,home *adrs);
    void Decreasinghealth(int attackpowerzombie);
    void Set_Position(QPointF pos);
    int get_health();
    enum Type{boomerang,non_boomerang};
    void setHomeAdrs(home *adrs);
    //func health
    //func attack
    ~Plant();
public slots:
    void shut();

protected :
    int health;
    int FiringRate;
    int AttackPower;
    QPair<int,int> position;
    home *HomeAdrs;

};

#endif // PLANT_H
