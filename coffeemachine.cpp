#include "coffeemachine.h"
#include <iostream>
#include <string>
#include <limits>


using namespace std;

void CoffeeMachine::displayCurrentResources(CoffeeMachine &c)
{
    cout << "Your coffee machine has the following resources:" << endl << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Beans: " << c.hopper.beans << " grams of beans" << endl;
    cout << "Current Heat: " << c.heater.heat << " degrees Celsius" << endl;
    cout << "Water Level: " << c.waterReservoir.water << " liter(s)" << endl;
}

int CoffeeMachine::input(CoffeeMachine &c)
{
    while(true)
    {
        cout << "----How many cups of coffee would you like today?----" << endl;
        cout << "--=|    1    |     2     |     3     |     4     |=--" << endl;
        cout << "-----------------------------------------------------" << endl;
        cin >> c.coffeeRequested;
        if(c.coffeeRequested >= 1 && c.coffeeRequested <= 4)
        {
            cout << "Amount of coffee requested is " << c.coffeeRequested << " cups" << endl;
            break;
        }
        else
        {
            cout << "Amount of coffee invalid, please enter an amount within parameters" << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return c.coffeeRequested;
}

float CoffeeMachine::grindBeans(CoffeeMachine &c)
{
    float grinds = c.cupOfCoffee.grindsRequired;
    cout << "Grinding Beans..." << endl;
    if(c.hopper.beans - grinds < 0)
    {
        cout << "Not enough beans in hopper" << endl;
        return 0;
    }
    // Takes from the hopper and grinds the coffee
    c.grinder.grinds += grinds;
    c.hopper.beans -= grinds;

    // informational text output
    cout << grinds << "g of beans have been ground!" << endl;
    cout << c.hopper.beans << "g of beans are remaining" << endl;
    // Returns the grinds as a value
    return c.grinder.grinds;
}

float CoffeeMachine::heatWater(CoffeeMachine &c)
{
    cout <<"Heating water..." << endl;
    if(c.heater.heat == c.heater.heatLimit)
    {
        cout << "Heater is already hot enough for coffee!" << endl;
        cout << "Heat is at " << c.heater.heat << " degrees Celsius" << endl;
        return c.heater.heat;
    }
    c.heater.heat = c.heater.heatLimit;
    cout << "Heat is at " << c.heater.heat << " degrees Celsius" << endl;
    return c.heater.heat;
}

float CoffeeMachine::dripWater(CoffeeMachine &c)
{
    float water = c.cupOfCoffee.waterRequired;
    cout << "Pouring water over grounds..." << endl;
    if(c.waterReservoir.water - water < 0)
    {
        cout << "Insufficient amount of water!" << endl;
        return 0;
    }
    c.waterReservoir.water -= water;
    return water; 


}

void CoffeeMachine::createCoffee(CoffeeMachine &c)
{
    float grinds, heat, water;
    cout << "Starting coffee creation process..." << endl;
    grinds = grindBeans(c);
    heat = heatWater(c);
    water = dripWater(c);

    if(grinds == c.cupOfCoffee.grindsRequired && heat == c.cupOfCoffee.heatRequired && water == c.cupOfCoffee.waterRequired)
    {
        c.grinder.grinds -= c.cupOfCoffee.grindsRequired;
        c.coffeeMade++;
        cout << c.coffeeMade << " cup(s) of coffee have been made" << endl << endl; 
    }
}


CoffeeMachine::CoffeeMachine()
{
    // This ASCII art took me way too long, should've not done it but whatever
    cout << "                      (" << endl;
    cout << "                       )     (" << endl;
    cout << "                ___...(-------)-....___" << endl;
    cout << "            .-``       )    (          ``-." << endl;
    cout << "      .-'``'|-._             )         _.-|" << endl;
    cout << "     /  .--.|   ```---...........---```   |" << endl;
    cout << "     |  |   |                             |" << endl;
    cout << "     |  |   |                             |" << endl;
    cout << "     \\  \\   |                             |" << endl;
    cout << "      `\\ `\\ |                             |" << endl;
    cout << "        `\\ `|                             |" << endl;
    cout << "        _/ /\\                            /" << endl;
    cout << "       (__/  \\                          /" << endl;
    cout << "    _..---``` \\                        /```---.._" << endl;
    cout << " .-'           \\                      /          '-." << endl;
    cout << ":              '-.__             __.-'             :" << endl;
    cout << ":                 ) ``---...---`` (                :" << endl;
    cout << "'._               ``--...___...--``              _.'" << endl;
    cout << " \\``--..__                              __..--``/" << endl;
    cout << "  '._      `''----.....______.....----''`     _.'" << endl;
    cout << "     `--..,,_____                _____,,..--`" << endl;
    cout << "                  `````----`````" << endl << endl;
    cout << "-----------_______________________________-----------" << endl;
    cout << "----------|                               |----------" << endl;
    cout << "----------| Welcome to the Coffee Machine |----------" << endl;
    cout << "----------|_______________________________|----------" << endl << endl;
    // Fills everthing to the max once instanciated for the first time
    CoffeeMachine::hopper.beans = 200;
    CoffeeMachine::heater.heat = 30;
    CoffeeMachine::waterReservoir.water = 1;
}

    
