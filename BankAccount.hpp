#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

class BankAccount{
    private:
        double balance;
    public:
        BankAccount(){
            balance = 100000;
        }
        double getBalance(){
            return balance;
        }
        void makeDeposit(double amount){
            balance += amount;
        }
        void makeWithdrawal(double amount){
            balance -= amount;
        }
};

#endif