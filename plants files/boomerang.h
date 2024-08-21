#ifndef BOOMERANG_H
#define BOOMERANG_H
#include "plant.h"
#include <QTimer>
class Boomerang : public Plant
{
public:
    Boomerang(QPointF pos,home *adrs);
public slots:
    void shut();
private :
    QTimer *timer;
};

#endif // BOOMERANG_H
