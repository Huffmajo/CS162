/*********************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Joel Huffman
 ** Date: 02/25/18
 ** Description: Header for Barbarian class. Declares variables and 
 ** functions for the barbarian class
 *********************************************************************/

#ifndef Barbarian_hpp
#define Barbarian_hpp

#include <stdio.h>
#include "Character.hpp"

class Barbarian: public Character
{
public:
    Barbarian(string team, string name);
    ~Barbarian();
    int attack();
    int defense(int incomingAttack);
    int defenseDieRoll();
};

#endif /* Barbarian_hpp */
