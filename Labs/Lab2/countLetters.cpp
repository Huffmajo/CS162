/*********************************************************************
 ** Program name: File Letter Counter
 ** Author: Joel Huffman
 ** Date: 1/19/2018
 ** Description: This program counts the frequency of every letter in a
 ** user provided file. For each separate paragraph of text in the file, a
 ** separate letter frequency count will be generated and written to a
 ** user chosen output file.
 *********************************************************************/

#include "countLetters.hpp"

void countLetters(ifstream &inputFile, int* ptrLetterFreq)
{
    const int ALPHABET_NUM = 26;
    //create char array of lowercase alphabet
    char alphabet[] =
    {'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z'};
    
    string nextLine;
    
    //Read the next paragraph
    while (getline(inputFile, nextLine))
    {
        //read paragraph one char at a time
        for (int i = 0; i < nextLine.length(); i++)
        {
            for (int j = 0; j < ALPHABET_NUM; j++)
            {
                if (tolower(nextLine[i]) == alphabet[j])
                {
                    ptrLetterFreq[j]++;
                }
            }
        }
        //output letter counts to user files
        ofstream outputFile;
        outputLetter(outputFile, ptrLetterFreq);
    }
    //end of file
    inputFile.close();
}
