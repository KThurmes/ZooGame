#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include "Exhibit.hpp"
#include "Animal.hpp"


class Collection{
    private:
        Exhibit* collect;
        int arraySize;
        int nExhibits;

    public:
        Collection();
        int getnAnimals();
        double getAnimalFoodCost();
        int hayAdulto();
        void addExhibit();
        void resizeArray();
        void acquireAnimal(int, int);
        void animalsAge();
        bool animalDies();
        bool animalBirth();
        void freeTheAnimals();
        double animalPayoff();
        int getnTigers();
        
        
        
};

#endif