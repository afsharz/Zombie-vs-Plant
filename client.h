#ifndef CLIENT_H
#define CLIENT_H
#include <QTcpSocket>
#include <QHostInfo>
#include <QMainWindow>
#include "plantscene.h"
#include "zombiescene.h"

class Client : public QObject
{
    Q_OBJECT
public:
    Client();
private :
    QTcpSocket* ClientSocket;
    PlantScene* plantscene;
    ZombieScene* zombiescene;
public slots:
    void ConnectingToServer();
    void ReadingData();
    void WritingData();
    void ConnectedToServer();
    void DisconnectedFromServer();
};

#endif // CLIENT_H

