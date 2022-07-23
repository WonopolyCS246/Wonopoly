#ifndef TUITION_H
#define TUITION_H

#include "property.h"
#include <string>

class Player;

//  virtual void applyRule(Player *p) = 0;
// virtual std::string getName();

class Tuition : public Property {

    public:
    Tuition();
    void applyRule(Player *p) override;
    std::string getName() override;
};

#endif TUITION_H
