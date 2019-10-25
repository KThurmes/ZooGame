/* Description: The Zoo class implements a Zoo for the 2nd project of Oregon State University's CS162 in the Fall of 2019. It contains a data member that keeps track of the zoo's finances (account), an array of exhibits representing the total collection of animals in the zoo, and a double keeping track of the total income for the day so that it can be printed out at the end of the day before being deposited into the bank account.
It has member functions that allow it to get user input to set up the zoo initially, and to complete a cycle of each day (morning, event, and evening). It contains helper functions that make an event happen each day (a birth, a death, a boom in attendance, or a quiet day)
*/

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

		void zooMorning(int);
		void zooEvent();
		void zooEvening();
		void sicknessEvent();
		void attendanceEvent();
		void birthEvent();
		void showAnimalCosts();
		void showBankBalance();
		void animalPurchase();
		void startNewExhibit();
    
    public:
        Zoo();
        void freeTheAnimals();
        void zooSetup();
        void zooDay(int day);
};

#endif