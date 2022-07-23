#ifndef COOPFEE_H
#define COOPFEE_H


#include "property.h"
#include <string>
class Player; // Forward
//  virtual void applyRule(Player *p) = 0;
// virtual std::string getName();
class CoOp : public Property {

    public:
        CoOp();
        void applyRule(Player *p) override;
        std::string getName() override;
};

#endif
