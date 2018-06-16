/*********************************************************************
 ** Program name: Buffer and Palindrome
 ** Author: Joel Huffman
 ** Date: 03/5/18
 ** Description: Header for the utility functions. Declares the variables
 ** and functions for the menus and input validation.
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
int bufferMenu();
int palindromeMenu();
int menu();

#endif /* utils_hpp */
