/********************************************************************* 
** Author: Katheen Thurmes
** Date: 27 Oct., 2019
** Description: Tiger.hpp describes a child class of the parent class 
Animal. This class represents a Tiger that can be found at the zoo.
All animals have an age, a cost of buying an adult instance of that 
animal, the number of babies that the animal has at a time, a food 
cost that is dependent on the "baseFoodCost" and an amount of money 
(payoff) that the animal makes for the zoo each day.
*********************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP
#include "Animal.hpp"

class Tiger : public Animal
{
private:
    double foodCost;

public:
    Tiger(int years)
    {
        age = years;
        cost = 10000;
        foodCost = baseFoodCost * 5;
        nBabies = 1;
        payoff = 0.2 * cost;
    }
    string getName();
    double getFoodCost()
    {
        return foodCost;
    };
    ~Tiger(){};
};
#endif