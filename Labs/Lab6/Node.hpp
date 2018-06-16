/*********************************************************************
 ** Program name: Doubly-linked List
 ** Author: Joel Huffman
 ** Date: 2/17/2018
 ** Description: Allows users to add, delete and print out nodes of a
 ** doubly-linked list
 *********************************************************************/

#ifndef Node_hpp
#define Node_hpp

class Node
{
public:
    Node();
    int val;
    Node* next;
    Node* prev;
};

#endif /* Node_hpp */
