/*********************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Joel Huffman
 ** Date: 02/25/18
 ** Description: Header for the game class. Declares variables and
 ** functions that create and run the battles between the provided
 ** combatants
 *********************************************************************/

#ifndef Game_hpp
#define Game_hpp

#include "Character.hpp"

class Game
{
private:
    Character* player1 = NULL;
    Character* player2 = NULL;
    Character* victor = NULL;
    Character* loser = NULL;
public:
    Game(Character* p1, Character* p2);
    void fight(Character* attacker, Character* defender);
    void round();
    bool isDead(Character* player);
    bool checkForVictor();
    void battle();
    
    Character* getVictor();
    Character* getLoser();
};

#endif /* Game_hpp */
