/*********************************************************************
 ** Program name: Searching and Sorting
 ** Author: Joel Huffman
 ** Date: 2/28/2018
 ** Description: Reads in arrays from .txt files and sorts the arrays
 ** before both printing the sorted arrays and writing them to a user
 ** named .txt file.
 *********************************************************************/

#ifndef searchFor_hpp
#define searchFor_hpp

#include <string>
using std::string;
#include <vector>
using std::vector;

string searchFor(int target, vector<int>* arr);
string binarySearch(int target, vector<int>* arr);

#endif /* searchFor_hpp */
