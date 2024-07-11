#include "resetpasswordpage.h"
#include <QSizePolicy>
#include <QFile>
#include "login.h"

ResetPasswordPage::ResetPasswordPage(QWidget *parent)
    : QWidget{parent}
{
    newItems();
    DesignWindow();
    connect(btnReset,&QPushButton::clicked,this,&ResetPasswordPage::checkinfo);
    connect(btnBack,&QPushButton::clicked,this,&ResetPasswordPage::BackBtnClicked);
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
    ledConfirmPass =new QLineEdit(this);
    btnBack=new QPushButton(this);
    btnReset=new QPushButton(this);
    errorNumber=new QLabel(this);
}

void ResetPasswordPage::DesignWindow()
{
    setWindowTitle("Reset Password");
    layout->addWidget(ledUsername,1,0,1,3);
    layout->addWidget(ledNumber,3,0,1,3);
    layout->addWidget(ledPass,5,0,1,3);
    layout->addWidget(ledConfirmPass,7,0,1,3);
    layout->addWidget(errorNumber,8,0,2,2);
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
    /// confirm password line edit
    ledConfirmPass->setPlaceholderText("Repeat Password");
    ledConfirmPass->show();
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
}

ResetPasswordPage::~ResetPasswordPage()
{

}

void ResetPasswordPage::checkinfo()
{
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
    }



}

void ResetPasswordPage::BackBtnClicked()
{
    LogIn *login=new LogIn;
    login->show();
    this->close();
}

