/*********************************************************************
 ** Program name: Zoo Tycoon
 ** Author: Joel Huffman
 ** Date: 2/02/2018
 ** Description: You're the owner of your very own zoo. Choose which
 ** animals to purchase and try to keep from going bankrupt. Random
 ** events happen daily that could be positive or negative. Your animals
 ** can even have babies once they reach adulthood.
 *********************************************************************/
#ifndef Turtle_hpp
#define Turtle_hpp

#include <stdio.h>
#include "Animal.hpp"

/*********************************************************************
 ** Turtle class:
 ** Requires an integer parameter to determine the animal's stating age.
 ** Derived class of Animal.
 *********************************************************************/
class Turtle: public Animal
{
private:
    
public:
    Turtle(int ageIn);
};

#endif /* Turtle_hpp */