#include "Collection.hpp"
#include <iostream>
using std::cout;
using std::endl;

Collection::Collection(){
    nExhibits = 3;
    arraySize = 3;
    collect = new Exhibit[arraySize];
    Tiger* tigre = new Tiger(0);
    Penguin* pinguino= new Penguin(0);
    Turtle* tortuga = new Turtle(0);

    prototypes[0] = tigre;
    prototypes[1] = pinguino;
    prototypes[2] = tortuga;
    //prototypes[3] = &whatever;
}

int Collection::getnAnimals(){
    int nAnimals = 0;
    for (int i = 0; i < nExhibits; i++){
        nAnimals += collect[i].getnAnimals();
    }
    return nAnimals;
}

double Collection::getAnimalFoodCost(){
    double totalCost = 0;
    for (int i = 0; i < nExhibits; i++){
        totalCost += collect[i].animalFoodCost();
    }
    return totalCost;
}

int Collection::hayAdulto(){
    int nAdults = 0;
    for (int i = 0; i < nExhibits; i++){
        nAdults += collect[i].hayAdulto();
    }
    return nAdults;
}

void Collection::addExhibit(){
    if (nExhibits == arraySize){
        resizeArray();
    }
    nExhibits++;
}

void Collection::resizeArray(){
    cout<< "Collection array is being resized!" <<endl;
    
    int newSize = arraySize * 2;

    //Create new array with double capacity
    Exhibit* newCollect = new Exhibit[newSize];
    
    //Copy all exhibits into it
    for (int i = 0; i < nExhibits; i++){
        newCollect[i] = collect[i];
    }

    //Delete the array exhib used to point to
    delete[] collect;

    //Reassign exhib pointer to point to new array
    collect = newCollect;
    arraySize = newSize;
}

void Collection::acquireAnimal(int age, int index){
    if (index == 0){
        //make a new tiger
        Tiger* tigre;
        tigre = new Tiger(age);

        //send it into the appropriate exhibit
        collect[index].acquireAnimal(tigre);
    }
    if (index == 1){
        Penguin* pinguino;
        pinguino = new Penguin(age);
        collect[index].acquireAnimal(pinguino);
    }

    if (index == 2){
        Turtle* tortuga;
        tortuga = new Turtle(age);
        collect[index].acquireAnimal(tortuga);
    }
}

void Collection::animalsAge(){
    for (int i = 0; i < nExhibits; i++){
        collect[i].animalsAge();
    }
}

int Collection::animalDies(){
    int nAnimals = getnAnimals();
    if (nAnimals > 0){
        //Choose random number between 1 and nAnimals. 
        srand(time(NULL));
        int nRand = (rand() % getnAnimals() + 1);
    
        //That's the animal that dies
        int animalsInExhibit;
        int i = 0;
        while(nRand > 0){
            animalsInExhibit = collect[i].getnAnimals();
            if (nRand <= animalsInExhibit){
                collect[i].animalDies(nRand-1);
            }
            nRand -= animalsInExhibit;
            i++;
        }
        return i;
    }
    else{
        return 0;
    }
}

int Collection::animalBirth(){
    if (!hayAdulto()){
        return 0;
    }
    srand(time(NULL));
    int nRand = (rand() % nExhibits);


    //Cycle through the exhibits until we find a type of animal that has an adult
    bool adult = false;
    while (adult == false){
        nRand = (nRand + 1) % nExhibits;
        adult = collect[nRand].hayAdulto();
    }

    //There will be at least one adult animal in the chosen exhibit.
    int nBabies = prototypes[nRand]->getnBabies();
    for (int i = 0; i < nBabies; i++){
        acquireAnimal(0, nRand);
    }
    return (nRand + 1);
}

void Collection::freeTheAnimals(){
    for (int i = 0; i < nExhibits; i++){
        collect[i].freeTheAnimals();
    }
    delete[] collect;
    for( int i = 0; i < 3; i++){
        delete prototypes[i];
    }
}

double Collection::animalPayoff(){
    int totalPayoff = 0;
    for (int i = 0; i < nExhibits; i++){
        totalPayoff += collect[i].animalPayoff();
    }  
    return totalPayoff; 
}

int Collection::getnTigers(){
    return collect[0].getnAnimals();
}

string Collection::animalName(int index){
    string animalName = prototypes[index]->getName();
    return animalName;
}

void Collection::showCollection(){
    cout << "Tigers: \n";
    collect[0].viewExhibit();
    cout << "\nPenguins: \n";
    collect[1].viewExhibit();
    cout << "\nTurtles: \n";
    collect[2].viewExhibit();
}

Animal* Collection::getPrototype(int index){
    return prototypes[index];
}