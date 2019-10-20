#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal{
    protected:
        int age;
        int nBabies;
        //double cost;
        static double baseFoodCost;
        double foodCost;
        double payoff;
    public:
        Animal(){
            age = -1;
            //cost = 0;
            nBabies = 0;
            baseFoodCost = 10; 
            foodCost = 0;
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

        double getFoodCost(){
            return foodCost;
        }

        double getPayoff(){
            return payoff;
        }
        int getnBabies(){
            return nBabies;
        }

};

#endif