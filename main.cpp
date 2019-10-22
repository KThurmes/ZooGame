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
    cout << "Zoo is completed\n";
    z.startNewExhibit();

    return 0;
}