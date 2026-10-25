#include "ImmunityCompetition.h"


using namespace std;

ImmunityCompetition::ImmunityCompetition(int a, string b, ImmunityAward c): Competition(a,b)
 {
     immunityAward=c;
 }


ImmunityCompetition::ImmunityCompetition()
{
  id=0;
  name="";
  winner="";

}

ImmunityCompetition::~ImmunityCompetition()
{

    cout << "ImmunityCompetition " << name << " is destroyed." << endl;
}

ImmunityAward ImmunityCompetition::getImmunityAward()
{
    return immunityAward;
}

void ImmunityCompetition::setImmunityAward(ImmunityAward x)
{
    immunityAward=x;
}


void ImmunityCompetition::status(){

    Competition::status();
    cout << "ImmunityAward: "<<endl;
    immunityAward.status();
}


void ImmunityCompetition::compete(Team &team){
 float chance;
 int j,k=0; // CHANGED: k was uninitialised
 float x=-1; // CHANGED: float and below every score (it was int starting at 0, which cut off decimals and made player 0 the winner when all scores were negative)

 for(int i=0;i<11;i++){
  chance= team.getPlayers()[i].getTechnique()*0.75+(100-team.getPlayers()[i].getFatigue())*0.25; // CHANGED: 75% technique and 25% not tired, as in the brief (the ranking was the same, the scores were 25 lower)
  team.getPlayers()[i].compete();
  if(chance>x){
    k=i;
    x=chance;
  }
 }
 j=team.getPlayers()[k].getWins();
 j++;
 team.getPlayers()[k].setWins(j);
 winner=team.getPlayers()[k].getName();

}
