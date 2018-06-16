/*********************************************************************
 ** Program name: OSU Information System
 ** Author: Joel Huffman
 ** Date: 1/30/2018
 ** Description: Gives the user information about the OSU campus. This
 ** includes buildings, students and instructors and statistics about
 ** each of these objects.
 *********************************************************************/

#include "Instructor.hpp"
#include <stdlib.h>
#include <iostream>
using std::cout;

Instructor::Instructor(string nameIn, int ageIn, float ratingIn): Person(nameIn, ageIn)
{
    setName(nameIn);
    setAge(ageIn);
    rating = ratingIn;
}


void Instructor::printRatingOrGPA()
{
    cout << "Rating: " << rating << "\n\n";
}

void Instructor::doWork()
{
    int hours = rand() % 6 + 2;
    cout << getName() << " graded papers for " << hours << " hours.\n\n";
}
