#include "Competition.h"
#include "TeamCompetition.h"
#include "ImmunityCompetition.h"
#include "CreativityCompetition.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

// Index 0 = Red Team, Index 1 = Blue Team
Team teams[2] = { Team("Red"), Team("Blue")};
int competitionId = 0;
int loser=-1; // Receives the value returned by the compete function of the competition
void menu();
void normalDay();
void teamCompetitionDay();
void immunityCompetitionDay();
void creativityCompetitionDay();

string CreativityCompetition::ingredients[10]={"rice","chicken","pork","milk","flour","cereals","tuna","sauce","oregano","pepper"};

int main()
{
    srand(time(NULL)); // CHANGED: seeded once here (TeamCompetition used to call srand(time) inside its loops, and nothing else seeded the generator)
    menu();

    return 0;
}

void menu()
{
    int choice = -1;

    while(choice != 0)
    {
        cout << endl << "1.Normal Day." << endl;
        cout << "2.Team Competition Day." << endl;
        cout << "3.Immunity Competition Day." << endl;
        cout << "4.Creativity Competition Day." << endl;
        cout << "0.Quit" << endl;

        if(!(cin >> choice))
            break; // CHANGED: stop when stdin ends

        switch(choice)
        {

        case 1:
            normalDay();
            break;
        case 2:
            teamCompetitionDay();
            break;
        case 3:
            immunityCompetitionDay();
            break;
        case 4:
            creativityCompetitionDay();
            break;
        case 0:
            break;
        default:
            cout << "Incorrect Input. Choose between 1 and 3. Press 0 to quit." << endl;

        }
    }
}

void normalDay()
{

    cout << endl << "This is a normal day in the Master Chef Game." << endl << endl;

    teams[0].teamEats();
    teams[1].teamEats();
    teams[0].teamWorks();
    teams[1].teamWorks();

    teams[0].teamSocializes();
    teams[1].teamSocializes();
    teams[0].teamEats();
    teams[1].teamEats();
    teams[0].teamSleeps();
    teams[1].teamSleeps();

}

void teamCompetitionDay()
{
    cout << endl << "This is a Team Competition day in the Master Chef Game." << endl << endl;

    teams[0].teamEats();
    teams[1].teamEats();
    teams[0].teamWorks();
    teams[1].teamWorks();

    string foodname;

    cout << "The food award of the team competition is: " << endl;
    cin >> foodname;

    FoodAward award(foodname, false);

    string competitionname;

    cout << "Enter the name of the competition: " << endl;
    cin >> competitionname;

    TeamCompetition competition(competitionId, competitionname, award);

    loser = competition.compete(teams[0], teams[1]);
    competition.status();

    teams[0].teamSocializes();
    teams[1].teamSocializes();
    teams[0].teamEats();
    teams[1].teamEats();
    teams[0].teamSleeps();
    teams[1].teamSleeps();
    competitionId++;

}

void immunityCompetitionDay()
{

    cout << endl << "This is a Immunity Competition day in the Master Chef Game." << endl << endl;

    teams[0].teamEats();
    teams[1].teamEats();
    teams[0].teamWorks();
    teams[1].teamWorks();

    string awardname;

    cout << "Enter the name of the immunity award: " << endl;
    cin >> awardname;
    ImmunityAward award(awardname, true);

    string competitionname;

    cout << "Enter the name of the competition: " << endl;
    cin >> competitionname;


    ImmunityCompetition competition(competitionId, competitionname, award);

    if(loser >= 0) // CHANGED: loser is -1 until a Team Competition has been played
        competition.compete(teams[loser]);
    else
        cout << "No team has lost a Team Competition yet, nobody competes." << endl;
    competition.status();

    teams[0].teamSocializes();
    teams[1].teamSocializes();
    teams[0].teamEats();
    teams[1].teamEats();
    teams[0].teamSleeps();
    teams[1].teamSleeps();

    competitionId++;

}

void creativityCompetitionDay()
{

    cout << endl << "This is a Creativity Competition day in the Master Chef Game." << endl << endl;

    teams[0].teamEats();
    teams[1].teamEats();
    teams[0].teamWorks();
    teams[1].teamWorks();

    string n;
    string b;
    cout<<"enter name of ExcursionAward"<< endl;
    cin>>n;
    ExcursionAward award(n,true);
    cout<<"enter name of Creativity Competition"<< endl;
    cin>>b;
    CreativityCompetition competition(competitionId,b,award);

    competition.compete(teams[0],teams[1]);
    competition.status();

    teams[0].teamSocializes();
    teams[1].teamSocializes();
    teams[0].teamEats();
    teams[1].teamEats();
    teams[0].teamSleeps();
    teams[1].teamSleeps();

    competitionId++;

}
