/*********************************************************************
 ** Program name: Predator-Prey Game
 ** Author: Group 13 (Joel Huffman, Andrew Swaim, Frank Li, Henry Clay)
 ** Date: 2/05/2018
 ** Description: This is the header file for the Dbug class.
 *********************************************************************/

#ifndef Doodlebug_hpp
#define Doodlebug_hpp

#include <stdio.h>
#include "Critter.hpp"

class Doodlebug: public Critter
{
private:
	// Unique member variable.
    int daysSinceEaten;

protected:
	// INHERITED MEMBERS FROM CRITTER.
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
    Doodlebug(int startingRow, int startingCol);
    
	// Primary functions.
    void move(Board&);
	void update(Board&);
};


#endif /* Doodlebug_hpp */
