/*********************************************************************
 ** Program name: Circular-linked List
 ** Author: Joel Huffman
 ** Date: 2/19/2018
 ** Description: Allows users to add, delete and print out nodes of a
 ** circular-linked list
 *********************************************************************/

#ifndef Queue_hpp
#define Queue_hpp

#include "QueueNode.hpp"

class Queue
{
private:
    QueueNode* head;
    
public:
    Queue();
    ~Queue();
    bool isEmpty();
    void addBack(int val);
    int getFront();
    void removeFront();
    void printQueue();
};

#endif /* Queue_hpp */
