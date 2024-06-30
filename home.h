#ifndef HOME_H
#define HOME_H
#include <QGraphicsRectItem>
#include "plant.h"
class home
:public QGraphicsRectItem,public QObject
{
public:
    home(QPointF pos, qreal w, qreal h);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    void highlight();
    void unhighlight();
    void dropPlant(QString plantType);
    void setVectorP(QVector<Plant*> plantList);
    // void setVectorZ
private:
    QPointF position;
    QVector<Plant*> plantList;
};

#endif // HOME_H
