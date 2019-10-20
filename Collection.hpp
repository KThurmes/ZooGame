#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"

class Collection{
    private:
        int nAnimals;
        int arraySize;
        Animal* collect;
        void resizeArray();

    public:
        Collection();
        void animalDies(int index);
        void acquireAnimal(Animal);
        void viewCollection();
        void freeTheAnimals();
        void animalsAge();
        double animalFoodCost();
        double animalPayoff();
        bool hayAdulto();
        int getnAnimals();


};

#endif