#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string.h>

using namespace std;
//the classes and methods are described in detail in docs/part-b.md
class team{
 public:
  //setters/getters
  void setColor(string x);
  string getColor();

  void setNum(int y);
  unsigned int getNum();

  void setWins(int z);
  unsigned int getWins();

  void setGames(int w);
  unsigned int getGames();
  //constructors&destructors
  team();
  team(string a);
  ~team();

  void DisplayData();

private:
 string color;  //team color
 unsigned int num; //number of players
 unsigned int wins; //number of wins
 unsigned int games;  // number of contests the team participated in

};

#endif // TEAM_H
