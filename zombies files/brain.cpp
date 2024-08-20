#include "brain.h"
#include <QtCore/QRandomGenerator>

// random number between min and max
int getRandomIntB(int min, int max) {
    return QRandomGenerator::global()->bounded(min, max);
}

Brain::Brain(QGraphicsScene *_scene , Wallet* _wallet) : scene (_scene) , wallet(_wallet){

    this->setPixmap(QPixmap(":/new/prefix1/Brain.png"));
    // set random position
    int random_numberX = getRandomIntB(590 , 1000);
    int random_numberY = getRandomIntB(45 , 420);
    this->setPos(random_numberX , random_numberY);
    this->setScale(0.15);
}

void Brain::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        wallet->Increasing();
        //this->hide();
        this->deleteLater();
    }

}

