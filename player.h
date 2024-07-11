#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include <QFile>

class Player
{
public:
    Player();
    QString& set_PlayerName();
    QString& set_CompetitorName();
    bool& set_PlantOrZombie();
    bool& set_WinOrLose();
    void setQfile(QFile* _file);
    QFile* getQFile();
private :
    QString PlayerName;
    QString CompetitorName;
    bool IsPlant;//0 for zombie and 1 for plant
    bool WinOrLose;//0 for lose and 1 for win
    QFile* PlayerFile;
};

#endif // PLAYER_H
