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
    bool IsAccessibale;
    Card(QGraphicsScene *scene,QString _Type);
    QString Get_Type();
    ~Card();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QString Type;
    QPointF dragStartPosition;
    QGraphicsPixmapItem *transparent;
    QGraphicsScene *scene;
    home *pre;
};

#endif // CARD_H
