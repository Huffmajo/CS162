/*********************************************************************
 ** Program name: Buffer and Palindrome
 ** Author: Joel Huffman
 ** Date: 03/5/18
 ** Description: Creates a buffer from user input that can add random
 ** numbers to the back or delete them from the front.
 *********************************************************************/

#include "buffer.hpp"
#include <iostream>
#include <queue>
using std::cout;
using std::queue;

void buffer(int chanceAdd, int chanceRemove, int rounds)
{
    int randAdd;
    int randRemove;
    int N;
    double prevAvgBufferLen = 0;
    queue<int> queueBuffer;
    
    cout << "+--------------------------+\n";
    cout << "|       BUFFER QUEUE       |\n";
    cout << "+--------------------------+\n";
    
    for (int i = 0; i < rounds; i++)
    {
        randAdd = rand() % 100 + 1;
        randRemove = rand() % 100 + 1;
        N = rand() % 1000 + 1;
        
        cout << "+---------+\n";
        cout << "|Round: " << i + 1 << "|\n";
        cout << "+---------+\n";
        
        //check if add to buffer
        if (randAdd <= chanceAdd)
        {
            queueBuffer.push(N);
            cout << N << " added to queue\n";
        }
        
        //check if remove from buffer
        if (randRemove <= chanceRemove)
        {
            if (!queueBuffer.empty())
            {
                queueBuffer.pop();
                cout << "Number removed from queue\n";
            }
            else
            {
                cout << "Tried to remove number, but queue is empty\n";
            }
        }
        
        
        cout << "Current buffer: ";
        
        //print each first value
        //pop that value
        //add to back of queue
        for (int i = 0; i < queueBuffer.size(); i++)
        {
            int val = queueBuffer.front();
            cout << val << " ";
            queueBuffer.pop();
            queueBuffer.push(val);
        }
        
        cout << "\n";
        
        /*
        cout << "********DEBUG***********\n";
        cout << "prevAvgLen: " << prevAvgBufferLen << "\n";
        cout << "i: " << i+1 << "\n";
        cout << "Buffer length: " << queueBuffer.size() << "\n";
        cout << "************************\n";
        */
        
        //calculate new avg buffer length
        //set to previous avg buffer length for next round
        prevAvgBufferLen = calcAvgLen(prevAvgBufferLen, i, queueBuffer.size());
        
        //print average length of buffer
        cout << "Average length of buffer: ";
        cout << prevAvgBufferLen << "\n\n";
    }
}

double calcAvgLen(double prevAvg, int i, int length)
{
    double avgLen = (prevAvg * (i) + length) / (i+1);
    return avgLen;
}
