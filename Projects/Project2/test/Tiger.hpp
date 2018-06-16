/*********************************************************************
 ** Program name: Zoo Tycoon
 ** Author: Joel Huffman
 ** Date: 2/02/2018
 ** Description: You're the owner of your very own zoo. Choose which
 ** animals to purchase and try to keep from going bankrupt. Random
 ** events happen daily that could be positive or negative. Your animals
 ** can even have babies once they reach adulthood.
 *********************************************************************/

#ifndef Tiger_hpp
#define Tiger_hpp

#include <stdio.h>
#include "Animal.hpp"

/*********************************************************************
 ** Tiger class:
 ** Requires an integer parameter to determine the animal's stating age.
 ** Derived class of Animal.
 *********************************************************************/
class Tiger: public Animal
{
private:
    
public:
    Tiger(int ageIn);
};

#endif /* Tiger_hpp */
