/*
Description: Turtle.hpp describes a child class of the parent class Animal. This class represents a Tiger that can be found at the zoo.
All animals have an age, a cost of buying an adult instance of that animal, the number of babies that the animal has at a time, a food cost that is dependent on the "baseFoodCost" and an amount of money (payoff) that the animal makes for the zoo each day.
*/

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