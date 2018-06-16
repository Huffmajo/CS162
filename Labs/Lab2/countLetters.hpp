/*********************************************************************
 ** Program name: File Letter Counter
 ** Author: Joel Huffman
 ** Date: 1/19/2018
 ** Description: This program counts the frequency of every letter in a
 ** user provided file. For each separate paragraph of text in the file, a
 ** separate letter frequency count will be generated and written to a
 ** user chosen output file.
 *********************************************************************/

#ifndef countLetters_hpp
#define countLetters_hpp


#include <stdio.h>
#include "outputLetters.hpp"
#include <fstream>
#include <string>
using std::ifstream;
using std::string;

/*********************************************************************
 ** Function: countLetters
 ** Accepts an ifstream file and a pointer to an array of letter
 ** frequencies. This function counts the frequency of letters in the
 ** given input file. A frequency table is generated for each section
 ** of text divided by linebreaks. These frequency tables are sent to
 ** the function outputLetters.
 *********************************************************************/
void countLetters(ifstream &inputFile, int* ptrLetterFreq);

#endif /* countLetters_hpp */
