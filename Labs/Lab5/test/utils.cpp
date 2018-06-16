/*********************************************************************
 ** Program name: Recursive Functions
 ** Author: Joel Huffman
 ** Date: 2/04/2018
 ** Description: Allows users to run any of three functions created
 ** using recursion. All three programs require string or int input
 ** from the user.
 *********************************************************************/

#include "utils.hpp"
#include "recursiveFunctions.hpp"

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
 ** menu:
 ** Allows the user to choose which function to run and input values
 ** for said functions
 *********************************************************************/
int menu()
{
    bool keepLooping = true;
    string prompts[] = {"Which function do you want to run?\n1. stringReverser\n2. arraySum\n3. triangularNumber\n4. Quit\n",
        "Enter a string to be reversed.\n",
        "Enter an integer for the size of the array.\n",
        "Enter an integer to fill the array.\n",
        "Enter an integer to find it's triangular number.\n"};
    
    while (keepLooping)
    {
        switch(intValidation(1, 4, prompts[0]))
        {
            case 1:
            {
                //get info
                string userInput;
                cout << prompts[1];
                getline(cin, userInput);
                
                //run function
                cout << stringReverser(userInput);
                break;
            }
                
            case 2:
            {
                //get info
                int arraySize = intValidation(0, 99, prompts[2]);
                int intArray[arraySize];
                int* ptrArray = intArray;
                for (int i = 0; i < arraySize; i++)
                {
                    intArray[i] = intValidation(-999, 999, prompts[3]);
                }
                
                //run function
                cout << arraySum(ptrArray, arraySize) << "\n";
                break;
            }
                
            case 3:
            {
                //get info
                int userInt = intValidation(0, 999, prompts[4]);
                
                //run function
                cout << triangularNumber(userInt) << "\n";
                break;
            }
                
            case 4:
                keepLooping = false;
                return 0;
                break;
                
            default:
                return -1;
                break;
        }
    }
    return 0;
}
