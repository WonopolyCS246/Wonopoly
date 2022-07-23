#include "CoOpfee.h"
#include "player.h"
#include "errorclass.h"

/*
CoOp();
void applyRule(Player *p) override;
std::string getName() override;
*/

void CoOp :: applyRule(Player *p){
    if (p->getAssets >= 150){
        p->setAssets(p->getAssets()-150);
    } else {
        throw CoOp();
    }
}

std::string CoOp::getName() {
    return "Coop Fee";
}

