/*********************************************************************
 ** Program name: OSU Information System
 ** Author: Joel Huffman
 ** Date: 1/30/2018
 ** Description: Gives the user information about the OSU campus. This
 ** includes buildings, students and instructors and statistics about
 ** each of these objects.
 *********************************************************************/

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <string>
using std::string;

class Person
{
private:
    string name;
    int age;
    
public:
    Person(string, int);
    string getName();
    int getAge();
    void setName(string);
    void setAge(int);
    
    /*********************************************************************
     ** printRatingsOrGPA:
     ** Prints either a rating or gpa for an instructor or student respectively
     *********************************************************************/
    void virtual printRatingOrGPA();
    
    /*********************************************************************
     ** doWork:
     ** Prints a statement with about how many hours a specific person spent
     ** either grading papers (for instructors) or doing homework (for students)
     *********************************************************************/
    void virtual doWork();
};


#endif /* Person_hpp */
