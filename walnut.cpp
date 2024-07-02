#include "walnut.h"

Walnut::Walnut(QPointF pos) : Plant(400 , 0 , 0)
{    setPixmap(QPixmap(":/new/prefix1/walnut_transparent.png"));
    setScale(0.07);
    setPos(pos);
    show();
}
