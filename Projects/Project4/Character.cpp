/*********************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Joel Huffman
 ** Date: 02/25/18
 ** Description: Character class. The base class for the five types of
 ** combatants. Functions are defined here.
 *********************************************************************/

#include "Character.hpp"
#include <random>
#include <iostream>
using std::cout;

int Character::roll(int die)
{
    return (rand() % die + 1);
}


/*********************************************************************
 ** recovery(int startingStrength):
 ** Accepts an int for strength at beginning of battle. If strength was
 ** lost during the battle, a small portion is regained. New strength
 ** cannot exceed what it was before the battle started.
 *********************************************************************/
void Character::recovery()
{
    int strengthLost = getMaxStrength() - getStrength();
    
    if (strengthLost == 0)
    {
        cout << "No recovery needed!\n";
        cout << "Current strength now " << getStrength() << "\n";
    }
    else
    {
        int healPercentage = rand() % 10 + 1;
        int healAmount = (strengthLost * healPercentage) / 10;
        
        if (healAmount > strengthLost)
        {
            healAmount = strengthLost;
        }
        
        setStrength(getStrength() + healAmount);
        
        cout << healAmount << " strength recovered!\n";
        cout << "Current strength now " << getStrength() << "\n";
    }
}

/*********************************************************************
 ** attack:
 ** Rolls the characters attack dice and returns the sum of all the rolls.
 *********************************************************************/
int Character::attack()
{
    int totalAttack = 0;
    
    for(int i = 0; i < getAttackDieNumber(); i++)
    {
        totalAttack += roll(getAttackDieSize());
    }
    
    return totalAttack;
}

//getters
int Character::getStrength()
{
    return strength;
}

int Character::getArmor()
{
    return armor;
}

string Character::getType()
{
    return type;
}

string Character::getName()
{
    return name;
}

string Character::getTeam()
{
    return team;
}

int Character::getMaxStrength()
{
    return maxStrength;
}

int Character::getAttackDieSize()
{
    return attackDieSize;
}

int Character::getAttackDieNumber()
{
    return attackDieNumber;
}

int Character::getDefenseDieSize()
{
    return defenseDieSize;
}

int Character::getDefenseDieNumber()
{
    return defenseDieNumber;
}

//setters
void Character::setStrength(int strengthIn)
{
    strength = strengthIn;
}

void Character::setArmor(int armorIn)
{
    armor = armorIn;
}

void Character::setType(string typeIn)
{
    type = typeIn;
}

void Character::setName(string nameIn)
{
    name = nameIn;
}

void Character::setTeam(string teamIn)
{
    team = teamIn;
}

void Character::setMaxStrength(int maxStrengthIn)
{
    maxStrength = maxStrengthIn;
}

void Character::setAttackDieSize(int attackDieSizeIn)
{
    attackDieSize = attackDieSizeIn;
}

void Character::setAttackDieNumber(int attackDieNumberIn)
{
    attackDieNumber = attackDieNumberIn;
}

void Character::setDefenseDieSize(int defenseDieSizeIn)
{
    defenseDieSize = defenseDieSizeIn;
}

void Character::setDefenseDieNumber(int defenseDieNumberIn)
{
    defenseDieNumber = defenseDieNumberIn;
}
