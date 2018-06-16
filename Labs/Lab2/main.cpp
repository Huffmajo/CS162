/*********************************************************************
 ** Program name: File Letter Counter
 ** Author: Joel Huffman
 ** Date: 1/19/2018
 ** Description: This program counts the frequency of every letter in a
 ** user provided file. For each separate paragraph of text in the file, a
 ** separate letter frequency count will be generated and written to a
 ** user chosen output file.
 *********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "countLetters.hpp"
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;

int main() {

    //create array of ints for each letter's frequency
    int letterFreq[26];
    
    //create pointer to letterFreq array
    int *ptrLetterFreq = letterFreq;
    
    //Set each letter frequency to 0 to start with
    for (int i = 0; i < 26; i++)
    {
        letterFreq[i] = 0;
    }
    
    //ask user for file to read
    cout << "What is the name of the file you'd like to read?\n";

    string inputFilename;
    cin >> inputFilename;
    
    ifstream inputFile(inputFilename);
    
    //Make sure the user's filename is accessable
    while (inputFile.fail())
    {
        cout << "File not found. Try inputting the filename again.\n";
        cin >> inputFilename;
        inputFile.open(inputFilename);
    }
    
    //count the frequency of the letters
    countLetters(inputFile, ptrLetterFreq);
    
    inputFile.close();
    
    
    return 0;
}

