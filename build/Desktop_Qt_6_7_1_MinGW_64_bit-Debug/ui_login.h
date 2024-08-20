/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LogIn
{
public:
    QLineEdit *lineEdit;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pushButton_4;

    void setupUi(QDialog *LogIn)
    {
        if (LogIn->objectName().isEmpty())
            LogIn->setObjectName("LogIn");
        LogIn->resize(936, 529);
        LogIn->setStyleSheet(QString::fromUtf8("background-color: rgb(122, 122, 122);"));
        lineEdit = new QLineEdit(LogIn);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(210, 112, 391, 41));
        QFont font;
        font.setPointSize(11);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8(""));
        lineEdit->setFrame(false);
        label_8 = new QLabel(LogIn);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(210, 81, 271, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        label_8->setFont(font1);
        label = new QLabel(LogIn);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 941, 531));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI Black")});
        font2.setBold(true);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/R.jfif);"));
        label_7 = new QLabel(LogIn);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(210, 212, 261, 16));
        label_7->setFont(font1);
        label_9 = new QLabel(LogIn);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(210, 80, 191, 31));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(true);
        label_9->setFont(font3);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);"));
        label_2 = new QLabel(LogIn);
        label_2->setObjectName("label_2");
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(190, 50, 161, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("B Compset")});
        font4.setPointSize(20);
        font4.setBold(true);
        label_2->setFont(font4);
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setFrameShadow(QFrame::Plain);
        label_2->setLineWidth(1);
        label_2->setMidLineWidth(0);
        label_2->setTextFormat(Qt::PlainText);
        label_2->setScaledContents(false);
        label_2->setWordWrap(false);
        label_2->setIndent(-1);
        label_2->setOpenExternalLinks(false);
        pushButton_3 = new QPushButton(LogIn);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(920, 330, 20, 20));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("B Compset")});
        font5.setPointSize(14);
        font5.setBold(true);
        pushButton_3->setFont(font5);
        lineEdit_2 = new QLineEdit(LogIn);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(210, 172, 391, 41));
        lineEdit_2->setFont(font);
        lineEdit_2->setFrame(false);
        lineEdit_2->setEchoMode(QLineEdit::Password);
        pushButton_2 = new QPushButton(LogIn);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 260, 151, 24));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("B Compset")});
        font6.setPointSize(9);
        font6.setBold(true);
        pushButton_2->setFont(font6);
        label_5 = new QLabel(LogIn);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(230, 240, 201, 16));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("B Compset")});
        font7.setBold(true);
        label_5->setFont(font7);
        pushButton = new QPushButton(LogIn);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(380, 230, 71, 31));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("B Compset")});
        font8.setPointSize(11);
        font8.setBold(true);
        pushButton->setFont(font8);
        pushButton_4 = new QPushButton(LogIn);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(550, 260, 71, 24));
        pushButton_4->setFont(font5);

        retranslateUi(LogIn);

        QMetaObject::connectSlotsByName(LogIn);
    } // setupUi

    void retranslateUi(QDialog *LogIn)
    {
        LogIn->setWindowTitle(QCoreApplication::translate("LogIn", "Dialog", nullptr));
        lineEdit->setText(QString());
        label_8->setText(QString());
        label->setText(QString());
        label_7->setText(QString());
        label_9->setText(QString());
        label_2->setText(QCoreApplication::translate("LogIn", "    Log In", nullptr));
        pushButton_3->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("LogIn", "Forgot my password", nullptr));
        label_5->setText(QCoreApplication::translate("LogIn", "Don't you have an acount?", nullptr));
        pushButton->setText(QCoreApplication::translate("LogIn", "create", nullptr));
        pushButton_4->setText(QCoreApplication::translate("LogIn", "log in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogIn: public Ui_LogIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
