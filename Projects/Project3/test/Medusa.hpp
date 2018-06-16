/*********************************************************************
 ** Program name: Fantasy Combat Game
 ** Author: Joel Huffman
 ** Date: 02/12/18
 ** Description: Header for Medusa class. Declares variables and
 ** functions for the Medusa class
 *********************************************************************/

#ifndef Medusa_hpp
#define Medusa_hpp

#include <stdio.h>
#include "Character.hpp"

class Medusa: public Character
{
public:
    Medusa();
    ~Medusa();
    int attack();
    int defense(int incomingAttack);
    int defenseDieRoll();
};

#endif /* Medusa_hpp */
