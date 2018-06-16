/*********************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Joel Huffman
 ** Date: 02/25/18
 ** Description: Header for BlueMen class. Declares variables and
 ** functions for the BlueMen class
 *********************************************************************/

#ifndef BlueMen_hpp
#define BlueMen_hpp

#include <stdio.h>
#include "Character.hpp"

class BlueMen: public Character
{
public:
    BlueMen(string team, string name);
    ~BlueMen();
    int attack();
    int defense(int incomingAttack);
    int defenseDieRoll();
    void mob();
};

#endif /* BlueMen_hpp */
