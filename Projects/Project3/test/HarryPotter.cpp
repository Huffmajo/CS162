/*********************************************************************
 ** Program name: Fantasy Combat Game
 ** Author: Joel Huffman
 ** Date: 02/12/18
 ** Description: Derived from the Character class. Defines Harry Potter's
 ** attacks, defense, armor, strength and abilities
 *********************************************************************/

#include "HarryPotter.hpp"

/*********************************************************************
 ** HarryPotter:
 ** Initializes stats for Harry Potter.
 *********************************************************************/
HarryPotter::HarryPotter():Character()
{
    setName("Harry Potter");
    setStrength(10);
    setArmor(0);
    setAttackDieSize(6);
    setAttackDieNumber(2);
    setDefenseDieSize(6);
    setDefenseDieNumber(2);
    tearsOfDenial = true;
}

/*********************************************************************
 ** attack:
 ** Rolls the characters attack dice and returns the result.
 *********************************************************************/
int HarryPotter::attack()
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
 ** Then reduces strength points by inflicted value. If this would kill
 ** Harry Potter and he has tears of denial, his strength is reset to
 ** 20. Returns the defense roll.
 *********************************************************************/
int HarryPotter::defense(int incomingAttack)
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
    
    //checks if hogwarts needs to enable
    if (getStrength() < 1 && tearsOfDenial)
    {
        //revives Harry and sets strength to 20
        hogwarts();
    }
    
    //return the defensive roll
    return defense;
}

/*********************************************************************
 ** defenseDieRoll:
 ** Rolls the characters defense dice and returns the result
 *********************************************************************/
int HarryPotter::defenseDieRoll()
{
    int totalDefense = 0;
    
    for(int i = 0; i < getDefenseDieNumber(); i++)
    {
        totalDefense += roll(getDefenseDieSize());
    }
    
    return totalDefense;
}

/*********************************************************************
 ** hogwarts:
 ** Resets Harry Potters strength back to 20. Only one use of this
 ** ability per object
 *********************************************************************/
void HarryPotter::hogwarts()
{
    setStrength(20);
    
    //for one time use
    tearsOfDenial = false;
    
}
