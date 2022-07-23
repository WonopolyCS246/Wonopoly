#include "start.h"
#include "player.h"

void Start::addOwner(Player *p){
    // This Should be empty
}

bool Start::isNewOwnable(){
    return false;
}

Player * Start::getOwner() {
    return nullptr;
}

void Start::applyRule(Player *p) {
    // AND Codn
    /*
    * 
    * When a player lands on the Go To Tims square, 
    * they are moved to the DC Tims Line square. 
    * They do not collect the $200 from Collect OSAP.
    * 
    */
    p->addAssets(200);
}
