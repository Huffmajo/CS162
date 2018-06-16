/*********************************************************************
 ** Program name: Dice War
 ** Author: Joel Huffman
 ** Date: 1/26/2018
 ** Description: Program simulates a dice war game between two players
 ** with dice type, dice size and number of rounds decided by the user.
 ** Every round's result is printed to the screen with a final printout
 ** showing who won the entire game and the final scores.
 *********************************************************************/

#include <iostream>
#include <time.h>
#include "LoadedDie.hpp"
#include "utils.hpp"
//just use for debugging
#include "Game.hpp"
using std::cout;
using std::cin;

int main() {
    
    //seed random number generator with time stamp
    srand(time(NULL));
    
    //call menu to prompt user for information for the game
    menu();
    
    return 0;
}
