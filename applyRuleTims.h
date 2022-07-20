#include <iostream>
#include "player.h"
#include "roll2die.h"
enum Chances {rollDouble, pay50, rollUp};


void takingInput(Player *p){
    int i = 1;
    if (p->getRUTR()){

    }
}

void applyRuleTims(Player *p, Chances Case){
    std::vector v = roll2die();
    switch (Case)
    {
    case rollDouble:
        std::cout << "Player (name of the player) has to roll the die" << std::endl; 
        std::cout << "Rolling Dice" << std::endl;
        std::cout << "The die got ";
        for (int i = 0 ; i < 2; i++){
            std::cout << v[i] << "  "; 
        }
        std::cout << std::endl;
        if (v[0] == v[1]){
            p->setPreviousPosition(p->getPosition());
            p->setAtTims(false);
            // Function to Roll a die again for the player
        } else {
            std::cout << "Better Luck Next Time : P" << std::endl;
            p->setTurnsAtTims(p->getTurnsAtTims() + 1);
        }
        break;
    case pay50:
        std::cout << "Player (name of the player) pay 50 dollars" << std::endl; 
        p->setPreviousPosition(p->getPosition());
        p->setAtTims(false);
        // Function to Roll a die again for the player
        p->addAssets(-50);
        break;
    case rollUp:
        std::cout << "Player (name of the player) roll up the Rim" << std::endl; 
        p->setPreviousPosition(p->getPosition());
        p->setAtTims(false);
        // Function to Roll a die again for the player
        p->setRUTR(p->getRUTR() -1);
        break;
    default:
        break;
    }


    return;
}


