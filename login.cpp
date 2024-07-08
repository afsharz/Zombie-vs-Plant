#include "login.h"
#include "ui_login.h"
#include "plantscene.h"
#include "zombiescene.h"
#include "resetpasswordpage.h"
#include <QThread>

LogIn::LogIn(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LogIn)
{
    ui->setupUi(this);
    //These codes that are repeated are for the color and size and transparency of line edits, lebels and push bottons
    //"background-color: rgba(0, 0, 0, 127);"
    //ui->label->setStyleSheet("QLabel {""border-radius: 15px;" "border: none;" "}");
    ui->label_2->setFrameShape(QFrame::NoFrame);
    ui->label_2->setAttribute(Qt::WA_NoSystemBackground);
    ui->label_2->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_2->setStyleSheet("color: black;");

    ui->label_5->setFrameShape(QFrame::NoFrame);
    ui->label_5->setAttribute(Qt::WA_NoSystemBackground);
    ui->label_5->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_5->setStyleSheet("color: black;");

    ui->label_7->setFrameShape(QFrame::NoFrame);
    ui->label_7->setAttribute(Qt::WA_NoSystemBackground);
    ui->label_7->setAttribute(Qt::WA_TranslucentBackground);

    ui->label_8->setFrameShape(QFrame::NoFrame);
    ui->label_8->setAttribute(Qt::WA_NoSystemBackground);
    ui->label_8->setAttribute(Qt::WA_TranslucentBackground);

    ui->label_9->setFrameShape(QFrame::NoFrame);
    ui->label_9->setAttribute(Qt::WA_NoSystemBackground);
    ui->label_9->setAttribute(Qt::WA_TranslucentBackground);

    ui->pushButton->setFlat(true);
    ui->pushButton->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    ui->pushButton->setStyleSheet("color: red;");

    ui->pushButton_2->setFlat(true);
    ui->pushButton_2->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    ui->pushButton_2->setStyleSheet("color: black;");

    ui->pushButton_3->setFlat(true);
    ui->pushButton_3->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    ui->pushButton_3->setStyleSheet("color: black;");

    ui->lineEdit->setStyleSheet("font-size: 10px;");
    ui->lineEdit_2->setStyleSheet("font-size: 10px;");
    ui->lineEdit_2->setStyleSheet("color: white;");
    ui->lineEdit->setStyleSheet("color: white;");
    ui->lineEdit->setPlaceholderText("Username");
    ui->lineEdit_2->setPlaceholderText("Password");

    ui->label->stackUnder(ui->label_8);
    ui->label->stackUnder(ui->lineEdit);

}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::on_pushButton_clicked()
{
    //to open register page to create an acount
    rg = new registeration(this);
    rg->show();
}


void LogIn::on_pushButton_3_clicked()
{
    QString filename = ui->lineEdit->text() + ".txt";
    QFile userfile(filename);

    if(!(userfile.exists())){
        //it means that the user doesn't have any account and should register (because there's no file with this user name)
        //so we should show an error to say you dont have any account
        ui->label_7->hide();
        ui->label_8->show();
        ui->label_8->setStyleSheet("color: red;");
        ui->label_8->setText(tr("There's no account with this username"));
        return;
    }

    if(!userfile.open(QIODevice :: ReadOnly | QIODevice :: Text)){
        qDebug() << "File cannot be opened.";
        return;
    }

    QTextStream in(&userfile);

    QString username = in.readLine();
    username = in.readLine();
    //second line in files is username

    QString password = in.readLine();
    password = in.readLine();
    QString tmp = ui->lineEdit_2->text();
    QByteArray bytes = QCryptographicHash :: hash(tmp.toUtf8() , QCryptographicHash :: Md4);
    QString digest = QString(bytes.toHex());
    //forth line in files is password

    if(password!=digest){
        //should show an error that your password is incorrect
        ui->label_8->hide();
        ui->label_7->show();
        ui->label_7->setStyleSheet("color: red;");
        ui->label_7->setText(tr("password is incorrect"));
    }
    else{
        //log in successfuly and close the window after 5 second and open game window
        ui->label_8->hide();
        ui->label_7->hide();
        ui->label_9->show();
        ui->label_9->setText(tr("log in successfully!"));
    }
}


void LogIn::on_pushButton_5_clicked()
{
    PlantScene *PSc = new PlantScene;
   // ZombieScene *ZSc = new ZombieScene;
}


void LogIn::on_pushButton_2_clicked()
{
    ResetPasswordPage *r=new ResetPasswordPage;
    r->show();
    this->close();
}

