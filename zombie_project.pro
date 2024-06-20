QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    astronautzombie.cpp \
    boomerang.cpp \
    brain.cpp \
    bucketheadzombie.cpp \
    bullet.cpp \
    jalapeno.cpp \
    leafheadzombie.cpp \
    main.cpp \
    mainwindow.cpp \
    peashooter.cpp \
    plant.cpp \
    plummine.cpp \
    purplehairzombie.cpp \
    registeration.cpp \
    regularzombie.cpp \
    sun.cpp \
    tallzombie.cpp \
    two_peashooter.cpp \
    userinfo.cpp \
    walnut.cpp \
    zombie.cpp

HEADERS += \
    astronautzombie.h \
    boomerang.h \
    brain.h \
    bucketheadzombie.h \
    bullet.h \
    jalapeno.h \
    leafheadzombie.h \
    mainwindow.h \
    peashooter.h \
    plant.h \
    plummine.h \
    purplehairzombie.h \
    registeration.h \
    regularzombie.h \
    sun.h \
    tallzombie.h \
    two_peashooter.h \
    userinfo.h \
    walnut.h \
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
