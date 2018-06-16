/*********************************************************************
 ** Program name: Predator-Prey Game
 ** Author: Group 13 (Joel Huffman, Andrew Swaim, Frank Li, Henry Clay)
 ** Date: February 18, 2018
 ** Description: Ant.cpp, implementation file for the Ant class.
 *********************************************************************/

#include "Ant.hpp"
#include "Board.hpp"

#include <iostream>
using std::cout;

 /*********************************************************************
 ** Ant(int startingRow, int startingCol):
 ** Constructor for the Ant class. Passes the starting row and column 
 ** to the Critter constructor, and initializes the object's type to ANT.
 *********************************************************************/
Ant::Ant(int startingRow, int startingCol) : Critter(startingRow, startingCol) {

	type = ANT;
}

/*********************************************************************
 ** move(Board& board):
 ** Picks a random direction, if it's unoccupied the ant is moved to 
 ** that location.
 *********************************************************************/
void Ant::move(Board& board) {
    
	Direction dir = static_cast<Direction>(rand() % numOfDirections + 1);

	switch (dir) {

	case UP:

		// If not at the top border and space above is empty.
		if (currRow != 0) {

			if (board.getCritter((currRow - 1), currCol) == NULL) {

				board.moveCritter(board.getCritter(currRow, currCol), UP);
				currRow--;
				hasMoved = true;
			}
		}
		break;

	case RIGHT:

		// If not at the right border and space to the right is empty.
		if (currCol != (board.getBoardWidth()-1)) {

			if (board.getCritter(currRow, (currCol + 1)) == NULL) {

				board.moveCritter(board.getCritter(currRow, currCol), RIGHT);
				currCol++;
				hasMoved = true;
			}
		}
		break;

	case DOWN:		

		// If not at the bottom border and space below is empty.
		if (currRow != (board.getBoardHeight()-1)) {

			if (board.getCritter((currRow + 1), currCol) == NULL) {

				board.moveCritter(board.getCritter(currRow, currCol), DOWN);
				currRow++;
				hasMoved = true;
			}
		}
		break;

	case LEFT:

		// If not at the left border and space to the left is empty.
		if (currCol != 0) {

			if (board.getCritter(currRow, (currCol - 1)) == NULL) {

				board.moveCritter(board.getCritter(currRow, currCol), LEFT);
				currCol--;
				hasMoved = true;
			}
		}
		break;
	}
}

/*********************************************************************
 ** update(Board& board):
 ** Creates a new ant if, and only if, the ant is old enough, hasn't 
 ** given birth in at least 3 turns, and has at least one open adjacent
 ** space.
 *********************************************************************/
void Ant::update(Board& board) {

	// Reset moved flag.
	hasMoved = false;

	// Check if the Ant can breed.
	if (daysSurvived >= 3) {

		// Check for and get a random empty space around the Ant.
		Direction dir = checkSpacesRandomly(board, EMPTY);

		// If an empty space was found, create a new Ant object there.
		switch (dir) {

		case UP:

			board.addCritter((currRow - 1), currCol, ANT);
			daysSurvived = 0;
			break;
		case RIGHT:

			board.addCritter(currRow, (currCol + 1), ANT);
			daysSurvived = 0;
			break;
		case DOWN:

			board.addCritter((currRow + 1), currCol, ANT);
			daysSurvived = 0;
			break;
		case LEFT:

			board.addCritter(currRow, (currCol - 1), ANT);
			daysSurvived = 0;
			break;
		case NONE:

			// No empty space was found so do not breed.
			// daysSurvived continues to increment until a successful
			// breed occurs.
			break;
		}
	}
}

