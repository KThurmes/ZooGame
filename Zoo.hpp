#ifndef ZOO_HPP
#define ZOO_HPP

#include "BankAccount.hpp"
#include "Exhibit.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"
#include "Collection.hpp"

class Zoo{

    private:

        Collection collect;
        BankAccount account;
/*      Exhibit tigerExhibit;
        Exhibit penguinExhibit;
        Exhibit turtleExhibit; */
    
    public:
        Zoo();
        //int getTotalAnimals();
        void addTiger(Animal&);
        void addPenguin(Animal&);
        void addTurtle(Animal&);
/*         Exhibit getTigerExhibit(){
            return tigerExhibit;
        } */
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
        void startNewExhibit();
        
};

#endif