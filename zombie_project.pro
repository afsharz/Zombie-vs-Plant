QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    astronautzombie.cpp \
    bucketheadzombie.cpp \
    leafheadzombie.cpp \
    main.cpp \
    mainwindow.cpp \
    purplehairzombie.cpp \
    registeration.cpp \
    regularzombie.cpp \
    tallzombie.cpp \
    userinfo.cpp \
    zombie.cpp

HEADERS += \
    astronautzombie.h \
    bucketheadzombie.h \
    leafheadzombie.h \
    mainwindow.h \
    purplehairzombie.h \
    registeration.h \
    regularzombie.h \
    tallzombie.h \
    userinfo.h \
    zombie.h

FORMS += \
    mainwindow.ui \
    registeration.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagee.qrc \
    pic.qrc
