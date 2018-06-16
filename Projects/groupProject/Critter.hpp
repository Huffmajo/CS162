/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 13 (Joel Huffman, Andrew Swaim, Frank Li, Henry Clay)
** Date: February 18, 2018
** Description: Critter.hpp, specification file for the Critter class.
*********************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <cstdlib>

class Board;

enum Direction { NONE = 0, UP, RIGHT, DOWN, LEFT};
enum CritterType { EMPTY = 0, ANT, DOODLEBUG };

class Critter
{
protected:
	// Member variables.
	CritterType type;
    int currRow;
    int currCol;
    int daysSurvived;
	bool hasMoved;
	int numOfDirections;
	Direction* randDirections;

	// Member functions.
	Direction checkSpacesRandomly(Board&, CritterType);
	void shuffleDirections();
    
public:
	// Constructor and destructor.
	Critter(int row, int col);
	~Critter();

	// Virtual functions.
	virtual void move(Board&) = 0;
	virtual void update(Board&) = 0;

	// Primary function.
	void incDaysSurvived();

	// Getters and setters.
	CritterType getType();
	bool checkIfMoved();

    int getDaysSurvived();
    void setDaysSurvived(int);
    int getPositionRow();
    void setPositionRow(int);
    int getPositionCol();
    void setPositionCol(int);
};

#endif
