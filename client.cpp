#include "client.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

Client::Client(QString name) {
    // we should make a view with a pushbotton that try to connect to server
    //connect(ui->pushButton , SIGNAL(clicked()) , this , SLOT(ConnectingToServer()));
    player = new Player;
    player->set_PlayerName()=name;
    player->setQfile();
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
    // we should read the jason file came from other client and add the new object to our vector and our scene and also read competitor name and add it to player info
    // we also read a boolian that server give us to said if we are plant or zombie and set it in the player
    // we should set the competitor name and roles
    //this if else should be in the scope that client recieve a boolian from server
    if(player->set_PlantOrZombie()){
        plantscene = new PlantScene;
        connect(plantscene,SIGNAL(AddedToVector()),this,SLOT(WritingData()));
        connect(plantscene,SIGNAL(Plantwin()),this,SLOT(plantwin()));
        connect(plantscene,SIGNAL(Zombiewin()),this,SLOT(zombiewin()));
    }
    else{
        zombiescene = new ZombieScene;
        connect(zombiescene,SIGNAL(AddedToVector()),this,SLOT(WritingData()));
        connect(zombiescene,SIGNAL(Plantwin()),this,SLOT(plantwin()));
        connect(zombiescene,SIGNAL(Zombiewin()),this,SLOT(zombiewin()));
    }
}

void Client::WrittenData()
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

void Client::WritingData()
{
    // we should write information of the last vector info in json file and send it to server
}

void Client::zombiewin()
{
    if(player->set_PlantOrZombie()){
        plantscene->deleteLater();
        player->set_WinOrLose()=0;
    }
    else{
        zombiescene->deleteLater();
        player->set_WinOrLose()=1;
    }
    gamescene = new GameResult("Zombie");

    QTimer* timer = new QTimer;
    QObject::connect(timer , SIGNAL(timeout()) , this , SLOT(checkround()));
    timer->start(5000);
}

void Client::plantwin()
{
    if(player->set_PlantOrZombie()){
        plantscene->deleteLater();
        player->set_WinOrLose()=1;
    }
    else{
        zombiescene->deleteLater();
        player->set_WinOrLose()=0;
    }
    gamescene = new GameResult("Plant");

    QTimer* timer = new QTimer;
    QObject::connect(timer , SIGNAL(timeout()) , this , SLOT(checkround()));
    timer->start(5000);
}

void Client::checkround()
{
    gamescene->deleteLater();
    if(round==1){
        QTextStream out(player->getQFile());
        // Move the cursor to the end of the document
        out.seek(player->getQFile()->size());
        out << "Competitor name : " << player->set_CompetitorName();
        if(player->set_PlantOrZombie())
            out << "\n round 1 : Plant ";
        else
            out << "\n round 1 : Zombie ";
        if(player->set_WinOrLose())
            out << "\n round 1 : Winner ";
        else
            out << "\n round 1 : Loser ";
        player->getQFile()->flush();
        player->getQFile()->close();
        // we should send a message to server that the game has finished
    }
    else{
        QTextStream out(player->getQFile());
        // Move the cursor to the end of the document
        out.seek(player->getQFile()->size());
        if(player->set_PlantOrZombie())
            out << "\n round 2 : Plant ";
        else
            out << "\n round 2 : Zombie ";
        if(player->set_WinOrLose())
            out << "\n round 2 : Winner ";
        else
            out << "\n round 2 : Loser ";
        player->getQFile()->flush();
        player->getQFile()->close();
        // we should make object of menue and delete this client
    }
}
