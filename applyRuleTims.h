#include <iostream>
#include "player.h"
#include "roll2die.h"
enum Chances {rollDouble, pay50, rollUp};


void takingInput(Player *p){
    int k = 3;
    if (p->getRUTR())
    {
        k = 2;
    }
    while (true)
    {
        for (int i = 0; i < k; ++i)
        {
            if (i == 0)
            {
                std::cout << "1. Roll a double die" << std::endl;
            }
            else if (i == 1)
            {
                std::cout << "2. Pay 50 dollars" << std::endl;
            }
            else if (i == 2)
            {
                std::cout << "3. Roll Up" << std::endl;
            }
            else 
            {
                continue;
            }
        }
        int input;
        std::cin >> input;
        if (input == 0)
        {
            applyRuleTims(p, Chances::rollDouble);
            break;
        }
        else if (input == 1)
        {
            applyRuleTims(p, Chances::pay50);
            break;
        }
        else if (input == k-1)
        {
            applyRuleTims(p, Chances::rollUp);
            break;
        }
        else 
        {
            std::cout << "Invalid Input" << std::endl;
            continue;
        }
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
        } 
        else 
        {
            std::cout << "Better Luck Next Time : P" << std::endl;
            p->setTurnsAtTims(p->getTurnsAtTims() + 1);
        }
        if (p->getTurnsAtTims() == 3)
        {
            int k = 2;
            if (p->getRUTR())
            {
                k = 1;
            }
            while (true)
            {
                for (int i = 0; i < k; ++i)
                {
                    if (i == 0)
                    {
                        std::cout << "1. Pay 50 dollars" << std::endl;
                    }
                    else if (i == 1)
                    {
                        std::cout << "2. Roll Up " << std::endl;
                    }
                }
                int input;
                std::cin >> input;
                if (input == 0)
                {
                    applyRuleTims(p, Chances::pay50);
                    break;
                }
                else if (input == k-1)
                {
                    applyRuleTims(p, Chances::rollUp);
                    break;
                }
                else 
                {
                    std::cout << "Invalid Input" << std::endl;
                    continue;
                }
            }
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


