#ifndef IMMUNITYCOMPETITION_H_INCLUDED
#define IMMUNITYCOMPETITION_H_INCLUDED

#include "Competition.h"


using namespace std;

class ImmunityCompetition : public Competition{



ImmunityAward immunityAward;


public:

ImmunityCompetition(int a, string b, ImmunityAward c);

ImmunityCompetition();

~ImmunityCompetition();

ImmunityAward getImmunityAward();

void setImmunityAward(ImmunityAward x);

void status();

void compete(Team &team);
};

#endif // IMMUNITYCOMPETITION_H_INCLUDED
