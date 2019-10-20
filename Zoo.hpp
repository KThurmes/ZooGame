#ifndef ZOO_HPP
#define ZOO_HPP

#include "BankAccount.hpp"
#include "Exhibit.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"

class Zoo{

    private:

        BankAccount account;
        Exhibit tigerExhibit;
        Exhibit penguinExhibit;
        Exhibit turtleExhibit;
    
    public:
        int getTotalAnimals();
        void addTiger(Animal&);
        void addPenguin(Animal&);
        void addTurtle(Animal&);
        Zoo();
        Exhibit getTigerExhibit(){
            return tigerExhibit;
        }
        void freeTheAnimals();
        void allAnimalsAge();
        void zooSetup();
        double getTotalFoodCost();
        void zooMorning(int);
        void zooEvent();
        void zooEvening();
        void sicknessEvent();
        void attendanceEvent();
        void birthEvent();
        void showAnimalCosts();
        void showBankBalance();
        void zooDay(int day);
        void animalPurchase();
        double getTodaysPayoff();
        
};

#endif