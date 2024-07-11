#ifndef CLIENT_H
#define CLIENT_H
#include <QTcpSocket>
#include <QHostInfo>
#include <QMainWindow>
#include <QFile>
#include "plantscene.h"
#include "zombiescene.h"
#include "player.h"
#include "gameresult.h"
#include "menu.h"

class Client : public QObject
{
    Q_OBJECT
public:
    Client(QString name , QFile* _file,Menu* _menu);
private :
    QTcpSocket* ClientSocket;
    PlantScene* plantscene;
    ZombieScene* zombiescene;
    Player* player;
    GameResult* gamescene;
    Menu* menu;
    int round=1;
public slots:
    void ConnectingToServer();
    void ReadingData();
    void WrittenData();
    void ConnectedToServer();
    void DisconnectedFromServer();
    void WritingData(QString type);
    void zombiewin();
    void plantwin();
    void checkround();
};

#endif // CLIENT_H

