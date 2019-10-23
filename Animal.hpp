#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
using std::string;


class Animal{
    protected:
        int age;
        double cost;
        int nBabies;
        static double baseFoodCost;
        double payoff;
    public:
        virtual string getName() {
            return "animal";
        };
        Animal(){
            age = -1;
            //cost = 0;
            nBabies = 0;
            baseFoodCost = 10; 
            payoff = 0;
        }
        void ageOneDay(){
            age++;
        }
        void die(){
            age = -1;
        }
        bool isAdult();

        int getAge(){
            return age;
        }

        double getPayoff(){
            return payoff;
        }
        int getnBabies(){
            return nBabies;
        }
        double getCost(){
            return cost;
        }

        virtual double getFoodCost(){
            return baseFoodCost;
        }
        virtual ~Animal(){};
};

#endif