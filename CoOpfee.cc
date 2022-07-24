#include "CoOpfee.h"
#include "player.h"
#include "errorclass.h"

/*
CoOp();
void applyRule(Player *p) override;
std::string getName() override;
*/

CoOp::CoOp(int position) {
    Property::position = position;
}

void CoOp :: applyRule(Player *p){
    if (p->getAssets() >= 150){
        p->setAssets(p->getAssets()-150);
    } else {
        throw NoCoOp();
    }
}

std::string CoOp::getName() {
    return "Coop Fee";
}

