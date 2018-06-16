/*********************************************************************
 ** Program name: Dice War
 ** Author: Joel Huffman
 ** Date: 1/26/2018
 ** Description: Program simulates a dice war game between two players
 ** with dice type, dice size and number of rounds decided by the user.
 ** Every round's result is printed to the screen with a final printout
 ** showing who won the entire game and the final scores.
 *********************************************************************/

#include "Die.hpp"

Die::Die()
{
    setNumberOfSides(6);
}

Die::Die(int n)
{
    setNumberOfSides(n);
    
}

int Die::getNumberOfSides()
{
    return numberOfSides;
}

void Die::setNumberOfSides(int nIn)
{
    numberOfSides = nIn;
}

int Die::roll()
{
    
    int n = getNumberOfSides();
    int result = rand() % n + 1;
    return result;
}
