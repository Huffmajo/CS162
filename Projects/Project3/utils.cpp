/*********************************************************************
 ** Program name: Fantasy Combat Game
 ** Author: Joel Huffman
 ** Date: 02/12/18
 ** Description: Header for the utility functions. Declares the variables
 ** and functions for the menu and input validation.
 *********************************************************************/

#include "utils.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Game.hpp"

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
 ** Allows the user to choose which characters to battle and continue
 ** to set up battles until ready to quit.
 *********************************************************************/
int menu()
{
    bool keepLooping = true;
    Character* p1;
    Character* p2;
    
    string prompts[] = {
        "Which character should P1 be?\n1. Vampire\n2. Barbarian\n3. Blue men\n4. Medusa\n5. Harry Potter\n",
        "Which character should P2 be?\n1. Vampire\n2. Barbarian\n3. Blue men\n4. Medusa\n5. Harry Potter\n",
        "Would you like to play again?\n1. Play again\n2. Exit the game\n"};
    
    while (keepLooping)
    {
        //Choose player 1 character
        switch(intValidation(1, 5, prompts[0]))
        {
            case 1:
            {
                //Vampire v;
                //p1 = &v;
                Character* v = new Vampire();
                p1 = v;
                break;
            }
                
            case 2:
            {
                Character* b = new Barbarian();
                p1 = b;
                break;
            }
                
            case 3:
            {
                Character* bm = new BlueMen();
                p1 = bm;
                break;
            }
                
            case 4:
            {
                Character* m = new Medusa();
                p1 = m;
                break;
            }
                
            case 5:
            {
                Character* hp = new HarryPotter();
                p1 = hp;
                break;
            }
                
            default:
                Character* b = new Barbarian();
                p1 = b;
                break;
        }
        
        //Choose player 2 character
        switch(intValidation(1, 5, prompts[1]))
        {
            case 1:
            {
                //Vampire v2;
                //p2 = &v2;
                Character* v2 = new Vampire();
                p2 = v2;
                break;
            }
                
            case 2:
            {
                Character* b2 = new Barbarian();
                p2 = b2;
                break;
            }
                
            case 3:
            {
                Character* bm2 = new BlueMen();
                p2 = bm2;
                break;
            }
                
            case 4:
            {
                Character* m2 = new Medusa();
                p2 = m2;
                break;
            }
                
            case 5:
            {
                Character* hp2 = new HarryPotter();
                p2 = hp2;
                break;
            }
                
            default:
                Character* b2 = new Barbarian();
                p2 = b2;
                break;
        }
        
        //create game with user picked combatants
        Game battle(p1, p2);
        
        while (battle.getVictor() == NULL)
        {
            battle.round();
        }
        
        //print who won the battle
        cout << "****************************\n";
        cout << battle.getVictor()->getName() << " is victorious!\n";
        cout << "****************************\n\n";
        
        //deallocate memory
        delete p1;
        delete p2;
        
        //ask to play again
        switch(intValidation(1, 2, prompts[2]))
        {
            case 1:
            {
                keepLooping = true;
                break;
            }
                
            case 2:
            {
                keepLooping = false;
                break;
            }
                
            default:
                //something went wrong
                break;
        }
    }
    cout << "Thank you for playing Fantasy Combat Game.";
    return 0;
}
