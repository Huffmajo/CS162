/*********************************************************************
 ** Program name: Fantasy Combat Game
 ** Author: Joel Huffman
 ** Date: 02/12/18
 ** Description: Header for the game class. Declares variables and
 ** functions that create and run the battles between the provided
 ** combatants
 *********************************************************************/

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Barbarian.hpp"

class Game
{
private:
    Character* player1 = NULL;
    Character* player2 = NULL;
    Character* victor = NULL;
public:
    Game(Character* p1, Character* p2);
    void fight(Character* attacker, Character* defender);
    void round();
    bool isDead(Character* player);
    bool checkForVictor();
    
    Character* getVictor();
};

#endif /* Game_hpp */
