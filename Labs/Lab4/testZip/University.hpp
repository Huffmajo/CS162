/*********************************************************************
 ** Program name: OSU Information System
 ** Author: Joel Huffman
 ** Date: 1/30/2018
 ** Description: Gives the user information about the OSU campus. This
 ** includes buildings, students and instructors and statistics about
 ** each of these objects.
 *********************************************************************/

#ifndef University_hpp
#define University_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Building.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
using std::string;
using std::vector;

class University
{
private:
    string name;
    vector<Building*> buildings;
    vector<Person*> people;
    
public:
    University();
    University(string);
    string getName();
    vector<Person*> getPeople();
    vector<Building*> getBuildings();
    
    /*********************************************************************
     ** addPerson(Person*):
     ** Accepts a pointer to a Person object. Appends that person object to
     ** the people vector to later be printed by the printPeopleInfo() 
     ** function.
     *********************************************************************/
    void addPerson(Person*);
    
    /*********************************************************************
     ** addBuilding(Building*):
     ** Accepts a pointer to a Building object. Appends that building 
     ** object to the buildings vector to later be printed by the 
     ** printBuildingInfo() function.
     *********************************************************************/
    void addBuilding(Building*);
    
    /*********************************************************************
     ** printBuildingInfo():
     ** Prints the name, size and address of each building in the buildings
     ** vector.
     *********************************************************************/
    void printBuildingInfo();
    
    /*********************************************************************
     ** printPeopleInfo():
     ** Prints the name, age and GPA or rating (depending of if they are a
     ** student or instructor respectively).
     *********************************************************************/
    void printPeopleInfo();
};

#endif /* University_hpp */
