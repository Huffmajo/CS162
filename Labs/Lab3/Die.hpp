/*********************************************************************
 ** Program name: Dice War
 ** Author: Joel Huffman
 ** Date: 1/26/2018
 ** Description: Program simulates a dice war game between two players
 ** with dice type, dice size and number of rounds decided by the user.
 ** Every round's result is printed to the screen with a final printout
 ** showing who won the entire game and the final scores.
 *********************************************************************/

#ifndef Die_hpp
#define Die_hpp

#include <stdio.h>
#include <stdlib.h>

class Die{
private:
    int numberOfSides;
    
public:
    Die();
    Die(int n);
    int getNumberOfSides();
    void setNumberOfSides(int nIn);
    
    /*********************************************************************
     ** roll:
     ** simulates a random roll of the dice object. All sides are equally
     ** likely to be rolled. The result is returned
     *********************************************************************/
    int virtual roll();
};

#endif /* Die_hpp */
