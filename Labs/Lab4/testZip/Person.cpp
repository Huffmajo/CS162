/*********************************************************************
 ** Program name: OSU Information System
 ** Author: Joel Huffman
 ** Date: 1/30/2018
 ** Description: Gives the user information about the OSU campus. This
 ** includes buildings, students and instructors and statistics about
 ** each of these objects.
 *********************************************************************/

#include "Person.hpp"
#include <iostream>

Person::Person(string nameIn, int ageIn)
{
    setName(nameIn);
    setAge(ageIn);
}

string Person::getName()
{
    return name;
}

int Person::getAge()
{
    return age;
}

void Person::setName(string nameIn)
{
    name = nameIn;
}

void Person::setAge(int ageIn)
{
    age = ageIn;
}

void Person::printRatingOrGPA()
{
    //won't be using this virtual base function
}

void Person::doWork()
{
    //won't be using this virtual base function
}
