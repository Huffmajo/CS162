/*********************************************************************
 ** Program name: Fantasy Combat Game
 ** Author: Joel Huffman
 ** Date: 02/12/18
 ** Description: Derived from the Character class. Defines the BlueMen's
 ** attacks, defense, armor, strength and abilities
 *********************************************************************/

#include "BlueMen.hpp"

/*********************************************************************
 ** BlueMen:
 ** Sets all the bluemen's base stats
 *********************************************************************/
BlueMen::BlueMen():Character()
{
    setName("Blue Men");
    setStrength(12);
    setArmor(3);
    setAttackDieSize(10);
    setAttackDieNumber(2);
    setDefenseDieSize(6);
    setDefenseDieNumber(3);
}

/*********************************************************************
 ** attack:
 ** Rolls the characters attack dice and returns the result.
 *********************************************************************/
int BlueMen::attack()
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
 ** Then reduces strength points by inflicted value. Adjusts the blue
 ** men's defensive dice based on new health. Then returns the defense
 ** roll.
 *********************************************************************/
int BlueMen::defense(int incomingAttack)
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
    
    //enact mob ability
    mob();
    
    //return the defensive roll
    return defense;
}

/*********************************************************************
 ** defenseDieRoll:
 ** Rolls a defense value based on the character's defense dice.
 *********************************************************************/
int BlueMen::defenseDieRoll()
{
    int totalDefense = 0;
    
    for(int i = 0; i < getDefenseDieNumber(); i++)
    {
        totalDefense += roll(getDefenseDieSize());
    }
    
    return totalDefense;
}

/*********************************************************************
 ** mob:
 ** For every 4 points of damage sustained the blue men lose 1d6 of
 ** defensive capability.
 *********************************************************************/
void BlueMen::mob()
{
    int newDefensiveDieNumber = (getStrength() + 3) / 4;
    setDefenseDieNumber(newDefensiveDieNumber);
}
