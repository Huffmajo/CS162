/*********************************************************************
 ** Program name: Doubly-linked List
 ** Author: Joel Huffman
 ** Date: 2/17/2018
 ** Description: Allows users to add, delete and print out nodes of a
 ** doubly-linked list
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