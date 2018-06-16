/*********************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Joel Huffman
 ** Date: 2/25/2018
 ** Description: Allows users to create teams of fantasy characters and
 ** have these teams battle one another to ultimately claim victory.
 *********************************************************************/

#include "Queue.hpp"
#include <iostream>
using std::cout;

/*********************************************************************
 ** Queue():
 ** initializes the relationship between head and tail
 *********************************************************************/
Queue::Queue()
{
    head = nullptr;
}

/*********************************************************************
 ** ~Queue():
 ** deletes and frees all QueueNode memory
 *********************************************************************/
Queue::~Queue()
{
    while (!isEmpty())
    {
        //if only one element in queue
        if (head->next == head)
        {
            delete head->val;
            delete head;
            head = nullptr;
        }
        
        //otherwise, remove element at head and adjust other elements accordingly
        else
        {
            QueueNode* temp = head;
            QueueNode* last = head->prev;
            delete head->val;
            delete head;
            temp->next->prev = nullptr;
            head = temp->next;
            head->prev = last;
            last->next = head;
        }
    }
}

/*********************************************************************
 ** isEmpty():
 ** checks if queue is empty. If empty, return true. Otherwise, return
 ** false
 *********************************************************************/
bool Queue::isEmpty()
{
    bool noElements= false;
    
    if (head == nullptr)
    {
        noElements = true;
    }
    
    return noElements;
}

/*********************************************************************
 ** addBack(int val):
 ** takes an integer. Creates a QueueNode with an integer value and
 ** appends it to the back of the list
 *********************************************************************/
void Queue::addBack(Character* val)
{
    //create new node to be appended
    QueueNode* newNode = new QueueNode;
    newNode->val = val;
    
    //if list is empty
    if (isEmpty())
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    }
    
    //if list has some elements
    else
    {
        QueueNode* last = head->prev;
        
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }
}

/*********************************************************************
 ** getFront():
 ** retuns the value of the node at the front of the queue
 *********************************************************************/
Character* Queue::getFront()
{
    return head->val;
}

/*********************************************************************
 ** removeFront():
 ** removes the front QueueNode of the queue and frees the memory
 *********************************************************************/
void Queue::removeFront()
{
    //if only one element in queue
    if (head->next == head)
    {
        delete head;
        head = nullptr;
    }
    
    //otherwise, remove element at head and adjust other elements accordingly
    else
    {
        QueueNode* temp = head;
        QueueNode* last = head->prev;
        delete head;
        temp->next->prev = nullptr;
        head = temp->next;
        head->prev = last;
        last->next = head;
    }
}

/*********************************************************************
 ** printQueue():
 ** prints the values of the QueueNodes from front to back
 *********************************************************************/
void Queue::printQueue()
{
    //if list is empty, print empty list message
    if (isEmpty())
    {
        cout << "\nYour queue is empty\n\n";
    }
    
    //otherwise, print each node's value starting with head
    else
    {
        QueueNode* temp = head;
        cout << "\nLosers stack is:\n";
        
        //keep printing and cycling through
        //node's until node before head is reached
        while (temp->next != head)
        {
            cout << temp->val->getName() << "\n";
            temp = temp->next;
        }
        cout << temp->val->getName() << "\n\n";
    }
}

/*********************************************************************
 ** printQueueBackwards():
 ** prints the values of the QueueNodes from back to front
 *********************************************************************/
void Queue::printQueueBackwards()
{
    //if list is empty, print empty list message
    if (isEmpty())
    {
        cout << "\nYour queue is empty\n\n";
    }
    
    //otherwise, print each node's value starting with head
    else
    {
        QueueNode* temp = head->prev;
        cout << "\nLosers stack is:\n";
        
        //keep printing and cycling through
        //node's until node before head is reached
        while (temp != head)
        {
            cout << "Type: " << temp->val->getType() << ", Name: " << temp->val->getName() << ", Team: " << temp->val->getTeam() << "\n";
            temp = temp->prev;
        }
        cout << "Type: " << temp->val->getType() << ", Name: " << temp->val->getName() << ", Team: " << temp->val->getTeam() << "\n\n";
    }
}
