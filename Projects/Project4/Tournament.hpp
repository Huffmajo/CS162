/*********************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Joel Huffman
 ** Date: 02/25/18
 ** Description: Tournament class. Creates a tournament in which two
 ** teams of multiple combatants fight one another until only one team
 ** survives.
 *********************************************************************/

#ifndef Tournament_hpp
#define Tournament_hpp

#include "Queue.hpp"
#include <string>
using std::string;

class Tournament
{
private:
    Queue* ptrTeam1;
    Queue* ptrTeam2;
    Queue* ptrLosers;
    int team1Score;
    int team2Score;
    string tournamentWinners;
    
public:
    Tournament(Queue* team1, Queue* team2, Queue* losers);
    ~Tournament();
    void runTournament();
    void tournamentResults();
};

#endif /* Tournament_hpp */
