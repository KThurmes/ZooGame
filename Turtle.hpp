#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "Animal.hpp"

class Turtle:public Animal{
    private:
        static double cost;
        static int nBabies;

    public:
    Turtle(int years){
        foodCost = 0.5 * baseFoodCost;
        //nBabies = 10;
        payoff = 0.05 * cost;
        age = years;
    }
    static double getCost();
    static int getnBabies();

};

#endif