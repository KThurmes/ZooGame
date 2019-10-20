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

using std::cout;
using std::endl;


Zoo::Zoo(){
}

void Zoo::addTiger(Animal& tigre){
    tigerExhibit.acquireAnimal(tigre);
}

void Zoo::addPenguin(Animal& pinguino){
    penguinExhibit.acquireAnimal(pinguino);
}

void Zoo::addTurtle(Animal& tortuga){
    turtleExhibit.acquireAnimal(tortuga);
}

void Zoo::freeTheAnimals(){
    tigerExhibit.freeTheAnimals();
    penguinExhibit.freeTheAnimals();
    turtleExhibit.freeTheAnimals();
}

void Zoo::allAnimalsAge(){
    tigerExhibit.animalsAge();
    penguinExhibit.animalsAge();
    turtleExhibit.animalsAge();
}

void Zoo::zooSetup(){
    
    //Show animal costs
    showAnimalCosts();
    //Show bank account balance
    showBankBalance();

    //Ask how many Tigers player would like to buy
    cout << "How many tigers would you like to start your zoo with?\n";
    int nTigers = getNumberBetween(1,2);
    //Add animals to Exhibit
    Tiger tigre(1);
    for (int i = 0; i < nTigers; i++){
        addTiger(tigre);
    }
    //Withdraw money
    account.makeWithdrawal(Tiger::getCost()*nTigers);


    //Ask how many Penguins player would like to buy
    cout << "How many penguins would you like to start your zoo with?\n";
    int nPenguins = getNumberBetween(1,2);
    //Add animals to Exhibit
    Penguin pinguino(1);
    for (int i = 0; i < nPenguins; i++){
        addPenguin(pinguino);
    }   
    //Withdraw money
    account.makeWithdrawal(Penguin::getCost()*nPenguins);

    //Ask how many Turtles player would like to buy
    cout << "How many turtles would you like to start your zoo with?\n";
    int nTurtles = getNumberBetween(1,2);
    //Add animals to Exhibit
    Turtle tortuga(1);
    for (int i = 0; i < nTurtles; i++){
        addTurtle(tortuga);
    }   
    //Withdraw money
    account.makeWithdrawal(Turtle::getCost()*nTurtles);
}

double Zoo::getTotalFoodCost(){
    double totalCost = 0;
    totalCost += tigerExhibit.animalFoodCost();
    totalCost += turtleExhibit.animalFoodCost();
    totalCost += penguinExhibit.animalFoodCost();
    return totalCost;
}

void Zoo::zooMorning(int day){
    allAnimalsAge();
    cout << "\n--------Day " << day <<"--------\n";
    cout << "Good morning!\n";
    double foodCost = getTotalFoodCost();
    cout << "Your food cost for today is $" << foodCost << "."<<endl;
    account.makeWithdrawal(foodCost);
    showBankBalance();
    cout << "----------------------------\n";
}

void Zoo::zooEvent(){
    //srand use adapted from http://www.cplusplus.com/reference/cstdlib/srand/
    //Accessed 10.17.19
    srand(time(NULL));
    //int nRand = (rand() % 4) + 1;
    int nRand = 3; //testing attendance event
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
    cout << "Great! You're purchasing an animal!\nWhich critter would you like to purchase?\n1. Tiger\n2. Penguin\n3. Turtle\n";
    int choice = getNumberBetween(1, 3);
    if (choice == 1){
        Tiger tigre(3);
        addTiger(tigre);
        account.makeWithdrawal(tigre.getCost());
    }
    if (choice == 2){
        Penguin pinguino(3);
        addPenguin(pinguino);
        account.makeWithdrawal(pinguino.getCost());
    }
    if (choice == 3){
        Turtle tortuga(3);
        addTurtle(tortuga);
        account.makeWithdrawal(tortuga.getCost());
    }
}

void Zoo::zooEvening(){
    cout << "\nTime to close up for the day!\n";
    double payoff = getTodaysPayoff();
    account.makeDeposit(payoff);
    cout << "Today's profit: $" << payoff << endl;
    showBankBalance();
    cout << "\nWould you like to purchase an adult animal?\n1. Yes\n2. No\n";
    int choice = getNumberBetween(1, 2);
    if (choice == 1){
        animalPurchase();
    }
    cout << "Good night!\n";
}

void Zoo::sicknessEvent(){
    cout << "Oh no! Your critter got sick and died!\n";
    srand(time(NULL));
    int nRand = (rand() % 3) + 1;
    //###This assumes that there is at least one of every animal
    if (nRand == 1){
        cout << "A tiger has died!\n" << endl;
        tigerExhibit.animalDies();
        tigerExhibit.viewExhibit();
    }
    if (nRand == 2){
        cout << "A penguin has died!\n" << endl;
        penguinExhibit.animalDies();
        penguinExhibit.viewExhibit();
    }
    if (nRand == 3){
        cout << "A turtle has died!\n" << endl;
        turtleExhibit.animalDies();
        turtleExhibit.viewExhibit();
    }
}

void Zoo::attendanceEvent(){
    srand(time(NULL));
    double totalBonus = 0;
    cout << "Memorial Day weekend boosts attendence!\n";
    int nTigers = tigerExhibit.getnAnimals();
    for (int i = 0; i < nTigers; i++){
        totalBonus += (rand() % 250) + 250;
    }
    cout << "Your zoo has received a bonus of $" <<totalBonus <<"!\n";
    account.makeDeposit(totalBonus);
}

void Zoo::birthEvent(){
    cout << "Please welcome a new critter!\n";
    srand(time(NULL));
    int nRand = (rand() % 3) + 1;
    int nBabies = 0;
    //###This assumes that there is at least one adult of every animal
    if (nRand == 1){
        if(tigerExhibit.hayAdulto()){
            cout << "A tiger has given birth!\n" << endl;
            nBabies = Tiger::getnBabies();
            for (int i = 0; i <nBabies; i++){
                Tiger tigre(0);
                tigerExhibit.acquireAnimal(tigre);
            }
        }
        else {
            nRand = 2;
        }
        tigerExhibit.viewExhibit();
    }
    if (nRand == 2){
        cout << "A penguin has given birth!\n" << endl;
        nBabies = Penguin::getnBabies();
        for (int i =0; i < nBabies;i++){
            Penguin pinguino(0);
            penguinExhibit.acquireAnimal(pinguino);
        }
        penguinExhibit.viewExhibit();
    }
    if (nRand == 3){
        cout << "A turtle has given birth!\n" << endl;
        nBabies = Turtle::getnBabies();
        for (int i = 0; i < nBabies; i++){
            Turtle tortuga(0);
            turtleExhibit.acquireAnimal(tortuga);
        }
        turtleExhibit.viewExhibit();
    }
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

double Zoo::getTodaysPayoff(){
    double totalPayoff = 0;
    totalPayoff += tigerExhibit.animalPayoff();
    totalPayoff += turtleExhibit.animalPayoff();
    totalPayoff += penguinExhibit.animalPayoff();
    return totalPayoff;
}