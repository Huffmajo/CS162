/*********************************************************************
 ** Program name: Zoo Tycoon
 ** Author: Joel Huffman
 ** Date: 2/02/2018
 ** Description: You're the owner of your very own zoo. Choose which
 ** animals to purchase and try to keep from going bankrupt. Random
 ** events happen daily that could be positive or negative. Your animals
 ** can even have babies once they reach adulthood.
 *********************************************************************/

#include "Zoo.hpp"
#include <iostream>
#include <stdlib.h>
using std::cout;

Zoo::Zoo()
{
    funds = 50000;
    day = 0;
    bonus = 0;
    tigerCageSize = 10;
    penguinCageSize = 10;
    turtleCageSize = 10;
    numTigers = 0;
    numPenguins = 0;
    numTurtles = 0;
    
    tigerCage = new Animal*[tigerCageSize];
    for (int i = 0; i < tigerCageSize; i++)
    {
        tigerCage[i] = NULL;
    }
    
    penguinCage = new Animal*[penguinCageSize];
    for (int i = 0; i < penguinCageSize; i++)
    {
        penguinCage[i] = NULL;
    }
    
    turtleCage = new Animal*[turtleCageSize];
    for (int i = 0; i < turtleCageSize; i++)
    {
        turtleCage[i] = NULL;
    }

}

int Zoo::getFunds()
{
    return funds;
}

int Zoo::getDay()
{
    return day;
}

int Zoo::getBonus()
{
    return bonus;
}

int Zoo::getTigerCageSize()
{
    return tigerCageSize;
}

Animal** Zoo::getTigerCage()
{
    return tigerCage;
}

Animal** Zoo::getPenguinCage()
{
    return penguinCage;
}

Animal** Zoo::getTurtleCage()
{
    return turtleCage;
}

int Zoo::getPenguinCageSize()
{
    return penguinCageSize;
}

int Zoo::getNumPenguins()
{
    return numPenguins;
}

int Zoo::getTurtleCageSize()
{
    return turtleCageSize;
}

int Zoo::getNumTurtle()
{
    return numTurtles;
}

void Zoo::setPenguinCageSize(int penguinCageSizeIn)
{
    penguinCageSize = penguinCageSizeIn;
}

void Zoo::setNumPenguins(int numPengIn)
{
    numPenguins = numPengIn;
}

void Zoo::setTurtleCageSize(int turtleCageSizeIn)
{
    turtleCageSize = turtleCageSizeIn;
}

void Zoo::setNumTurtles(int numTurtlesIn)
{
    numTurtles = numTurtlesIn;
}

int Zoo::getNumTigers()
{
    return numTigers;
}

void Zoo::setNumTigers(int numTigersIn)
{
    numTigers = numTigersIn;
}

void Zoo::setTigerCageSize(int tigerCageSizeIn)
{
    tigerCageSize = tigerCageSizeIn;
}

void Zoo::setFunds(int fundsIn)
{
    funds = fundsIn;
}

void Zoo::setDay(int dayIn)
{
    day = dayIn;
}

void Zoo::setBonus(int bonusIn)
{
    bonus = bonusIn;
}

void Zoo::incrementDay()
{
    setDay(getDay() + 1);
    
    //age each tiger one day
    for (int i = 0; i < getNumTigers(); i++)
    {
        getTigerCage()[i]->setAge(getTigerCage()[i]->getAge()+1);
    }

    //age each penguin one day
    for (int i = 0; i < getNumPenguins(); i++)
    {
        getPenguinCage()[i]->setAge(getPenguinCage()[i]->getAge()+1);
    }
    
    //age each turtle one day
    for (int i = 0; i < getNumTurtle(); i++)
    {
        getTurtleCage()[i]->setAge(getTurtleCage()[i]->getAge()+1);
    }
}

void Zoo::addTiger(int ageIn)
{
    if (getNumTigers() >= getTigerCageSize())
    {
        doubleTigerCageSize();
    }
    
    //only birthed tigers are free
    if (ageIn > 0)
    {
        setFunds(getFunds() - 10000);
    }
    
    //create new tiger and add it to the cage
    tigerCage[numTigers] = new Tiger(ageIn);

    
    setNumTigers(getNumTigers() + 1);
}

void Zoo::removeTiger(int numTigerIn)
{
    setNumTigers(numTigerIn - 1);
    delete tigerCage[getNumTigers()];
    tigerCage[getNumTigers()] = NULL;
}

void Zoo::addPenguin(int ageIn)
{
    if (getNumPenguins() >= getPenguinCageSize())
    {
        doublePenguinCageSize();
    }
    
    //only birthed penguins are free
    if (ageIn > 0)
    {
        setFunds(getFunds() - 1000);
    }
    
    //create new penguin and add it to the cage
    getPenguinCage()[numPenguins] = new Penguin(ageIn);
    
    setNumPenguins(getNumPenguins() + 1);
}


void Zoo::removePenguin(int numPeng)
{
    setNumPenguins(numPeng - 1);
    delete penguinCage[getNumPenguins()];
    penguinCage[getNumPenguins()] = NULL;
}


void Zoo::addTurtle(int ageIn)
{
    if (getNumTurtle() >= getTurtleCageSize())
    {
        doubleTurtleCageSize();
    }
    
    //only birthed turtles are free
    if (ageIn > 0)
    {
        setFunds(getFunds() - 100);
    }
    
    getTurtleCage()[numTurtles] = new Turtle(ageIn);
    setNumTurtles(getNumTurtle() + 1);
}


void Zoo::removeTurtle(int numTurtle)
{
    setNumTurtles(numTurtle - 1);
    delete turtleCage[getNumTurtle()];
    turtleCage[getNumTurtle()] = NULL;
}

void Zoo::doubleTigerCageSize()
{    
    //create new cage with larger size
    Animal** tempCage = new Animal*[getTigerCageSize() * 2];
    
    //copy all animals from old cage to new one
    for (int i = 0; i < getTigerCageSize(); i++)
    {
        tempCage[i] = getTigerCage()[i];
        tempCage[i + getTigerCageSize()] = NULL;
    }
    
    //delete old array, point to new array
    for (int i = 0; i < getTigerCageSize(); i++)
    {
        delete[] tigerCage[i];
    }
    delete[] tigerCage;
    tigerCage = tempCage;
    
    //update cageSize
    setTigerCageSize(getTigerCageSize() * 2);
}

void Zoo::doublePenguinCageSize()
{
    //create new cage with larger size
    Animal** tempCage = new Animal*[getPenguinCageSize() * 2];
    
    //copy all animals from old cage to new one
    for (int i = 0; i < getPenguinCageSize(); i++)
    {
        tempCage[i] = getPenguinCage()[i];
        tempCage[i + getPenguinCageSize()] = NULL;
    }
    
    //have old pointer point to new, bigger cage
    for (int i = 0; i < getPenguinCageSize(); i++)
    {
        delete[] penguinCage[i];
    }
    delete[] penguinCage;
    penguinCage = tempCage;
    
    //update cageSize
    setPenguinCageSize(getPenguinCageSize() * 2);
}

void Zoo::doubleTurtleCageSize()
{
    //create new cage with larger size
    Animal** tempCage = new Animal*[getTurtleCageSize() * 2];
    
    //copy all animals from old cage to new one
    for (int i = 0; i < getTurtleCageSize(); i++)
    {
        tempCage[i] = getTurtleCage()[i];
        tempCage[i + getTurtleCageSize()] = NULL;
    }
    
    //have old pointer point to new, bigger cage
    for (int i = 0; i < getTurtleCageSize(); i++)
    {
        delete[] turtleCage[i];
    }
    delete[] turtleCage;
    turtleCage = tempCage;
    
    //update cageSize
    setTurtleCageSize(getTurtleCageSize() * 2);}

void Zoo::doubleCageSize(Animal** cageIn, int oldCageSize)
{
    //update cageSize
    setTigerCageSize(oldCageSize * 2);
    
    //create new cage with larger size
    Animal** tempCage = new Animal*[getTigerCageSize()];
    
    //copy all animals from old cage to new one
    for (int i = 0; i < oldCageSize; i++)
    {
        tempCage[i] = cageIn[i];
    }
    
    //have old pointer point to new, bigger cage
    cageIn = tempCage;
}

void Zoo::feedAnimals()
{
    int feedCost = 0;
    
    //tiger feed cost
    if (getNumTigers() > 0)
    {
        feedCost += numTigers * tigerCage[0]->getBaseFoodCost();
    }
    
    
    //penguin feed cost
    if (getNumPenguins() > 0)
    {
        feedCost += getNumPenguins() * penguinCage[0]->getBaseFoodCost();
    }

    //turtles feed cost
    if (numTurtles > 0)
    {
        feedCost += numTurtles * turtleCage[0]->getBaseFoodCost();
    }
    
    
    setFunds(getFunds()-feedCost);
    
}


void Zoo::randomEvent()
{
    int event = rand() % 4;
    
    switch(event)
    {
        case 0:
            randomDeath();
            break;
        
        case 1:
            randomBonus();
            break;
            
        case 2:
            randomBirth();
            break;
            
        case 3:
            cout << "Today was just a usual day at the zoo.\n";
            break;
            
        default:
            cout << "error";
            break;
    }
}

void Zoo::randomDeath()
{
    int randAnimal = rand() % 3;
    
    switch(randAnimal)
    {
        case 0:
            if (getNumTigers() > 0)
            {
                removeTiger(getNumTigers());
            }
            cout << "You had a random tiger die today :(\n";
            break;
            
        case 1:
            if (getNumPenguins() > 0)
            {
                removePenguin(getNumPenguins());
            }
            cout << "You had a random penguin die today :(\n";
            break;
            
        case 2:
            if (getNumTurtle() > 0)
            {
                removeTurtle(getNumTurtle());
            }
            cout << "You had a random turtle die today :(\n";
            break;
            
        default:
            cout << "These animals won't die D:\n";
            break;
    }
}

void Zoo::randomBonus()
{
    int randBoom = rand() % 251 + 250;
    setBonus(getNumTigers() * randBoom);
    cout << "You got a bonus of $" << randBoom << " per tiger today!\n";
    cout << "That netted you $" << getBonus() << " for your " << getNumTigers() << " tigers!\n";
}

void Zoo::randomBirth()
{
    int randAnimal = rand() % 3;
    
    switch(randAnimal)
    {
        case 0:
            for (int i = 0; i < getNumTigers(); i++)
            {
                if (getTigerCage()[i]->getAge() >= 3)
                {
                    addTiger(0);
                    cout << "One of your tigers gave birth today :D\n";
                    break;
                }
            }
            break;
            
        case 1:
            for (int i = 0; i < getNumPenguins(); i++)
            {
                if (getPenguinCage()[i]->getAge() >= 3)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        addPenguin(0);
                    }
                    cout << "One of your penguins gave birth today :D\n";
                    break;
                }
            }
            break;
            
        case 2:
            for (int i = 0; i < getNumTurtle(); i++)
            {
                if (getTurtleCage()[i]->getAge() >= 3)
                {
                    for (int i = 0; i < 10; i++)
                    {
                        addTurtle(0);
                    }
                    cout << "One of your turtles gave birth today :D\n";
                    break;
                }
            }
            break;
            
        default:
            cout << "These animals aren't creating D:\n";
            break;
    }

}

void Zoo::dailyProfit()
{
    int totalProfit = 0;
    
    //payout from tigers
    for (int i = 0; i < getNumTigers(); i++)
    {
        totalProfit += getTigerCage()[i]->getPayoff();
    }
    

    //payout from penguins
    for (int i = 0; i < getNumPenguins(); i++)
    {
        totalProfit += getPenguinCage()[i]->getPayoff();
    }
    
    //payout from turtles
    for (int i = 0; i < getNumTurtle(); i++)
    {
        totalProfit += getTurtleCage()[i]->getPayoff();
    }
    
    totalProfit += getBonus();
    setFunds(getFunds() + totalProfit);
}

Zoo::~Zoo()
{
    //deallocate/delete dynamic memory
    for (int i = 0; i < getTigerCageSize(); i++)
    {
        delete[] tigerCage[i];
    }
    delete[] tigerCage;
    
    for (int i = 0; i < getPenguinCageSize(); i++)
    {
        delete[] penguinCage[i];
    }
    delete[] penguinCage;
    
    for (int i = 0; i < getTurtleCageSize(); i++)
    {
        delete[] turtleCage[i];
    }
    delete[] turtleCage;
}

