#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include "Animal.hpp"

class Penguin : public Animal{

private:

public:

    Penguin(int years){
        age = years;
        cost = 1000;

        nBabies = 5;
        payoff = 0.1 * cost;
    }
    string getName();
    double getFoodCost(){
        return baseFoodCost;
    }
    ~Penguin(){};
};
#endif