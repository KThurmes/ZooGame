/********************************************************************* 
** Author: Katheen Thurmes
** Date: 27 Oct., 2019
** Description: Tiger.cpp describes a parent class of animals. The 
homework assignment constrained the data members to a very specific 
set. This class represents a generic animal that can be found at the 
zoo and child classes represent the different species.
All animals have an age, a cost of buying an adult instance of that 
animal, the number of babies that the animal has at a time, a food 
cost that is dependent on the "baseFoodCost" and an amount of money 
(payoff) that the animal makes for the zoo each day.
*********************************************************************/

#include "Tiger.hpp"

string Tiger::getName()
{
    return "tiger";
}