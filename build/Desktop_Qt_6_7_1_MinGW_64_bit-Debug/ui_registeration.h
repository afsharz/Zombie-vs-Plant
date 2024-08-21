/********************************************************************************
** Form generated from reading UI file 'registeration.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERATION_H
#define UI_REGISTERATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_registeration
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_8;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *registeration)
    {
        if (registeration->objectName().isEmpty())
            registeration->setObjectName("registeration");
        registeration->resize(958, 540);
        registeration->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(122, 122, 122);"));
        label = new QLabel(registeration);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 961, 541));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Black")});
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/R.jfif);"));
        label_2 = new QLabel(registeration);
        label_2->setObjectName("label_2");
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(200, 17, 161, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("B Compset")});
        font1.setPointSize(20);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setFrameShadow(QFrame::Plain);
        label_2->setLineWidth(1);
        label_2->setMidLineWidth(0);
        label_2->setTextFormat(Qt::PlainText);
        label_2->setScaledContents(false);
        label_2->setWordWrap(false);
        label_2->setIndent(-1);
        label_2->setOpenExternalLinks(false);
        lineEdit = new QLineEdit(registeration);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(210, 77, 401, 41));
        QFont font2;
        font2.setPointSize(11);
        lineEdit->setFont(font2);
        lineEdit->setCursor(QCursor(Qt::IBeamCursor));
        lineEdit->setToolTipDuration(-1);
        lineEdit->setStyleSheet(QString::fromUtf8(""));
        lineEdit->setFrame(false);
        lineEdit_3 = new QLineEdit(registeration);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(210, 147, 401, 41));
        lineEdit_3->setFont(font2);
        lineEdit_3->setFrame(false);
        lineEdit_4 = new QLineEdit(registeration);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(210, 217, 401, 41));
        lineEdit_4->setFont(font2);
        lineEdit_4->setStyleSheet(QString::fromUtf8(""));
        lineEdit_4->setFrame(false);
        lineEdit_5 = new QLineEdit(registeration);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(210, 290, 401, 41));
        lineEdit_5->setFont(font2);
        lineEdit_5->setFrame(false);
        lineEdit_5->setEchoMode(QLineEdit::Password);
        label_8 = new QLabel(registeration);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(210, 47, 281, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("B Compset")});
        font3.setPointSize(11);
        font3.setBold(true);
        label_8->setFont(font3);
        lineEdit_6 = new QLineEdit(registeration);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(210, 360, 401, 41));
        lineEdit_6->setFont(font2);
        lineEdit_6->setStyleSheet(QString::fromUtf8(""));
        lineEdit_6->setFrame(false);
        lineEdit_6->setEchoMode(QLineEdit::Normal);
        pushButton_3 = new QPushButton(registeration);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(940, 360, 20, 20));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("B Compset")});
        font4.setPointSize(14);
        font4.setBold(true);
        pushButton_3->setFont(font4);
        pushButton_4 = new QPushButton(registeration);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(540, 420, 71, 31));
        pushButton_4->setFont(font4);

        retranslateUi(registeration);

        QMetaObject::connectSlotsByName(registeration);
    } // setupUi

    void retranslateUi(QDialog *registeration)
    {
        registeration->setWindowTitle(QCoreApplication::translate("registeration", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("registeration", "  Register", nullptr));
#if QT_CONFIG(statustip)
        lineEdit->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        label_8->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("registeration", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registeration: public Ui_registeration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERATION_H
