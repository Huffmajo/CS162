/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 13 (Joel Huffman, Andrew Swaim, Frank Li, Henry Clay)
** Date: February 18, 2018
** Description: Game.hpp, specification file for the Game class.
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Critter.hpp"

#include <iostream>
using std::cout;

class Board {

private:
	// Member variables.
	Critter*** board;
	int boardWidth;
	int boardHeight;
    int quantAnts;
    int quantDbugs;

	// Member functions.
	void randomlyPlace(CritterType);

public:
	// Constructor and destructor.
	Board(int rows, int cols, int bugs, int ants);
	~Board();

	// Getters and setters.
	int getBoardWidth();
	int getBoardHeight();
    int getQuantDbugs();
    int getQuantAnts();

	// Main functions.
	void timeStep();
	Critter* getCritter(int row, int col);
	void moveCritter(Critter*, Direction);
	void addCritter(int row, int col, CritterType);
	void delCritter(int row, int col);
	void drawBoard();

};

#endif // !BOARD_HPP
