#include "Animal.hpp"

double Animal::baseFoodCost = 10;

bool Animal::isAdult(){
    if (age < 3){
        return false;
    }
    else{
        return true;
    }
}