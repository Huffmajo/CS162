/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 13 (Joel Huffman, Andrew Swaim, Frank Li, Henry Clay)
** Date: February 18, 2018
** Description: Critter.cpp, implementation file for the Critter class.
*********************************************************************/

#include "Critter.hpp"
#include "Board.hpp"

/*********************************************************************
** Critter(int startRow, int startCol):
** Constructor for the Critter class. Initializes the current row and col
** of the object, initializes its days survived to 0, as well as the array
** of random directions for shuffling.
*********************************************************************/
Critter::Critter(int startRow, int startCol) {

	currRow = startRow;
	currCol = startCol;
	daysSurvived = 0;
	hasMoved = false;
	numOfDirections = 4;
	randDirections = new Direction[numOfDirections];	// For shuffling.

	// Fill the array used for shuffling.
	for (int i = 0; i < numOfDirections; i++) {
		randDirections[i] = static_cast<Direction>(i + 1);
	}
}

/*********************************************************************
** ~Critter():
** Deallocate memory for the array of random directions.
*********************************************************************/
Critter::~Critter() {

	delete[] randDirections;
}

/*********************************************************************
** checkSpacesRandomly(Board& board, CritterType lookFor):
** Checks each space around the object randomly for the type specified 
** (EMPTY if looking for an empty space for breeding or ANT if its a 
** Doodlebug looking for an Ant.)
*********************************************************************/
Direction Critter::checkSpacesRandomly(Board& board, CritterType lookFor) {
    
	Critter* critPtr;
	bool directionFound = false;

	shuffleDirections();

	int i = 0;
	do {

		switch (randDirections[i]) {

		case UP:

			// Make sure its not at the top border.
			if (currRow != 0) {

				// Get critter pointer to above.
				critPtr = board.getCritter((currRow - 1), currCol);

				// Check for empty space above.
				if (lookFor == EMPTY && critPtr == NULL) {
					return UP;
				}
				// Or check for ant above.
				else if (lookFor == ANT && critPtr != NULL) {

					if (critPtr->getType() == ANT) {
						return UP;
					}
				}
			}

			break;
		case RIGHT:

			// Make sure its not at the right border.
			if (currCol != (board.getBoardWidth() - 1)) {

				// Get the critter pointer to the right.
				critPtr = board.getCritter(currRow, (currCol + 1));

				// Check for empty space to the right.
				if (lookFor == EMPTY && critPtr == NULL) {
					return RIGHT;
				}
				// Or check for ant to the right.
				else if (lookFor == ANT && critPtr != NULL) {

					if (critPtr->getType() == ANT) {
						return RIGHT;
					}
				}
			}

			break;
		case DOWN:

			// Make sure its not at the bottom border.
			if (currRow != (board.getBoardHeight() - 1)) {

				// Get critter pointer below.
				critPtr = board.getCritter((currRow + 1), currCol);

				// Check for empty space below.
				if (lookFor == EMPTY && critPtr == NULL) {
					return DOWN;
				}
				// Or check for ant below.
				else if (lookFor == ANT && critPtr != NULL) {

					if (critPtr->getType() == ANT) {
						return DOWN;
					}
				}
			}

			break;
		case LEFT:

			// Make sure its not at the left border.
			if (currCol != 0) {

				// Get critter pointer to the left.
				critPtr = board.getCritter(currRow, (currCol - 1));

				// Check for empty space to the left.
				if (lookFor == EMPTY && critPtr == NULL) {
					return LEFT;
				}
				// Or check for ant to the left.
				else if (lookFor == ANT && critPtr != NULL) {

					if (critPtr->getType() == ANT) {
						return LEFT;
					}
				}
			}
			break;
		}

		i++;
	} while (i < numOfDirections && directionFound == false);

	// If no direction found return NONE
	return NONE;
}

/*********************************************************************
** shuffleDirections():
** Shuffle the array of directions so that they are in a new random
** order for iterating through.
*********************************************************************/
void Critter::shuffleDirections() {

	Direction temp;		// To hold a temporary index for swapping.
	int index2;			// To hold an second index for swapping.

	for (int index1 = numOfDirections - 1; index1 > 0; index1--) {

		// Get a random index.
		index2 = rand() % index1;

		// Swap the current index with the random index.
		temp = randDirections[index1];
		randDirections[index1] = randDirections[index2];
		randDirections[index2] = temp;
	}
}

/*********************************************************************
** incDaysSurvived():
** Increase the daysSurived of the Critter object by 1.
*********************************************************************/
void Critter::incDaysSurvived() { this->daysSurvived++; }

// Getters and setters.
CritterType Critter::getType() { return this->type; }
bool Critter::checkIfMoved() { return this->hasMoved; }

int Critter::getDaysSurvived() { return this->daysSurvived; }
void Critter::setDaysSurvived(int days) { this->daysSurvived = days; }

int Critter::getPositionRow() { return this->currRow; }
void Critter::setPositionRow(int row) { this->currRow = row; }

int Critter::getPositionCol() { return this->currCol; }
void Critter::setPositionCol(int col) { this->currCol = col; }
