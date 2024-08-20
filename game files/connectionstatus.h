#ifndef CONNECTIONSTATUS_H
#define CONNECTIONSTATUS_H
#include <QWidget>
#include <QLabel>
class ConnectionStatus
:public QWidget
{
public:
    ConnectionStatus();
    void showStatus(bool isConnecting);
    ~ConnectionStatus();
private:
    QLabel *status;
};

#endif // CONNECTIONSTATUS_H
