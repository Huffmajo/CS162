/*********************************************************************
 ** Program name: Circular-linked List
 ** Author: Joel Huffman
 ** Date: 2/19/2018
 ** Description: Allows users to add, delete and print out nodes of a
 ** circular-linked list
 *********************************************************************/

#ifndef QueueNode_hpp
#define QueueNode_hpp

struct QueueNode
{
    int val;
    QueueNode* next = nullptr;
    QueueNode* prev = nullptr;
};

#endif /* QueueNode_hpp */
