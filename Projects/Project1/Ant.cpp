/*********************************************************************
 ** Program name: Langtons Ant Simulation
 ** Author: Joel Huffman
 ** Date: 1/20/2018
 ** Description: This program runs simulations of Langston's Ant from
 ** user supplied inputs. The simulations are displayed with ASCII
 ** characters onto the screen. The user can continually run simulations
 ** until they are satisfied with exiting the program.
 *********************************************************************/

#include "Ant.hpp"
#include <iostream>
using std::cout;

Ant::Ant()
{
}


Ant::Ant(int boardSizeXIn, int boardSizeYIn, int antXIn, int antYIn, int facingIn, int stepsIn)
{
    boardSizeX = boardSizeXIn;
    boardSizeY = boardSizeYIn;
    antX = antXIn;
    antY = antYIn;
    facing = facingIn;
    lastStep = stepsIn;
    currentStep = 0;
    
    //create board from user boardSize inputs
    board = new char*[boardSizeX];
    for (int i = 0; i < boardSizeX; i++)
    {
        board[i] = new char[boardSizeY];
    }
    
    //fill board with white spaces
    for (int i = 0; i < boardSizeX; i++)
    {
        for (int j = 0; j < boardSizeY; j++)
        {
            board[i][j] = white;
        }
    }
    
    //set spaceUnderAnt before drawing ant symbol (*) at that location
    spaceUnderAnt = board[antX][antY];
    setSpaceColor(antX, antY, ant);
    
    printBoard();
}

int Ant::getBoardX()
{
    return boardSizeX;
}

int Ant::getBoardY()
{
    return boardSizeY;
}

int Ant::getAntX()
{
    return antX;
}

int Ant::getAntY()
{
    return antY;
}

int Ant::getFacing()
{
    return facing;
}

int Ant::getCurrentStep()
{
    return currentStep;
}

int Ant::getLastStep()
{
    return lastStep;
}

char Ant::getSpaceColor(int xIn, int yIn)
{
    return board[xIn][yIn];
}

void Ant::setSpaceColor(int x, int y, char color)
{
    board[x][y] = color;
}

void Ant::takeStep()
{
    if (spaceUnderAnt == white)
    {
        //turn right
        if (facing + 1 > 3)
        {
            facing = 0;
        }
        else
        {
            facing++;
        }
        
        //change current space color
        board[antX][antY] = black;
        
    }
    else if (spaceUnderAnt == black)
    {
        //turn left
        if (facing - 1 < 0)
        {
            facing = 3;
        }
        else
        {
            facing--;
        }
        
        //change current space color
        board[antX][antY] = white;
    }
    
    //move forward
    moveForward();
    
    //update spaceUnderAnt
    spaceUnderAnt = board[antX][antY];
    
    //update ant symbol (*) on board
    board[antX][antY] = ant;
    
    //increment currentStep
    currentStep++;
    
    //print out the board
    printBoard();
    
}

void Ant::moveForward()
{
    
    //UPDATE BOUNDS CHECKING FOR EDGE CASES
    switch (facing)
    {
        case 0:
        {
            if (antX - 1 < 0)
            {
                antX = boardSizeX - 1;
            }
            else
            {
                antX -= 1;
            }
            break;
        }
            
        case 1:
        {
            if (antY + 1 >= boardSizeX)
            {
                antY = 0;
            }
            else
            {
                antY += 1;
            }
            break;
        }
            
        case 2:
        {
            if (antX + 1 >= boardSizeX)
            {
                antX = 0;
            }
            else
            {
                antX += 1;
            }
            break;
        }
            
        case 3:
        {
            if (antY - 1 < 0)
            {
                antY = boardSizeY - 1;
            }
            else
            {
                antY -= 1;
            }
            break;
        }
            
        default:
        {
            cout << "Invalid direction facing value \n";
            break;
        }
    }
}

void Ant::printBoard()
{
    //print the top border
    for (int i = 0; i < boardSizeY + 2; i++)
    {
        cout << "-";
    }
    cout << "\n";
    
    //print the board
    for (int i = 0; i < boardSizeX; i++)
    {
        
        //left boarder
        cout << "|";
        
        for (int j = 0; j < boardSizeY; j++)
        {
            cout << board[i][j];
        }
        
        //right boarder
        cout << "|\n";
    }
    
    //print the bottom border
    for (int i = 0; i < boardSizeY + 2; i++)
    {
        cout << "-";
    }
    cout << "\n";
}

void Ant::simulator()
{
    while (currentStep < lastStep)
    {
        takeStep();
    }
}

Ant::~Ant()
{
    //deallocate memory and delete pointers
    for (int i = 0; i < boardSizeX; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}
