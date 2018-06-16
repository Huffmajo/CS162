/*********************************************************************
 ** Program name: OSU Information System
 ** Author: Joel Huffman
 ** Date: 1/30/2018
 ** Description: Gives the user information about the OSU campus. This
 ** includes buildings, students and instructors and statistics about
 ** each of these objects.
 *********************************************************************/

#include "University.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "utils.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using std::cout;


int main() {
    
    //seed random number generator
    srand(time(NULL));
    
    //create the university
    University osu;
    University* ptrOSU = &osu;
    
    //create some buildings
    Building bentonHall("Benton Hall", 21593, "1650 SW Pioneer Place");
    Building dearbornHall("Dearborn Hall", 59713, "1891 SW Campus Way");
    Building waldoHall("Waldo Hall", 64367, "2250 SW Jefferson Way");
    
    //make pointers to the buildings
    Building* ptrBenton = &bentonHall;
    Building* ptrDearborn = &dearbornHall;
    Building* ptrWaldo = &waldoHall;
    
    //add the buildings to the university
    osu.addBuilding(ptrBenton);
    osu.addBuilding(ptrDearborn);
    osu.addBuilding(ptrWaldo);
    
    //make some people
    Instructor shuman("Matt Shuman", 35, 4.5);
    Student joel("Joel Huffman", 28, 3.8);
    
    //make pointers to people
    Instructor* ptrShuman = &shuman;
    Student* ptrJoel = &joel;

    //add the people to the university
    osu.addPerson(ptrShuman);
    osu.addPerson(ptrJoel);
    
    //Generate menu for user
    menu(ptrOSU);
    
    return 0;
}
