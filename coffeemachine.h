#ifndef COFFEEMACHINE_H
#define COFFEEMACHINE_H

class CoffeeMachine
{
    struct Hopper
    {
        float beans;
        float beansLimit = 200;
    } hopper;
    struct Heater
    {
        float heat;
        float heatLimit = 100;
    } heater;
    struct WaterReservoir
    {
        float water;
        float waterLimit = 1;
    } waterReservoir;
    struct Grinder
    {
        float grinds;

    } grinder;
    struct CupOfCoffee
    {
        float grindsRequired = 50;
        float heatRequired = 100;
        float waterRequired = 0.25;
    } cupOfCoffee;
       
    public:
        int coffeeRequested;
        int coffeeMade;
        // Default Constructor
        CoffeeMachine();
        // Displays the current amount of beans, current heat, as well as water level
        void displayCurrentResources(CoffeeMachine &c);
        // Takes the beans from the coffee machine and makes them into
        // grounds for the coffee
        float grindBeans(CoffeeMachine &c);
        // Heats the water to 100 C, once it is at that point it should
        // keep the heat there if making multiple cups
        float heatWater(CoffeeMachine &c);
        // Takes water from the reservoir
        float dripWater(CoffeeMachine &c);
        // Stores the amount of cups the user wants
        int input(CoffeeMachine &c);
        // Creates the cup of coffee
        void createCoffee(CoffeeMachine &c);

        
};

#endif