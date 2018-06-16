/*********************************************************************
 ** Program name: OSU Information System
 ** Author: Joel Huffman
 ** Date: 1/30/2018
 ** Description: Gives the user information about the OSU campus. This
 ** includes buildings, students and instructors and statistics about
 ** each of these objects.
 *********************************************************************/

#include "University.hpp"
#include <iostream>
using std::cout;

University::University()
{
    name = "Oregon State University";
}

University::University(string nameIn)
{
    name = nameIn;
}

string University::getName()
{
    return name;
}

vector<Person*> University::getPeople()
{
    return people;
}

vector<Building*> University::getBuildings()
{
    return buildings;
}

void University::addPerson(Person* ptrPerson)
{
    people.push_back(ptrPerson);
}

void University::addBuilding(Building* ptrBuilding)
{
    buildings.push_back(ptrBuilding);
}

void University::printBuildingInfo()
{
    for (int i = 0; i < buildings.size(); i++)
    {
        cout << "Name: " << buildings.at(i)->getName() << "\n";
        cout << "Size: " << buildings.at(i)->getSize() << " sqft\n";
        cout << "Address: " << buildings.at(i)->getAddress() << "\n\n";
    }
}

void University::printPeopleInfo()
{
    for (int i = 0; i < people.size(); i++)
    {
        cout << "Name: " << people.at(i)->getName() << "\n";
        cout << "Age: " << people.at(i)->getAge() << "\n";
        people.at(i)->printRatingOrGPA();
    }
}
