/*********************************************************************
 ** Program name: Searching and Sorting
 ** Author: Joel Huffman
 ** Date: 2/28/2018
 ** Description: Reads in arrays from .txt files and sorts the arrays
 ** before both printing the sorted arrays and writing them to a user
 ** named .txt file.
 *********************************************************************/

#include "readFileToArray.hpp"
#include <iostream>
using std::cout;

/*********************************************************************
 ** readFileToArray(string fileName, vector<int>* arr):
 ** accepts a fileName and a pointer to a vector. Populates arr with
 ** the values from the given fileName.
 *********************************************************************/
void readFileToArray(string fileName, vector<int>* arr)
{
    int nextVal;
    ifstream inputFile;
    inputFile.open(fileName);
    
    if (!inputFile)
    {
        cout << "error opening file\n";
    }
    
    while (inputFile >> nextVal)
    {
        arr->push_back(nextVal);
    }
    
    inputFile.close();
}
