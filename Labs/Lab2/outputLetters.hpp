/*********************************************************************
 ** Program name: File Letter Counter
 ** Author: Joel Huffman
 ** Date: 1/19/2018
 ** Description: This program counts the frequency of every letter in a
 ** user provided file. For each separate paragraph of text in the file, a
 ** separate letter frequency count will be generated and written to a
 ** user chosen output file.
 *********************************************************************/

#ifndef outputLetters_hpp
#define outputLetters_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
using std::ofstream;
using std::cout;
using std::cin;
using std::string;

/*********************************************************************
 ** Function: outputLetters
 ** Accepts an ofstream file and a pointer to an array of letter
 ** frequencies. This function gets an output filename from the user 
 ** and writes the information from the letter frequency array into that
 ** file.
 *********************************************************************/
void outputLetter(ofstream&, int*);

#endif /* outputLetters_hpp */
