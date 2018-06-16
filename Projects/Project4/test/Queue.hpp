/*********************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Joel Huffman
 ** Date: 2/25/2018
 ** Description: Allows users to create teams of fantasy characters and
 ** have these teams battle one another to ultimately claim victory.
 *********************************************************************/

#ifndef Queue_hpp
#define Queue_hpp

#include "QueueNode.hpp"
#include "Character.hpp"

class Queue
{
private:
    QueueNode* head;
    
public:
    Queue();
    ~Queue();
    bool isEmpty();
    void addBack(Character* val);
    Character* getFront();
    void removeFront();
    void printQueue();
    void printQueueBackwards();
};

#endif /* Queue_hpp */
