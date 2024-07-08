#include "wallet.h"
#include <QFont>


Wallet::Wallet( int _flag , QGraphicsTextItem * parent)
    : QGraphicsTextItem(parent) , Money(500) , flag(_flag) {

    //draw money
    if(flag)
        setPlainText(QString("Suns : ") + QString::number(Money));
    else
        setPlainText(QString("Brains : ") + QString::number(Money));
    setDefaultTextColor((Qt::white));
    setFont(QFont("times" , 16));
}

void Wallet:: Increasing() {
    Money+=25;
    if(flag){
        setPlainText(QString("Suns : ") + QString::number(Money));
        for(auto itr=QVec.begin() ; itr!=QVec.end();itr++){
            if((**itr).Get_Type() == "PeaShooter" && Money >= 50){
                (**itr).IsAccessibale = true;
                (**itr).setPixmap(QPixmap(":/new/prefix1/pea shooter.jpg"));
            }
            else if((**itr).Get_Type() == "TwoPeashooter" && Money >= 100){
                (**itr).IsAccessibale = true;
                (**itr).setPixmap(QPixmap(":/new/prefix1/two_peashooter.jpg"));
            }
            else if((**itr).Get_Type() == "Walnut" && Money >= 100){
                (**itr).IsAccessibale = true;
                (**itr).setPixmap(QPixmap(":/new/prefix1/walnut.jpg"));
            }
            else if((**itr).Get_Type() == "PlumMine" && Money >= 175){
                (**itr).IsAccessibale = true;
                (**itr).setPixmap(QPixmap(":/new/prefix1/plum mine.jpg"));
            }
            else if((**itr).Get_Type() == "Jalapeno" && Money >= 150){
                (**itr).IsAccessibale = true;
                (**itr).setPixmap(QPixmap(":/new/prefix1/jalapino.jpg"));
            }
            else if((**itr).Get_Type() == "Boomerang" && Money >= 125){
                (**itr).IsAccessibale = true;
                (**itr).setPixmap(QPixmap(":/new/prefix1/boomerang.jpg"));
            }
        }
    }

    else{
        setPlainText(QString("Brains : ") + QString::number(Money));
        for(auto itr=QVec.begin() ; itr!=QVec.end();itr++){
            if((**itr).Get_Type() == "regularzombie" && Money >= 100){
                (**itr).IsAccessibale = true;
                (**itr).setPixmap(QPixmap(":/new/prefix1/regular zombie.jpg"));
            }
            else if((**itr).Get_Type() == "bucketheadzombie" && Money >= 200){
                (**itr).IsAccessibale = true;
                (**itr).setPixmap(QPixmap(":/new/prefix1/Bucket head zombie.jpg"));
            }
            else if((**itr).Get_Type() == "leafheadzombie" && Money >= 150){
                (**itr).IsAccessibale = true;
                (**itr).setPixmap(QPixmap(":/new/prefix1/leaf hair zombie.jpg"));
            }
            else if((**itr).Get_Type() == "tallzombie" && Money >= 155){
                (**itr).IsAccessibale = true;
                (**itr).setPixmap(QPixmap(":/new/prefix1/tall zombie.jpg"));
            }
            else if((**itr).Get_Type() == "astronautzombie" && Money >= 200){
                (**itr).IsAccessibale = true;
                (**itr).setPixmap(QPixmap(":/new/prefix1/astronaut zombie.jpg"));
            }
            else if((**itr).Get_Type() == "purplehairzombie" && Money >= 800){
                (**itr).IsAccessibale = true;
                (**itr).setPixmap(QPixmap(":/new/prefix1/purple hair zombie.jpg"));
            }
        }
    }
    setDefaultTextColor((Qt::white));
    setFont(QFont("times" , 16));


}

void Wallet:: Decreasing(int HowMany) {
    Money-=HowMany;
    if(flag){
        setPlainText(QString("Suns : ") + QString::number(Money));
        for(auto itr=QVec.begin() ; itr!=QVec.end();itr++){
            if((**itr).Get_Type() == "PeaShooter" && Money < 50){
                (**itr).IsAccessibale = false;
                (**itr).setPixmap(QPixmap(":/new/prefix1/pea-shooter-black.jpg"));
            }
            else if((**itr).Get_Type() == "TwoPeashooter" && Money < 100){
                (**itr).IsAccessibale = false;
                (**itr).setPixmap(QPixmap(":/new/prefix1/two_peashooter-black.jpg"));
            }
            else if((**itr).Get_Type() == "Walnut" && Money < 100){
                (**itr).IsAccessibale = false;
                (**itr).setPixmap(QPixmap(":/new/prefix1/walnut-black.jpg"));
            }
            else if((**itr).Get_Type() == "PlumMine" && Money < 175){
                (**itr).IsAccessibale = false;
                (**itr).setPixmap(QPixmap(":/new/prefix1/plum-mine-black.jpg"));
            }
            else if((**itr).Get_Type() == "Jalapeno" && Money < 150){
                (**itr).IsAccessibale = false;
                (**itr).setPixmap(QPixmap(":/new/prefix1/jalapino-black.jpg"));
            }
            else if((**itr).Get_Type() == "Boomerang" && Money < 125){
                (**itr).IsAccessibale = false;
                (**itr).setPixmap(QPixmap(":/new/prefix1/boomerang-black.jpg"));
            }
        }
    }
    else{
        setPlainText(QString("Brains : ") + QString::number(Money));
        for(auto itr=QVec.begin() ; itr!=QVec.end();itr++){
            if((**itr).Get_Type() == "regularzombie" && Money < 100){
                (**itr).IsAccessibale = false;
                (**itr).setPixmap(QPixmap(":/new/prefix1/regular-zombie-black.jpg"));
            }
            else if((**itr).Get_Type() == "bucketheadzombie" && Money < 200){
                (**itr).IsAccessibale = false;
                (**itr).setPixmap(QPixmap(":/new/prefix1/bucket-head-zombie-black.jpg"));
            }
            else if((**itr).Get_Type() == "leafheadzombie" && Money < 150){
                (**itr).IsAccessibale = false;
                (**itr).setPixmap(QPixmap(":/new/prefix1/leaf-hair-zombie-black.jpg"));
            }
            else if((**itr).Get_Type() == "tallzombie" && Money < 155){
                (**itr).IsAccessibale = false;
                (**itr).setPixmap(QPixmap(":/new/prefix1/tall-zombie-black.jpg"));
            }
            else if((**itr).Get_Type() == "astronautzombie" && Money < 200){
                (**itr).IsAccessibale = false;
                (**itr).setPixmap(QPixmap(":/new/prefix1/astronaut-zombie-black.jpg"));
            }
            else if((**itr).Get_Type() == "purplehairzombie" && Money < 800){
                (**itr).IsAccessibale = false;
                (**itr).setPixmap(QPixmap(":/new/prefix1/purple-hair-zombie-black.jpg"));
            }
        }
    }
    setDefaultTextColor((Qt::white));
    setFont(QFont("times" , 16));


}

int Wallet:: Get_Money() { return Money; }

void Wallet::Set_QVec(QVector<Card*> _QVec)
{
    QVec = _QVec;
}
