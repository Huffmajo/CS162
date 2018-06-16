/*********************************************************************
 ** Program name: Predator-Prey Game
 ** Author: Group 13 (Joel Huffman, Andrew Swaim, Frank Li, Henry Clay)
 ** Date: February 18, 2018
 ** Description: Menu.cpp, header file for the Menu class 
 *********************************************************************/

#include "Board.hpp"

using std::cin;
using std::endl;

class Menu {
	
public:
	Menu();
	void runSim();

private:
	int isInputInt(int ceiling = 2, int base = 1); // validates input
	int numOfSteps = 9;
	int initRows = 0;
	int initCols = 0;
	int initBugs = 0;
    int initAnts = 0;
    bool keepPlaying = true;
	int keepPlayingChoice = 0;
};
