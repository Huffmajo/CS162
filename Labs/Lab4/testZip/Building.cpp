/*********************************************************************
 ** Program name: OSU Information System
 ** Author: Joel Huffman
 ** Date: 1/30/2018
 ** Description: Gives the user information about the OSU campus. This
 ** includes buildings, students and instructors and statistics about
 ** each of these objects.
 *********************************************************************/

#include "Building.hpp"

Building::Building(string nameIn, int sizeIn, string addressIn)
{
    name = nameIn;
    size = sizeIn;
    address = addressIn;
}

string Building::getName()
{
    return name;
}

int Building::getSize()
{
    return size;
}

string Building::getAddress()
{
    return address;
}
