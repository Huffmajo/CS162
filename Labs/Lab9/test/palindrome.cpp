/*********************************************************************
 ** Program name: Buffer and Palindrome
 ** Author: Joel Huffman
 ** Date: 03/5/18
 ** Description: Creates a palindrome from a user-supplied string
 *********************************************************************/

#include "palindrome.hpp"
#include <iostream>
using std::cout;

void palindrome(string inString)
{
    stack<char> palindrome;
    
    cout << "+--------------------------+\n";
    cout << "|        PALINDROME        |\n";
    cout << "+--------------------------+\n\n";
    
    cout << "Your palindrome is: " << inString;
    
    for (int i = 0; i < inString.length(); i++)
    {
        palindrome.push(inString[i]);
    }
    
    for (int i = 0; i < inString.length(); i++)
    {
        cout << palindrome.top();
        palindrome.pop();
    }
    
    cout << "\n\n";
}
