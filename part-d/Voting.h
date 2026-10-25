#ifndef VOTING_H_INCLUDED
#define VOTING_H_INCLUDED

#include <vector>
#include <map>
#include "Team.h"
#include "Vote.h"

class Voting{

private:

    static vector<Vote> votes;
    static map<string, int> results;

public:

    static void votingProcess(Team &team);


};

#endif // VOTING_H_INCLUDED
