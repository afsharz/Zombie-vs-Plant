#ifndef PEASHOOTER_H
#define PEASHOOTER_H
#include "plant.h"

class PeaShooter : public Plant
{
public:
    PeaShooter(QPointF pos,home *adrs);
private:
    QTimer *timer;
};

#endif // PEASHOOTER_H
