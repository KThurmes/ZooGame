/* Description: a Collection object represents a gouping of exhibits. Each of the exhibits contains an array of pointers to animals. Each of the exhibits contains only one type of animal. The class contains a data member to hold the exhibits, an int that represents the number of exhibits, an int that represents the capacity of the array holding the exhibits, and an array of animals that represent a "prototype" animal of each species that can be accessed even when there are no instances of that animal present int he zoo.

*/
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