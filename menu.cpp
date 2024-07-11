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
    connect(Start,&QPushButton::clicked,this,&Menu::start);
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
    Start=new QPushButton(this);
    Back->hide();
    Save->hide();
    Start->hide();
}

void Menu::DesignWindow()
{
    setWindowTitle("Menu");
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
    Back->setGeometry(340,400,300,50);
    Back->setText("Back");
    Back->setFont(QFont("Berlin Sans FB Demi",18,2,false));
    Back->setStyleSheet("color: black;");
    ///push botton Save
    Save->setFlat(true);
    Save->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    Save->setStyleSheet("color: black;");
    Save->setGeometry(280,40,300,40);
    Save->setText("Save");
    Save->setFont(QFont("Berlin Sans FB Demi",18,2,false));
    Save->setStyleSheet("color: black;");
    ///push botton Save
    Start->setFlat(true);
    Start->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    Start->setStyleSheet("color: black;");
    Start->setGeometry(280,95,300,40);
    Start->setText("Start");
    Start->setFont(QFont("Berlin Sans FB Demi",18,2,false));
    Start->setStyleSheet("color: black;");
}

void Menu::game()
{
    Start->show();
    Game->hide();
    EditInfo->hide();
    Exit->hide();
    History->hide();
    IP=new QLineEdit(this);
    IP->setPlaceholderText("IP");
    IP->setGeometry(170,140,300,40);
    IP->show();
}

void Menu::history()
{
    Back->show();
    showhistory=new QListWidget(this);
    showhistory->stackUnder(Back);
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
    Game->hide();
    EditInfo->hide();
    Exit->hide();
    History->hide();
    Username=new QLineEdit(this);
    Username->setPlaceholderText(userinfo->getUsername());
    Username->setGeometry(170,140,300,40);
    Username->show();
    Name=new QLineEdit(this);
    Name->setPlaceholderText(userinfo->getName());
    Name->setGeometry(170,80,300,40);
    Name->show();
    Mobile=new QLineEdit(this);
    Mobile->setPlaceholderText(userinfo->getMobile());
    Mobile->setGeometry(170,260,300,40);
    Mobile->show();
    Address=new QLineEdit(this);
    Address->setPlaceholderText(userinfo->getEmail());
    Address->setGeometry(170,320,300,40);
    Address->show();
    Password=new QLineEdit(this);
    Password->setPlaceholderText(userinfo->getPassword());
    Password->setGeometry(170,200,300,40);
    Password->show();
    Save->show();
}

void Menu::exit()
{
    this->close();
}

void Menu::back()
{
    showhistory->hide();
    Back->hide();
    showhistory->deleteLater();
}

void Menu::save()
{
    QString tmp=userinfo->getUsername();
    int flag=0;
    QString currentText = Username->text();
    if(!currentText.isEmpty()){
        tmp = userinfo->getUsername();
        userinfo->set_Username(currentText);
        flag++;
    }
    currentText = Name->text();
    if(!currentText.isEmpty()){
        userinfo->set_Name(currentText);
    }
    currentText = Address->text();
    if(!currentText.isEmpty()){
        userinfo->set_Address(currentText);
    }
    currentText = Password->text();
    if(!currentText.isEmpty()){
        userinfo->set_Password(currentText);
    }
    currentText = Mobile->text();
    if(!currentText.isEmpty()){
        userinfo->set_Mobile(currentText);
    }

    QString filename = tmp + ".txt";
    QFile userfile(filename);
    if(!(userfile.exists())){
        qDebug() << "File Doesn't Exist";
        return;
    }
    if(!userfile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "File cannot be opened.";
        return;
    }

    QTextStream out(&userfile);
    out.seek(0);
    QByteArray bytes = QCryptographicHash :: hash(userinfo->getPassword().toUtf8() , QCryptographicHash :: Md4);
    QString digest = QString(bytes.toHex());
    out << userinfo->getName() << "\n" <<userinfo->getUsername() << "\n" << userinfo->getMobile() <<"\n" << digest << "\n" << userinfo->getEmail() << "\n";
    userfile.close();
    Game->show();
    EditInfo->show();
    Exit->show();
    History->show();
    Username->hide();
    Name->hide();
    Address->hide();
    Mobile->hide();
    Password->hide();
    Save->hide();
    if(flag){
        if (userfile.rename(userinfo->getUsername()+".txt")) {
            qDebug() << "File renamed successfully!";
        } else {
            qDebug() << "Error renaming the file.";
        }
    }
}

void Menu::start()
{
    Start->hide();
    Game->show();
    EditInfo->show();
    Exit->show();
    History->show();
    IP->hide();
    this->hide();
    Client * client1;
    client1 = new Client(userinfo->getUsername(),userinfo->get_QFile(),this,IP->text());
}
