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

float templateDesign :: random(){
    return zeroToOne();
}


float templateDesign :: random(){
    return zeroToOne();
}

void Slc :: applyRule(Player *p ){
    std::string Val = Rule(this->random());
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



