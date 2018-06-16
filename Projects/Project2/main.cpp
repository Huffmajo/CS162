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
#include "Tiger.hpp"
#include "utils.hpp"

#include <iostream>
#include <time.h>
using std::cout;

int main() {
    
    //seed random number generator
    srand(time(NULL));
    
    Zoo x;
    Zoo* ptrZoo = &x;
    
    menu(ptrZoo);
    
    return 0;
}
