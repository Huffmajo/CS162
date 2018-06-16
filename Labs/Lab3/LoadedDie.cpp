/*********************************************************************
 ** Program name: Dice War
 ** Author: Joel Huffman
 ** Date: 1/26/2018
 ** Description: Program simulates a dice war game between two players
 ** with dice type, dice size and number of rounds decided by the user.
 ** Every round's result is printed to the screen with a final printout
 ** showing who won the entire game and the final scores.
 *********************************************************************/

#include "LoadedDie.hpp"

LoadedDie::LoadedDie(int n): Die(n)
{
    setNumberOfSides(n);
}

int LoadedDie::roll()
{
    int result;
    int n = getNumberOfSides();
    int roll = rand() % (2 * n) + 1;
    
    if (roll >= n)
    {
        result = n;
    }
    else
    {
        result = roll;
    }
    
    return result;
}
