#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger:public Animal{
    private:
    static double cost;
    static int nBabies;
    public:

        Tiger(int years){
            foodCost = baseFoodCost * 5;
            //nBabies = 1;
            payoff = 0.2 * cost;
            age = years;
        }

        static double getCost();
        static int getnBabies();
};
#endif