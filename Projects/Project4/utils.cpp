/*********************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Joel Huffman
 ** Date: 2/25/2018
 ** Description: Allows users to create teams of fantasy characters and
 ** have these teams battle one another to ultimately claim victory.
 *********************************************************************/

#include "utils.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "Tournament.hpp"

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
                << min << " and " << max << ".\n\n";
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
            cout << "Invalid input. Please enter an integer.\n\n";
        }
        
    }
}

/*********************************************************************
 ** menu:
 ** Interface for user to create teams for tournament.
 *********************************************************************/
int menu()
{
    bool keepLooping = true;
    int teamSize;
    
    string prompts[] = {
        "Welcome to the Fantasy Combat Tournament!\n",
        "\nWhat would you like to do?\n1. Play.\n2. Exit.\n",
        "How many fighters should each team have?\n",
        "Would you like to view the tournament losers?\n1. View loser stack\n2. Skip\n",
        "Would you like to play another tournament?\n1. Play again.\n2. Exit\n"
    };

    //welcome message
    cout << prompts[0];
    
        switch(intValidation(1, 2, prompts[1]))
        {
                //begin set-up for tourny
            case 1:
            {
                while (keepLooping)
                {
                    //get size of teams
                    teamSize = intValidation(1, 10, prompts[2]);
                    
                    //create queues
                    Queue* team1 = new Queue;
                    Queue* team2 = new Queue;
                    Queue* losers = new Queue;
                    
                    //have user create team rosters
                    setupTournament(teamSize, team1, team2);
                    
                    //run tournament
                    Tournament t((team1), team2, losers);
                    t.runTournament();
                    
                    //would you like to see losers queue
                    switch(intValidation(1, 2, prompts[3]))
                    {
                            //print stack
                        case 1:
                            losers->printQueueBackwards();
                            break;
                            
                            //skip
                        case 2:
                            break;
                    }
                    
                    //delete queues
                    delete team1;
                    delete team2;
                    delete losers;
                    
                    //would you like to play again?
                    switch (intValidation(1, 2, prompts[4]))
                    {
                        case 1:
                            keepLooping = true;
                            break;
                            
                        case 2:
                            keepLooping = false;
                            break;
                    }
                }
                break;
            }
                
                //exit
            case 2:
            {
                keepLooping = false;
                break;
            }
                
            default:
            {
                cout << "ERROR";
                break;
            }
        }
    
    cout << "Now exiting Fantasy Combat Tournament. Thanks for playing!\n";
    return 0;
}

/*********************************************************************
 ** setupTournament(int teamSize):
 ** Gathers information from user to create teams for tournament.
 *********************************************************************/
int setupTournament(int teamSize, Queue* team1, Queue* team2)
{
    string prompts[] = { "\nChoose a fighter type:\n1. Vampire\n2. Barbarian\n3. Blue men\n4. Medusa\n5. Harry Potter\n",
        "\nChoose a name for that fighter:\n" };
    
    cout << "----------------------------\n";
    cout << "|Let's setup team1's roster|\n";
    cout << "----------------------------\n";
    
    //setup team1
    for (int i = 0; i < teamSize; i++)
    {
        Character* ptrTeam1Fighter;
        int fighterType;
        string fighterName;
        
        //pick fighter type
        fighterType = intValidation(1, 5, prompts[0]);
        
        //pick fighter's name
        cout << prompts[1];
        getline(cin, fighterName);
        
        //create fighter
        switch (fighterType)
        {
        case 1:
            {
                Character* v = new Vampire("team1", fighterName);
                ptrTeam1Fighter = v;
                break;
            }
            
        case 2:
            {
                Character* b = new Barbarian("team1", fighterName);
                ptrTeam1Fighter = b;
                break;
            }
            
        case 3:
            {
                Character* bm = new BlueMen("team1", fighterName);
                ptrTeam1Fighter = bm;
                break;
            }
            
        case 4:
            {
                Character* m = new Medusa("team1", fighterName);
                ptrTeam1Fighter = m;
                break;
            }
            
        case 5:
            {
                Character* hp = new HarryPotter("team1", fighterName);
                ptrTeam1Fighter = hp;
                break;
            }
            
        default:
            Character* b = new Barbarian("team1", fighterName);
            ptrTeam1Fighter = b;
            break;
        }
        
        
        //add character to team queue
        team1->addBack(ptrTeam1Fighter);
    }
    
    cout << "--------------------------------\n";
    cout << "|Team1's roster complete!       \n";
    cout << "|Now let's setup team2's roster|\n";
    cout << "--------------------------------\n";
    
    //setup team2
    for (int i = 0; i < teamSize; i++)
    {
        Character* ptrTeam2Fighter;
        int fighterType;
        string fighterName;
        
        //pick fighter type
        fighterType = intValidation(1, 5, prompts[0]);
        
        //pick fighter's name
        cout << prompts[1] << "\n";
        getline(cin, fighterName);
        
        //create fighter
        switch (fighterType)
        {
            case 1:
            {
                Character* v = new Vampire("team2", fighterName);
                ptrTeam2Fighter = v;
                break;
            }
                
            case 2:
            {
                Character* b = new Barbarian("team2", fighterName);
                ptrTeam2Fighter = b;
                break;
            }
                
            case 3:
            {
                Character* bm = new BlueMen("team2", fighterName);
                ptrTeam2Fighter = bm;
                break;
            }
                
            case 4:
            {
                Character* m = new Medusa("team2", fighterName);
                ptrTeam2Fighter = m;
                break;
            }
                
            case 5:
            {
                Character* hp = new HarryPotter("team2", fighterName);
                ptrTeam2Fighter = hp;
                break;
            }
                
            default:
                Character* b = new Barbarian("team2", fighterName);
                ptrTeam2Fighter = b;
                break;
        }
        
        //add character to team queue
        team2->addBack(ptrTeam2Fighter);
    }
    return 0;
}






















