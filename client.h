#ifndef CLIENT_H
#define CLIENT_H
#include <QTcpSocket>
#include <QHostInfo>
#include <QMainWindow>
#include "plantscene.h"
#include "zombiescene.h"
#include "player.h"
#include "gameresult.h"

class Client : public QObject
{
    Q_OBJECT
public:
    Client(QString name);
private :
    QTcpSocket* ClientSocket;
    PlantScene* plantscene;
    ZombieScene* zombiescene;
    Player* player;
    GameResult* gamescene;
    int round=1;
public slots:
    void ConnectingToServer();
    void ReadingData();
    void WrittenData();
    void ConnectedToServer();
    void DisconnectedFromServer();
    void WritingData();
    void zombiewin();
    void plantwin();
    void checkround();
};

#endif // CLIENT_H

