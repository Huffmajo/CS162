/*********************************************************************
 ** Program name: Predator-Prey Game
 ** Author: Group 13 (Joel Huffman, Andrew Swaim, Frank Li, Henry Clay)
 ** Date: February 18, 2018
 ** Description: Menu.cpp, source file for the Menu class.
 *********************************************************************/

#include "Menu.hpp" 

#include <limits.h> 

/*********************************************************************
** Constructor: creates a Menu object
*********************************************************************/
Menu::Menu() {

	int numOfSteps = 0;
	int initRows = 0;
    int initCols = 0;
    int initBugs = 0;
    int initAnts = 0;
    bool keepPlaying = true;
	int keepPlayingChoice = 0; 
}

/*********************************************************************
** runSim : function that runs the Doodlebug simulation, taking user 
** input and then calling appropriate game functions with it. 
*********************************************************************/
void Menu::runSim() {
    int numTotalSpaces;
    int numFreeSpaces;
    
	cout << "\nWelcome to the Predator Prey Simulation!" << endl;
	
	cout << "\nHow many columns should the game board be?\n" << endl; 
	initCols = isInputInt(INT_MAX);
	
	cout << "\nHow many rows should the game board be?\n" << endl;
        initRows = isInputInt(INT_MAX);
	
    //ceiling limit of critters that can be placed
    numFreeSpaces = numTotalSpaces = initRows * initCols;
    
	cout << "\nHow many doodlebugs should the simulation start with?\n" << endl;
        initBugs = isInputInt(numFreeSpaces, 0);

    //update ceiling limit with dbugs added
    numFreeSpaces -= initBugs;
    
	cout << "\nHow many ants should the simulation start with?\n" << endl;
        initAnts = isInputInt(numFreeSpaces, 0);
	
	Board* game = new Board(initCols, initRows, initBugs, initAnts);
	
	while(keepPlaying == true) {

		cout << "\nHow many steps should the simulation run for?\n" << endl;
		numOfSteps = isInputInt(INT_MAX);
        
    	// Execute steps, drawing the board after each step.
    	for (int i = 0; i < numOfSteps; i++) {

			cout << "\nPress enter to continue...\n";
			cin.ignore();

       		game->timeStep();
       		game->drawBoard();
            
            //check to terminate sim early
            if ((numTotalSpaces == game->getQuantAnts()) || game->getQuantAnts() + game->getQuantDbugs() == 0)
            {
                cout << "\nContinued steps will result in an unchanged board. Simulation terminated\n";
                cout << "Program is ending! Thank you!";
                delete game;
                keepPlaying = false;
                break;
            }
   		}	

        if (keepPlaying)
        {
            cout << "\nEnd of steps. Continue?\n";
            cout << "\n1. Continue.\n2. Exit\n" << endl;
            keepPlayingChoice = isInputInt();
        }
   		

		if ( keepPlayingChoice == 2) {

			cout << "\nProgram is ending! Thank you!" << endl;

			delete game;
			exit(0); 
		}
	}
}


/*********************************************************************
** isInputInt: input validation that takes a ceiling and floor for a
** range of inputs, defaults to 2 and 1 for choices of 1 and 2 on a 
** menu. Recycled.  
*********************************************************************/
int Menu::isInputInt(int ceiling, int base)
{
        int intChecker = 0;
        bool validInput = false;
        do
        {
                cin >> intChecker;
                if (cin.fail())
                {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "Input not accepted, try again!" << endl;
                }
                else
                {
                        if (intChecker >= base && intChecker <= ceiling)
                        {
                            validInput = true;
                            return intChecker;
                        }
                        else
                        {
                                cout << "Out of range - enter integer between " << base << " and " << ceiling << ". try again!" << endl;
                        }
               	}
        } while (validInput == false);
    return validInput = true;
}
