#ifndef SUN_H
#define SUN_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>

class Sun :public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Sun(QGraphicsScene *scene);
private :
    QGraphicsScene *scene;
};

#endif // SUN_H
