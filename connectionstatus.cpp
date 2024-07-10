#include "connectionstatus.h"

ConnectionStatus::ConnectionStatus()
{
    setWindowTitle("Starting game...");
    setFixedSize(300,140);
    status =new QLabel(this);
    status->setText("Connecting To Server...");
    status->setStyleSheet("color: red;");
    status->show();
    status->setFont(QFont("times",12,2,false));
}

void ConnectionStatus::showStatus(bool isConnecting)
{
    if(isConnecting)
    {
        status->setText("Connecting To Server...");
        status->setStyleSheet("color: red;");
        status->show();
    }
    else
    {
        status->hide();
        status->setText("Could not connect to server.\nCheck your internet connection.");
        status->setStyleSheet("color: red;");
        status->show();
    }
}

ConnectionStatus::~ConnectionStatus()
{
    delete status;
}
