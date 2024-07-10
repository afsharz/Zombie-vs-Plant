#include "gameresult.h"

GameResult::GameResult(QString winner) {
    backgroundLabel=new QLabel(this);
    backgroundLabel->setScaledContents(true);
    if(winner=="Plant"){
        backgroundLabel->setPixmap(QPixmap(""));
    }
    else{
        backgroundLabel->setPixmap(QPixmap(":/new/prefix1/IMG_20240709_125814_689.jpg"));
    }
    backgroundLabel->setGeometry(this->rect());
    backgroundLabel->lower();
    setFixedSize(640,480);
}
