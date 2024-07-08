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
    layoutContainer->setGeometry(130,90,230,300);
    layout=new QGridLayout(layoutContainer);
    lblUsername=new QLabel(this);
    lblNumber=new QLabel(this);
    lblPass=new QLabel(this);
    lblConfirmPass=new QLabel(this);
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

    layout->addWidget(lblUsername,0,0);
    layout->addWidget(ledUsername,1,0,1,3);
    layout->addWidget(lblNumber,2,0);
    layout->addWidget(ledNumber,3,0,1,3);
    layout->addWidget(lblPass,4,0);
    layout->addWidget(ledPass,5,0,1,3);
    layout->addWidget(lblConfirmPass,6,0);
    layout->addWidget(ledConfirmPass,7,0,1,3);
    layout->addWidget(errorNumber,8,0,2,2);
    /// set background
    backgroundLabel->setScaledContents(true);
    backgroundLabel->setPixmap(QPixmap(":/new/prefix1/forgotpasswordBG.png"));
    backgroundLabel->setGeometry(this->rect());
    backgroundLabel->lower();
    setFixedSize(640,480);
    ///username label
    lblUsername->setText("Username");
    lblUsername->setStyleSheet("color: white;");
    lblUsername->setFont(QFont("Showcard Gothic",12,2,false));
    lblUsername->show();
    ///username lineedit
    ledUsername->setPlaceholderText("Enter Username");
    ledUsername->show();
    ///phone number label
    lblNumber->setText("Phone Number");
    lblNumber->setStyleSheet(("color: white;"));
        lblNumber->setFont(QFont("Showcard Gothic",12,2,false));
    lblNumber->show();
    ///phone number line edit
    ledNumber->setPlaceholderText("Enter phone number");
    ledNumber->show();
    ///new password label
    lblPass->setText("New Password");
    lblPass->setStyleSheet(("color: white;"));
        lblPass->setFont(QFont("Showcard Gothic",12,2,false));
    lblPass->show();
    ///new password line edit
    ledPass->setPlaceholderText("Enter Password");
    ledPass->show();
    ///confirm password label
    lblConfirmPass->setText("Confirm Password");
    lblConfirmPass->setStyleSheet(("color: white;"));
    lblConfirmPass->setFont(QFont("Showcard Gothic",12,2,false));
    lblConfirmPass->show();
    /// confirm password line edit
    ledConfirmPass->setPlaceholderText("Enter Password");
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
    btnReset->setGeometry(200,350,70,50);
    btnReset->setText("Reset");
    btnReset->setFont(QFont("Berlin Sans FB Demi",15,2,false));
    btnReset->setStyleSheet("color: white;");
    ///push button back

    btnBack->setFlat(true);
    btnBack->setStyleSheet("QPushButton { background-color: transparent; border: 0px; }");
    btnBack->setStyleSheet("color: black;");
    btnBack->setGeometry(500,350,70,50);
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

