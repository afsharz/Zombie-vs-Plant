#include "zombiestore.h"

ZombieStore::ZombieStore(QGraphicsScene *scene , Wallet* _wallet ) : scene(scene) , wallet(_wallet){
    regularzombie=new Card(scene,"regularzombie");
    bucketheadzombie=new Card(scene,"bucketheadzombie");
    leafheadzombie=new Card(scene,"leafheadzombie");
    tallzombie=new Card(scene,"tallzombie");
    astronautzombie=new Card(scene,"astronautzombie");
    purplehairzombie=new Card(scene,"purplehairzombie");

    regularzombie->setPixmap(QPixmap(":/new/prefix1/regular-zombie-black.jpg"));
    regularzombie->setPos(750,-120);
    regularzombie->setScale(0.1);

    bucketheadzombie->setPixmap(QPixmap(":/new/prefix1/bucket-head-zombie-black.jpg"));
    bucketheadzombie->setPos(750,-225);
    bucketheadzombie->setScale(0.1);

    leafheadzombie->setPixmap(QPixmap(":/new/prefix1/leaf-hair-zombie-black.jpg"));
    leafheadzombie->setPos(860,-225);
    leafheadzombie->setScale(0.1);

    tallzombie->setPixmap(QPixmap(":/new/prefix1/tall-zombie-black.jpg"));
    tallzombie->setPos(860,-120);
    tallzombie->setScale(0.1);

    astronautzombie->setPixmap(QPixmap(":/new/prefix1/astronaut-zombie-black.jpg"));
    astronautzombie->setPos(970,-225);
    astronautzombie->setScale(0.1);

    purplehairzombie->setPixmap(QPixmap(":/new/prefix1/purple-hair-zombie-black.jpg"));
    purplehairzombie->setPos(970,-120);
    purplehairzombie->setScale(0.1);

    QVector<Card*> QZombies;
    QZombies.push_back(regularzombie);
    QZombies.push_back(bucketheadzombie);
    QZombies.push_back(leafheadzombie);
    QZombies.push_back(tallzombie);
    QZombies.push_back(astronautzombie);
    QZombies.push_back(purplehairzombie);

    wallet->Set_QVec(QZombies);
}

