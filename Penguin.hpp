#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include "Animal.hpp"

class Penguin : public Animal{

private:
    static double cost;
public:

    Penguin(int years){
        foodCost = baseFoodCost;
        nBabies = 5;
        payoff = 0.1 * cost;
        age = years;
    }

    static double getCost();
};
#endif