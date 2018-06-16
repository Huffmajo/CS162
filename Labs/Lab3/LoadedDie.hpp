/*********************************************************************
 ** Program name: Dice War
 ** Author: Joel Huffman
 ** Date: 1/26/2018
 ** Description: Program simulates a dice war game between two players
 ** with dice type, dice size and number of rounds decided by the user.
 ** Every round's result is printed to the screen with a final printout
 ** showing who won the entire game and the final scores.
 *********************************************************************/

#ifndef LoadedDie_hpp
#define LoadedDie_hpp

#include <stdio.h>
#include "Die.hpp"

class LoadedDie: public Die{
public:
    LoadedDie(int n);
    
    /*********************************************************************
     ** roll:
     ** simulates a random roll of the LoadedDice object. The highest value
     ** side is significantly more likely to be rolled. The result of the
     ** roll is returned.
     *********************************************************************/
    int roll();
};

#endif /* LoadedDie_hpp */
