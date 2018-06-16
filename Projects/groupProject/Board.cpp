/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 13 (Joel Huffman, Andrew Swaim, Frank Li, Henry Clay)
** Date: February 18, 2018
** Description: Game.cpp, implementation file for the Game class.
*********************************************************************/

#include "Board.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"


/*********************************************************************
** Game(int numOfRows, int numOfCols, int numOfBugs, int numOfAnts):
** Constructor for the Game class. Initializes the boardHeight and boardWidth
** member variables. Allocates memory for the board member variable, and initializes
** each space on the board to NULL. Fill the board randomly with the number of 
** doodlebugs and ants specified by the user.
*********************************************************************/
Board::Board(int numOfRows, int numOfCols, int numOfBugs, int numOfAnts) {

	// Initialize member variables.
	boardHeight = numOfRows;
	boardWidth = numOfCols;
    quantDbugs = numOfBugs;
    quantAnts = numOfAnts;

	// Allocate memory.
	board = new Critter**[numOfRows];
	for (int row = 0; row < numOfRows; row++) {

		board[row] = new Critter*[numOfCols];
		for (int col = 0; col < numOfCols; col++) {

			board[row][col] = NULL;
		}
	}

	// Place doodlebugs and ants randomly.
	for (int bugs = 0; bugs < numOfBugs; bugs++) {

		randomlyPlace(DOODLEBUG);
	}

	for (int ants = 0; ants < numOfAnts; ants++) {

		randomlyPlace(ANT);
	}
}


/*********************************************************************
** ~Game():
** Destructor for the Game class. Deallocates the memory for the board 
** and the arrays of row and col indexes before the Game object is also 
** deleted.
*********************************************************************/
Board::~Board() {

	for (int row = 0; row < boardHeight; row++) {

		for (int col = 0; col < boardWidth; col++) {

			delete board[row][col];
		}

		delete[] board[row];
	}
	delete[] board;
}


/*********************************************************************
** randomlyPlace(int numberOfDBugs, int numOfAnts):
** Picks a random spot on the board and checks if it is empty, and if so 
** places the doodlebug or ant in the empty space. If the space is not empty, 
** another spot is chosen until a free space is found.
*********************************************************************/
void Board::randomlyPlace(CritterType type) {

	bool placedSuccessfully = false;
	int randomRow;
	int randomCol;

	do {

		randomRow = rand() % boardHeight;
		randomCol = rand() % boardWidth;

		if (board[randomRow][randomCol] == NULL) {

			switch (type) 
			{
			case ANT:

				board[randomRow][randomCol] = new Ant(randomRow, randomCol);
				placedSuccessfully = true;
				break;
			case DOODLEBUG:

				board[randomRow][randomCol] = new Doodlebug(randomRow, randomCol);
				placedSuccessfully = true;
				break;
			}
		}

	} while (placedSuccessfully == false);
}


/*********************************************************************
** timeStep():
** Loop through the array of Critters and update each one, passing a pointer
** to this Game object so the Critters have the information necessary to 
** move, breed, etc.
*********************************************************************/
void Board::timeStep() {

	int row;
	int col;

	// Move each Doodlebug.
	for (row = 0; row < boardHeight; row++) {
		for (int col = 0; col < boardWidth; col++) {

			if (board[row][col] != NULL) {

				if (board[row][col]->getType() == DOODLEBUG && !(board[row][col]->checkIfMoved())) {

					board[row][col]->move(*this);
				}
			}
		}
	}

	// Move each Ant.
	for (row = 0; row < boardHeight; row++) {
		for (int col = 0; col < boardWidth; col++) {

			if (board[row][col] != NULL) {

				if (board[row][col]->getType() == ANT && !(board[row][col]->checkIfMoved())) {

					board[row][col]->move(*this);
				}
			}
		}
	}

	// Age each critter by 1 (indicating 1 time step).
	for (row = 0; row < boardHeight; row++) {
		for (int col = 0; col < boardWidth; col++) {

			if (board[row][col] != NULL) {

				board[row][col]->incDaysSurvived();
			}
		}
	}

	// Breed or starve each Doodlebug if able.
	for (row = 0; row < boardHeight; row++) {
		for (int col = 0; col < boardWidth; col++) {

			if (board[row][col] != NULL) {

				if (board[row][col]->getType() == DOODLEBUG) {

					board[row][col]->update(*this);
				}
			}
		}
	}

	// Breed each Ant if able.
	for (row = 0; row < boardHeight; row++) {
		for (int col = 0; col < boardWidth; col++) {

			if (board[row][col] != NULL) {

				if (board[row][col]->getType() == ANT) {

					board[row][col]->update(*this);
				}
			}
		}
	}

}

/*********************************************************************
** drawBoard():
** Draws the current board to the screen.
*********************************************************************/
void Board::drawBoard() {

	// Top border.
	for (int col = 0; col < (boardWidth + 2); col++) {

		cout << "-";
	}
	cout << "\n";

	for (int row = 0; row < boardHeight; row++) {

		// Left border.
		cout << "|";

		for (int col = 0; col < boardWidth; col++) {

			// If the space is empty.
			if (board[row][col] == NULL) {
				
				cout << " ";
			}
			// Otherwise if the space is occupied.
			else {

				switch (board[row][col]->getType()) {

				case ANT:
					cout << "O";
					break;

				case DOODLEBUG:
					cout << "X";
					break;
				}
			}
		}

		// Right border.
		cout << "|" << "\n";
	}

	// Bottom border.
	for (int col = 0; col < (boardWidth + 2); col++) {

		cout << "-";
	}
	cout << "\n";
}

/*********************************************************************
** moveCritter(Critter* c, Direction dir):
** Moves a Critter pointer to a new location depending on the indicated
** direction, and sets its old location to NULL. Warning: does not check
** spaces for walls or neighboring objects - this is done in the calling
** function from the Ant or Doodlebug objects - so the new space is 
** assumed to be empty.
*********************************************************************/
void Board::moveCritter(Critter* c, Direction dir) {

	int row = c->getPositionRow();
	int col = c->getPositionCol();

	switch (dir) {

	case UP:

		board[row - 1][col] = board[row][col];
		board[row][col] = NULL;
		break;
	case RIGHT:

		board[row][col + 1] = board[row][col];
		board[row][col] = NULL;
		break;
	case DOWN:

		board[row + 1][col] = board[row][col];
		board[row][col] = NULL;
		break;
	case LEFT:

		board[row][col - 1] = board[row][col];
		board[row][col] = NULL;
		break;
	}

}

/*********************************************************************
** addCritter(int row, int col, CritterType type):
** Creates a new Critter of specified type in the indicated location.
** Warning: does not check if indicated location is occupied or out
** of bounds - indicated location is assumed to be empty.
*********************************************************************/
void Board::addCritter(int row, int col, CritterType type) {

	Critter* newCritter;

	switch (type) {

	case ANT:

		newCritter = new Ant(row, col);
		board[row][col] = newCritter;
        quantAnts++;
		break;

	case DOODLEBUG:

		newCritter = new Doodlebug(row, col);
		board[row][col] = newCritter;
        quantDbugs++;
		break;
	}
}

/*********************************************************************
** delCritter(int row, int col):
** Deletes the Critter object at the indicated location.
*********************************************************************/
void Board::delCritter(int row, int col) { 
    
    //decrement quantAnts/quantDbugs for
    //early terminate conditions
    switch(board[row][col]->getType())
    {
        case ANT:
            quantAnts--;
            break;
            
        case DOODLEBUG:
            quantDbugs--;
            break;
            
        case EMPTY:
            break;
    }
    
	delete board[row][col];
	board[row][col] = NULL;
}

// Getters.
Critter* Board::getCritter(int row, int col) { return this->board[row][col]; }
int Board::getBoardWidth() { return this->boardWidth; }
int Board::getBoardHeight() { return this->boardHeight; }
int Board::getQuantDbugs() { return this->quantDbugs; }
int Board::getQuantAnts() { return this->quantAnts; }
