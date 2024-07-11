#ifndef BRAIN_H
#define BRAIN_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "wallet.h"

class Brain :public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Brain(QGraphicsScene *scene , Wallet* _wallet);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private :
    QGraphicsScene *scene;
    Wallet* wallet;
};

#endif // BRAIN_H
