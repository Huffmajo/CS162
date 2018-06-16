/*********************************************************************
 ** Program name: Dice War
 ** Author: Joel Huffman
 ** Date: 1/26/2018
 ** Description: Program simulates a dice war game between two players
 ** with dice type, dice size and number of rounds decided by the user.
 ** Every round's result is printed to the screen with a final printout
 ** showing who won the entire game and the final scores.
 *********************************************************************/

#include "Game.hpp"

Game::Game(int p1DieIn, int p2DieIn, int p1SidesIn, int p2SidesIn, int roundsIn)
{
    p1Sides = p1SidesIn;
    p2Sides = p2SidesIn;
    rounds = roundsIn;
    currentRound = 1;
    p1Score = 0;
    p2Score = 0;
    
    switch (p1DieIn)
    {
        case 1:
        {
            p1Die = "Regular";
            ptrDie1 = new Die(getP1Sides());
            break;
        }
            
        case 2:
        {
            p1Die = "Loaded";
            ptrDie1 = new LoadedDie(getP1Sides());
            break;
        }
            
        default:
        {
            break;
        }
    }

    
    switch (p2DieIn)
    {
        case 1:
        {
            p2Die = "Regular";
            ptrDie2 = new Die(getP2Sides());
            break;
        }
            
        case 2:
        {
            p2Die = "Loaded";
            ptrDie2 = new LoadedDie(getP2Sides());
            break;
        }
            
        default:
        {
            break;
        }
    }
}

string Game::getP1Die()
{
    return p1Die;
}

string Game::getP2Die()
{
    return p2Die;
}

int Game::getP1Sides()
{
    return p1Sides;
}

int Game::getP2Sides()
{
    return p2Sides;
}

int Game::getRounds()
{
    return rounds;
}


/*********************************************************************
 ** playRound:
 ** simulates a single round of dice wars between the two players. 
 ** Prints out the results of the round at the end.
 *********************************************************************/
void Game::playRound()
{
    //roll both dice
    p1Roll = ptrDie1->roll();
    p2Roll = ptrDie2->roll();
    
    
    //calculate who wins
    if (p1Roll > p2Roll)
    {
        victoryStatement = "Player 1 wins";
        p1Score++;
    }
    
    else if (p2Roll > p1Roll)
    {
        victoryStatement = "Player 2 wins";
        p2Score++;
    }
    
    else
    {
        victoryStatement = "It's a draw. Nobody wins";
    }
    
    //print results
    printResults();
    
    currentRound++;
}

void Game::playGame()
{
    
    while (currentRound < rounds + 1)
    {
        playRound();
    }
    
    printFinalResults();
    
    //deallocate memory
    delete ptrDie1;
    ptrDie1 = NULL;
    delete ptrDie2;
    ptrDie2 = NULL;
}

void Game::printResults()
{
    //print the round #
    cout << "ROUND " << currentRound << "\n";
    
    //victory stats
    cout << victoryStatement << " this round.\n\n";
    
    //P1's stats
    cout << "P1's die type: " << p1Die << "\n";
    cout << "P1's s die sides: " << p1Sides << "\n";
    cout << "P1's roll: " << p1Roll << "\n";
    cout << "P1's score: " << p1Score << "\n\n";
    
    //P2's stats
    cout << "P2's die type: " << p2Die << "\n";
    cout << "P2's s die sides: " << p2Sides << "\n";
    cout << "P2's roll: " << p2Roll << "\n";
    cout << "P2's score: " << p2Score << "\n\n";
    
}

void Game::printFinalResults()
{
    //print the round #
    cout << "FINAL SCORE\n";
    
    //print players final scores
    cout << "P1's final score: " << p1Score << "\n";
    cout << "P2's final score: " << p2Score << "\n";
    
    if (p1Score > p2Score)
    {
        cout << "P1 is the winner of the game!\n";
    }
    
    else if (p2Score > p1Score)
    {
        cout << "P2 is the winner of the game!\n";
    }
    
    else
    {
        cout << "It's a draw. No one wins the game!\n";
    }
}
