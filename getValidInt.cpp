/********************************************************************* 
** Title: getValidInt
** Author: Katheen Thurmes
** Date: 6 Oct., 2019
** Description: getValidInt() is a function that will accept 
input from the user and will do checks to ensure that the input is an 
integer. It will continue to ask the user for an integer until the 
user submits a valid integer.
** Return value: Returns the submitted integer.
** Limitation: getValidInt() will accept decimal values that end in ".0" 
as integers.
*********************************************************************/ 

#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;

int getValidInt(){
    //Input validation code and cin stream resetting adapted from https://stackoverflow.com/questions/19521320/why-do-i-get-an-infinite-loop-if-i-enter-a-letter-rather-than-a-number
    //Accessed 1 Oct., 2019

    int input;
    float rawInput;
    cin >> rawInput;

    //Check that the inputted value is a number. If it isn't, ask the user for input again.
    if (!(cin))
    {
        cout << "Please enter an integer." << endl;
        //Clear input stream
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        rawInput = getValidInt();
    }

    //Check to make sure a decimal value hasn't been entered. If it isn't, ask the user for input again. This also checks that the max/min value of an int hasn't been exceeded
    //Will not reject an input that ends in ".0".
    input = rawInput; //value of "input" will be the floor of "rawInput".

    if (!(rawInput-input == 0)){
        cout << "Please enter an integer between -2147483648 and 2147483647.." << endl;

        //Clear input stream
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        rawInput = getValidInt();
    }

    return input;
}