#include "registeration.h"
#include "ui_registeration.h"

registeration::registeration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registeration)
{
    ui->setupUi(this);

    //These codes that are repeated are for the color and size and transparency of line edits, lebels and push bottons
    ui->label->setStyleSheet("QLabel {""background-color: rgba(0, 0, 0, 127);" "border-radius: 15px;" "border: none;" "}");
    ui->label_2->setFrameShape(QFrame::NoFrame);
    ui->label_2->setAttribute(Qt::WA_NoSystemBackground);
    ui->label_2->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_2->setStyleSheet("color: white;");

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
    ui->pushButton_3->setStyleSheet("color: white;");

    ui->label_9->stackUnder(ui->label);
    ui->label_10->stackUnder(ui->label);
    ui->label_11->stackUnder(ui->label);
    ui->label_12->stackUnder(ui->label);
    ui->label_13->stackUnder(ui->label);
    ui->label_14->stackUnder(ui->label);
    ui->label_15->stackUnder(ui->label);
}

registeration::~registeration()
{
    delete ui;
}

void registeration::on_pushButton_3_clicked()
{
    QString filename = ui->lineEdit_3->text() + ".txt";
    QFile userfile(filename);

    if(userfile.exists()){
        //if the file existed yet, it means that the uer has an account yet
        ui->label_8->setStyleSheet("color: red;");
        ui->label_8->setText(tr("There's still an account with this username"));
        return;
    }

    if(!userfile.open(QIODevice :: WriteOnly | QIODevice :: Append | QIODevice :: Text)){
        qDebug() << "File cannot be opened.";
        return;
    }
    QTextStream out(&userfile);

    QString name = ui->lineEdit->text();
    QString username = ui->lineEdit_3->text();
    QString mobile = ui->lineEdit_4->text();
    QString password = ui->lineEdit_5->text();
    QString address = ui->lineEdit_6->text();

    QByteArray bytes = QCryptographicHash :: hash(password.toUtf8() , QCryptographicHash :: Md4);
    QString digest = QString(bytes.toHex());


    out << name << "\n" <<username << "\n" << mobile <<"\n" << digest << "\n" << address << "\n";

    userfile.flush();
    userfile.close();
}

