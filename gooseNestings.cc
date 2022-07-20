#include "gooseNestings.h"
#include <iostream>

void gooseNestings :: addOwner(Player *p){
    // This Should be empty
}

bool gooseNestings :: isNewOwnable(){
    return false;
}

Player * gooseNestings ::getOwner() {
    return nullptr;
}

void gooseNestings :: applyRule(Player *p) {
    std::cout << "Goose Attack!" << std::endl;
}


