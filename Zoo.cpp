#include "Zoo.hpp"
#include "BankAccount.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Exhibit.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
#include <cstdlib>
#include <ctime>
#include <string>

using std::cout;
using std::endl;
using std::string;


Zoo::Zoo(){
    dailyIncome = 0;
}

void Zoo::startNewExhibit(){
    collect.addExhibit();
}

void Zoo::freeTheAnimals(){
    collect.freeTheAnimals();
    cout<< "Freeing the zoo!\n";
}

void Zoo::zooSetup(){
    
    //Show animal costs
    showAnimalCosts();
    //Show bank account balance
    showBankBalance();

    //Ask how many Tigers player would like to buy
    cout << "\nHow many tigers would you like to start your zoo with?\n";
    int nTigers = getNumberBetween(1,2);
    
    //Add animals to Exhibit
    for (int i = 0; i < nTigers; i++){
        collect.acquireAnimal(1, 0);
    }
    //Withdraw money
    account.makeWithdrawal(collect.getPrototype(0)->getCost()*nTigers);


    //Ask how many Penguins player would like to buy
    cout << "How many penguins would you like to start your zoo with?\n";
    int nPenguins = getNumberBetween(1,2);
    
    //Add animals to Exhibit
    for (int i = 0; i < nPenguins; i++){
        collect.acquireAnimal(1, 1);
    }   
    //Withdraw money
    account.makeWithdrawal(collect.getPrototype(1)->getCost()*nPenguins);

    //Ask how many Turtles player would like to buy
    cout << "How many turtles would you like to start your zoo with?\n";
    int nTurtles = getNumberBetween(1,2);
    
    
    //Add animals to Exhibit
    for (int i = 0; i < nTurtles; i++){
        collect.acquireAnimal(1, 2);
    }   
    collect.showCollection();
    cout <<"Made it!";
    //Withdraw money
    account.makeWithdrawal(collect.getPrototype(2)->getCost()*nTurtles);
}

void Zoo::zooMorning(int day){
    collect.animalsAge();
    cout << "\n------------Day " << day <<"-------------\n";
    cout << "Good morning!\n";
    double foodCost = collect.getAnimalFoodCost();
    cout << "Your food cost for today is $" << foodCost << "."<<endl;
    account.makeWithdrawal(foodCost);
    showBankBalance();
    cout << "-------------------------------\n";
}

void Zoo::zooEvent(){
    //srand use adapted from http://www.cplusplus.com/reference/cstdlib/srand/
    //Accessed 10.17.19
    srand(time(NULL));
    int nRand = (rand() % 4) + 1;
    //int nRand = 3; //testing attendance event
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
    cout << "-------------------------------\n";
}

void Zoo::zooDay(int day){
    dailyIncome = 0;
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
    cout << "\nGreat! You're purchasing an animal!\n";
    showAnimalCosts();
    cout << "Which critter would you like to purchase?\n1. Tiger\n2. Penguin\n3. Turtle\n";
    int choice = getNumberBetween(1, 3);
    if (choice == 1){
        collect.acquireAnimal(3,0);
        account.makeWithdrawal(collect.getPrototype(0)->getCost());
    }
    if (choice == 2){
        collect.acquireAnimal(3,1);
        account.makeWithdrawal(collect.getPrototype(1)->getCost());
    }
    if (choice == 3){
        collect.acquireAnimal(3,2);
        account.makeWithdrawal(collect.getPrototype(2)->getCost());
    }

    string animalName = collect.animalName(choice-1);
    cout << "\nCongratulations on your shiny new adult " << animalName << "!\n";
}

void Zoo::zooEvening(){
    cout << "Time to close up for the day!\n";
    double payoff = collect.animalPayoff();
    dailyIncome += payoff;
    cout << "Today's profit: $" << dailyIncome << endl;
    account.makeDeposit(dailyIncome);
    showBankBalance();
    cout << "-------------------------------\n";
    cout << "\nWould you like to purchase an adult animal?\n1. Yes\n2. No\n";
    int choice = getNumberBetween(1, 2);
    if (choice == 1){
        animalPurchase();
    }
    cout << "Good night!\n\n";
}

void Zoo::sicknessEvent(){
    int deadAnimal = collect.animalDies();
    string animalName;

    //If there aren't any animals in the zoo
    if (deadAnimal == 0){
        cout << "It was a quiet day at the zoo...\n";
    }
    //Otherwise, an animal dies.
    else {
        animalName = collect.animalName(deadAnimal-1);
        cout << "Oh no! A " << animalName << " got sick and died!\n";
    }
}

void Zoo::attendanceEvent(){
    srand(time(NULL));
    double totalBonus = 0;
    cout << "Memorial Day weekend boosts attendence!\n";
    int nTigers = collect.getnTigers();
    for (int i = 0; i < nTigers; i++){
        totalBonus += (rand() % 250) + 250;
    }
    cout << "Your zoo has received a bonus of $" << totalBonus <<"!\n";
    dailyIncome += totalBonus;
    //account.makeDeposit(totalBonus);
}

void Zoo::birthEvent(){
    int animalID = collect.animalBirth();
    if(animalID == 0){
        cout << "It was a quiet day at the zoo...\n";
    }
    else{
        string animalName = collect.animalName(animalID-1);
        cout << "An " << animalName << " has given birth!\n";
    }
}

void Zoo::showAnimalCosts(){
    cout << "\n\n-------Animal Price List-------\n";
    cout << "Tigers: $" << collect.getPrototype(0)->getCost() << endl;
    cout << "Penguins: $" << collect.getPrototype(1)->getCost() << endl;
    cout << "Turtles: $" << collect.getPrototype(2)->getCost() << endl;
    cout << "-------------------------------\n\n";
}

void Zoo::showBankBalance(){
    cout << "The zoo has a bank balance of $" << account.getBalance()<< "."<<endl;
}
