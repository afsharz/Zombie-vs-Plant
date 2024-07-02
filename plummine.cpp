#include "plummine.h"

PlumMine::PlumMine(QPointF pos) : Plant(0 ,0 , 500) {
    setPixmap(QPixmap(":/new/prefix1/plum mine_transparent.png"));
    setScale(0.07);
    setPos(pos);
    show();
}
