#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Zoo.hpp"
#include <iostream>
#include "Exhibit.hpp"

using std::cout;
using std::endl;

int main(){
    Zoo z;
    z.zooSetup();
    z.zooDay(1);
    z.freeTheAnimals();
    return 0;
}