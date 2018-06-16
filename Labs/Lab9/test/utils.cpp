/*********************************************************************
 ** Program name: Buffer and Palindrome
 ** Author: Joel Huffman
 ** Date: 03/5/18
 ** Description: Definitions for the utility functions. Defines the variables
 ** and functions for the menus and input validation.
 *********************************************************************/

#include "utils.hpp"
#include "buffer.hpp"
#include "palindrome.hpp"

/*********************************************************************
 ** intValidation:
 ** Checks cin if input is an integer within the minimum and maximum
 ** values. Returns the integer if it is acceptable, lists prompt and
 ** asks again if input is invalid.
 *********************************************************************/
int intValidation(int min, int max, string prompt)
{
    string input;
    int validInt;
    
    while (true)
    {
        cout << prompt;
        
        //get inut from user
        getline(cin, input);
        
        stringstream ss(input);
        
        //if input has an int and nothing after that
        if (ss >> validInt && !(ss >> input))
        {
            //check if within bounds
            if (validInt > max || validInt < min)
            {
                cout << "Invalid int. Must be between "
                << min << " and " << max << ".\n";
            }
            
            //if valid integer
            else
            {
                return validInt;
            }
        }
        
        //if noninteger value entered
        else
        {
            cout << "Invalid input. Please enter an integer.\n";
        }
        
    }
}

/*********************************************************************
 ** bufferMenu:
 ** Allows the user to input information to create a buffer queue
 *********************************************************************/
int bufferMenu()
{
    string bufferPrompts[] = { "Enter the percent chance to add a random number to the buffer:\n",
        "Enter the percent chance to remove a number from the buffer:\n",
        "How many rounds should be simulated for the buffer?\n" };
    
    int chanceAdd = intValidation(1, 100, bufferPrompts[0]);
    int chanceRemove = intValidation(1, 100, bufferPrompts[1]);
    int rounds = intValidation(1, 100, bufferPrompts[2]);
    
    //create buffer queue for above info
    buffer(chanceAdd, chanceRemove, rounds);
    
    return 0;
}

/*********************************************************************
 ** palindromeMenu:
 ** Allows the user to input a string to create a palidrome
 *********************************************************************/
int palindromeMenu()
{
    cout << "Enter the string you'd like to create a palindrome from:\n";
    string inString;
    getline(cin, inString);
    
    //create palindrome with above info
    palindrome(inString);
    
    return 0;
}

/*********************************************************************
 ** menu:
 ** Allows the user to choose which function to run or to exit the program
 *********************************************************************/
int menu()
{
    bool keepLooping = true;
    string prompts[] = {
        "Welcome to the queue buffer and stack palindrone program!\n\n",
        "What function do you want to try out?\n1. Queue buffer\n2. Stack palindrome\n3. Exit\n\n" };
    
    cout << prompts[0];
    
    while (keepLooping)
    {
       
        switch(intValidation(1, 3, prompts[1]))
        {
            //run buffer menu
            case 1:
            {
                bufferMenu();
                break;
            }
            
            //run palidrome menu
            case 2:
            {
                palindromeMenu();
                break;
            }
                
            //exit
            case 3:
            {
                keepLooping = false;
                break;
            }
                
           
            default:
                
                break;
        }
    }
    cout << "Thank you for using the queue buffer and palindrome stack program\n";
    return 0;
}


