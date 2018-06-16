/*********************************************************************
 ** Program name: Dice War
 ** Author: Joel Huffman
 ** Date: 1/26/2018
 ** Description: Program simulates a dice war game between two players
 ** with dice type, dice size and number of rounds decided by the user.
 ** Every round's result is printed to the screen with a final printout
 ** showing who won the entire game and the final scores.
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

/*********************************************************************
 ** intValidation:
 ** Checks cin if input is an integer within the minimum and maximum
 ** values. Returns the integer if it is acceptable, lists prompt and
 ** asks again if input is invalid.
 *********************************************************************/
int intValidation(int min, int max, string prompt);

/*********************************************************************
 ** menu:
 ** Asks the user questions to gather data to build the game off of. 
 ** Will continue to build and play games from the users data until they
 ** choose to quit the program.
 *********************************************************************/
int menu();


#endif /* utils_hpp */
