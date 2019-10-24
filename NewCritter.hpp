#ifndef NEWCRITTER_HPP
#define NEWCRITTER_HPP 

#include "Animal.hpp"

class NewCritter: public Animal{
    private:
        double foodCost;
    public:
        NewCritter();
};

#endif