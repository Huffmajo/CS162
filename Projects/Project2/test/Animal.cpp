/*********************************************************************
 ** Program name: Zoo Tycoon
 ** Author: Joel Huffman
 ** Date: 2/02/2018
 ** Description: You're the owner of your very own zoo. Choose which
 ** animals to purchase and try to keep from going bankrupt. Random
 ** events happen daily that could be positive or negative. Your animals
 ** can even have babies once they reach adulthood.
 *********************************************************************/

#include "Animal.hpp"

Animal::Animal(int ageIn)
{
    setAge(ageIn);
}

int Animal::getAge()
{
    return age;
}

int Animal::getCost()
{
    return cost;
}

int Animal::getnumberOfBabies()
{
    return numberOfBabies;
}

int Animal::getBaseFoodCost()
{
    return baseFoodCost;
}

int Animal::getPayoff()
{
    return payoff;
}

void Animal::setAge(int ageIn)
{
    age = ageIn;
}

void Animal::setCost(int costIn)
{
    cost = costIn;
}

void Animal::setnumberOfBabies(int babiesIn)
{
    numberOfBabies = babiesIn;
}

void Animal::setBaseFoodCost(int baseFoodIn)
{
    baseFoodCost = baseFoodIn;
}

void Animal::setPayoff(int payoffIn)
{
    payoff = payoffIn;
}
