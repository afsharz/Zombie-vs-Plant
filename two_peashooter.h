#ifndef TWO_PEASHOOTER_H
#define TWO_PEASHOOTER_H
#include "plant.h"

class Two_PeaShooter : public Plant
{
public:
    Two_PeaShooter(QPointF pos);
private :
    QTimer *timer;
};

#endif // TWO_PEASHOOTER_H
