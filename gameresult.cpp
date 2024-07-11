#include "gameresult.h"

GameResult::GameResult(QString winner) {
    backgroundLabel=new QLabel(this);
    backgroundLabel->setScaledContents(true);
    if(winner=="Plant"){
        QImage image(":/new/prefix1/Designer (42).jpeg");
        backgroundLabel->setPixmap(QPixmap::fromImage(image));
    }
    else{
        QImage image(":/new/prefix1/IMG_20240709_125814_689.jpg");
        backgroundLabel->setPixmap(QPixmap::fromImage(image));
    }
    backgroundLabel->setGeometry(this->rect());
    backgroundLabel->lower();
    setFixedSize(600,480);
}
