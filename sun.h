#ifndef SUN_H
#define SUN_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "wallet.h"


class Sun :public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Sun(QGraphicsScene *scene , Wallet* _wallet);
    //~Sun();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private :
    QGraphicsScene *scene;
    Wallet* wallet;

};

#endif // SUN_H
