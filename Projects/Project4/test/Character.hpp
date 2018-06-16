/*********************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Joel Huffman
 ** Date: 02/25/18
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
    string type;
    string name;
    string team;
    int attackDieSize;
    int attackDieNumber;
    int defenseDieSize;
    int defenseDieNumber;
    int maxStrength;
    
    int roll(int);
    
public:
    void recovery();
    
    int virtual attack();
    int virtual defense(int incomingAttack)=0;
    int virtual defenseDieRoll()=0;
    
    int getStrength();
    int getArmor();
    string getType();
    string getName();
    string getTeam();
    int getMaxStrength();
    int getAttackDieSize();
    int getAttackDieNumber();
    int getDefenseDieSize();
    int getDefenseDieNumber();
    
    void setStrength(int);
    void setArmor(int);
    void setType(string);
    void setName(string);
    void setTeam(string);
    void setMaxStrength(int);
    void setAttackDieSize(int);
    void setAttackDieNumber(int);
    void setDefenseDieSize(int);
    void setDefenseDieNumber(int);
};


#endif /* Character_hpp */
