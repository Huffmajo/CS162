/*********************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Joel Huffman
 ** Date: 02/25/18
 ** Description: Derived from the Character class. Defines the Medusa's
 ** attacks, defense, armor, strength and abilities
 *********************************************************************/

#include "Medusa.hpp"

/*********************************************************************
 ** Medusa:
 ** Sets all the medusa's base stats
 *********************************************************************/
Medusa::Medusa(string team, string name):Character()
{
    setType("Medusa");
    setName(name);
    setTeam(team);
    setStrength(8);
    setMaxStrength(getStrength());
    setArmor(3);
    setAttackDieSize(12);
    setAttackDieNumber(1);
    setDefenseDieSize(6);
    setDefenseDieNumber(1);
}

/*********************************************************************
 ** attack:
 ** Rolls the characters attack dice. If a critical (12) is rolled, the
 ** attack power is ridiculously increased. On any other roll the attack
 ** power is the rolled value. Returns the attack value.
 *********************************************************************/
int Medusa::attack()
{
    int totalAttack = roll(getAttackDieSize());
    
    //glare attack on crit
    if (totalAttack == 12)
    {
        totalAttack = 50;
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
int Medusa::defense(int incomingAttack)
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
 ** Rolls the characters defense dice and returns the result
 *********************************************************************/
int Medusa::defenseDieRoll()
{
    int totalDefense = 0;
    
    for(int i = 0; i < getDefenseDieNumber(); i++)
    {
        totalDefense += roll(getDefenseDieSize());
    }
    
    return totalDefense;
}
