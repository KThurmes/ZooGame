#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include "Exhibit.hpp"
#include "Animal.hpp"
#include <string>

using std::string;

class Collection{
    private:
        Exhibit* collect;
        int arraySize;
        int nExhibits;
        Animal* prototypes[4];

    public:
        Collection();
        int getnAnimals();
        double getAnimalFoodCost();
        int hayAdulto();
        void addExhibit();
        void resizeArray();
        void acquireAnimal(int, int);
        void animalsAge();
        int animalDies();
        int animalBirth();
        void freeTheAnimals();
        double animalPayoff();
        int getnTigers();
        string animalName(int);
        void showCollection();
        Animal* getPrototype(int);
          
};

#endif