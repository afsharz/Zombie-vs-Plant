QT       += core gui network

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
    card.cpp \
    client.cpp \
    gameresult.cpp \
    home.cpp \
    jalapeno.cpp \
    leafheadzombie.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    peashooter.cpp \
    plant.cpp \
    plantscene.cpp \
    plantstore.cpp \
    player.cpp \
    plummine.cpp \
    purplehairzombie.cpp \
    registeration.cpp \
    regularzombie.cpp \
    resetpasswordpage.cpp \
    sun.cpp \
    tallzombie.cpp \
    two_peashooter.cpp \
    userinfo.cpp \
    wallet.cpp \
    walnut.cpp \
    zombie.cpp \
    zombiescene.cpp \
    zombiestore.cpp

HEADERS += \
    astronautzombie.h \
    boomerang.h \
    brain.h \
    bucketheadzombie.h \
    bullet.h \
    card.h \
    client.h \
    gameresult.h \
    home.h \
    jalapeno.h \
    leafheadzombie.h \
    login.h \
    mainwindow.h \
    menu.h \
    peashooter.h \
    plant.h \
    plantscene.h \
    plantstore.h \
    player.h \
    plummine.h \
    purplehairzombie.h \
    registeration.h \
    regularzombie.h \
    resetpasswordpage.h \
    sun.h \
    tallzombie.h \
    two_peashooter.h \
    userinfo.h \
    wallet.h \
    walnut.h \
    zombie.h \
    zombiescene.h \
    zombiestore.h

FORMS += \
    login.ui \
    mainwindow.ui \
    registeration.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagee.qrc \
    pic.qrc

DISTFILES += \
    IMG_20240709_125814_689.jpg \
    pea.png
