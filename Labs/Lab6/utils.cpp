/*********************************************************************
 ** Program name: Doubly-linked List
 ** Author: Joel Huffman
 ** Date: 2/17/2018
 ** Description: Allows users to add, delete and print out nodes of a
 ** doubly-linked list
 *********************************************************************/

#include "utils.hpp"
#include "DoubleLink.hpp"

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
 ** from the linked list.
 *********************************************************************/
int menu()
{
    bool keepLooping = true;
    
    //create DoubleLink object
    DoubleLink* linkedList = new DoubleLink;
    
    string prompts[] = {
        "Welcome to the doubly-linked list!\n\n",
        "What would you like to do?\n1. Add a new node to the head.\n2. Add a new node to the tail.\n3. Delete the first node in the list.\n4. Delete the last node in the list.\n5. Traverse the list reversely.\n6. Print the value of the node the head is pointing to.\n7. Print the value of the node the tail is pointing to.\n8. Exit\n",
        "Enter a positive integer\n"
    };
    
    cout << "***Extra credit task 1 included in this program***\n";
    cout << prompts[0];
    
    while (keepLooping)
    {
        switch(intValidation(1, 8, prompts[1]))
        {
                //add node to head
            case 1:
            {
                int addHeadVal = intValidation(1, 999, prompts[2]);
                linkedList->addNodeHead(addHeadVal);
                break;
            }
                
                //add node to tail
            case 2:
            {
                int addTailVal = intValidation(1, 999, prompts[2]);
                linkedList->addNodeTail(addTailVal);
                break;
            }
                
                //delete node from head
            case 3:
            {
                linkedList->deleteHead();
                break;
            }
                
                //delete node from tail
            case 4:
            {
                linkedList->deleteTail();
                break;
            }
                
                //print link from tail to head
            case 5:
            {
                linkedList->traverseBackwards();
                break;
            }
                
                //print val at head
            case 6:
            {
                linkedList->printNode(linkedList->getHead());
                break;
            }
                //print val at tail
            case 7:
            {
                linkedList->printNode(linkedList->getTail());
                break;
            }
                //exit the program
            case 8:
            {
                cout << "Exiting program.\n";
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

    delete linkedList;
    return 0;
}
