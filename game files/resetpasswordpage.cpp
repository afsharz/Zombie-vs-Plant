#include "resetpasswordpage.h"
#include <QSizePolicy>
#include <QFile>
#include "login.h"
#include <QRegularExpression>

ResetPasswordPage::ResetPasswordPage(LogIn *_PrvPage)
    :PrvPage(_PrvPage)
{
    newItems();
    DesignWindow();
    vpass=new QRegularExpression("^.{8,24}$");
    connect(btnReset,&QPushButton::clicked,this,&ResetPasswordPage::checkinfo);
    connect(btnBack,&QPushButton::clicked,this,&ResetPasswordPage::BackBtnClicked);
    connect(ledPass,&QLineEdit::textEdited,this,&ResetPasswordPage::checkSecurity);
    isPassValid=false;
}

void ResetPasswordPage::newItems()
{
    backgroundLabel=new QLabel(this);
    layoutContainer=new QWidget(this);
    layoutContainer->setGeometry(120,140,230,300);
    layout=new QGridLayout(layoutContainer);
    lblWrongNum=new QLabel(this);
    ledUsername=new QLineEdit(this);
    ledNumber=new QLineEdit(this);
    ledPass=new QLineEdit(this);
    btnBack=new QPushButton(this);
    btnReset=new QPushButton(this);
    errorNumber=new QLabel(this);
    PasswordState=new QLabel(this);
    UnacceptablePass=new QLabel(this);
}

void ResetPasswordPage::DesignWindow()
{
    setWindowTitle("Reset Password");
    ///add items to layout
    layout->addWidget(ledUsername,1,0,1,3);
    layout->addWidget(ledNumber,3,0,1,3);
    layout->addWidget(ledPass,5,0,1,3);
    layout->addWidget(PasswordState,5,3);
    layout->addWidget(UnacceptablePass,6,0);
    layout->addWidget(errorNumber,9,0,2,2);
    /// set background
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setPixmap(QPixmap(":/new/prefix1/forgotpasswordBG.png"));
    backgroundLabel->setGeometry(this->rect());
    backgroundLabel->lower();
    setFixedSize(640,480);
    ///username lineedit
    ledUsername->setPlaceholderText("Username");
    ledUsername->show();
    ///phone number line edit
    ledNumber->setPlaceholderText("Phone Number");
    ledNumber->show();
    ///new password line edit
    ledPass->setPlaceholderText("Password");
    ledPass->show();
    /// error message
    errorNumber->setText("incorrect Username or Number");
    errorNumber->setStyleSheet("color: red;");
    errorNumber->setFont(QFont("Berlin Sans FB Demi",11,2,false));
    errorNumber->hide();
    ///push button reset
    btnReset->setFlat(true);
    btnReset->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    btnReset->setStyleSheet("color: black;");
    btnReset->setGeometry(150,270,70,50);
    btnReset->setText("Reset");
    btnReset->setFont(QFont("Berlin Sans FB Demi",15,2,false));
    btnReset->setStyleSheet("color: white;");
    ///push button back
    btnBack->setFlat(true);
    btnBack->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    btnBack->setStyleSheet("color: black;");
    btnBack->setGeometry(250,270,70,50);
    btnBack->setText("Back");
    btnBack->setFont(QFont("Berlin Sans FB Demi",15,2,false));
    btnBack->setStyleSheet("color: white;");
    ///unacceptable password
    UnacceptablePass->setText("must contains 8-24 digits");
   UnacceptablePass->setStyleSheet(("color: red;"));
    UnacceptablePass->setFont(QFont("Berlin Sans FB Demi",10,2,false));
   UnacceptablePass->hide();
}

void ResetPasswordPage::checkinfo()
{
    if(!isPassValid)
        return;

    QString filename = ledUsername->text() + ".txt";
    QFile userfile(filename);
    if(!(userfile.exists())){
        lblWrongNum->show();
        return;
    }

    if(!userfile.open(QIODevice :: ReadOnly | QIODevice :: Text))
    {
        qDebug() << "File cannot be opened.";
        return;
    }
    QStringList lines;
    QTextStream in(&userfile);

    while (!in.atEnd())
        lines.append(in.readLine());

    userfile.close();

    if (lines.size() < 3 || lines[2] != ledNumber->text())
    {
        lblWrongNum->show();
        return;
    }
    else
    {
        lblWrongNum->hide();
        QString password = ledPass->text();
        QByteArray bytes = QCryptographicHash :: hash(password.toUtf8() , QCryptographicHash :: Md4);
        QString digest = QString(bytes.toHex());
        if (lines.size() >= 4)
        {
            lines[3] = digest;
        } else
        {
            lines.append(digest);
        }
        if (!userfile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "File cannot be opened for writing.";
            return;
        }

        QTextStream out(&userfile);
        for (const QString &line : lines)
        {
            out << line << "\n";
        }
        userfile.close();
        PrvPage->show();
        this->close();
        this->deleteLater();
    }



}

void ResetPasswordPage::BackBtnClicked()
{
    PrvPage->show();
    this->close();
    this->deleteLater();
}

void ResetPasswordPage::checkSecurity(QString pass)
{
    int count=0;
    QRegularExpressionMatch *match=new QRegularExpressionMatch();
    *match=vpass->match(pass);
    if(!match->hasMatch())
        showUnacceptablePwd(true);
    else
    {
        showUnacceptablePwd(false);
    }
    QRegularExpression *state=new QRegularExpression("\\W+");
    *match=state->match(pass);
    if(match->hasMatch()) count++;
    state->setPattern("[A-Z]+");
    *match=state->match(pass);
    if(match->hasMatch()) count++;
    state->setPattern("[a-z]+");
    *match=state->match(pass);
    if(match->hasMatch()) count++;
    state->setPattern("\\d+");
    *match=state->match(pass);
    if(match->hasMatch()) count++;
    state->setPattern("^.{10}");
    *match=state->match(pass);
    if(match->hasMatch()) count++;
    switch(count)
    {
    case 0:
    {
        showPasswordState(UserInfo::weak);
        break;
    }
    case 1:
    {
        showPasswordState(UserInfo::weak);
        break;
    }
    case 2:
    {
        showPasswordState(UserInfo::medium);
        break;
    }
    case 3:
    {
        showPasswordState(UserInfo::medium);
        break;
    }
    case 4:
    {
        showPasswordState(UserInfo::strong);
        isPassValid=true;
        break;
    }
    case 5:
    {
        showPasswordState(UserInfo::strong);
        isPassValid=true;
        break;
    }

    }

    delete state;
    delete match;
}

void ResetPasswordPage::showPasswordState(UserInfo::state state)
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


void ResetPasswordPage::showUnacceptablePwd(bool IsTrue)
{
    if(IsTrue)
        UnacceptablePass->show();
    else
        UnacceptablePass->hide();
}

ResetPasswordPage::~ResetPasswordPage()
{
    delete backgroundLabel;
    delete layout;
    delete lblWrongNum;
    delete errorNumber;
    delete PasswordState;
    delete UnacceptablePass;
    delete ledUsername;
    delete ledNumber;
    delete ledPass;
    delete btnBack;
    delete btnReset;
    delete layoutContainer;
    delete user;
    delete vpass;
}
