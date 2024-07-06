#include "walnut.h"
#include "home.h"
Walnut::Walnut(QPointF pos,home *adrs) : Plant( pos ,400 , 0 , 0,adrs)
{
    setPixmap(QPixmap(":/new/prefix1/walnut_transparent.png"));
    setScale(0.07);
    setPos(pos);
    show();
}
