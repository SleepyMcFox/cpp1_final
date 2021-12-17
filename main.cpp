#include "coffeemachine.h"
#include <iostream>

int main()
{
    // Runs the Coffee Machine Method
    CoffeeMachine c;
    c.input(c);
    // Loops through the amount of cups requested
    for(int i = 0; i < c.coffeeRequested; i++)
    {
        c.createCoffee(c);
    }
    
}
