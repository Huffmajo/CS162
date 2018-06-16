/*********************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Joel Huffman
 ** Date: 2/25/2018
 ** Description: Allows users to create teams of fantasy characters and
 ** have these teams battle one another to ultimately claim victory.
 *********************************************************************/

#ifndef QueueNode_hpp
#define QueueNode_hpp

#include "Character.hpp"

struct QueueNode
{
    Character* val;
    QueueNode* next = nullptr;
    QueueNode* prev = nullptr;
};

#endif /* QueueNode_hpp */
