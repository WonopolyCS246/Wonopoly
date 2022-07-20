#include "slcRandom.h"

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


