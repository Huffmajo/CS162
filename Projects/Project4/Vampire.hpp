/*********************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Joel Huffman
 ** Date: 02/25/18
 ** Description: Header for Vampire class. Declares variables and
 ** functions for Vampire combatants
 *********************************************************************/


#ifndef Vampire_hpp
#define Vampire_hpp

#include <stdio.h>
#include "Character.hpp"

class Vampire: public Character
{
public:
    Vampire(string team, string name);
    ~Vampire();
    int attack();
    int defense(int incomingAttack);
    int defenseDieRoll();
    bool charmEnemy();
};
#endif /* Vampire_hpp */
