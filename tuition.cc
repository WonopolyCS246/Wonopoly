#include "tuition.h"
#include "player.h"
#include "errorclass.h"

/*
Tuition();
void applyRule(Player *p) override;
std::string getName() override;
*/

Tuition::Tuition(int position) {
    Property::position = position;
}

void Tuition::applyRule(Player *p) {
    throw NoTuition{};
}

std::string Tuition::getName() {
    return "Tuition";
}