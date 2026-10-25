#include "Competition.h"

using namespace std;

Competition::Competition()
{
    id=0;
    name="";
    winner="";

}

Competition::Competition(int a, string b)
{
    setId(a);
    setName(b);
    setWinner("");
}


Competition::~Competition()
{

    cout << "Competition " << name << " is destroyed." << endl;
}

int Competition::getId()
{
    return id;
}

string Competition::getName()
{
    return name;
}

string Competition::getWinner()
{
    return winner;
}

void Competition::setId(int val)
{
    id=val;
}

void Competition::setName(string val)
{
    name=val;
}

void Competition::setWinner(string val)
{
    winner=val;
}


void Competition::status()
{
    cout << endl << "Competition information." << endl << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Winner: " << winner << endl << endl;
}
