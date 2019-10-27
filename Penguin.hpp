/********************************************************************* 
** Author: Katheen Thurmes
** Date: 27 Oct., 2019
** Description: Penguin.hpp describes a child class of the parent 
class Animal. This class represents a Tiger that can be found at the 
zoo.
All animals have an age, a cost of buying an adult instance of that 
animal, the number of babies that the animal has at a time, a food 
cost that is dependent on the "baseFoodCost" and an amount of money 
(payoff) that the animal makes for the zoo each day.
*********************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include "Animal.hpp"

class Penguin : public Animal
{

private:
public:
    Penguin(int years)
    {
        age = years;
        cost = 1000;
        nBabies = 5;
        payoff = 0.1 * cost;
    }
    string getName();
    double getFoodCost()
    {
        return baseFoodCost;
    }
    ~Penguin(){};
};
#endif