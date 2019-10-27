
/********************************************************************* 
** Author: Katheen Thurmes
** Date: 27 Oct., 2019
** Description: Description: a Collection object represents a gouping 
of exhibits. Each of the exhibits contains an array of pointers to 
animals. Each of the exhibits contains only one type of animal. The 
class contains a data member to hold the exhibits, an int that 
represents the number of exhibits, an int that represents the 
capacity of the array holding the exhibits, and an array of animals 
that represent a "prototype" animal of each species that can be 
accessed even when there are no instances of that animal present 
in the zoo.
*********************************************************************/

#include "Collection.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*********************************************************************
Description: The default constructor for this class will create a 
collection that contains three exhibits and will create three animal 
prototypes to be used to get information about the animal type without 
the user having to own one.
*/
Collection::Collection()
{
    nExhibits = 3;
    arraySize = 3;
    collect = new Exhibit[arraySize];

    //Add the original three prototypes
    Tiger *tigre = new Tiger(0);
    Penguin *pinguino = new Penguin(0);
    Turtle *tortuga = new Turtle(0);
    prototypes[0] = tigre;
    prototypes[1] = pinguino;
    prototypes[2] = tortuga;
    //prototypes[3] = &whatever;
}

/*********************************************************************
Description: Returns the number of animals in the collection, 
regardless of their type.
*/
int Collection::getnAnimals()
{
    int nAnimals = 0;
    //Add the number of animals contained in each of the exhibits
    for (int i = 0; i < nExhibits; i++)
    {
        nAnimals += collect[i].getnAnimals();
    }
    return nAnimals;
}

/*********************************************************************
Description: Returns the total cost of feeding all the animals in the 
collection
*/
double Collection::getAnimalFoodCost()
{
    double totalCost = 0;
    //Sum the costs of all the food for all the animals in all the exhibits
    for (int i = 0; i < nExhibits; i++)
    {
        totalCost += collect[i].animalFoodCost();
    }
    return totalCost;
}

/*********************************************************************
Description: Returns the number of adult animals in the zoo
*/
int Collection::hayAdulto()
{
    int nAdults = 0;
    //Search all exhibits for adult animals.
    for (int i = 0; i < nExhibits; i++)
    {
        nAdults += collect[i].hayAdulto();
    }
    return nAdults;
}

/*********************************************************************
Description: addExhibit adds another exhibit to the collection. If the 
collection array is too small to hold all the exhibits, call 
resizeArray() to expand the array
*/
void Collection::addExhibit()
{
    //Expand the number of exhbits in the collection, or just add to the number of exhibits
    if (nExhibits == arraySize)
    {
        resizeArray();
    }
    nExhibits++;
}

/*********************************************************************
Description: resizeArray is a helper function that will expand the 
size of the collect array. It doubles the capacity.
*/
void Collection::resizeArray()
{

    int newSize = arraySize * 2;

    //Create new array with double capacity
    Exhibit *newCollect = new Exhibit[newSize];

    //Copy all exhibits into it
    for (int i = 0; i < nExhibits; i++)
    {
        newCollect[i] = collect[i];
    }

    //Delete the array exhib used to point to
    delete[] collect;

    //Reassign exhib pointer to point to new array
    collect = newCollect;
    arraySize = newSize;
}

/*********************************************************************
Description: acquireAnimal allows the user to purchase another animal. 
It takes the age of the desired animal (3 for adults, 0 for babies) 
and the index that indicates which exhibit the new animal will be in.
*/
void Collection::acquireAnimal(int age, int index)
{

    if (index == 0)
    {
        //make a new tiger
        Tiger *tigre;
        tigre = new Tiger(age);

        //send it into the appropriate exhibit
        collect[index].acquireAnimal(tigre);
    }
    if (index == 1)
    {
        Penguin *pinguino;
        pinguino = new Penguin(age);
        collect[index].acquireAnimal(pinguino);
    }

    if (index == 2)
    {
        Turtle *tortuga;
        tortuga = new Turtle(age);
        collect[index].acquireAnimal(tortuga);
    }
}

/*********************************************************************
Description: animalsAge allows the user to increment the ages of all 
the animals in the collection
*/
void Collection::animalsAge()
{
    //Add one to the ages of all the animals in every exhibit
    for (int i = 0; i < nExhibits; i++)
    {
        collect[i].animalsAge();
    }
}

/*********************************************************************
Description: animalDies simulates an event where an animal is chosen 
randomly from the collection to get sick and die. It is very sad.
*/
int Collection::animalDies()
{
    int nAnimals = getnAnimals();
    if (nAnimals > 0)
    {
        //Choose random number between 1 and nAnimals.
        srand(time(NULL));
        int nRand = (rand() % getnAnimals() + 1);

        //That's the animal that dies
        int animalsInExhibit;
        int i = 0;
        while (nRand > 0)
        {
            animalsInExhibit = collect[i].getnAnimals();
            if (nRand <= animalsInExhibit)
            {
                collect[i].animalDies(nRand - 1);
            }
            nRand -= animalsInExhibit;
            i++;
        }
        return i;
    }
    else
    {
        return 0;
    }
}

/*********************************************************************
Description: animalBirth chooses an adult animal at random to give 
birth. It adds a litter of their babies to the appropriate exhibit
*/
int Collection::animalBirth()
{

    //First, make sure there is an adult in the zoo.
    if (!hayAdulto())
    {
        return 0;
    }
    srand(time(NULL));
    int nRand = (rand() % nExhibits);

    //Cycle through the exhibits until we find a type of animal that has an adult
    bool adult = false;
    while (adult == false)
    {
        nRand = (nRand + 1) % nExhibits;
        adult = collect[nRand].hayAdulto();
    }

    //Determine how many babies to make
    int nBabies = prototypes[nRand]->getnBabies();

    //Make babies!
    for (int i = 0; i < nBabies; i++)
    {
        acquireAnimal(0, nRand);
    }
    return (nRand + 1);
}

/*********************************************************************
Description: Frees all the dynamically allocated memory
*/
void Collection::freeTheAnimals()
{
    //Unlock the exhibits
    for (int i = 0; i < nExhibits; i++)
    {
        collect[i].freeTheAnimals();
    }
    delete[] collect;
    //Unlock individual cages
    for (int i = 0; i < 3; i++)
    {
        delete prototypes[i];
    }
}

/*********************************************************************
Description: animalPayoff returns the sum of the daily payoff values 
of all animals in the collection
*/
double Collection::animalPayoff()
{
    int totalPayoff = 0;
    //Sum the payoff value of each animal in every exhibit
    for (int i = 0; i < nExhibits; i++)
    {
        totalPayoff += collect[i].animalPayoff();
    }
    return totalPayoff;
}

/*********************************************************************
Description: Returns the number of tigers in the zoo.
*/
int Collection::getnTigers()
{
    return collect[0].getnAnimals();
}

/*********************************************************************
Description: animalName returns the name of the animal in the exhibit 
represented by the index in the collection
*/
string Collection::animalName(int index)
{
    //Get the name of the prototype animal
    string animalName = prototypes[index]->getName();
    return animalName;
}

/*********************************************************************
Description: showCollection prints a list of all animals in the 
collection, sorted by exhibit. This was primarily used for debugging 
applications.
*/
void Collection::showCollection()
{
    //Print out the entirety of the collection
    cout << "Tigers: \n";
    collect[0].viewExhibit();
    cout << "\nPenguins: \n";
    collect[1].viewExhibit();
    cout << "\nTurtles: \n";
    collect[2].viewExhibit();
}

/*********************************************************************
Description: getPrototype returns the animal found in index index of 
the prototype array.
*/
Animal *Collection::getPrototype(int index)
{
    return prototypes[index];
}