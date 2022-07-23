#include "tuition.h"
#include "player.h"
#include "errorclass.h"

/*
Tuition();
void applyRule(Player *p) override;
std::string getName() override;
*/

Tuition::Tuition() {

}

void Tuition::applyRule(Player *p) {
    throw Tuition{};
}

std::string Tuition::getName() {
    return "Tuition";
}