#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

enum NH_Cases {N200,N100,N50,P25,P50,P100,P200};
std::vector<NH_Cases> NH_DECK{};

NH_Cases NHall_Card_Generator(unsigned seed);