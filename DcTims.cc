#include "DcTims.h"
#include "errorclass.h"
//#include "applyRuleTims.h"

void DcTims :: addOwner(Player *p){
    // This Should be empty
    throw IllegalMove();
}

bool DcTims :: isNewOwnable(){
    return false;
}

Player * DcTims :: getOwner() {
    return nullptr;
}

void DcTims :: applyRule(Player *p) {
    std::cout << "Enjoy your coffee at Tim Hortons" << std::endl;
}
