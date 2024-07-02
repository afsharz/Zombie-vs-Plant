#include "jalapeno.h"

Jalapeno::Jalapeno(QPointF pos) : Plant(0 ,0 , 300) {
    setPixmap(QPixmap(":/new/prefix1/jalapino_transparent.png"));
    setScale(0.07);
    setPos(pos);
    show();
}
