/*********************************************************************
 ** Program name: Zoo Tycoon
 ** Author: Joel Huffman
 ** Date: 2/02/2018
 ** Description: You're the owner of your very own zoo. Choose which
 ** animals to purchase and try to keep from going bankrupt. Random
 ** events happen daily that could be positive or negative. Your animals
 ** can even have babies once they reach adulthood.
 *********************************************************************/

#ifndef Zoo_hpp
#define Zoo_hpp

#include <stdio.h>
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

/*********************************************************************
 ** Zoo class:
 ** Contains dynamic array 'cages' for each animal type. Can add or remove
 ** animals from the zoo. Runs each day as an entity with random events 
 ** happening.
 *********************************************************************/
class Zoo
{
private:
    int funds;
    int day;
    int bonus;
    
    int tigerCageSize;
    int numTigers;
    Animal** tigerCage;
    int penguinCageSize;
    int numPenguins;
    Animal** penguinCage;
    int turtleCageSize;
    int numTurtles;
    Animal** turtleCage;
    
public:
    Zoo();
    int getFunds();
    int getDay();
    int getBonus();
    int getTigerCageSize();
    int getNumTigers();
    void setFunds(int fundsIn);
    void setDay(int dayIn);
    void setBonus(int bonusIn);
    void setNumTigers(int numTigersIn);
    void setTigerCageSize(int tigerCageSizeIn);
    Animal** getTigerCage();
    Animal** getPenguinCage();
    Animal** getTurtleCage();
    int getPenguinCageSize();
    int getNumPenguins();
    int getTurtleCageSize();
    int getNumTurtle();
    void setPenguinCageSize(int penguinCageSizeIn);
    void setNumPenguins(int numPengIn);
    void setTurtleCageSize(int turtleCageSizeIn);
    void setNumTurtles(int numTurtlesIn);
    ~Zoo();
    
    /*********************************************************************
     ** incrementDay:
     ** Ages all the animals one day.
     *********************************************************************/
    void incrementDay();
    
    /*********************************************************************
     ** addTiger:
     ** Creates a tiger object and adds it to the tigerCage. Accepts an 
     ** integer for it's age. If tiger wasn't born at the zoo, user is
     ** charged for the animal.
     *********************************************************************/
    void addTiger(int ageIn);
    
    /*********************************************************************
     ** removeTiger:
     ** Removes a tiger from the tigerCage to simulate death. This is done
     ** by changing the pointer to NULL.
     *********************************************************************/
    void removeTiger(int numTiger);
    
    /*********************************************************************
     ** addPenguin:
     ** Creates a penguin object just like the addTiger function
     *********************************************************************/
    void addPenguin(int ageIn);
    
    /*********************************************************************
     ** removePenguin:
     ** Removes a penguin from the cage just like the removeTiger function
     *********************************************************************/
    void removePenguin(int numPeng);
    
    /*********************************************************************
     ** addTurtle:
     ** Creates a penguin object just like the addTiger function
     *********************************************************************/
    void addTurtle(int ageIn);
    
    /*********************************************************************
     ** removeTurtle:
     ** Removes a turtle from the cage just like the removeTiger function
     *********************************************************************/
    void removeTurtle(int numTurtle);
    
    /*********************************************************************
     ** doubleTigerCageSize:
     ** Creates a new dynamic array "cage "twice the size of the original and
     ** points to the new array. A dynamic array of pointers to animal
     ** objects and the size of that array are needed.
     *********************************************************************/
    void doubleTigerCageSize();

    /*********************************************************************
     ** doublePenguinCageSize:
     ** Creates a new dynamic array "cage "twice the size of the original and
     ** points to the new array. A dynamic array of pointers to animal
     ** objects and the size of that array are needed.
     *********************************************************************/
    void doublePenguinCageSize();
    
    /*********************************************************************
     ** doubleTurtleCageSize:
     ** Creates a new dynamic array "cage "twice the size of the original and
     ** points to the new array. A dynamic array of pointers to animal
     ** objects and the size of that array are needed.
     *********************************************************************/
    void doubleTurtleCageSize();
    
    /*********************************************************************
     ** doubleCageSize:
     ** Creates a new dyncamic array twice the size of the original and 
     ** points to the new array. A dynamic array of pointers to animal 
     ** objects and the size of that array are needed.
     *********************************************************************/
    void doubleCageSize(Animal** cageIn, int oldCageSize);
    
    /*********************************************************************
     ** feedAnimals:
     ** Deducts the costs of feeding all the animals from the total funds.
     *********************************************************************/
    void feedAnimals();
    
    /*********************************************************************
     ** randomEvent:
     ** Chooses one of the three random events and executes it. Each event 
     ** is equally likely to be chosen.
     *********************************************************************/
    void randomEvent();
    
    /*********************************************************************
     ** random Death:
     ** Chooses a random animal type to die. The chosen animal type is 
     ** removed from it's cage.
     *********************************************************************/
    void randomDeath();
    
    /*********************************************************************
     ** randomBonus:
     ** A random bonus from 250-500 is generated. The user is granted this
     ** bonus for every tiger they possess.
     *********************************************************************/
    void randomBonus();
    
    /*********************************************************************
     ** randomBirth:
     ** A random animal type is chosen. If a animal of that type exists 
     ** that older than age 2, they create a brood of however many more
     animals of that same type.
     *********************************************************************/
    void randomBirth();
    
    /*********************************************************************
     ** dailyProfit:
     ** The payoff from every animal and the potential bonus for tigers are
     ** added to the total funds.
     *********************************************************************/
    void dailyProfit();
    
};

#endif /* Zoo_hpp */
