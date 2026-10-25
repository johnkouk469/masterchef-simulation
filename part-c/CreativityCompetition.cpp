#include "CreativityCompetition.h"

using namespace std;

CreativityCompetition::CreativityCompetition()
{
  id=0;
  name="";
  winner="";

}

CreativityCompetition::~CreativityCompetition()
{
    cout << "CreativityCompetition " << name << " is destroyed." << endl;
}





ExcursionAward CreativityCompetition::getExcursionAward()
{
    return excursionAward;
}

void CreativityCompetition::setExcursionAward(ExcursionAward x)
{
    excursionAward=x;
}


void CreativityCompetition::status(){

    Competition::status();
    cout << "ExcursionAward: "<< endl;
    excursionAward.status();
}


void CreativityCompetition::compete(Team &team1,Team &team2){

// CHANGED: the winner is looked for among the teams' own players. The function used to copy all 22 players and give the award to the copy, so the real winner never received it.
Player *allplayers[22];

for(int i=0;i<11;i++)
{
    allplayers[i]=&team1.getPlayers()[i];
    allplayers[i+11]=&team2.getPlayers()[i];
    team1.getPlayers()[i].compete();
    team2.getPlayers()[i].compete();
}

float MaxTechnique=-1; // CHANGED: float (it was int, which cut off the decimals of the technique)
int Maxindex=-1,playersindex=0;
float tech=0;

 for(playersindex=0;playersindex<22;playersindex++){
    tech=allplayers[playersindex]->getTechnique();
    if (tech>MaxTechnique){
       MaxTechnique=tech;
       Maxindex=playersindex;
    }
 }
 cout << endl << "Winner player." << endl << endl;
 allplayers[Maxindex]->status();
 float t,p;
 t=allplayers[Maxindex]->getTechnique();
 p=allplayers[Maxindex]->getPopularity();
 t+=excursionAward.getTechniqueBonus();
 p-=excursionAward.getPopularityPenalty();
 // CHANGED: setTechnique and setPopularity refuse values outside 0..100, so the new values are kept inside that range
 if(t>100)
    t=100;
 if(p<0)
    p=0;
 if(p>100)
    p=100;
 allplayers[Maxindex]->setTechnique(t);
 allplayers[Maxindex]->setPopularity(p);
 winner=allplayers[Maxindex]->getName();

}
