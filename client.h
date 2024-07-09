#ifndef CLIENT_H
#define CLIENT_H
#include <QTcpSocket>
#include <QHostInfo>
#include <QMainWindow>
#include "plantscene.h"
#include "zombiescene.h"
#include "player.h"

class Client : public QObject
{
    Q_OBJECT
public:
    Client();
private :
    QTcpSocket* ClientSocket;
    PlantScene* plantscene;
    ZombieScene* zombiescene;
    Player* player;
public slots:
    void ConnectingToServer();
    void ReadingData();
    void WrittenData();
    void ConnectedToServer();
    void DisconnectedFromServer();
    void WritingData();
};

#endif // CLIENT_H

