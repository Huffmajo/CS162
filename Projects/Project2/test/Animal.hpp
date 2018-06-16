/*********************************************************************
 ** Program name: Zoo Tycoon
 ** Author: Joel Huffman
 ** Date: 2/02/2018
 ** Description: You're the owner of your very own zoo. Choose which
 ** animals to purchase and try to keep from going bankrupt. Random
 ** events happen daily that could be positive or negative. Your animals
 ** can even have babies once they reach adulthood.
 *********************************************************************/

#ifndef Animal_hpp
#define Animal_hpp

#include <stdio.h>


/*********************************************************************
 ** Animal class:
 ** Requires an integer parameter to determine the animal's stating age.
 ** Base class for Tiger, Penguin and Turtle classes.
 *********************************************************************/
class Animal
{
private:
    int age;
    int cost;
    int numberOfBabies;
    int baseFoodCost;
    int payoff;
    
public:
    Animal(int ageIn);
    int getAge();
    int getCost();
    int getnumberOfBabies();
    int getBaseFoodCost();
    int getPayoff();
    void setAge(int ageIn);
    void setCost(int costIn);
    void setnumberOfBabies(int babiesIn);
    void setBaseFoodCost(int baseFoodIn);
    void setPayoff(int payoffIn);
};

#endif /* Animal_hpp */
