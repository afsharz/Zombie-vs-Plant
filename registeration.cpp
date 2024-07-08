#include "registeration.h"
#include "ui_registeration.h"

registeration::registeration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registeration)
{
    ui->setupUi(this);
    this->setWindowTitle("Sign Up");
    user=new UserInfo(this);
    designWindow();
    connect(ui->lineEdit,&QLineEdit::textEdited, user, &UserInfo::setName);
    connect(ui->lineEdit_3,&QLineEdit::textEdited, user, &UserInfo::setUsername);
    connect(ui->lineEdit_6,&QLineEdit::textEdited, user, &UserInfo::setAddress);
    connect(ui->lineEdit_4,&QLineEdit::textEdited, user, &UserInfo::setMobile);
    connect(ui->lineEdit_5,&QLineEdit::textEdited, user, &UserInfo::setPassword);
}

registeration::~registeration()
{
    delete InvalidEmailError;
    delete InvalidMobileError;
    delete UnacceptablePass;
    delete PasswordState;
    delete ui;
}

void registeration::designWindow()
{
    ui->lineEdit_6->setEchoMode(QLineEdit::Normal);
    //These codes that are repeated are for the color and size and transparency of line edits, lebels and push bottons
    InvalidEmailError=new QLabel(this);
    InvalidEmailError->setText("Invalid Email Address");
    InvalidEmailError->setStyleSheet("color: red;");
        InvalidEmailError->setFrameShape(QFrame::NoFrame);
    InvalidEmailError->setGeometry(ui->lineEdit_6->x()+ui->lineEdit_6->width()-120,
                                   ui->lineEdit_6->y()+(ui->lineEdit_6->height()/4),120,20);
    InvalidEmailError->setVisible(false);

    InvalidMobileError=new QLabel(this);
    InvalidMobileError->setText("Invalid Mobile Number");
    InvalidMobileError->setStyleSheet("color: red;");
    InvalidMobileError->setFrameShape(QFrame::NoFrame);
    InvalidMobileError->setGeometry(ui->lineEdit_4->x()+ui->lineEdit_4->rect().width()-125,
                                   ui->lineEdit_4->y()+(ui->lineEdit_4->height()/4),125,20);
    InvalidMobileError->setVisible(false);

    //password state label initialize
    PasswordState=new QLabel(this);
    PasswordState->setFrameShape(QFrame::NoFrame);
    PasswordState->setGeometry(ui->lineEdit_5->x()+ui->lineEdit_5->rect().width()-50,ui->lineEdit_5->y()+(ui->lineEdit_5->height())/3,50,20);
    PasswordState->setStyleSheet("backgound-color: rgba(0,0,0,0);");
    PasswordState->show();
    //unacceptabel password

    UnacceptablePass=new QLabel(this);
    UnacceptablePass->setFrameShape(QFrame::NoFrame);
     UnacceptablePass->setGeometry(ui->lineEdit_5->x(),ui->lineEdit_5->y()+ui->lineEdit_5->height(),150,20);
    UnacceptablePass->setStyleSheet("backgound-color: rgba(0,0,0,0);");
    UnacceptablePass->setText("Unacceptable Password");
    UnacceptablePass->setStyleSheet("color: red;");
    UnacceptablePass->hide();

    //ui->label->setStyleSheet("QLabel {""background-color: rgba(0, 0, 0, 127);" "border-radius: 15px;" "border: none;" "}");

    ui->label_2->setFrameShape(QFrame::NoFrame);
    ui->label_2->setAttribute(Qt::WA_NoSystemBackground);
    ui->label_2->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_2->setStyleSheet("color: black;");

    ui->label_8->setFrameShape(QFrame::NoFrame);
    ui->label_8->setAttribute(Qt::WA_NoSystemBackground);
    ui->label_8->setAttribute(Qt::WA_TranslucentBackground);

    ui->lineEdit->setStyleSheet("font-size: 10px;");
    ui->lineEdit_3->setStyleSheet("font-size: 10px;");
    ui->lineEdit_4->setStyleSheet("font-size: 10px;");
    ui->lineEdit_5->setStyleSheet("font-size: 10px;");
    ui->lineEdit_6->setStyleSheet("font-size: 10px;");
    ui->lineEdit->setStyleSheet("color: white;");
    ui->lineEdit_3->setStyleSheet("color: white;");
    ui->lineEdit_4->setStyleSheet("color: white;");
    ui->lineEdit_5->setStyleSheet("color: white;");
    ui->lineEdit_6->setStyleSheet("color: white;");
    ui->lineEdit->setPlaceholderText("Name");
    ui->lineEdit_3->setPlaceholderText("Username");
    ui->lineEdit_4->setPlaceholderText("Mobile");
    ui->lineEdit_5->setPlaceholderText("Password");
    ui->lineEdit_6->setPlaceholderText("Email");

    ui->pushButton_3->setFlat(true);
    ui->pushButton_3->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    ui->pushButton_3->setStyleSheet("color: black;");

    ui->pushButton_4->setFlat(true);
    ui->pushButton_4->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    ui->pushButton_4->setStyleSheet("color: black;");

    //ui->label_9->stackUnder(ui->label);
    //ui->label_10->stackUnder(ui->label);
    //ui->label_11->stackUnder(ui->label);
    //ui->label_12->stackUnder(ui->label);
    //ui->label_13->stackUnder(ui->label);
    //ui->label_14->stackUnder(ui->label);
   //ui->label_15->stackUnder(ui->label);
}

void registeration::showInvalidEmailError(bool IsTrue)
{
    if(IsTrue)
    InvalidEmailError->show();
    else
        InvalidEmailError->hide();
}

void registeration::showInvalidMoblieError(bool IsTrue)
{
    if(IsTrue)
        InvalidMobileError->show();
    else
        InvalidMobileError->hide();
}

void registeration::showUnacceptablePwd(bool IsTrue)
{
    if(IsTrue)
        UnacceptablePass->show();
    else
        UnacceptablePass->hide();
}



void registeration::showPasswordState(UserInfo::state state)
{
    switch (state)
    {
    case UserInfo::weak:
    {
        PasswordState->setStyleSheet("color: red;");
        PasswordState->setText("Weak");
        break;
    }
    case UserInfo::medium:
    {
        PasswordState->setStyleSheet("color: orange;");
        PasswordState->setText("Medium");
        PasswordState->setFont(QFont("times",10,2,false));
        break;
    }
    case UserInfo::strong:
    {
        PasswordState->setStyleSheet("color: green;");
        PasswordState->setText("Strong");
        break;
    }
    }
}


void registeration::on_pushButton_4_clicked()
{
    QString filename = ui->lineEdit_3->text() + ".txt";
    QFile userfile(filename);

    if(userfile.exists()){
        //if the file existed yet, it means that the user has an account yet
        ui->label_8->setStyleSheet("color: red;");
        ui->label_8->setText(tr("Username already taken"));
        return;
    }

    if(!userfile.open(QIODevice :: WriteOnly | QIODevice :: Append | QIODevice :: Text)){
        qDebug() << "File cannot be opened.";
        return;
    }
    QTextStream out(&userfile);

    QByteArray bytes = QCryptographicHash :: hash(user->getPassword().toUtf8() , QCryptographicHash :: Md4);
    QString digest = QString(bytes.toHex());


    out << user->getName() << "\n" <<user->getUsername() << "\n" << user->getMobile() <<"\n" << digest << "\n" << user->getEmail() << "\n";

    userfile.flush();
    userfile.close();
}

