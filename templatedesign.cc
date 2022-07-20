#include "templatedesign.h"

Player* templateDesign :: getOwner(){
    return nullptr;
}

void templateDesign :: addOwner(Player *p){
    return;
}

bool templateDesign ::isNewOwnable(){
    return false;
 }

unsigned templateDesign :: random(){
    return seed();
}

void Slc :: applyRule(Player *p ){
    p->setPreviousPosition(p->getPosition());
    SLC_Cases Case = SLC_Card_Generator(this->random());
    switch (Case)
    {
    case B3:
        //std::cout << "B3" << std::endl;
        p->setPosition(p->getPosition() - 3);
        break;
    case B2:
        //std::cout << "B2" << std::endl;
        p->setPosition(p->getPosition() - 2);
        break;
    case B1:
        //std::cout << "B1" << std::endl;
        p->setPosition(p->getPosition() - 1);
        break;
    case F3:
        //std::cout << "F3" << std::endl;
        p->setPosition(p->getPosition() + 3);
        break;
    case F2:
        //std::cout << "F2" << std::endl;
        p->setPosition(p->getPosition() + 2);
        break;
    case F1:
        //std::cout << "F1" << std::endl;
        p->setPosition(p->getPosition() + 1);
        break;
    case DC:
        //std::cout << "DC" << std::endl;
        p->setAtTims(true);
        p->setPosition(10);
        break;
    case OSAP:
        //std::cout << "OSAP" << std::endl;
        p->setPosition(0);
        break;
    default:
        break;
    }
}

void Nhall :: applyRule(Player *p ){
    p->setPreviousPosition(p->getPosition());
    NH_Cases Case = NHall_Card_Generator(this->random());
    switch (Case)
    {
    case N200:
        //std::cout << "N200" << std::endl;
        p->addAssets(-200);
        break;
    case N100:
        //std::cout << "N100" << std::endl;
        p->addAssets(-100);
        break;
    case N50:
        //std::cout << "N50" << std::endl;
        p->addAssets(-50);
        break;
    case P25:
        //std::cout << "P25" << std::endl;
        p->addAssets(25);
        break;
    case P50:
        //std::cout << "P50" << std::endl;
        p->addAssets(50);
        break;
    case P100:
        //std::cout << "P100" << std::endl;
        p->addAssets(100);
        break;
    case P200:
        //std::cout << "P200" << std::endl;
        p->addAssets(200);
        break;
    default:
        break;
    }
}


