#ifndef GAMERESULT_H
#define GAMERESULT_H
#include <QString>
#include <QDialog>
#include <QLabel>

class GameResult : public QDialog
{
public:
    GameResult(QString winner);
private :
    QLabel *backgroundLabel;
};

#endif // GAMERESULT_H
