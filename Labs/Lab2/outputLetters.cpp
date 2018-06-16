/*********************************************************************
 ** Program name: File Letter Counter
 ** Author: Joel Huffman
 ** Date: 1/19/2018
 ** Description: This program counts the frequency of every letter in a
 ** user provided file. For each separate paragraph of text in the file, a
 ** separate letter frequency count will be generated and written to a
 ** user chosen output file.
 *********************************************************************/

#include "outputLetters.hpp"

void outputLetter(ofstream &outputFile, int* ptrLetterFreq)
{
    const int ALPHABET_NUM = 26;
    //create char array of lowercase alphabet
    char alphabet[] =
    {'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z'};
    
     string outputFilename;
    
    //prompt user for an output file name
    cout << "Choose filename to write paragraph letter count frequencies to\n";
    cin >> outputFilename;
    
    //open user-named file
    outputFile.open(outputFilename);
    
    //write letter counts to file
    for (int i = 0; i < ALPHABET_NUM; i++)
    {
        outputFile << alphabet[i] << ": " << ptrLetterFreq[i] << "\n";
        
        //reset letter counts to 0 for next paragraph
        ptrLetterFreq[i] = 0;
    }
    
    outputFile.close();
}
