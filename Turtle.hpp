#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "Animal.hpp"

class Turtle:public Animal{
    private:
        double foodCost;

    public:
    Turtle(int years){
        cost = 100;
        foodCost = 0.5 * baseFoodCost;
        nBabies = 10;
        payoff = 0.05 * cost;
        age = years;
    }
    string getName();
    double getFoodCost(){
        return baseFoodCost * .5;
    }
    ~Turtle(){};
};

#endif