/*********************************************************************
 ** Program name: Langtons Ant Simulation
 ** Author: Joel Huffman
 ** Date: 1/20/2018
 ** Description: This program runs simulations of Langston's Ant from
 ** user supplied inputs. The simulations are displayed with ASCII
 ** characters onto the screen. The user can continually run simulations
 ** until they are satisfied with exiting the program.
 *********************************************************************/

#include "intValidation.hpp"

//This function was inspired by Long Le's getIntFromUser() function shared
//on the piazza Utility Functions topic. I altered the do-while structure to
//a while loop and negated the use of a boolean variable.
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
