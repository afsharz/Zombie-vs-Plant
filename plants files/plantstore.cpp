#include "plantstore.h"

PlantStore::PlantStore(QGraphicsScene *scene , Wallet* _wallet)
    :scene(scene) , wallet(_wallet)
{

    peashooter = new Card(scene, "PeaShooter");
    two_peashooter = new Card(scene, "TwoPeashooter");
    walnut = new Card(scene, "Walnut");
    jalapeno = new Card(scene, "Jalapeno");
    boomerang = new Card(scene, "Boomerang");
    plumMine = new Card(scene, "PlumMine");

    two_peashooter->setPixmap(QPixmap(":/new/prefix1/two_peashooter-black.jpg"));
    two_peashooter->setPos(0,-120);
    two_peashooter->setScale(0.1);

    peashooter->setPixmap(QPixmap(":/new/prefix1/pea-shooter-black.jpg"));
    peashooter->setPos(0,-225);
    peashooter->setScale(0.1);

    walnut->setPixmap(QPixmap(":/new/prefix1/walnut-black.jpg"));
    walnut->setPos(110,-225);
    walnut->setScale(0.1);

    jalapeno->setPixmap(QPixmap(":/new/prefix1/jalapino-black.jpg"));
    jalapeno->setPos(110,-120);
    jalapeno->setScale(0.1);

    boomerang->setPixmap(QPixmap(":/new/prefix1/boomerang-black.jpg"));
    boomerang->setPos(220,-225);
    boomerang->setScale(0.292);

    plumMine->setPixmap(QPixmap(":/new/prefix1/plum-mine-black.jpg"));
    plumMine->setPos(220,-120);
    plumMine->setScale(0.1);

    QVector<Card*> QPlants;
    QPlants.push_back(peashooter);
    QPlants.push_back(two_peashooter);
    QPlants.push_back(walnut);
    QPlants.push_back(jalapeno);
    QPlants.push_back(boomerang);
    QPlants.push_back(plumMine);
    wallet->Set_QVec(QPlants);

}
