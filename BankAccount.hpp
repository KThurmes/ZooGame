/********************************************************************* 
** Author: Katheen Thurmes
** Date: 27 Oct., 2019
** Description: BankAccount is a simple class that manages a bank 
account. It contains a data member to store the current balance. It 
contains methods that make deposits, make withdrawals, and get the 
current balance. A new bank account is initialized to start with 
$10,000 
*********************************************************************/

#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP
#include <iostream>
using std::cout;
using std::endl;

class BankAccount
{
private:
    double balance;

public:
    BankAccount()
    {
        balance = 100000;
    }
    double getBalance()
    {
        return balance;
    }
    void makeDeposit(double amount)
    {
        balance += amount;
    }
    void makeWithdrawal(double amount)
    {
        balance -= amount;
        cout << "Withdrawing $" << amount << endl;
    }
};

#endif