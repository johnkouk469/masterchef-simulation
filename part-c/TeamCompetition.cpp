#include "TeamCompetition.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

TeamCompetition::TeamCompetition():Competition()
{

}

TeamCompetition::TeamCompetition(int a, string b, FoodAward c):Competition(a,b)
{
    foodAward=c;
}

TeamCompetition::~TeamCompetition()
{
    cout << "Team Competition: " << name << " is destroyed." << endl;
}

FoodAward TeamCompetition::getfoodAward()
{
    return foodAward;
}

Round TeamCompetition::getrounds(int i)
{
    return rounds[i];
}

void TeamCompetition::setfoodAward(FoodAward val)
{
    foodAward=val;
}

void TeamCompetition::setrounds(int i, Round val)
{
    rounds[i]=val;
}

void TeamCompetition::status()
{
    Competition::status();
    cout << "Foodaward." << endl << endl;
    foodAward.status();
}

int TeamCompetition::compete(Team &team1, Team &team2)
{
    int wins[2]={0};
    int sumtechnique[2]={0,0}; // CHANGED: were uninitialised
    int sumfatigue[2]={0,0};   // CHANGED: were uninitialised
    int averagetechnique[2];
    int averagefatigue[2];
    // CHANGED: the teams' own players compete (they were copied into local arrays, so the fatigue from competing never reached the team)
    Player *p = team1.getPlayers();
    Player *k = team2.getPlayers();

    for(int round=1; round<4; round++)
    {
        rounds[round-1].setId(round); //record the round in the rounds array (position round-1; CHANGED: the array has 3 positions, as the brief says)
        rounds[round-1].setDuration(3);
        // CHANGED: 5 distinct random players per team and round, chosen with a partial shuffle. The old selection could pick a player twice, only 4 of the 5 competed, and the sums were never reset, so rounds 2 and 3 used cumulative averages.
        int j[11], l[11];
        for(int i=0; i<11; i++)
        {
            j[i]=i;
            l[i]=i;
        }
        for(int i=0; i<5; i++)
        {
            int a=i+rand()%(11-i);
            int tmp=j[i]; j[i]=j[a]; j[a]=tmp;
            int b=i+rand()%(11-i);
            tmp=l[i]; l[i]=l[b]; l[b]=tmp;
        }

        for(int g=0; g<2; g++)
        {
            sumtechnique[g]=0;
            sumfatigue[g]=0;
        }

        for(int i=0; i<5; i++)
        {
            p[j[i]].compete();
            sumtechnique[0]+=p[j[i]].getTechnique();
            sumfatigue[0]+=p[j[i]].getFatigue();

            k[l[i]].compete();
            sumtechnique[1]+=k[l[i]].getTechnique();
            sumfatigue[1]+=k[l[i]].getFatigue();

        }

        for(int g=0; g<2; g++)
        {
            averagetechnique[g]=(sumtechnique[g])/5;
            averagefatigue[g]=(sumfatigue[g])/5;
        }
        if(averagetechnique[0]>averagetechnique[1]){
            rounds[round-1].setWinner("Red");
            wins[0]++;
            rounds[round-1].status();
        }
        else if(averagetechnique[0]==averagetechnique[1])
        {
            if(averagefatigue[0]<averagefatigue[1]){ // CHANGED: on equal technique the less tired team wins (the comparison was the other way round)
                rounds[round-1].setWinner("Red");
                wins[0]++;
                rounds[round-1].status();
            }
            else{
                rounds[round-1].setWinner("Blue");
                wins[1]++;
                rounds[round-1].status();
            }
        }
        else{
            rounds[round-1].setWinner("Blue");
            wins[1]++;
            rounds[round-1].status();

        }


    }

    if(wins[0]>wins[1])
    {
        winner = "Red";
        team1.setWins(team1.getWins()+1);
        team1.setSupplies(team1.getSupplies()+foodAward.getBonusSupplies());
        return 1;

    }
    else
    {
        winner = "Blue";
        team2.setWins(team2.getWins()+1);
        team2.setSupplies(team2.getSupplies()+foodAward.getBonusSupplies());
        return 0;
    }

}
