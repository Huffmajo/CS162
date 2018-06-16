/*********************************************************************
 ** Program name: Zoo Tycoon
 ** Author: Joel Huffman
 ** Date: 2/02/2018
 ** Description: You're the owner of your very own zoo. Choose which
 ** animals to purchase and try to keep from going bankrupt. Random
 ** events happen daily that could be positive or negative. Your animals
 ** can even have babies once they reach adulthood.
 *********************************************************************/

#include "Penguin.hpp"

Penguin::Penguin(int ageIn): Animal(ageIn)
{
    setAge(ageIn);
    setCost(1000);
    setnumberOfBabies(5);
    setBaseFoodCost(10);
    setPayoff(getCost()/10);
}
