#include "menu.h"
#include "client.h"
#include <QFile>

Menu::Menu(UserInfo* _userinfo) : userinfo(_userinfo) {
    newItems();
    DesignWindow();
    connect(Exit,&QPushButton::clicked,this,&Menu::exit);
    connect(EditInfo,&QPushButton::clicked,this,&Menu::editinfo);
    connect(History,&QPushButton::clicked,this,&Menu::history);
    connect(Game,&QPushButton::clicked,this,&Menu::game);
    connect(Back,&QPushButton::clicked,this,&Menu::back);
    connect(Save,&QPushButton::clicked,this,&Menu::save);
}

void Menu::newItems()
{
    backgroundLabel=new QLabel(this);
    Exit=new QPushButton(this);
    EditInfo=new QPushButton(this);
    Game=new QPushButton(this);
    History=new QPushButton(this);
    Back=new QPushButton(this);
    Save=new QPushButton(this);
    Back->hide();
    Save->hide();
}

void Menu::DesignWindow()
{
    QImage image(":/new/prefix1/Designer (42).jpeg");
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setPixmap(QPixmap::fromImage(image));
    backgroundLabel->setGeometry(this->rect());
    backgroundLabel->lower();
    setFixedSize(640,480);
    ///push button EditInfo
    EditInfo->setFlat(true);
    EditInfo->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    EditInfo->setStyleSheet("color: black;");
    EditInfo->setGeometry(170,60,300,50);
    EditInfo->setText("Edit Information");
    EditInfo->setFont(QFont("Berlin Sans FB Demi",18,2,false));
    EditInfo->setStyleSheet("color: black;");
    EditInfo->show();
    ///push button History
    History->setFlat(true);
    History->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    History->setStyleSheet("color: black;");
    History->setGeometry(170,100,300,50);
    History->setText("History");
    History->setFont(QFont("Berlin Sans FB Demi",18,2,false));
    History->setStyleSheet("color: black;");
    ///push button Game
    Game->setFlat(true);
    Game->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    Game->setStyleSheet("color: black;");
    Game->setGeometry(165,148,300,50);
    Game->setText("Game");
    Game->setFont(QFont("Berlin Sans FB Demi",18,2,false));
    Game->setStyleSheet("color: black;");
    ///push button Exit
    Exit->setFlat(true);
    Exit->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    Exit->setStyleSheet("color: black;");
    Exit->setGeometry(165,190,300,50);
    Exit->setText("Exit");
    Exit->setFont(QFont("Berlin Sans FB Demi",18,2,false));
    Exit->setStyleSheet("color: black;");
    ///push botton back
    Back->setFlat(true);
    Back->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    Back->setStyleSheet("color: black;");
    Back->setGeometry(200,350,70,50);
    Back->setText("Back");
    Back->setFont(QFont("Berlin Sans FB Demi",18,2,false));
    Back->setStyleSheet("color: black;");
    ///push botton Save
    Save->setFlat(true);
    Save->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    Save->setStyleSheet("color: black;");
    Save->setGeometry(165,148,300,50);
    Save->setText("Save");
    Save->setFont(QFont("Berlin Sans FB Demi",18,2,false));
    Save->setStyleSheet("color: black;");
}

void Menu::game()
{
    this->close();
    Client * client;
    client = new Client(userinfo->getUsername(),userinfo->get_QFile(),this);
}

void Menu::history()
{
    Back->show();
    showhistory=new QListWidget(this);
    showhistory->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    showhistory->setStyleSheet("color: black;");
    showhistory->setGeometry(30,10,580,460);
    QFile* file = userinfo->get_QFile();
    if (!file) {
        qDebug() << "File pointer is null.";
        return;
    }
    if(!file->open(QIODevice :: ReadOnly | QIODevice :: Text)){
        qDebug() << "File cannot be opened.";
        return;
    }
    showhistory->show();
    QTextStream in(file);
    in.seek(0); // Move to the beginning of the file
    while (!in.atEnd()) {
        QString line = in.readLine();
        showhistory->addItem(line);
        showhistory->addItem("\n");
    }
    file->close();
    showhistory->setFont(QFont("Berlin Sans FB Demi",18,2,false));
    showhistory->setStyleSheet("color: black;");
}

void Menu::editinfo()
{

}

void Menu::exit()
{
    this->close();
}

void Menu::back()
{
    showhistory->hide();
    showhistory->deleteLater();
}

void Menu::save()
{

}
