#include "player.h"
#include "QDebug"

Player::Player() {}

QString& Player::set_PlayerName(){ return PlayerName; }

QString& Player::set_CompetitorName(){return CompetitorName;}

bool& Player::set_PlantOrZombie(){return IsPlant;}

bool& Player::set_WinOrLose(){return WinOrLose;}

void Player::setQfile(QFile* _file)
{
    PlayerFile = _file;
    if(!PlayerFile->open(QIODevice :: WriteOnly | QIODevice :: Append | QIODevice :: Text)){
        qDebug() << "File cannot be opened.";
        return;
    }
}

QFile *Player::getQFile() {return PlayerFile;}
