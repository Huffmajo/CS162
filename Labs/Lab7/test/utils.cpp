/*********************************************************************
 ** Program name: Circular-linked List
 ** Author: Joel Huffman
 ** Date: 2/19/2018
 ** Description: Allows users to add, delete and print out nodes of a
 ** circular-linked list
 *********************************************************************/

#include "utils.hpp"
#include "Queue.hpp"

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
                cout << "\nInvalid int. Must be between "
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
            cout << "\nInvalid input. Please enter an integer.\n\n";
        }
        
    }
}

/*********************************************************************
 ** menu:
 ** Interface that the user interacts with to add, remove and print nodes
 ** from the circular linked list.
 *********************************************************************/
int menu()
{
    bool keepLooping = true;
    
    //create Queue object
    Queue* q = new Queue;
    
    string prompts[] = {
        "Welcome to the circular-linked list!\n",
        "\nWhat would you like to do?\n1. Add a value to the back of the queue.\n2. Display the front value.\n3. Remove the front node.\n4. Display the queue's content.\n5. Exit.\n\n",
        "\nEnter a positive integer\n\n"
    };

    //welcome message
    cout << prompts[0];
    
    while (keepLooping)
    {
        switch(intValidation(1, 5, prompts[1]))
        {
                //add node to back of queue
            case 1:
            {
                int addVal = intValidation(1, 999, prompts[2]);
                q->addBack(addVal);
                break;
            }
                
                //print head node's value
            case 2:
            {
                if (q->isEmpty())
                {
                    cout << "\nYour queue is empty\n\n";
                }
                
                else
                {
                    cout << "\nThe first node value is: " << q->getFront() << "\n\n";
                }
                break;
            }
                
                //delete the head node
            case 3:
            {
                if (q->isEmpty())
                {
                    cout << "\nYour queue is empty\n\n";
                }
                
                else
                {
                    q->removeFront();
                }
                break;
            }
                
                //print queue from head to tail
            case 4:
            {
                q->printQueue();
                break;
            }
                
                //exit the loop and the program
            case 5:
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
    }

    delete q;
    return 0;
}
