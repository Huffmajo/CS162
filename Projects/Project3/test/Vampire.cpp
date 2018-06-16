/*********************************************************************
 ** Program name: Fantasy Combat Game
 ** Author: Joel Huffman
 ** Date: 02/12/18
 ** Description: Vampire class. Defines functions and variables for the
 ** Vampire combatant.
 *********************************************************************/

#include "Vampire.hpp"

/*********************************************************************
 ** Vampire:
 ** Sets all the vampire's base stats
 *********************************************************************/
Vampire::Vampire():Character()
{
    setName("Vampire");
    setStrength(18);
    setArmor(1);
    setAttackDieSize(12);
    setAttackDieNumber(1);
    setDefenseDieSize(1);
    setDefenseDieNumber(6);
}


/*********************************************************************
 ** attack:
 ** Rolls the characters attack dice and returns the result.
 *********************************************************************/
int Vampire::attack()
{
    int totalAttack = 0;
    
    for(int i = 0; i < getAttackDieNumber(); i++)
    {
        totalAttack += roll(getAttackDieSize());
    }
    
    return totalAttack;
}

/*********************************************************************
 ** defense:
 ** Defends against an incoming attack. Takes an incoming attack value
 ** and subtracts the defense roll and armor to get the infliced damage.
 ** Then reduces strength points by inflicted value. Returns the defense
 ** roll.
 *********************************************************************/
int Vampire::defense(int incomingAttack)
{
    int inflictedDamage;
    int defense = defenseDieRoll();
    
    //calculate inflicted damage
    inflictedDamage = incomingAttack - defense - getArmor();
    if (inflictedDamage < 0)
    {
        inflictedDamage = 0;
    }
    
    //inflict damage to defending character
    setStrength(getStrength() - inflictedDamage);
    
    //return the defensive roll
    return defense;
}

/*********************************************************************
 ** defenseDieRoll:
 ** Rolls to see if the enemy is charmed. If so, defense is impregnable.
 ** otherwise roll the characters defense dice. Returns the defense result.
 *********************************************************************/
int Vampire::defenseDieRoll()
{
    int totalDefense = 0;
    
    //if enemy is successfully charmed
    //defense is impregnable
    if (charmEnemy())
    {
        totalDefense = 999;
    }
    
    //otherwise defense rolls as normal
    else
    {
        for(int i = 0; i < getDefenseDieNumber(); i++)
        {
            totalDefense += roll(getDefenseDieSize());
        }
    }
    
    return totalDefense;
}

/*********************************************************************
 ** charmEnemy:
 ** Has a 50% chance to charm the enemy. If the enemy is charmed, true
 ** is returned. If enemy is not charmed, false is returned.
 *********************************************************************/
bool Vampire::charmEnemy()
{
    bool charmed = false;
    int coinFlip = rand() % 2 + 1;
    
    if (coinFlip == 1)
    {
        charmed = true;
    }
    return charmed;
}
