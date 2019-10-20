#include "Zoo.hpp"
#include "BankAccount.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Collection.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;


Zoo::Zoo(){
}

void Zoo::addTiger(Animal& tigre){
    tigerCollect.acquireAnimal(tigre);
}

void Zoo::addPenguin(Animal& pinguino){
    penguinCollect.acquireAnimal(pinguino);
}

void Zoo::addTurtle(Animal& tortuga){
    turtleCollect.acquireAnimal(tortuga);
}

void Zoo::freeTheAnimals(){
    tigerCollect.freeTheAnimals();
    penguinCollect.freeTheAnimals();
    turtleCollect.freeTheAnimals();
}

void Zoo::allAnimalsAge(){
    tigerCollect.animalsAge();
    penguinCollect.animalsAge();
    turtleCollect.animalsAge();
}

void Zoo::zooSetup(){
    
    //Show animal costs
    showAnimalCosts();
    //Show bank account balance
    showBankBalance();

    //Ask how many Tigers player would like to buy
    cout << "How many tigers would you like to start your zoo with?\n";
    int nTigers = getNumberBetween(1,2);
    //Add animals to collection
    Tiger tigre(1);
    for (int i = 0; i < nTigers; i++){
        addTiger(tigre);
    }
    //Withdraw money
    account.makeWithdrawal(Tiger::getCost()*nTigers);


    //Ask how many Penguins player would like to buy
    cout << "How many penguins would you like to start your zoo with?\n";
    int nPenguins = getNumberBetween(1,2);
    //Add animals to collection
    Penguin pinguino(1);
    for (int i = 0; i < nPenguins; i++){
        addPenguin(pinguino);
    }   
    //Withdraw money
    account.makeWithdrawal(Penguin::getCost()*nPenguins);

    //Ask how many Turtles player would like to buy
    cout << "How many turtles would you like to start your zoo with?\n";
    int nTurtles = getNumberBetween(1,2);
    //Add animals to collection
    Turtle tortuga(1);
    for (int i = 0; i < nTurtles; i++){
        addTurtle(tortuga);
    }   
    //Withdraw money
    account.makeWithdrawal(Turtle::getCost()*nTurtles);
}

double Zoo::getTotalFoodCost(){
    double totalCost = 0;
    totalCost += tigerCollect.animalFoodCost();
    totalCost += turtleCollect.animalFoodCost();
    totalCost += penguinCollect.animalFoodCost();
    return totalCost;
}

void Zoo::zooMorning(int day){
    cout << "\n--------Day " <<day <<"--------\n";
    cout << "Good morning!\n";
    double foodCost = getTotalFoodCost();
    cout << "Your food cost for today is $" << foodCost <<"."<<endl;
    account.makeWithdrawal(foodCost);
    showBankBalance();
    cout << "----------------------------\n";
}

void Zoo::zooEvent(){
    //srand use adapted from http://www.cplusplus.com/reference/cstdlib/srand/
    //Accessed 10.17.19
    srand(time(NULL));
    int nRand = (rand() % 4) + 1;
    switch(nRand){
        case 1: sicknessEvent();
        break;
        break;
        case 2: attendanceEvent();
        break;
        break;
        case 3: birthEvent();
        break;
        case 4: 
            cout << "It was a quiet day at the zoo...\n";
        break;
    }
    cout << "-----------------------------\n";
}

void Zoo::zooDay(int day){
    zooMorning(day);
    zooEvent();
    zooEvening();
    cout << "Would you like to play another day?\n1. Continue\n2. Quit" << endl;
    int choice = getNumberBetween(1, 2);
    if (choice == 1){
        day++;
        zooDay(day);
    }

}
void Zoo::animalPurchase(){
    cout << "Great! You're purchasing an animal!\n";
}

void Zoo::zooEvening(){
    cout << "\nTime to close up for the day!\n";
    cout << "Today's profit: $" << endl;
    cout << "Total funds available: $" <<endl;
    cout << "Would you like to purchase an adult animal?\n1. Yes\n2. No\n";
    int choice = getNumberBetween(1,2);
    if (choice == 1){
        animalPurchase();
    }
    cout << "Good night!\n";
}

void Zoo::sicknessEvent(){
    cout << "Oh no! Your critter is sick!\n";
}

void Zoo::attendanceEvent(){
    cout << "Memorial Day weekend boosts attendence!\n";
}

void Zoo::birthEvent(){
    cout << "Please welcome a new critter!\n";
}

void Zoo::showAnimalCosts(){
    cout << "\n\n---Animal Price List---\n";
    cout << "Tigers: $" << Tiger::getCost() << endl;
    cout << "Penguins: $" << Penguin::getCost() << endl;
    cout << "Turtles: $" << Turtle::getCost() << endl;
    cout << "------------------------\n\n";
}

void Zoo::showBankBalance(){
    cout << "The zoo has a bank balance of $" << account.getBalance()<< "."<<endl;

}