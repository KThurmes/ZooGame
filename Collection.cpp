#include "Collection.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"
#include <iostream>

using std::endl;
using std::cout;

Collection::Collection(){
    nAnimals = 0;
    arraySize = 10;
    collect = new Animal[arraySize];
    
}

void Collection::resizeArray(){

    cout<< "Collection array is being resized!" <<endl;
    
    int newSize = arraySize * 2;

    //Create new array with double capacity
    Animal* newCollect = new Animal[newSize];
    
    //Copy all animals into it
    for (int i = 0; i < nAnimals; i++){
        newCollect[i] = collect[i];
    }

    //Delete the array collect used to point to
    delete[] collect;

    //Reassign collect pointer to point to new array
    collect = newCollect;
    arraySize = newSize;
}

void Collection::animalDies(int index){

    //Overwrite dead animal by copying last animal in array into the space of the one that died
    if (nAnimals > 1){
        collect[index] = collect[nAnimals-1];
    }

    //Don't resize

    //Decrement number of animals
    nAnimals --;
}

void Collection::animalDies(){
    srand(time(NULL));
    int nRand = (rand() % nAnimals);
    animalDies(nRand);    
}

void Collection::acquireAnimal(Animal newGuy){
    if (nAnimals == arraySize){
        resizeArray();
    }

    //Copy the new animal into nAnimals index of array.
    collect[nAnimals] = newGuy;

    nAnimals++;
}

void Collection::viewCollection(){
    cout << nAnimals << " animals in collection.\n";
    cout << "Array of size " << arraySize << endl;;
    Animal steve;
    for (int i = 0; i < nAnimals; i++){
        steve = collect[i];
        cout << "Animal " << i+1 << ":"<< endl;
        cout << "Age: " << steve.getAge() << endl;
    }
}

void Collection::freeTheAnimals(){
    delete[] collect;
}

void Collection::animalsAge(){
    for (int i = 0 ; i < nAnimals; i++){
        collect[i].ageOneDay();
    }
}

double Collection::animalFoodCost(){
    double runningTotal = 0;
    for (int i = 0 ; i < nAnimals; i++){
        runningTotal += collect[i].getFoodCost();
    }
    return runningTotal;
}

double Collection::animalPayoff(){
    double runningTotal = 0;
    for(int i = 0; i < nAnimals; i++){
        runningTotal += collect[i].getPayoff();
    }
    return runningTotal;
}

bool Collection::hayAdulto(){
    bool adult = false;
    for (int i = 0; i < nAnimals; i++){
        if (collect[i].isAdult()){
            adult = true;
        }
    }
    return adult;
}

int Collection::getnAnimals(){
    return nAnimals;
}
