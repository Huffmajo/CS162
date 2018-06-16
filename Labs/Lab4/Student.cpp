/*********************************************************************
 ** Program name: OSU Information System
 ** Author: Joel Huffman
 ** Date: 1/30/2018
 ** Description: Gives the user information about the OSU campus. This
 ** includes buildings, students and instructors and statistics about
 ** each of these objects.
 *********************************************************************/

#include "Student.hpp"
#include <iostream>
#include <stdlib.h>
using std::cout;

Student::Student(string nameIn, int ageIn, float gpaIn): Person(nameIn, ageIn)
{
    setName(nameIn);
    setAge(ageIn);
    gpa = gpaIn;
}

void Student::printRatingOrGPA()
{
    cout << "GPA: " << gpa << "\n\n";
}

void Student::doWork()
{
    int hours = rand() % 8 + 2;
    cout << getName() << " did " << hours << " hours of homework.\n\n";
}
