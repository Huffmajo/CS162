/*********************************************************************
 ** Program name: Zoo Tycoon
 ** Author: Joel Huffman
 ** Date: 2/02/2018
 ** Description: You're the owner of your very own zoo. Choose which
 ** animals to purchase and try to keep from going bankrupt. Random
 ** events happen daily that could be positive or negative. Your animals
 ** can even have babies once they reach adulthood.
 *********************************************************************/

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Zoo.hpp"
using std::cin;
using std::cout;
using std::string;
using std::stringstream;

/*********************************************************************
 ** intValidation:
 ** Checks cin if input is an integer within the minimum and maximum
 ** values. Returns the integer if it is acceptable, lists prompt and
 ** asks again if input is invalid.
 *********************************************************************/
int intValidation(int min, int max, string prompt);

/*********************************************************************
 ** menu:
 ** Allows the user to make choices within the game by integer input.
 ** Requires a Zoo pointer as a parameter.
 *********************************************************************/
int menu(Zoo*);

#endif /* utils_hpp */
