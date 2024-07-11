#include "client.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QJsonObject>
#include <QJsonDocument>

Client::Client(QString name , QFile* _file,Menu* _menu,QString _IP) : menu(_menu) , IP(_IP) {
    player = new Player;
    player->set_PlayerName()=name;
    player->setQfile(_file);
    round=1;
    ConnectingToServer();
}

void Client::ConnectingToServer()
{
    ClientSocket = new QTcpSocket();
    ClientSocket->connectToHost(IP , 1500); // first is the address IP and second is our port
    connect(ClientSocket , SIGNAL(connected()) , this , SLOT(ConnectedToServer()));
    if(ClientSocket->waitForConnected(10000))
    {
        qDebug()<<"connected to server";
    }
    else
    {
         qDebug()<<"could not connect";
        return;
    }
    connect(ClientSocket,&QTcpSocket::connected,this,&Client::ConnectedToServer);
    connect(ClientSocket , &QTcpSocket::bytesWritten , this , &Client::WrittenData);
    connect(ClientSocket , &QTcpSocket::readyRead , this , &Client::ReadingData);
    connect(ClientSocket , &QTcpSocket::disconnected , this , &Client::DisconnectedFromServer);
}

void Client::ReadingData()
{
    // we should read the jason file came from other client and add the new object to our vector and our scene and also read competitor name and add it to player info
    // we also read a boolian that server give us to said if we are plant or zombie and set it in the player
    // we should set the competitor name and roles
    //this if else should be in the scope that client recieve a boolian from server
    QByteArray byteArray=ClientSocket->readAll();
    QJsonObject mess;
    byteArray.replace("\\n", "\n");
    byteArray.replace("\\\"", "\"");
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArray);
    if (!jsonDoc.isNull() && jsonDoc.isObject()) {
         mess = jsonDoc.object();
    } else {
        qWarning() << "Failed to create JSON object from QByteArray";
    }

    if(mess["MessageType"].toString()=="role")
    {
        player->set_CompetitorName()=mess["CompetitorName"].toString();
        if(mess["role"]=="zombie")
        {
            player->set_PlantOrZombie()=0;
            zombiescene = new ZombieScene(player->set_CompetitorName());
            connect(zombiescene,&ZombieScene::AddedToVector,this,&Client::WritingData);
            connect(zombiescene,SIGNAL(Plantwin()),this,SLOT(plantwin()));
            connect(zombiescene,SIGNAL(Zombiewin()),this,SLOT(zombiewin()));
        }
        else
        {
            player->set_PlantOrZombie()=1;
            plantscene = new PlantScene(player->set_CompetitorName());
            connect(plantscene,&PlantScene::AddedToVector,this,&Client::WritingData);
            connect(plantscene,SIGNAL(Plantwin()),this,SLOT(plantwin()));
            connect(plantscene,SIGNAL(Zombiewin()),this,SLOT(zombiewin()));
        }
    }
    else if (mess["MessageType"]=="drop")
    {
        bool hasDropped=false;
        QPointF position(mess["X"].toInt(),mess["Y"].toInt());
        if(player->set_PlantOrZombie())///if true :plant
        {
            QList<QGraphicsItem*> items= plantscene->getScene()->items(position);
            for (QGraphicsItem* item : items) {
                home* h = dynamic_cast<home*>(item);
                if(h && !hasDropped)
                {
                    h->dropZombie(mess["type"].toString(),false);
                    hasDropped=true;
                }
            }
        }
        else /// zombie
        {
            QList<QGraphicsItem*> items= zombiescene->getScene()->items(position);
            for (QGraphicsItem* item : items) {
                home* h = dynamic_cast<home*>(item);
                if(h && !hasDropped)
                {
                    h->dropPlant(mess["type"].toString(),false);
                    hasDropped=true;
                }
            }
        }
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

    QJsonObject mess;
    mess["MessageType"]="Introduce";
    mess["name"]=this->player->set_PlayerName();
    QJsonDocument jsonDoc(mess);
    QByteArray jsonData = jsonDoc.toJson();
    ClientSocket->write(jsonData);
}

void Client::DisconnectedFromServer()
{
    qDebug() << "Connection Lost\n";
}

void Client::WritingData(QString type)
{
    // we should write information of the last vector info in json file and send it to server
    QJsonObject mess;
    mess["MessageType"]="drop";
    mess["type"]=type;
    if(player->set_PlantOrZombie())
    {
        mess["X"]=plantscene->getPlants().back()->pos().x();
        mess["Y"]=plantscene->getPlants().back()->pos().y()+15;
    }
    else
    {
        mess["X"]=zombiescene->getZombies().back()->pos().x();
        mess["Y"]=zombiescene->getZombies().back()->pos().y()+10;
    }

    QJsonDocument jsonDoc(mess);
    QByteArray jsonData = jsonDoc.toJson();
    ClientSocket->write(jsonData);
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
    gamescene->show();
    timer = new QTimer;
    QObject::connect(timer , &QTimer::timeout , this ,&Client::checkround);
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
    gamescene->show();
    timer = new QTimer;
    QObject::connect(timer , SIGNAL(timeout()) , this , SLOT(checkround()));
    timer->start(5000);
}

void Client::checkround()
{
    delete timer;
    gamescene->deleteLater();
    if(round==1){
        round++;
        QTextStream out(player->getQFile());
        // Move the cursor to the end of the document
        out.seek(player->getQFile()->size());
        out << "Competitor name : " << player->set_CompetitorName();
        QDateTime current = QDateTime::currentDateTime();
        QString formattedDate = current.toString("yyyy-MM-dd");
        out << "\nDate : " << formattedDate;
        if(player->set_PlantOrZombie())
            out << "\n round 1 : Plant ";
        else
            out << "\n round 1 : Zombie ";
        if(player->set_WinOrLose())
            out << "\n round 1 : Winner ";
        else
            out << "\n round 1 : Loser ";
        // we should send a message to server that the game has finished
        QJsonObject mess;
        mess["MessageType"]="finished";
        QJsonDocument jsonDoc(mess);
        QByteArray jsonData = jsonDoc.toJson();
        ClientSocket->write(jsonData);
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
            out << "\n round 2 : Winner \n";
        else
            out << "\n round 2 : Loser \n";
        player->getQFile()->flush();
        player->getQFile()->close();
        menu->show();
    }
}

