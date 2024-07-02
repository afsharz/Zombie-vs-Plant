#include "boomerang.h"

Boomerang::Boomerang(QPointF pos) : Plant(200 , 1 , 30)
{
    setPixmap(QPixmap(":/new/prefix1/boomrang_transparent.png"));
    setScale(0.2);
    setPos(pos);
    show();
}
