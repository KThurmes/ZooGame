#ifndef EXHIBIT_HPP
#define EXHIBIT_HPP

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"

class Exhibit{
    private:
        int nAnimals;
        int arraySize;
        Animal* exhib;
        void resizeArray();

    public:
        Exhibit();
        void animalDies(int index);
        void animalDies();
        void acquireAnimal(Animal&);
        void viewExhibit();
        void freeTheAnimals();
        void animalsAge();
        double animalFoodCost();
        double animalPayoff();
        int hayAdulto();
        int getnAnimals();
        void animalBirth();
        Animal getAnimal(int);

};

#endif