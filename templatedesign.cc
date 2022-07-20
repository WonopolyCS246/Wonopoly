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


/* Extra:==>
void Slc :: applyRule(Player *p ){
    std::string Val = Rule(this->random());
    p->setPreviousPosition(p->getPosition());
    if (Val == "Back3"){
        p->setPosition(p->getPosition() - 3);
    } else if (Val == "Back2") {
        p->setPosition(p->getPosition() - 2);
    } else if (Val == "Back1") {
        p->setPosition(p->getPosition() - 1);
    } else if (Val == "Forward1"){
        p->setPosition(p->getPosition() + 1);
    } else if (Val == "Forward2"){
        p->setPosition(p->getPosition() + 2);
    } else if (Val ==  "Forward3"){
        p->setPosition(p->getPosition() + 3);
    } else if (Val ==  "GoToDC"){
        // TO-DO: Sent to TIMS on the grid
        p->setAtTims(true);
        p->setPosition(10);
    } else if (Val == "OASP"){
        // TO-DO: Sent to TIMS on the grid
        p->setPosition(0);
    } else {
        std::cout << "Problem with apply rule SLC" << std::endl;
        // Just in Case
    }
}

void Nhall :: applyRule(Player *p ){
    std::string Val = Rule(this->random());
    if (Val == "neg200"){
        p->addAssets(-200);
    } else if (Val == "neg100") {
        p->addAssets(-100);
    } else if (Val == "neg50") {
        p->addAssets(-50);
    } else if (Val == "pos25"){
        p->addAssets(25);
    } else if (Val == "pos50"){
        p->addAssets(50);
    } else if (Val ==  "pos100"){
        p->addAssets(100);
    } else if (Val ==  "pos200"){
        p->addAssets(200);
    } else {
        // Just in Case
        std::cout << "Problem with apply rule Needles Hall" << std::endl;
    }
}

std::string Slc :: Rule(float compare) {
    float Back3 = 1/8;
    float Back2 = Back3 + 1/6; 
    float Back1 = Back2 + 1/6;
    float Forward1 = Back1 + 1/8;
    float Forward2 = Forward1 + 1/6;
    float Forward3 = Forward2 + 1/6;
    float GoToDC = Forward3 + 1/24;
    float CollectOSAP = GoToDC + 1/24;
    if (compare <= Back3){
        return "Back3";
    }
    if (compare <= Back2){
        return "Back2";
    }
    if (compare <= Back1){
        return "Back1";
    }
    if (compare <= Forward1){
        return "Forward1";
    }
    if (compare <= Forward2){
        return "Forward2";
    }
    if (compare <= Forward3){
        return "Forward3";
    }
    if (compare <= GoToDC){
        return "GoToDC";
    }
    return "OASP";
}


std::string Nhall :: Rule(float compare) {
    float neg200 = 1/18;
    float neg100 = neg200 + 1/9;
    float neg50 = neg100 + 1/6;
    float pos25 = neg100 + 1/3;
    float pos50 = pos25 + 1/6;
    float pos100 = pos50 + 1/9;
    float pos200 = pos100 + 1/18;
    if (compare <= neg200){
        return "neg200";
    }
    if (compare <= neg100){
        return "neg100";
    }
    if (compare <= neg50){
        return "neg100";
    }
    if (compare <= pos25){
        return "pos25";
    }
    if (compare <= pos50){
        return "pos50";
    }
    if (compare <= pos100){
        return "pos100";
    }
    return "pos200";
}
*/

