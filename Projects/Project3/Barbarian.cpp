/*********************************************************************
 ** Program name: Fantasy Combat Game
 ** Author: Joel Huffman
 ** Date: 02/12/18
 ** Description: Derived from the Character class. Defines the Barbarian's
 ** attacks, defense, armor, strength and abilities
 *********************************************************************/
#include "Barbarian.hpp"

/*********************************************************************
 ** Barbarian:
 ** Sets all the barbarian's base stats
 *********************************************************************/
Barbarian::Barbarian():Character()
{
    setName("Barbarian");
    setStrength(12);
    setArmor(0);
    setAttackDieSize(6);
    setAttackDieNumber(2);
    setDefenseDieSize(6);
    setDefenseDieNumber(2);
    
}

/*********************************************************************
 ** attack:
 ** Rolls the characters attack dice and returns the result.
 *********************************************************************/
int Barbarian::attack()
{
    int totalAttack = 0;
    
    for(int i = 0; i < getAttackDieNumber(); i++)
    {
        totalAttack += roll(getAttackDieSize());
    }
    
    return totalAttack;
}

/*********************************************************************
 ** defenseDieRoll:
 ** Rolls the characters defense dice and returns the result
 *********************************************************************/
int Barbarian::defenseDieRoll()
{
    int totalDefense = 0;
    
    for(int i = 0; i < getDefenseDieNumber(); i++)
    {
        totalDefense += roll(getDefenseDieSize());
    }
    
    return totalDefense;
}

/*********************************************************************
 ** defense:
 ** Defends against an incoming attack. Takes an incoming attack value
 ** and subtracts the defense roll and armor to get the infliced damage.
 ** Then reduces strength points by inflicted value. Returns the defense
 ** roll.
 *********************************************************************/
int Barbarian::defense(int incomingAttack)
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
