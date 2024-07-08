#include "client.h"

Client::Client() {
    // we should make a view with a pushbotton that try to connect to server
    //connect(ui->pushButton , SIGNAL(clicked()) , this , SLOT(ConnectingToServer()));
}

void Client::ConnectingToServer()
{
    ClientSocket = new QTcpSocket();

    ClientSocket->connectToHost("192.168.90.75" , 1025); // first is the address IP and second is our port
    connect(ClientSocket , SIGNAL(connected()) , this , SLOT(ConnectedToServer()));
    connect(ClientSocket , SIGNAL(bytesWritten(qint64)) , this , SLOT(WritingData()));
    connect(ClientSocket , SIGNAL(readyRead()) , this , SLOT(ReadingData()));
    connect(ClientSocket , SIGNAL(disconnected()) , this , SLOT(DisconnectedFromServer()));
}

void Client::ReadingData()
{
    // we should read the jason file came from other client and add the new object to our vector and our scene
}

void Client::WritingData()
{
    qDebug() << "written Successfully\n";
    //used to say that writing is finished
}

void Client::ConnectedToServer()
{
    qDebug() << "Connected Successfully\n";
    // we should first recieve other clients name and also send our names
    // then we should new our game scene ( we should handle if the client is plant or zombie )
    // we should show our scene
}

void Client::DisconnectedFromServer()
{
    qDebug() << "DisConnection Lost\n";
}
