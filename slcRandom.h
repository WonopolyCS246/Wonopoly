#ifndef SLCRANDOM
#define SLCRANDOM
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

enum SLC_Cases {B3,B2,B1,F1,F2,F3,DC,OSAP};
std::vector<SLC_Cases> SLC_DECK;

SLC_Cases SLC_Card_Generator(unsigned seed){
    if (SLC_DECK.size() == 0){
        for(int i = 0; i <  3;++i){
            SLC_DECK.emplace_back(SLC_Cases::F1);
            SLC_DECK.emplace_back(SLC_Cases::B3);
        }
        for(int i = 0; i <  4;++i){
            SLC_DECK.emplace_back(SLC_Cases::F2);
            SLC_DECK.emplace_back(SLC_Cases::F3);
            SLC_DECK.emplace_back(SLC_Cases::B2);
            SLC_DECK.emplace_back(SLC_Cases::B1);
        }
        SLC_DECK.emplace_back(SLC_Cases::DC);
        SLC_DECK.emplace_back(SLC_Cases::OSAP);
    }
    std::default_random_engine rng{seed};
    std::shuffle( SLC_DECK.begin(), SLC_DECK.end(), rng );
    SLC_Cases retval =  SLC_DECK.back();
    SLC_DECK.pop_back();
    return retval;
}

#endif

