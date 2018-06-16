/*********************************************************************
 ** Program name: Dice War
 ** Author: Joel Huffman
 ** Date: 1/26/2018
 ** Description: Program simulates a dice war game between two players
 ** with dice type, dice size and number of rounds decided by the user.
 ** Every round's result is printed to the screen with a final printout
 ** showing who won the entire game and the final scores.
 *********************************************************************/

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "LoadedDie.hpp"
using std::cout;
using std::string;

class Game
{
private:
    string p1Die;
    string p2Die;
    int p1Sides;
    int p2Sides;
    int currentRound;
    int rounds;
    int p1Score;
    int p2Score;
    int p1Roll;
    int p2Roll;
    Die *ptrDie1;
    Die *ptrDie2;
    string victoryStatement;
    
public:
    Game(int p1DieIn, int p2DieIn, int p1SidesIn, int p2SidesIn, int roundsIn);
    string getP1Die();
    string getP2Die();
    int getP1Sides();
    int getP2Sides();
    int getRounds();
    
    /*********************************************************************
     ** playRound():
     ** Simulates a single round of the chosen dice war game. This includes
     ** rolling both players' dice and comparing the results to declare a
     ** round winner
     *********************************************************************/
    void playRound();
    
    /*********************************************************************
     ** playGame():
     ** Simulates an entire game of dice war by playing rounds until the 
     ** declared round limit is reached. Then the final scores and game 
     ** winner is printed
     *********************************************************************/
    void playGame();
    
    /*********************************************************************
     ** printResults():
     ** Prints the stats of both players for that round. This includes die
     ** type, # of sides on die, current roll and score. The winner of the
     ** round is also printed
     *********************************************************************/
    void printResults();
    
    /*********************************************************************
     ** printFinalResults():
     ** Prints the final scores of both players and the victor of game 
     ** based on those scores.
     *********************************************************************/
    void printFinalResults();
};

#endif /* Game_hpp */
