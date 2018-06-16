/*********************************************************************
 ** Program name: OSU Information System
 ** Author: Joel Huffman
 ** Date: 1/30/2018
 ** Description: Gives the user information about the OSU campus. This
 ** includes buildings, students and instructors and statistics about
 ** each of these objects.
 *********************************************************************/

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include "University.hpp"
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
 ** Allows the user to navigate the information system to find out about
 ** the campus' buildings and people. Accepts a pointer to a populated 
 ** University object.
 *********************************************************************/
int menu(University*);

/*********************************************************************
 ** workMenu:
 ** Prints a list of all the students and instructors at the university.
 ** Lets the user choose from this list and see how many hours they have 
 ** worked. Accepts a pointer to a populated University object.
 *********************************************************************/
int workMenu(University* ptrUni);

#endif /* utils_hpp */
