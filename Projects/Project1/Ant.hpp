/*********************************************************************
 ** Program name: Langtons Ant Simulation
 ** Author: Joel Huffman
 ** Date: 1/20/2018
 ** Description: This program runs simulations of Langston's Ant from
 ** user supplied inputs. The simulations are displayed with ASCII
 ** characters onto the screen. The user can continually run simulations
 ** until they are satisfied with exiting the program.
 *********************************************************************/

#ifndef Ant_hpp
#define Ant_hpp
#include <stdio.h>

class Ant
{
private:
    const char white = ' ';
    const char black = '#';
    const char ant = '*';
    int boardSizeX;
    int boardSizeY;
    int antX;
    int antY;
    int facing;
    int currentStep;
    int lastStep;
    char **board;
    char spaceUnderAnt;
    
public:
    Ant();
    Ant(int boardSizeXIn, int boardSizeYIn, int antXIn, int antYIn, int facingIn, int stepsIn);
    int getBoardX();
    int getBoardY();
    int getAntX();
    int getAntY();
    int getFacing();
    int getCurrentStep();
    int getLastStep();
    
    char getSpaceColor(int xIn, int yIn);
    void setSpaceColor(int xIn, int yIn, char color);
    void takeStep();
    void moveForward();
    void printBoard();
    void simulator();
    
    ~Ant();
};

#endif


