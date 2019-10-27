/********************************************************************* 
** Author: Katheen Thurmes
** Date: 27 Oct., 2019
** Description: 
*********************************************************************/
#ifndef NEWCRITTER_HPP
#define NEWCRITTER_HPP

#include "Animal.hpp"

class NewCritter : public Animal
{
private:
    double foodCost;
    string name;

public:
    NewCritter(int years);
    string getName();
    double getFoodCost();
    ~NewCritter(){};
};

#endif