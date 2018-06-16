/*********************************************************************
 ** Program name: Langtons Ant Simulation
 ** Author: Joel Huffman
 ** Date: 1/20/2018
 ** Description: This program runs simulations of Langston's Ant from
 ** user supplied inputs. The simulations are displayed with ASCII
 ** characters onto the screen. The user can continually run simulations
 ** until they are satisfied with exiting the program.
 *********************************************************************/


#include "menu.hpp"

int menu()
{
    bool runSimulation,
    randomStart;
    bool playAgain = true;
    
    int rows,
    columns,
    steps,
    startRow,
    startColumn;
    
    string menuPrompt[] = { "*This program contains the extra credit random ant starting location option*\n",
        "Would you like to run a simulation?\n1. Start Langton's Ant simulation \n2. Quit\n",
        "Would you like the ant to start at a random location?\n1. Yes\n2. No\n",
        "How many rows should the board have? (1-999)\n",
        "How many columns should the board have? (1-999)\n",
        "How many steps should the simulation run? (1-9999)\n",
        "What row should the ant start on?\n",
        "What column should the ant start on?\n",
        "Would you like to run another simulation?\n1. Play again\n2. Quit\n"
    };
    
    //extra credit warning
    cout << menuPrompt[0];
    
    //ask if they want to run a simulation
    switch (intValidation(1, 2, menuPrompt[1]))
    {
        case 1:
            runSimulation = true;
            break;
            
        case 2:
            return 1;
            break;
            
        default:
            return 2;
            break;
    }
    
    //keep running simulations until user says they want to quit
    while (playAgain)
    {
        //ask if they want a random ant starting location
        switch (intValidation(1, 2, menuPrompt[2]))
        {
            case 1:
                randomStart = true;
                break;
            
            case 2:
                randomStart = false;
                break;
            
            default:
                return 2;
                break;
        }
    
        //ask for the dimensions of the board
        rows = intValidation(1, 999, menuPrompt[3]);
        columns = intValidation(1, 999, menuPrompt[4]);
    
        //ask how many steps the simulation should run
        steps = intValidation(1, 9999, menuPrompt[5]);
    
        //if user asked for a random ant start location
        //generate that for them
        if (randomStart)
        {
            srand(time(NULL));
            startRow = rand() % rows;
            startColumn = rand() % columns;
        }
    
        //otherwise ask them for the starting row and column
        else
        {
            startRow = intValidation(0, rows-1, menuPrompt[6]);
            startColumn = intValidation(0, columns-1, menuPrompt[7]);
        }
    
        //create Ant object with all the users data and run the simulation
        Ant sim(rows, columns, startRow, startColumn, 1, steps);
        sim.simulator();
    
        //ask user if they want to play again
        switch(intValidation(1, 2, menuPrompt[8]))
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
