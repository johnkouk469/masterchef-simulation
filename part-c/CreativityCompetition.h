#ifndef CREATIVITYCOMPETITION_H_INCLUDED
#define CREATIVITYCOMPETITION_H_INCLUDED

#include "Competition.h"


using namespace std;


class CreativityCompetition : public Competition{


ExcursionAward excursionAward;

static string ingredients[10];

public:

CreativityCompetition(int a, string b, ExcursionAward c): Competition(a,b)
 {
     excursionAward=c;
     winner="";
 }


CreativityCompetition();

~CreativityCompetition();

ExcursionAward getExcursionAward();

void setExcursionAward(ExcursionAward x);

void status();

void compete(Team &team1,Team &team2);

};

#endif // CREATIVITYCOMPETITION_H_INCLUDED
