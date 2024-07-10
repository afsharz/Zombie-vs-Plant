#include "player.h"
#include "QDebug"

Player::Player() {}

QString& Player::set_PlayerName(){ return PlayerName; }

QString& Player::set_CompetitorName(){return CompetitorName;}

bool& Player::set_PlantOrZombie(){return PlantOrZombie;}

bool& Player::set_WinOrLose(){return WinOrLose;}

void Player::setQfile()
{
    QString filename = PlayerName + "history.txt";
    PlayerFile = new QFile(filename);

    if(!PlayerFile->open(QIODevice :: WriteOnly | QIODevice :: Append | QIODevice :: Text)){
        qDebug() << "File cannot be opened.";
        return;
    }
}

QFile *Player::getQFile() {return PlayerFile;}
