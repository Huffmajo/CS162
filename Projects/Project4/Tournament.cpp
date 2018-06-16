/*********************************************************************
 ** Program name: Fantasy Combat Tournament
 ** Author: Joel Huffman
 ** Date: 02/25/18
 ** Description: Tournament class. Creates a tournament in which two
 ** teams of multiple combatants fight one another until only one team
 ** survives.
 *********************************************************************/

#include "Tournament.hpp"
#include "Game.hpp"
#include "iostream"
using std::cout;

/*********************************************************************
 ** Tournament(Queue* team1, Queue* team2, Queue* losers):
 ** Takes three queue pointers and assigns them to the local pointers
 ** for use within the Tournament class.
 *********************************************************************/
Tournament::Tournament(Queue* team1, Queue* team2, Queue* losers)
{
    ptrTeam1 = team1;
    ptrTeam2 = team2;
    ptrLosers = losers;
    team1Score = 0;
    team2Score = 0;
}

/*********************************************************************
 ** ~Tournament():
 ** Destructor for Tournament. Frees all allocated memory
 *********************************************************************/
Tournament::~Tournament()
{
    
}

/*********************************************************************
 ** runTournament():
 ** Has the two teams' combatants fight until one team is completely
 ** defeated.
 *********************************************************************/
void Tournament::runTournament()
{
    //while both teams have at least one fighter, continue tournament
    while (!ptrTeam1->isEmpty() && !ptrTeam2->isEmpty())
    {
        //get fighters from front of each queue
        Character* team1Fighter = ptrTeam1->getFront();
        Character* team2Fighter = ptrTeam2->getFront();
        
        //run battle between fighters
        Game g(team1Fighter, team2Fighter);
        g.battle();
        
        //print out results of the battle
        cout << "--------\n";
        cout << "|FIGHT!|\n";
        cout << "--------\n";
        cout << "Team1: Type: " << team1Fighter->getType() << ", Name: " << team1Fighter->getName() << "\n";
        cout << "Team2: Type: " << team2Fighter->getType() << ", Name: " << team2Fighter->getName() << "\n";
        cout << "Victor: Type: " << g.getVictor()->getType() << ", Name: " << g.getVictor()->getName() << "\n";
        cout << "Loser: Type: " << g.getLoser()->getType() << ", Name: " << g.getLoser()->getName() << "\n\n";
        
        //victor recovers
        g.getVictor()->recovery();
        
        cout << g.getLoser()->getName() << " sent to loser's queue\n";
        cout << g.getVictor()->getName() << " sent to back of team queue\n\n";
        
        //increase score for winner's team
        //move winner to back of team queue
        //move loser to loser queue
        if (g.getVictor()->getTeam() == "team1")
        {
            team1Score++;
            ptrTeam1->addBack(g.getVictor());
            ptrTeam1->removeFront();
            
            ptrLosers->addBack(g.getLoser());
            ptrTeam2->removeFront();
        }
        else
        {
            team2Score++;
            ptrTeam2->addBack(g.getVictor());
            ptrTeam2->removeFront();
            
            ptrLosers->addBack(g.getLoser());
            ptrTeam1->removeFront();
        }
        
    }
    
    //print final score
    tournamentResults();
    
}

/*********************************************************************
 ** tournamentResult():
 ** Prints out the final results of the tournament. This includes total
 ** points for each team and the team that won.
 *********************************************************************/
void Tournament::tournamentResults()
{
    if (team1Score > team2Score)
    {
        tournamentWinners = "Team 1";
    }
    
    else if (team1Score < team2Score)
    {
        tournamentWinners = "Team 2";
    }
    
    else
    {
        tournamentWinners = "Neither team";
    }
    
    cout << "------------------------\n";
    cout << "Team 1 score: " << team1Score << "\n";
    cout << "Team 2 score: " << team2Score << "\n";
    cout << tournamentWinners << " wins the tournament!\n";
    cout << "------------------------\n\n";
}

