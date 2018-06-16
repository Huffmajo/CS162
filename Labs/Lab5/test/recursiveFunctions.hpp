/*********************************************************************
 ** Program name: Recursive Functions
 ** Author: Joel Huffman
 ** Date: 2/04/2018
 ** Description: Allows users to run any of three functions created
 ** using recursion. All three programs require string or int input
 ** from the user.
 *********************************************************************/

#ifndef recursiveFunctions_hpp
#define recursiveFunctions_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::string;

string stringReverser(string stringIn);

int arraySum(int* ptrIntArray, int numElements);

int triangularNumber(int n);

#endif /* recursiveFunctions_hpp */
