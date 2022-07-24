#include "roll2die.h"

std::vector<int> roll2die(){
    // Defining two vectors 
    // Dice rep the faces of die
    std::vector<int> Dice = { 1, 2, 3, 4, 5, 6 };
    // result vector which will be returned
    std::vector<int> result;
    // Using the epoch time as the seed for random engine
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine rng{seed};

	std::shuffle( Dice.begin(), Dice.end(), rng );
	result.emplace_back(Dice[0]);
    result.emplace_back(Dice[1]);
    return result;
}

