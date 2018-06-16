/*********************************************************************
 ** Program name: Doubly-linked List
 ** Author: Joel Huffman
 ** Date: 2/17/2018
 ** Description: Allows users to add, delete and print out nodes of a
 ** doubly-linked list
 *********************************************************************/

#ifndef DoubleLink_hpp
#define DoubleLink_hpp

#include "Node.hpp"

class DoubleLink
{
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* newNode = nullptr;
    
public:
    void addNodeHead(int valIn);
    void addNodeTail(int valIn);
    void deleteHead();
    void deleteTail();
    void traverse();
    void traverseBackwards();
    void printNode(Node*);
    
    //getters
    Node* getHead();
    Node* getTail();
    
};

#endif /* DoubleLink_hpp */
