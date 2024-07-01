#include "sun.h"
#include <QtCore/QRandomGenerator>

// random number between min and max
int getRandomInt(int min, int max) {
    return QRandomGenerator::global()->bounded(min, max);
}

Sun::Sun(QGraphicsScene *_scene) : scene (_scene) {

    this->setPixmap(QPixmap(":/new/prefix1/sun.png"));
    // set random position
    int random_numberX = getRandomInt(125 , 500);
    int random_numberY = getRandomInt(40 , 450);
    this->setPos(random_numberX , random_numberY);
    this->setScale(0.1);
}
