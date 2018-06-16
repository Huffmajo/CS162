/*********************************************************************
 ** Program name: Fantasy Combat Game
 ** Author: Joel Huffman
 ** Date: 02/12/18
 ** Description: Header for abstract Character class. Defines variables
 ** and functions for Character base class
 *********************************************************************/

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <string>
using std::string;

class Character
{
protected:
    int strength;
    int armor;
    string name;
    int attackDieSize;
    int attackDieNumber;
    int defenseDieSize;
    int defenseDieNumber;
    
    int roll(int);
    
public:
    int virtual attack();
    
    //remember to re-initialize to pure virtual functions
    int virtual defense(int incomingAttack)=0;
    int virtual defenseDieRoll()=0;
    
    int getStrength();
    int getArmor();
    string getName();
    int getAttackDieSize();
    int getAttackDieNumber();
    int getDefenseDieSize();
    int getDefenseDieNumber();
    
    void setStrength(int);
    void setArmor(int);
    void setName(string);
    void setAttackDieSize(int);
    void setAttackDieNumber(int);
    void setDefenseDieSize(int);
    void setDefenseDieNumber(int);
};


#endif /* Character_hpp */
