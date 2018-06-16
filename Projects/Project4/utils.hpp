/*********************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Joel Huffman
 ** Date: 2/25/2018
 ** Description: Allows users to create teams of fantasy characters and
 ** have these teams battle one another to ultimately claim victory.
 *********************************************************************/

#ifndef utils_hpp
#define utils_hpp

#include "Queue.hpp"
#include <iostream>
#include <string>
#include <sstream>
using std::cin;
using std::cout;
using std::string;
using std::stringstream;

int intValidation(int min, int max, string prompt);
int menu();
int setupTournament(int teamSize, Queue* team1, Queue* team2);

#endif /* utils_hpp */
