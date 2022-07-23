#include "goToDcTims.h"
#include "player.h"
#include "errorclass.h"

void goToDcTims :: addOwner(Player *p){
    // This Should be empty
    throw IllegalMove();
}

bool goToDcTims :: isNewOwnable(){
    return false;
}

Player * goToDcTims :: getOwner() {
    return nullptr;
}

void goToDcTims :: applyRule(Player *p) {
    // AND Codn
    /*
    * 
    * When a player lands on the Go To Tims square, 
    * they are moved to the DC Tims Line square. 
    * They do not collect the $200 from Collect OSAP.
    * 
    */
    p->setPreviousPosition(p->getPosition());
    p->setAtTims(true);
    p->setPosition(10);

}

