#ifndef HOME_H
#define HOME_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "plant.h"
#include "zombie.h"

class Wallet;

class home
:public QObject , public QGraphicsRectItem
{
    Q_OBJECT
public:
    home(QPointF pos, qreal w, qreal h , QGraphicsScene * _scene , Wallet* _wallet=NULL);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    void highlight();
    void unhighlight();
    void dropPlant(QString plantType,bool IsMyCommand);
    void dropZombie(QString zombieType,bool IsMyCommand);
    void setVectorP(QVector<Plant*> *plantList);
    void setVectorZ(QVector<Zombie*> *zombieList);
    void setFlag(bool flag);
private:
    QPointF position;
    QVector<Plant*> *plantList;
    QVector<Zombie*> *zombieList;
    Wallet* wallet;
    QGraphicsScene *scene;
    bool IsFull;
public slots :
    void ZomWin();
signals:
    void AddedToVec(QString type);
    void zombiewin();
};

#endif // HOME_H
