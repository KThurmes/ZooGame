#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger:public Animal{
    private:
        double foodCost;
    public:
        Tiger(int years){
            age = years;
            cost = 10000;
            foodCost = baseFoodCost * 5;
            nBabies = 1;
            payoff = 0.2 * cost;
        }
        string getName();
        double getFoodCost(){
            return foodCost;
        };
        ~Tiger(){};
};
#endif