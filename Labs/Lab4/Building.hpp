/*********************************************************************
 ** Program name: OSU Information System
 ** Author: Joel Huffman
 ** Date: 1/30/2018
 ** Description: Gives the user information about the OSU campus. This
 ** includes buildings, students and instructors and statistics about
 ** each of these objects.
 *********************************************************************/

#ifndef Building_hpp
#define Building_hpp

#include <stdio.h>
#include <string>
using std::string;

class Building
{
private:
    string name;
    int size;
    string address;
    
public:
    Building(string, int, string);
    string getName();
    int getSize();
    string getAddress();
};


#endif /* Building_hpp */
