/*********************************************************************
 ** Program name: Recursive Functions
 ** Author: Joel Huffman
 ** Date: 2/04/2018
 ** Description: Allows users to run any of three functions created
 ** using recursion. All three programs require string or int input
 ** from the user.
 *********************************************************************/

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
using std::cin;
using std::cout;
using std::string;
using std::stringstream;

int intValidation(int min, int max, string prompt);
int menu();

#endif /* utils_hpp */
