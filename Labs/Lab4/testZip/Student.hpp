/*********************************************************************
 ** Program name: OSU Information System
 ** Author: Joel Huffman
 ** Date: 1/30/2018
 ** Description: Gives the user information about the OSU campus. This
 ** includes buildings, students and instructors and statistics about
 ** each of these objects.
 *********************************************************************/

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <string>
#include "Person.hpp"
using std::string;

class Student: public Person
{
private:
    float gpa;
    
public:
    Student(string, int, float);
    
    /*********************************************************************
     ** printRatingsOrGPA:
     ** Prints either a rating or gpa for an instructor or student respectively
     *********************************************************************/
    void printRatingOrGPA();
    
    
    /*********************************************************************
     ** doWork:
     ** Prints a statement with about how many hours a specific person spent
     ** either grading papers (for instructors) or doing homework (for students)
     *********************************************************************/
    void doWork();
};


#endif /* Student_hpp */