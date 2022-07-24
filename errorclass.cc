#include "errorclass.h"


NoRent::NoRent(int rent){
        this->rent = rent;
}

int NoRent::getRent(){
        return rent;
}


NotMortgage::NotMortgage(double amount){
        this->amount = amount;
}

double NotMortgage::getAmount(){
    return amount;
}

IllegalMove::IllegalMove(){
    std::cout << "This is an illegal move." << std::endl;
}


NotMonopoly::NotMonopoly(){
    std::cout << "You do not own all of the properties in this set." << std::endl;
}

MaxImprovements::MaxImprovements(){
    std::cout << "You cannot improve this property anymore" << std::endl;
}

MinImprovements::MinImprovements(){
    std::cout << "You must improve this property at least once" << std::endl;
}


