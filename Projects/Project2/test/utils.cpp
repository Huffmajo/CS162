/*********************************************************************
 ** Program name: Zoo Tycoon
 ** Author: Joel Huffman
 ** Date: 2/02/2018
 ** Description: You're the owner of your very own zoo. Choose which
 ** animals to purchase and try to keep from going bankrupt. Random
 ** events happen daily that could be positive or negative. Your animals
 ** can even have babies once they reach adulthood.
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

int menu(Zoo* ptrZoo)
{
    bool keepPlaying = true;
    
    string prompts[] = {"Zoo Tycoon Game\n",
                        "You have $50,000 to start your zoo.\n",
                        "Would you like to buy 1 or 2 tigers? ($10,000 per tiger)\n",
                        "Would you like to buy 1 or 2 penguins? ($1,000 per penguin)\n",
                        "Would you like to buy 1 or 2 turtles? ($100 per turtle)\n",
                        "Would you like to buy an adult animal?\n1. Tiger($10,000)\n2. Penguin($1,000)\n3. Turtle($100)\n4. No thanks\n",
                        "Play another day?\n 1. Keep playing\n 2. Quit\n"
    };
    
    cout << prompts[0] << prompts[1];
    
    //See how many tigers to initially buy
    switch(intValidation(1, 2, prompts[2]))
    {
        case 1:
            ptrZoo->addTiger(1);
            break;
            
        case 2:
            ptrZoo->addTiger(1);
            ptrZoo->addTiger(1);
            break;
            
        default:
            return -1;
            break;
    }
    
     //See how many penguins to initially buy
     switch(intValidation(1, 2, prompts[3]))
     {
     case 1:
     ptrZoo->addPenguin(1);
     break;
     
     case 2:
     ptrZoo->addPenguin(1);
     ptrZoo->addPenguin(1);
     break;
     
     default:
     return -1;
     break;
     }
     
     //See how many turtles to initially buy
     switch(intValidation(1, 2, prompts[4]))
     {
     case 1:
     ptrZoo->addTurtle(1);
     break;
     
     case 2:
     ptrZoo->addTurtle(1);
     ptrZoo->addTurtle(1);
     break;
     
     default:
     return -1;
     break;
     }

    while (keepPlaying)
    {
        
        //feed all the animals
        ptrZoo->feedAnimals();
        
        //experience a random event
        ptrZoo->randomEvent();
        
        //receive daily funds
        ptrZoo->dailyProfit();
        
        //Give option to buy an adult animal
        switch(intValidation(1, 4, prompts[5]))
        {
            case 1:
                ptrZoo->addTiger(3);
                break;
                
            case 2:
                //ptrZoo->addPenguin(3);
                break;
                
            case 3:
                //ptrZoo->addTurtle(3);
                break;
                
            case 4:
                break;
                
            default:
                return -1;
                break;
        }
        
        //if funds are depleted, end game
        if (ptrZoo->getFunds() <= 0)
        {
            cout << "Your funds are :" << ptrZoo->getFunds() << "\n";
            cout << "You have run out of money. Game over.\n";
            keepPlaying = false;
        }
        
        else
        {
            cout << "You have $" << ptrZoo->getFunds() << " remaining.\n";
            
            //prompt to keep playing or quit
            switch(intValidation(1, 2, prompts[6]))
            {
                case 1:
                    keepPlaying = true;
                    ptrZoo->incrementDay();
                    break;
                    
                case 2:
                    keepPlaying = false;
                    break;
                    
                default:
                    return -1;
                    break;
            }

        }
        
    }
    
    return 0;
}
