/*********************************************************************
 ** Program name: Searching and Sorting
 ** Author: Joel Huffman
 ** Date: 2/28/2018
 ** Description: Reads in arrays from .txt files and sorts the arrays
 ** before both printing the sorted arrays and writing them to a user
 ** named .txt file.
 *********************************************************************/

#ifndef bubbleSort_hpp
#define bubbleSort_hpp

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using std::vector;
using std::string;
using std::cout;
using std::ofstream;

void swap(int* a, int* b);
void bubbleSort(vector<int>* arr);
void printSorted(vector<int>* arr);
void outputSorted(vector<int>* arr, string outputFile);


#endif /* bubbleSort_hpp */
