/*********************************************************************
 ** Program name: Predator-Prey Game
 ** Author: Group 13 (Joel Huffman, Andrew Swaim, Frank Li, Henry Clay)
 ** Date: 2/05/2018
 ** Description: This file describes the methods that will move the
 dbug, starve it and/or have it eat an ant.
 *********************************************************************/

#include "Doodlebug.hpp"
#include "Board.hpp"

/*********************************************************************
** Doodlebug(int startingRow, int startingCol):
** Constructor for the Doodlebug class. Passes the starting row and 
** column to the Critter constructor, and initializes the object's 
** type to DOODLEBUG and daysSinceEaten to 0.
*********************************************************************/
Doodlebug::Doodlebug(int startingRow, int startingCol): Critter(startingRow, startingCol)
{
    type = DOODLEBUG;
    daysSinceEaten = 0;
}

/*********************************************************************
** move(Board& board):
** First checks randomly if there is an Ant object in an adjacent space,
** and if deletes that Ant object and moves to the Ant's space.
** Otherwise picks a random direction and, if it's unoccupied, moves to
** that location.
*********************************************************************/
void Doodlebug::move(Board& board)
{
	// Check randomly if there are any ants in an adjacent space.
    Direction dir = checkSpacesRandomly(board, ANT);
    
    //if an ant is in an adjacent space, eat it.
    if (dir != NONE) {

		// Delete the Ant object to be eaten.
		switch (dir)
		{
		case UP:
			board.delCritter((currRow - 1), currCol);
			daysSinceEaten = 0;
			break;
		case RIGHT:
			board.delCritter(currRow, (currCol + 1));
			daysSinceEaten = 0;
			break;
		case DOWN:
			board.delCritter((currRow + 1), currCol);
			daysSinceEaten = 0;
			break;
		case LEFT:
			board.delCritter(currRow, (currCol - 1));
			daysSinceEaten = 0;
			break;
		}
    }
    
    // If no adjacent Ant to eat, move like an ant and pick a random direction.
    else {

        dir = static_cast<Direction>(rand() % numOfDirections + 1);
		daysSinceEaten++;
    }

	// Move in the indicated directed; either the direction of the eaten ant,
	// or attempt to move in the randomly selected direction.
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
		if (currCol != (board.getBoardWidth() - 1)) {
			if (board.getCritter(currRow, (currCol + 1)) == NULL) {

				board.moveCritter(board.getCritter(currRow, currCol), RIGHT);
				currCol++;
				hasMoved = true;
			}
		}
		break;

	case DOWN:
		// If not at the bottom border and space below is empty.
		if (currRow != (board.getBoardHeight() - 1)) {
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
** First checks to see if the Doodlebug has starved, and if so simply
** deletes the Doodlebug object. Otherwise, creates a new Doodlebug
** if, and only if, the Doodlebug is old enough, hasn't given birth
** in at least 8 turns, and has at least one open adjacent space.
*********************************************************************/
void Doodlebug::update(Board& board) {

	// Reset moved flag.
	hasMoved = false;

	// Check if the Doodlebug has starved.
	if (daysSinceEaten >= 3) {

		// Delete this Doodlebug object.
		board.delCritter(currRow, currCol);
	}
	// If it didn't starve check if it can breed.
	else if (daysSurvived >= 8) {

		// Check for and get a random empty space around the Dbug.
		Direction dir = checkSpacesRandomly(board, EMPTY);

		// If an empty space was found, create a new Dbug object there.
		switch (dir) {

		case UP:

			board.addCritter((currRow - 1), currCol, DOODLEBUG);
			daysSurvived = 0;
			break;
		case RIGHT:

			board.addCritter(currRow, (currCol + 1), DOODLEBUG);
			daysSurvived = 0;
			break;
		case DOWN:

			board.addCritter((currRow + 1), currCol, DOODLEBUG);
			daysSurvived = 0;
			break;
		case LEFT:

			board.addCritter(currRow, (currCol - 1), DOODLEBUG);
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
