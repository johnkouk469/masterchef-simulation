#include "Voting.h"


using namespace std;

vector<Vote> Voting::votes;
map<string, int> Voting::results;

void Voting::votingProcess(Team &team)
{

    cout << "The " << team.getColor() << " team has " << team.getNumberOfPlayers() << " players." << endl << endl;

    // CHANGED: a removed player leaves an empty slot, so the loops below run over all 11 slots (they used to run over the number of players still in, which skipped the last slots and made the random pick unable to reach them)
    const int SLOTS = 11;

    //Create the array player, a copy of all 11 player slots of the team (a removed player leaves an empty slot)
    Player player[SLOTS];
    for(int j=0; j<SLOTS; j++)
            player[j] = team.getPlayers()[j];


   for(int i=0; i<SLOTS; i++)
   {
       if(player[i].getAge() == 0) // CHANGED: empty slot
           continue;

       int counter = 0; // Counts the players this player is thinking of voting for
       int index[SLOTS]; // Holds the array positions of the players this player is thinking of voting for


           while(player[i].getVotes() != 0){

                // CHANGED: counter is reset for every vote (it kept growing and wrote past the end of index[] for a player with more than one vote)
                counter = 0;

                // CHANGED: a voter with nobody left to vote for stops instead of looping forever
                bool hasTarget = false;
                for(int j=0; j<SLOTS; j++)
                    if(j != i && player[j].getAge() != 0 && !player[j].getImmunity())
                        hasTarget = true;
                if(!hasTarget)
                    break;

                //player votes
                    if (player[i].getPopularity() <= 50)
                    {
                        if (player[i].getFatigue() <= 50)
                        {
                            if (player[i].getTechnique() <=50)
                            {
                                // popularity < 50 && fatigue < 50 && technique < 50

                                for(int j=0; j<SLOTS; j++)
                                {
                                    if (player[j].getPopularity() > 50 && player[j].getFatigue() > 50 && player[j].getTechnique() > 50 && player[j].getAge() != 0)
                                    {
                                       if(j!=i){
                                        counter++;
                                        index[counter]=j;
                                       }
                                    }
                                }
                            }
                            else
                            {
                                // popularity < 50 && fatigue < 50 && technique > 50
                                for(int j=0; j<SLOTS; j++)
                                {

                                    if (player[j].getPopularity() > 50 && player[j].getFatigue() > 50 && player[j].getTechnique() < 50 && player[j].getAge() != 0)
                                    {
                                        if(j!=i){
                                        counter++;
                                        index[counter]=j;
                                        }
                                    }
                                }
                            }
                        }
                        else
                            {
                            if (player[i].getTechnique() <= 50)
                            {
                                // popularity < 50 && fatigue > 50 && technique < 50
                                for(int j=0; j<SLOTS; j++)
                                {

                                    if (player[j].getPopularity() > 50 && player[j].getFatigue() < 50 && player[j].getTechnique() > 50 && player[j].getAge() != 0)
                                    {
                                        if(j!=i){
                                        counter++;
                                        index[counter]=j;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                // popularity < 50 && fatigue > 50 && technique > 50
                                for(int j=0; j<SLOTS; j++)
                                {

                                    if (player[j].getPopularity() > 50 && player[j].getFatigue() < 50 && player[j].getTechnique() < 50 && player[j].getAge() != 0)
                                    {
                                        if(j!=i){
                                        counter++;
                                        index[counter]=j;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        if (player[i].getFatigue() <= 50)
                        {
                            if (player[i].getTechnique() <= 50)
                            {
                                // popularity > 50 && fatigue < 50 && technique < 50
                                for(int j=0; j<SLOTS; j++)
                                {

                                    if (player[j].getPopularity() < 50 && player[j].getFatigue() > 50 && player[j].getTechnique() > 50 && player[j].getAge() != 0)
                                    {
                                        if(j!=i){
                                        counter++;
                                        index[counter]=j;
                                        }
                                    }
                                }
                            }
                            else
                            {
                            // popularity > 50 && fatigue < 50 && technique > 50
                            for(int j=0; j<SLOTS; j++)
                                {

                                    if (player[j].getPopularity() < 50 && player[j].getFatigue() > 50 && player[j].getTechnique() < 50 && player[j].getAge() != 0)
                                    {
                                        if(j!=i){
                                        counter++;
                                        index[counter]=j;
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (player[i].getTechnique() <= 50)
                            {
                            // popularity > 50 && fatigue > 50 && technique < 50
                                for(int j=0; j<SLOTS; j++)
                                {

                                    if (player[j].getPopularity() < 50 && player[j].getFatigue() < 50 && player[j].getTechnique() > 50 && player[j].getAge() != 0)
                                    {
                                        if(j!=i){
                                        counter++;
                                        index[counter]=j;
                                        }
                                    }

                                }
                            }
                            else
                            {
                                // popularity > 50 && fatigue > 50 && technique > 50
                                for(int j=0; j<SLOTS; j++)
                                {

                                    if (player[j].getPopularity() < 50 && player[j].getFatigue() < 50 && player[j].getTechnique() < 50 && player[j].getAge() != 0)
                                    {
                                        if(j!=i){
                                        counter++;
                                        index[counter]=j;
                                        }
                                    }
                                }
                            }
                        }
                    }


                if (counter>0 && player[index[counter]].getImmunity() == false && player[index[counter]].getAge() != 0) // CHANGED: an immune favourite used to make this player retry forever, now falls back to the random pick
                {
                    if (player[index[counter]].getImmunity() == false && player[index[counter]].getAge() != 0)
                        {
                            Vote newVotes(player[index[counter]].getName(), "opposite characteristics"); // CHANGED: the reason is recorded
                            votes.push_back(newVotes);
                            player[i].setVotes(player[i].getVotes()-1);

                            cout << "Player " << player[i].getName() << " voted " << player[index[counter]].getName() << endl << endl;

                        }
                    counter--;
                }
                else
                {
                    int random;

                    random = rand()%SLOTS;
                    if (player[random].getImmunity() == false && random != i && player[random].getAge() != 0)
                        {
                            Vote newVotes(player[random].getName(), "random choice"); // CHANGED: the reason is recorded
                            votes.push_back(newVotes);
                            player[i].setVotes(player[i].getVotes()-1);

                            cout << "Player " << player[i].getName() << " voted " << player[random].getName() << endl << endl;
                        }
                }


           }

   }


   cout << "total number of votes: " << votes.size() << endl;

   //Show all the votes on the screen
   for(unsigned int i=0; i<votes.size(); i++)
   {
       votes[i].status();
   }


   //count the votes in the vector votes
   for(unsigned int i=0; i<votes.size(); i++)
   {
       bool keyexists = 0; //variable that shows whether the key exists
       for(map<string, int>::iterator it = results.begin(); it != results.end(); it++)
       {

           if(it->first==votes[i].getVoted())
              keyexists = 1;
       }
       if(keyexists==0)
           results[votes[i].getVoted()]=0;

       results[votes[i].getVoted()]++; // CHANGED: indentation only (silences -Wmisleading-indentation)

   }


   //Print the results
   for(map<string, int>::iterator it = results.begin(); it != results.end(); it++)
   {
       cout << it->first << " has been voted " << it->second << " times." << endl;
   }
   cout << endl;



   //Choose the 2 players with the most votes
   if(results.empty())
   {
       cout << "Nobody received a vote, nobody leaves the game." << endl << endl; // CHANGED: this case used to read past the end of the results
   }
   else
   {
       map<string, int>::iterator max1, max2;
       max1 = results.begin();
       for(map<string, int>::iterator it = results.begin(); it != results.end(); it++)
       {
               if((max1 -> second) < (it -> second))
                    max1=it;
       }
       // CHANGED: the second candidate is chosen among the other names (results.begin()++ returned the same player twice when the top vote getter came first alphabetically)
       max2 = results.end();
       for(map<string, int>::iterator it = results.begin(); it != results.end(); it++)
       {
               if(it != max1){
                    if(max2 == results.end() || (max2 -> second) < (it -> second))
                        max2=it;
               }

       }
       cout << max1 -> first << " has the most votes." << endl;
       if(max2 != results.end())
           cout << max2 -> first << " has the second largest amount of votes." << endl << endl;


       //Set the variable candidate of the 2 players to true
       int candidate[2]={-1, -1}; // CHANGED: the second element used to start at 0
       for(int i=0; i<SLOTS; i++)
       {

           if(max1 -> first == player[i].getName() && player[i].getAge() != 0){
                player[i].setCandidate(true);
                candidate[0]=i;
            }
            if(max2 != results.end() && max2 -> first == player[i].getName() && player[i].getAge() != 0){
                player[i].setCandidate(true);
                candidate[1]=i;
            }

       }


       //Choose one of the two and remove that player from the team
       if(candidate[1] == -1)
       {
           // CHANGED: only one player received votes, so that player leaves
           cout << "Player " << player[candidate[0]].getName() << " is the only candidate." << endl;
           cout << "Player " << player[candidate[0]].getName() << " will leave the game." << endl << endl;
           team.removePlayer(candidate[0]);
       }
       else if(player[candidate[0]].getTechnique() < player[candidate[1]].getTechnique())
       {
           cout << "Player " << player[candidate[0]].getName() << " has less technique than " << player[candidate[1]].getName() << endl;
           cout << "Player " << player[candidate[0]].getName() << " will leave the game." << endl << endl;
           team.removePlayer(candidate[0]);
           player[candidate[1]].setCandidate(false);
       }
       else
       {
           cout << "Player " << player[candidate[1]].getName() << " has less technique than " << player[candidate[0]].getName() << endl;
           cout << "Player " << player[candidate[1]].getName() << " will leave the game." << endl << endl;
           team.removePlayer(candidate[1]);
           player[candidate[0]].setCandidate(false);
       }
   }



   //setImmunity = 0
   // CHANGED: the immunity is cleared on the team's own players (it was cleared on the local copies, so the winner stayed immune for good)
   for(int i=0; i<SLOTS; i++)
   {
       if(team.getPlayers()[i].getImmunity()==true)
        team.getPlayers()[i].setImmunity(false);

   }


   cout << "The " << team.getColor() << " team now has " << team.getNumberOfPlayers() << " players." << endl << endl;


   votes.clear();
   results.clear();

   cout << "The voting process has ended." << endl;

}






















