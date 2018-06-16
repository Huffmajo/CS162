/*********************************************************************
 ** Program name: Searching and Sorting
 ** Author: Joel Huffman
 ** Date: 2/28/2018
 ** Description: Reads in arrays from .txt files and sorts the arrays
 ** before both printing the sorted arrays and writing them to a user
 ** named .txt file.
 *********************************************************************/

#include "bubbleSort.hpp"

/*********************************************************************
 ** swap(int* a, int* b):
 ** swaps the values of the two ints given as parameters.
 *********************************************************************/
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*********************************************************************
 bubble sort algorithm sourced and slightly modified from
 https://www.geeksforgeeks.org/bubble-sort/
 *********************************************************************/
/*********************************************************************
 ** bubbleSort(vector<int>* arr):
 ** accepts a pointer to a vector. Sorts values in vector into ascending
 ** order
 *********************************************************************/
void bubbleSort(vector<int>* arr)
{
    for (int i = 0; i < arr->size()-1; i++)
    {
        for (int j = 0; j < arr->size()-i-1; j++)
        {
            if (arr->at(j) > arr->at(j+1))
            {
                swap(&arr->at(j), &arr->at(j+1));
            }
        }
    }
}

/*********************************************************************
 ** printSorted(vector<int>* arr):
 ** accepts a pointer to a vector. Prints out the sorted values of the
 ** vector
 *********************************************************************/
void printSorted(vector<int>* arr)
{
    cout << "Sorted file: ";
    for (int i = 0; i < arr->size(); i++)
    {
        cout << arr->at(i) << " ";
    }
    cout << "\n\n";
}

/*********************************************************************
 ** outputSorted(vector<int>* arr, string outputFile):
 ** accepts a pointer to a vector and a string. Creates a .txt file with
 ** the string for a name. Outputs each element from the vector into
 ** the .txt file.
 *********************************************************************/
void outputSorted(vector<int>* arr, string outputFile)
{
    ofstream outFile;
    outFile.open(outputFile);
    for (int i = 0; i < arr->size(); i++)
    {
        outFile << arr->at(i) << " ";
    }
    outFile.close();
    cout << "\n";
}
