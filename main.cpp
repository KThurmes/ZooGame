/********************************************************************* 
** Author: Katheen Thurmes
** Date: 27 Oct., 2019
** Description: Project 2 of Oregon State University's CS162 in the 
Fall of 2019 is to create a simple text-based "Zoo Tycoon" game. The 
game simulates the management of a zoo, with the option of having 
three different animals: tigers, penguins, and turtles. The player 
must purchase animals and food, and the player makes money off of zoo 
attendance, which depends on which animals are being kept in the zoo 
and how many.
*********************************************************************/

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Zoo.hpp"
#include <iostream>
#include "Exhibit.hpp"

using std::cout;
using std::endl;

int main()
{
    Zoo z;
    z.zooSetup();
    z.zooDay(1);
    z.freeTheAnimals();
    return 0;
}