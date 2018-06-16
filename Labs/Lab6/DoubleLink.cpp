/*********************************************************************
 ** Program name: Doubly-linked List
 ** Author: Joel Huffman
 ** Date: 2/17/2018
 ** Description: Allows users to add, delete and print out nodes of a
 ** doubly-linked list
 *********************************************************************/

#include "DoubleLink.hpp"
#include <iostream>
using std::cout;


/*********************************************************************
 ** traverse(Node* headIn):
 ** Accepts an integer. Creates a new element at the tail of the list
 ** with the integer stored in that element.
 *********************************************************************/
void DoubleLink::addNodeHead(int valIn)
{
    //create new node
    Node* newNode = new Node;
    
    //set newNode's val to user input
    newNode->val = valIn;
    
    //if list is empty set newNode to head
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    
    //if list is not empty
    else
    {
        //old head's prev links to newNode
        head->prev = newNode;
        //newNode's next links to old head
        newNode->next = head;
        //newNode becomes the new head
        head = newNode;
    }
    
    //head's prev should always be null
    newNode->prev = nullptr;
    
    //print the list
    traverse();
}

/*********************************************************************
 ** addNodeTail(int valIn):
 ** Accepts an integer. Creates a new element at the tail of the list
 ** with the integer stored in that element.
 *********************************************************************/
void DoubleLink::addNodeTail(int valIn)
{
    //create new node
    Node* newNode = new Node;
    
    //set newNode's val to user input
    newNode->val = valIn;
    
    //if list is empty set newNode to head
    if (tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    
    //if list is not empty
    else
    {
        //old tail's next links to newNode
        tail->next = newNode;
        //newNode's prev links to old head
        newNode->prev = tail;
        //newNode becomes the new head
        tail = newNode;
    }
    
    //tail's next should always be null
    newNode->next = nullptr;
    
    //print the list
    traverse();
}

/*********************************************************************
 ** deleteHead():
 ** Delete's the element at the head of the list and shifts the remaining
 ** elements accordingly
 *********************************************************************/
void DoubleLink::deleteHead()
{
    //if list is empty, give warning message
    if (head == nullptr)
    {
        cout << "\nList is empty. No head to delete.\n\n";
    }
    
    //if only one element in list, delete it
    else if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        
        //print the list
        traverse();
    }
    
    //otherwise remove element at head and shift remaining elements
    else
    {
        Node* temp = head;
        delete head;
        temp->next->prev = nullptr;
        head = temp->next;
        
        //print the list
        traverse();
    }
}

/*********************************************************************
 ** deleteTail():
 ** Delete's the element at the tail of the list and shifts the remaining
 ** elements accordingly
 *********************************************************************/
void DoubleLink::deleteTail()
{
    //if list is empty, give warning message
    if (tail == nullptr)
    {
        cout << "\nList is empty. No tail to delete.\n\n";
    }
    
    //if only one element in list, delete it
    else if (head == tail)
    {
        delete tail;
        head = nullptr;
        tail = nullptr;
        
        //print the list
        traverse();
    }
    
    //otherwise remove element at tail and shift remaining elements
    else
    {
        Node* temp = tail;
        delete tail;
        temp->prev->next = nullptr;
        tail = temp->prev;
        
        //print the list
        traverse();
    }
}

/*********************************************************************
 ** traverse():
 ** Prints each element of the list from head to tail.
 *********************************************************************/
void DoubleLink::traverse()
{
    //if list isn't empty print it's contents
    if (head !=nullptr)
    {
        Node* temp = head;
        
        cout << "\nYour linked list is: ";
        
        while (temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        
        cout << "\n\n";
    }
    //print empty message if list is empty
    else
    {
        cout << "\nLinked list is empty\n\n";
    }
}

/*********************************************************************
 ** traverseBackwards():
 ** Prints each element of the list from tail to head.
 *********************************************************************/
void DoubleLink::traverseBackwards()
{
    //if list isn't empty print it's contents
    if (tail !=nullptr)
    {
        Node* temp = tail;
        
        cout << "\nYour linked list is: ";
        
        while (temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->prev;
        }
        
        cout << "\n\n";
    }
    //print empty message if list is empty
    else
    {
        cout << "\nLinked list is empty\n\n";
    }
}

/*********************************************************************
 ** printNode(Node* n):
 ** Accepts a pointer to node. Prints out the value at the given node.
 ** If node is null, prints out that the list is empty.
 *********************************************************************/
void DoubleLink::printNode(Node* n)
{
    if (n == nullptr)
    {
        cout << "\nLinked list is empty. No value to print\n\n";
    }
    
    else
    {
        cout << "\n" << n->val << "\n\n";
    }
    
}

/*********************************************************************
 ** ~DoubleLink():
 ** Destructor for DoubleLink class. Frees all allocated memory once
 ** class ends.
 *********************************************************************/
DoubleLink::~DoubleLink()
{
    while(head->next != nullptr)
    {
        //if only one element in list, delete it
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        
        //otherwise remove element at head and shift remaining elements
        else
        {
            while(head->next != nullptr)
            {
                Node* temp = head;
                delete head;
                temp->next->prev = nullptr;
                head = temp->next;
            }
        }
    }
    delete tail;
    tail = nullptr;
}

//getters
Node* DoubleLink::getHead()
{
    return head;
}

Node* DoubleLink::getTail()
{
    return tail;
}
