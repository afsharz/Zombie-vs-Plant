#ifndef CARD_H
#define CARD_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include "home.h"
class Card
:public QGraphicsPixmapItem
{
public:
    Card(QGraphicsScene *scene,QString _Type);
    ~Card();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QPointF dragStartPosition;
    const QPointF position;
    QGraphicsPixmapItem *transparent;
    QGraphicsScene *scene;
    home *pre;
    QString Type;
};

#endif // CARD_H
