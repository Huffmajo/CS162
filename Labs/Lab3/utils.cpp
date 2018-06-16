/*********************************************************************
 ** Program name: Dice War
 ** Author: Joel Huffman
 ** Date: 1/26/2018
 ** Description: Program simulates a dice war game between two players
 ** with dice type, dice size and number of rounds decided by the user.
 ** Every round's result is printed to the screen with a final printout
 ** showing who won the entire game and the final scores.
 *********************************************************************/

#include "utils.hpp"
#include "Game.hpp"

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

int menu()
{
    bool playAgain = true;
    
    int rounds,
    p1Die,
    p2Die,
    p1Sides,
    p2Sides;
    
    string menuPrompt[] = { "*This program contains extra credit*\n",
        "Would you like to play a dice game?\n1. Start game \n2. Exit game\n",
        "How many rounds will be played\n",
        "What type of die should player 1 use?\n1. Regular die \n2. LoadedDie\n",
        "What type of die should player 2 use?\n1. Regular die \n2. LoadedDie\n",
        "How many sides should there be on player 1's die?\n",
        "How many sides should there be on player 2's die?\n",
        "Would you like to play again?\n1. Play again\n2. Exit game\n"
    };
    
    //ask if they want to play a game
    switch (intValidation(1, 2, menuPrompt[1]))
    {
        case 1:
            break;
            
        case 2:
            return 1;
            break;
            
        default:
            return 2;
            break;
    }
    
    //keep playing games until user says they want to quit
    while (playAgain)
    {
        
        //ask for the number of rounds
        rounds = intValidation(1, 999, menuPrompt[2]);

        //ask for player 1's die type
        p1Die = intValidation(1, 2, menuPrompt[3]);
        
        //ask for player 2's die type
        p2Die = intValidation(1, 2, menuPrompt[4]);
        
        //ask for # of sides on player 1's die
        p1Sides = intValidation(2, 99, menuPrompt[5]);
        
        //ask for # of sides on player 2's die
        p2Sides = intValidation(2, 99, menuPrompt[6]);

        //create the game object with the collected data
        Game diceWar(p1Die, p2Die, p1Sides, p2Sides, rounds);
        
        //play the game
        diceWar.playGame();
        
        //ask user if they want to play again
        switch(intValidation(1, 2, menuPrompt[7]))
        {
            case 1:
                playAgain = true;
                break;
                
            case 2:
                playAgain = false;
                break;
                
            default:
                return 2;
                break;
        }
    }
    return 0;
}

