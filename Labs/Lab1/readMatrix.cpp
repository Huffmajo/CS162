/*********************************************************************
 ** Program name: readMatrix
 ** Author: Joel Huffman
 ** Date: 1/8/2018
 ** Description: Accepts a pointer to the empty matrix and the matrix
 ** size. Prompts the user to fill in the matrix cell by cell. Only ints
 ** are accepted as valid inputs for the matrix cells.
 *********************************************************************/

#include <iostream>
#include <limits>
using std::cin;
using std::cout;
using std::numeric_limits;
using std::streamsize;
#include "readMatrix.hpp"

void readMatrix(int** pointerToMatrix, int matrixSize)
{
    //get numbers for matrix from user
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            bool isValid = false;
            
            //validate input
            while (!isValid)
            {
                cout << "Enter value at [" << i << ", " << j << "]\n";
                cin >> pointerToMatrix[i][j];
                
                if (cin.good())
                {
                    isValid = true;
                }
                else{
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Invalid input. Please enter an integer. \n";
                }
            }
        }
    }
}
