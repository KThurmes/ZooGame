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
        int dailyIncome;
    
    public:
        Zoo();
        void freeTheAnimals();
        void zooSetup();
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
        void startNewExhibit();
        
};

#endif