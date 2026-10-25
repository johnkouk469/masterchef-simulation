#ifndef VOTE_H_INCLUDED
#define VOTE_H_INCLUDED // CHANGED: the guard macro was defined as VOTE_H_INCLUDE, so the guard never worked

#include <iostream> // CHANGED: the header uses cout
#include <string>

using namespace std;


class Vote{

string voted;
string reason;

public:
    //Constructors-Destructor
    Vote(){voted=" "; reason=" ";}
    Vote(string a, string b=" "){voted=a; reason=b;} // CHANGED: no default for the first argument, so that Vote() is not ambiguous
    ~Vote(){cout<<"Vote: " << voted << " is destroyed." << endl;}
    //Getters
    string getVoted(){return voted;}
    string getReason(){return reason;}
    //Setters
    void setVoted(string value){voted=value;}
    void setReason(string value){reason=value;}

    void status(){cout << endl << "Vote." << endl << "Voted: " << voted << endl << "Reason: " << reason << endl << endl;}
};

#endif // VOTE_H_INCLUDED
