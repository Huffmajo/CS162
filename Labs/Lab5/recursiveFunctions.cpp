/*********************************************************************
 ** Program name: Recursive Functions
 ** Author: Joel Huffman
 ** Date: 2/04/2018
 ** Description: Allows users to run any of three functions created 
 ** using recursion. All three programs require string or int input
 ** from the user.
 *********************************************************************/

#include "recursiveFunctions.hpp"

/*********************************************************************
 ** stringReverser(string):
 ** Accepts a string. Returns the reversed string (all characters) with
 ** a newline at the end.
 *********************************************************************/
string stringReverser(string stringIn)
{
    if (stringIn.length() <= 1)
    {
        return stringIn + "\n";
    }
    else
    {
        char lastLetter = stringIn[stringIn.length() - 1];
        stringIn.erase(stringIn.length() - 1);
        
        return (lastLetter + stringReverser(stringIn));
        
    }
}

/*********************************************************************
 ** arraySum(int*, int):
 ** Accepts a pointer to an array of ints and the size of that array as
 ** an int. Returns the sum of all the elements of the array
 *********************************************************************/
int arraySum(int* ptrIntArray, int numElements)
{
    if (numElements == 0)
    {
        return 0;
    }
    else
    {
        return (ptrIntArray[numElements - 1] + arraySum(ptrIntArray, numElements - 1));
    }
}

/*********************************************************************
 ** triangularNumber(int):
 ** Accepts an integer. Returns the triangular number of that integer.
 *********************************************************************/
int triangularNumber(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return (n + triangularNumber(n-1));
    }
}
