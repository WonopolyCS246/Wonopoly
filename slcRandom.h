#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

enum SLC_Cases {B3,B2,B1,F1,F2,F3,DC,OSAP};
std::vector<SLC_Cases> SLC_DECK{};

SLC_Cases SLC_Card_Generator(unsigned seed);


