#ifndef COMPETITION_H_INCLUDED
#define COMPETITION_H_INCLUDED

#include <iostream>
#include <string>
#include "Team.h"
#include "FoodAward.h"
#include "ImmunityAward.h"
#include "ExcursionAward.h"
#include "Round.h"

using namespace std;


class Competition{


protected:
    int id; //an integer, unique for every competition.
    string name; //a string with the name of the competition.
    string winner; //a string with the name of the winner of the competition, either a team or a single player.

public:
    Competition();
    Competition(int a, string b); // a is the id and b is the name of the competition
    ~Competition();

    //Getters
    int getId();
    string getName();
    string getWinner();

    //Setters
    void setId(int val);
    void setName(string val);
    void setWinner(string val);

    void status();

};


#endif // COMPETITION_H_INCLUDED
