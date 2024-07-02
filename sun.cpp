#include "sun.h"
#include <QtCore/QRandomGenerator>

// random number between min and max
int getRandomIntS(int min, int max) {
    return QRandomGenerator::global()->bounded(min, max);
}

Sun::Sun(QGraphicsScene *_scene , Wallet* _wallet) : scene (_scene) , wallet(_wallet){

    this->setPixmap(QPixmap(":/new/prefix1/sun.png"));
    // set random position
    int random_numberX = getRandomIntS(125 , 530);
    int random_numberY = getRandomIntS(45 , 410);
    this->setPos(random_numberX , random_numberY);
    this->setScale(0.05);
}

void Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        wallet->Increasing();
        //this->hide();
        this->deleteLater();
    }

}
