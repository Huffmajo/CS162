/*********************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Joel Huffman
 ** Date: 02/25/18
 ** Description: Game class. Creates battles between two combatants
 ** with statistics on attacks and defenses each round until one
 ** combatant is defeated.
 *********************************************************************/
#include "Game.hpp"
#include <iostream>
using std::cout;

/*********************************************************************
 ** Game:
 ** Takes two character pointers and assigns them to the local pointers
 ** for use within the game class.
 *********************************************************************/
Game::Game(Character* p1, Character* p2)
{
    player1 = p1;
    player2 = p2;
}

/*********************************************************************
 ** fight:
 ** Takes pointers for an attacker character and a defender character.
 ** The attacker attacks and the defender defends. All stats are printed
 ** out for the fight.
 *********************************************************************/
void Game::fight(Character* attacker, Character* defender)
{
    int attackRoll;
    int defendRoll;
    int inflictedDamage;
    
    //print out pre-attack stats
    /*
    cout << "Attacker: " << attacker->getType() << "\n";
    cout << "Defender: " << defender->getType() << "\n";
    cout << "Defender's armor: " << defender->getArmor() << "\t Defender's strength: " << defender->getStrength() << "\n";
    */
    
    //run attack and print out post-attack stats
    attackRoll = attacker->attack();
    defendRoll = defender->defense(attackRoll);
    inflictedDamage = attackRoll - defendRoll - defender->getArmor();
    
    //set minimum for inflicted damage to 0
    if (inflictedDamage < 0)
    {
        inflictedDamage = 0;
    }
    
    /*
    //show attack roll
    cout << "Attacker " << attacker->getType() << "'s attack roll: " << attackRoll << "\n";
    
    //show defense roll
    cout << "Defender " << defender->getType() << "'s defense roll: " << defendRoll << "\n";
    
    //show inflicted damage calculation
    cout << "Attack roll - defense roll - defender's armor = inflicted damage\n";
    cout << "\t" << attackRoll << "\t-\t" << defendRoll << "\t-\t" << defender->getArmor() << "\t=\t" << inflictedDamage << "\n";
    
    //show inflicted damage
    cout << "Attacker " << attacker->getType() << " inflicted " << inflictedDamage << " damage\n";
    
    //show defender's remaining strength
    cout << "Defender " << defender->getType() << "'s strength is now: " << defender->getStrength() << "\n\n";
     */
}

/*********************************************************************
 ** round:
 ** Consists of two fights, in which each combatant gets a chance to
 ** attack. P1 always goes first.
 *********************************************************************/
void Game::round()
{
    //p1 gets to attack first
    fight(player1, player2);
    
    //check to see if fight is over
    checkForVictor();
    
    //provide exit if p2 is defeated
    if (!checkForVictor())
    {
    
        //p2 has a chance to attack now
        fight(player2, player1);
    
        //check to see if fight is over
        checkForVictor();
    }
}

/*********************************************************************
 ** isDead:
 ** Checks if the player pointed to is dead. Returns true if they're
 ** dead, false if they are still alive.
 *********************************************************************/
bool Game::isDead(Character* player)
{
    bool dead = false;
    if (player->getStrength() <= 0)
    {
        dead = true;
        loser = player;
    }
    return dead;
}

/*********************************************************************
 ** checkForVictor:
 ** Checks if either of the combatants has died. If a combatant has
 ** died, they other combatant becomes the victor and true is returned.
 ** if there is no victor yet, false is returned.
 *********************************************************************/
bool Game::checkForVictor()
{
    bool gameOver = false;
    
    if (isDead(player1))
    {
        victor = player2;
        gameOver = true;
    }
    
    else if (isDead(player2))
    {
        victor = player1;
        gameOver = true;
    }
    
    return gameOver;
}

/*********************************************************************
 ** battle():
 ** Keeps rounds fighting until one combatant dies.
 *********************************************************************/
void Game::battle()
{
    //set players max strength to current strength for recovery function
    player1->setMaxStrength(player1->getStrength());
    player2->setMaxStrength(player2->getStrength());
    
    //keep fighting until one fighter dies
    while (getVictor() == NULL)
    {
        round();
    }
}

Character* Game::getVictor()
{
    return victor;
}

Character* Game::getLoser()
{
    return loser;
}
