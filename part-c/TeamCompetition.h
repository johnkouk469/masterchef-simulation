#ifndef TEAMCOMPETITION_H_INCLUDED
#define TEAMCOMPETITION_H_INCLUDED

#include <iostream>
#include "Competition.h"


using namespace std;


class TeamCompetition : public Competition{

    FoodAward foodAward;
    Round rounds[3]; // one Round per round of the competition, positions 0 to 2 (round numbers 1 to 3)

public:

    TeamCompetition();
    TeamCompetition(int a, string b, FoodAward c);
    ~TeamCompetition();

    FoodAward getfoodAward();
    Round getrounds(int i);

    void setfoodAward(FoodAward val);
    void setrounds(int i, Round val);

    void status();
    int compete(Team &team1, Team &team2);
    };

#endif // TEAMCOMPETITION_H_INCLUDED
