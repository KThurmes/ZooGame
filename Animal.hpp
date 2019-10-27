/********************************************************************* 
** Author: Katheen Thurmes
** Date: 27 Oct., 2019
** Description: Animal.hpp describes a parent class of animals. The 
homework assignment constrained the data members to a very specific 
set. This class represents a generic animal that can be found at the 
zoo and child classes represent the different species. 

All animals have an age, a cost of buying an adult instance of that 
animal, the number of babies that the animal has at a time, a food 
cost that is dependent on the "baseFoodCost" and an amount of money 
(payoff) that the animal makes for the zoo each day.
*********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
using std::string;

class Animal
{
protected:
    int age;
    double cost;
    int nBabies;
    static double baseFoodCost;
    double payoff;

public:
    virtual string getName()
    {
        return "animal";
    };
    Animal()
    {
        age = -1;
        nBabies = 0;
        baseFoodCost = 10;
        payoff = 0;
    }
    void ageOneDay()
    {
        age++;
    }

    bool isAdult();

    int getAge()
    {
        return age;
    }

    double getPayoff()
    {
        return payoff;
    }
    int getnBabies()
    {
        return nBabies;
    }
    double getCost()
    {
        return cost;
    }

    virtual double getFoodCost()
    {
        return baseFoodCost;
    }
    virtual ~Animal(){};
};

#endif