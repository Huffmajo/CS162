/*********************************************************************
 ** Program name: Searching and Sorting
 ** Author: Joel Huffman
 ** Date: 2/28/2018
 ** Description: Reads in arrays from .txt files and sorts the arrays
 ** before both printing the sorted arrays and writing them to a user
 ** named .txt file.
 *********************************************************************/
#include "searchFor.hpp"

/*********************************************************************
 ** searchFor(int target, vector<int>* arr):
 ** accepts a target int and a pointer to a vector. Searches through the
 ** vector for the target value. Prints out a message telling if the
 ** target was found.
 *********************************************************************/
string searchFor(int target, vector<int>* arr)
{
    
    for (int i = 0; i < arr->size(); i++)
    {
        if (target == arr->at(i))
        {
            return "target value found\n";
        }
    }
    return "target value not found\n";
}

/*********************************************************************
 ** string binarySearch(int target, vector<int>* arr):
 ** accepts a target int and a pointer to a vector. Searches through the
 ** vector for the target value. Prints out a message telling if the
 ** target was found.
 *********************************************************************/
string binarySearch(int target, vector<int>* arr)
{
    int lower = 0;
    int upper = arr->size()-1;
    int middle;
    
    while (lower <= upper)
    {
        middle = (lower + upper) / 2;
        
        if (arr->at(middle) == target)
        {
            return "target value found\n";
        }
        
        else if (arr->at(middle) < target)
        {
            lower = middle + 1;
        }
        
        else
        {
            upper = middle - 1;
        }
    }
    return "target value not found\n";
}
