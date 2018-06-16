/*********************************************************************
 ** Program name: Matrix Determinant Calculator
 ** Author: Joel Huffman
 ** Date: 1/8/2018
 ** Description: Creates a user-filled 2x2 or 3x3 matrix and calculates
 ** the determinant of that matrix. Both are printed for the user.
 *********************************************************************/

#include <iostream>
#include <limits>
#include "readMatrix.hpp"
#include "determinant.hpp"
using std::cout;
using std::cin;
using std::numeric_limits;
using std::streamsize;

int main() {
    int matrixSize;
    int deter;
    bool isValid = false;

    while (!isValid)
    {
        cout << "What size of matrix would you like to use?\n";
        cout << "2.) 2x2\n";
        cout << "3.) 3x3\n";
    
        cin >> matrixSize;
        
        //check if input is valid
        if (matrixSize == 2 || matrixSize == 3)
        {
            isValid = true;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input. Please try again. \n";
        }
    }
    
    //dynamically allocate 2D array from chosen matrix size
    int** matrix = new int*[matrixSize];
    for (int i = 0; i < matrixSize; i++)
    {
        matrix[i] = new int[matrixSize];
    }
    
    //pointer to 2D array of our matrix;
    int** ptr = matrix;
    
    //Call readMatrix() to have user fill the matrix
    readMatrix(ptr, matrixSize);
    
    //Calculate the determinant of the matrix
    deter = determinant(ptr, matrixSize);
    
    //Display the matrix for the user
    cout << "Matrix: \n";
    
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            cout << ptr[i][j] << " ";
        }
        cout << "\n";
    }
    
    //Print out the determinant
    cout << "\nDeterminant: \n" << deter;
    
    //delete dynamically allocated 2D array to prevent memory leaks
    for (int i = 0; i < matrixSize; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
