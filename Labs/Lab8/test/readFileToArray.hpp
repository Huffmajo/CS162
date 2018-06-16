/*********************************************************************
 ** Program name: Searching and Sorting
 ** Author: Joel Huffman
 ** Date: 2/28/2018
 ** Description: Reads in arrays from .txt files and sorts the arrays
 ** before both printing the sorted arrays and writing them to a user
 ** named .txt file.
 *********************************************************************/

#ifndef readFileToArray_hpp
#define readFileToArray_hpp

#include <string>
using std::string;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;

void readFileToArray(string fileName, vector<int>* arr);

#endif /* readFileToArray_hpp */
