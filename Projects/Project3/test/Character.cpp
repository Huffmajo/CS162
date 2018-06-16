/*********************************************************************
 ** Program name: Fantasy Combat Game
 ** Author: Joel Huffman
 ** Date: 02/12/18
 ** Description: Character class. The base class for the five types of
 ** combatants. Functions are defined here.
 *********************************************************************/

#include "Character.hpp"
#include <random>

int Character::roll(int die)
{
    return (rand() % die + 1);
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

string Character::getName()
{
    return name;
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

void Character::setName(string nameIn)
{
    name = nameIn;
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
