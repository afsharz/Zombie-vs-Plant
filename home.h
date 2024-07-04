#ifndef HOME_H
#define HOME_H
#include <QGraphicsRectItem>
#include "plant.h"
//#include "wallet.h"
#include "zombie.h"
class home
:public QGraphicsRectItem,public QObject
{
public:
    home(QPointF pos, qreal w, qreal h );
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    void highlight();
    void unhighlight();
    void dropPlant(QString plantType);
    void dropZombie(QString zombieType);
    void setVectorP(QVector<Plant*> *plantList);
    void setVectorZ(QVector<Zombie*> *zombieList);
private:
    QPointF position;
    QVector<Plant*> *plantList;
    QVector<Zombie*> *zombieList;
    //Wallet* wallet;
};

#endif // HOME_H
