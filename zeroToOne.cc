#include "zeroToOne.h"




float zeroToOne(){
    std::vector<float> list;
    for (int i = 0; i< 101; i++){
        list.emplace_back(i);
    }
    std::vector<int> index;
    for (int i = 0; i< 100; i++){
        index.emplace_back(i);
    }
    unsigned seed = 
std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};


    std::shuffle( list.begin(), list.end(), rng );
    std::shuffle( index.begin(), index.end(), rng );
    return list[index[0]]/100;

}


