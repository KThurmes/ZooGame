/* Description: The Zoo class a Zoo for the 2nd project of Oregon State University's CS162 in the Fall of 2019. It contains a data member that keeps track of the zoo's finances (account), an array of exhibits representing the total collection of animals in the zoo, and a double keeping track of the total income for the day so that it can be printed out at the end of the day before being deposited into the bank account.
It has member functions that allow it to get user input to set up the zoo initially, and to complete a cycle of each day (morning, event, and evening). It contains helper functions that make an event happen each day (a birth, a death, a boom in attendance, or a quiet day)
*/

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

/* 
Description: Starts a new exhibit. This will only be called when the zoo obtains a new species of animal
*/
void Zoo::startNewExhibit(){
    collect.addExhibit();
}

/*
/*
Description: This coordinates the freeing of all dynamically allocated memory in the game
*/
void Zoo::freeTheAnimals(){
    collect.freeTheAnimals();
}
*/

/*
Description: zooSetup coordinates the setup of a new zoo. It gets user input about how many of the three starting animals to start the zoo with (Tigers, Pengins, and Turtles)
*/
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
   
    //Withdraw money
    account.makeWithdrawal(collect.getPrototype(2)->getCost()*nTurtles);
}


/*
Description: zooMorning coordinates a morning at the zoo. It increases the ages of the animals and buys food for the animals for the day. It takes an int representing the number of days that have passed in the game.
*/
void Zoo::zooMorning(int day){

	//Increase ages of all the animals
    collect.animalsAge();
    cout << "\n------------Day " << day <<"-------------\n";
    cout << "Good morning!\n";

	//Buy food for the animals today
    double foodCost = collect.getAnimalFoodCost();
    cout << "Your food cost for today is $" << foodCost << "."<<endl;

	//Make withdrawal from account
    account.makeWithdrawal(foodCost);
    showBankBalance();
    cout << "-------------------------------\n";
}


/*
Description: zooEvent drives the event generator for the zoo. Each day, an event happens (animal death, animal birth, and a quiet day). This function randomly generates that event and makes it happen.
*/
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
    cout << "-------------------------------\n";
}


/*
Description: zooDay coordinates one full day at the zoo (morning, event, and evening). It takes an int representing the number of days that have passed in the game.
*/
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

/*
Description: animalPurchase runs the menu and the results for when a user chooses to purchase a new adult animal at the end of the day.
*/
void Zoo::animalPurchase(){
    cout << "\nGreat! You're purchasing an animal!\n";
    showAnimalCosts();
    cout << "Which critter would you like to purchase?\n1. Tiger\n2. Penguin\n3. Turtle\n";
    int choice = getNumberBetween(1, 3);
	int animalIndex = choice - 1;
	collect.acquireAnimal(3, animalIndex);
	account.makeWithdrawal(collect.getPrototype(animalIndex)->getCost());
    /*if (choice == 1){
		//buy a 3-year-old tiger
        collect.acquireAnimal(3,0);
		//withdraw the money it takes to buy a 3-year-old tiger
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
	*/
    string animalName = collect.animalName(animalIndex);
    cout << "\nCongratulations on your shiny new adult " << animalName << "!\n";
}


/*
Description: zooEvening represents an evening at the zoo. It tells the user how much they have made during the day, how much money they have left, and asks the user if they would like to purchase an adult animal. It also lets the user know if they have lost the game by losing all their money.
*/
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

	//###Must add a scenario where user runs out of money.
    cout << "Good night!\n\n";
}


/*
Description: sicknessEvent coordinates the event where an animal gets sick and dies. It calls on Collection::animalDies() to choose an animal at random to die.
*/
void Zoo::sicknessEvent(){
    int deadAnimal = collect.animalDies();
    string animalName;

    //If there aren't any animals in the zoo, nothing happens
    if (deadAnimal == 0){
        cout << "It was a quiet day at the zoo...\n";
    }
    //Otherwise, an animal dies.
    else {
        animalName = collect.animalName(deadAnimal-1);
        cout << "Oh no! A " << animalName << " got sick and died!\n";
    }
}


/*
Description: attendanceEvent coordinates the event where there is a boost in attendance of the zoo and the zoo earns a random amount of extra cash for each tiger in the zoo.
*/
void Zoo::attendanceEvent(){
    srand(time(NULL));
    double totalBonus = 0;
    cout << "Memorial Day weekend boosts attendence!\n";

	//Get the number of tigers in zoo
    int nTigers = collect.getnTigers();
	//Add a random bonus between $250 and $500 for each tiger
    for (int i = 0; i < nTigers; i++){
        totalBonus += (rand() % 250) + 250;
    }
    cout << "Your zoo has received a bonus of $" << totalBonus <<"!\n";
    dailyIncome += totalBonus;
}


/*
Description: birthEvent coordinates the event of a birth in the zoo. 
*/
void Zoo::birthEvent(){
	//Animal gives birth
    int animalID = collect.animalBirth();

	//If there aren't any adult animals in the zoo...
    if(animalID == 0){
        cout << "It was a quiet day at the zoo...\n";
    }
	//Otherwise, let the user know which animal has given birth
    else{
        string animalName = collect.animalName(animalID-1);
        cout << "An " << animalName << " has given birth!\n";
    }
}


/*
Description: showAnimalCosts prints the names of the animals available for purchase to the terminal and informs the user how much each animal costs.
*/
void Zoo::showAnimalCosts(){
    cout << "\n\n-------Animal Price List-------\n";
    cout << "Tigers: $" << collect.getPrototype(0)->getCost() << endl;
    cout << "Penguins: $" << collect.getPrototype(1)->getCost() << endl;
    cout << "Turtles: $" << collect.getPrototype(2)->getCost() << endl;
    cout << "-------------------------------\n\n";
}


/*
Description: showBankBalance prints out a message to the user letting them know how much money they have in the bank.
*/
void Zoo::showBankBalance(){
    cout << "The zoo has a bank balance of $" << account.getBalance()<< "."<<endl;
}
