/*********************************************************************
** Program name: Predator-Prey Game
** Author: Group 13 (Joel Huffman, Andrew Swaim, Frank Li, Henry Clay)
** Date: February 18, 2018
** Description: Ant.hpp, specification file for the Ant class.
*********************************************************************/

#ifndef Ant_hpp
#define Ant_hpp

#include "Critter.hpp"

class Ant: public Critter
{
private:
	// No unique member variables.

protected:
	// INHERITED MEMBER VARIABLES FROM CRITTER.
	// CritterType type;
	// int currRow;
	// int currCol;
	// int daysSurvived;
	// int numOfDirections;
	// Direction* randDirections;

	// Direction checkSpacesRandomly(Board&, CritterType);
	// void shuffleDirections();

public:
	// Constructor.
    Ant(int startingRow, int startingCol);

	// Primary functions.
	void move(Board&);
	void update(Board&);
};

#endif /* Ant_hpp */
