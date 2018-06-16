/*********************************************************************
 ** Program name: determinant
 ** Author: Joel Huffman
 ** Date: 1/8/2018
 ** Description: Accepts a pointer to the user-filled matrix and the 
 ** matrix size. Calculates the determinant of the matrix and returns
 ** that determinant.
 *********************************************************************/

#include "determinant.hpp"

int determinant(int** ptr, int matrixSize)
{
    int deter = 0;
    if (matrixSize == 2)
    {
        deter = (ptr[0][0] * ptr[1][1]) - (ptr[0][1] * ptr[1][0]);
    }
    
    else
    {
        deter = (ptr[0][0] * ((ptr[1][1] * ptr[2][2]) - (ptr[1][2] * ptr[2][1]))) -
                (ptr[1][0] * ((ptr[0][1] * ptr[2][2]) - (ptr[0][2] * ptr[2][1]))) +
                (ptr[2][0] * ((ptr[0][1] * ptr[1][2]) - (ptr[0][2] * ptr[1][1])));
    }
    return deter;
}
