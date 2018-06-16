/*********************************************************************
 ** Program name: OSU Information System
 ** Author: Joel Huffman
 ** Date: 1/30/2018
 ** Description: Gives the user information about the OSU campus. This
 ** includes buildings, students and instructors and statistics about
 ** each of these objects.
 *********************************************************************/

#include "utils.hpp"


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

int menu(University* ptrUni)
{
    bool loop = true;
    
    //Keep showing menu until user is ready to quit
    while (loop)
    {
        //Let user select action from menu
        string menuPrompt =  "Welcome to the OSU Information System.\n1. Prints information about all the buildings.\n2. Prints information of everybody at the university.\n3. Choose a person to do work.\n4. Exit the program.\n";
        
        
        switch (intValidation(1, 4, menuPrompt))
        {
            case 1:
                ptrUni->printBuildingInfo();
                break;
                
            case 2:
                ptrUni->printPeopleInfo();
                break;
                
            case 3:
                workMenu(ptrUni);
                break;
                
            case 4:
                loop = false;
                break;
                
            default:
                return 2;
                break;
        }
        
    }
        return 0;
}


int workMenu(University* ptrUni)
{
    string doWorkPrompt;
    
    //print out the people for the user to choose from
    cout << "Choose the corresponding number of the person that you'd like to see work.\n";
    for (int i = 0; i < ptrUni->getPeople().size(); i++)
    {
        doWorkPrompt +=  std::to_string(i+1) + ". " + ptrUni->getPeople().at(i)->getName() + "\n";
    }
    
    switch (intValidation(1, ptrUni->getPeople().size(), doWorkPrompt))
    {
        case 1:
            ptrUni->getPeople().at(0)->doWork();
            break;
            
        case 2:
            ptrUni->getPeople().at(1)->doWork();
            break;
            
        default:
            return 2;
            break;
    }
    
    
    return 1;
}
