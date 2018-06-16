/*********************************************************************
 ** Program name: Fantasy Combat Game
 ** Author: Joel Huffman
 ** Date: 02/12/18
 ** Description: Header for Harry Potter class. Declares variables and
 ** functions for the Harry Potter class
 *********************************************************************/

#ifndef HarryPotter_hpp
#define HarryPotter_hpp

#include <stdio.h>
#include "Character.hpp"

class HarryPotter: public Character
{
private:
    bool tearsOfDenial;
public:
    HarryPotter();
    ~HarryPotter();
    int attack();
    int defense(int incomingAttack);
    int defenseDieRoll();
    void hogwarts();
};

#endif /* HarryPotter_hpp */
