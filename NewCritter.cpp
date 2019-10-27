/********************************************************************* 
** Author: Katheen Thurmes
** Date: 27 Oct., 2019
** Description: 
*********************************************************************/
#include "NewCritter.hpp"
#include <string>
using std::string;


NewCritter::NewCritter(int years){
        age = years;
        cost = 10000;
        foodCost = baseFoodCost * 5;
        nBabies = 1;
        payoff = 0.2 * cost;
}

double NewCritter::NewCritter getFoodCost(){
    return foodCost;
}

string NewCritter::getName(){
    return name;
}