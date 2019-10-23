#include "Exhibit.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"
#include <iostream>

using std::endl;
using std::cout;

Exhibit::Exhibit(){
    nAnimals = 0;
    arraySize = 10;
    exhib = new Animal*[arraySize];
}

void Exhibit::resizeArray(){
    
    int newSize = arraySize * 2;

    //Create new array with double capacity
    Animal** newExhib = new Animal*[newSize];
    
    //Copy all animals into it
    for (int i = 0; i < nAnimals; i++){
        newExhib[i] = exhib[i];
    }

    //Delete the array exhib used to point to
    delete[] exhib;

    //Reassign exhib pointer to point to new array
    exhib = newExhib;
    arraySize = newSize;
}

void Exhibit::animalDies(int index){

    //Overwrite dead animal by copying last animal in array into the space of the one that died
    if (nAnimals > 1){
        delete exhib[index];
        exhib[index] = exhib[nAnimals-1];
    }

    //Don't resize

    //Decrement number of animals
    nAnimals --;
}

void Exhibit::animalDies(){
    srand(time(NULL));
    int nRand = (rand() % nAnimals);
    animalDies(nRand);    
}

void Exhibit::acquireAnimal(Animal* newGuy){
    if (nAnimals == arraySize){
        resizeArray();
    }

    //Copy the new animal into nAnimals index of array.
    exhib[nAnimals] = newGuy;
    nAnimals++;
}

void Exhibit::viewExhibit(){
    cout << nAnimals << " animals in Exhibit.\n";
    cout << "Array of size " << arraySize << endl;;
    Animal* steve;
    for (int i = 0; i < nAnimals; i++){
        steve = exhib[i];
        cout << "Animal " << i+1 << ":"<< endl;
        cout << "Age: " << steve->getAge() << endl;
    }
}

void Exhibit::freeTheAnimals(){
    for(int i = 0 ; i < nAnimals; i++){
        delete exhib[i];
    }
    delete[] exhib;
}

void Exhibit::animalsAge(){
    for (int i = 0 ; i < nAnimals; i++){
        exhib[i]->ageOneDay();
    }
}

double Exhibit::animalFoodCost(){
    double runningTotal = 0;
    for (int i = 0 ; i < nAnimals; i++){
        runningTotal += exhib[i]->getFoodCost();
    }
    return runningTotal;
}

double Exhibit::animalPayoff(){
    double runningTotal = 0;
    for(int i = 0; i < nAnimals; i++){
        runningTotal += exhib[i]->getPayoff();
    }
    return runningTotal;
}

int Exhibit::hayAdulto(){
    int adult = 0;
    for (int i = 0; i < nAnimals; i++){
        if (exhib[i]->isAdult()){
            adult++;
        }
    }
    return adult;
}

int Exhibit::getnAnimals(){
    return nAnimals;
}

Animal* Exhibit::getAnimal(int index){
    return exhib[index];
}