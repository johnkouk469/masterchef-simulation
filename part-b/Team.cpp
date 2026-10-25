#include <iostream>
#include <string>
#include "Team.h"

using namespace std;
//the classes and methods are described in detail in docs/part-b.md
  void team::setColor(string  x)
  {
    color=x;
  }
  string team::getColor()
  {
   return color;
  }


 void team::setNum(int y)
  {
     num=y;
  }
  unsigned int team::getNum()
  {
   return num;
  }


  void team::setWins(int z)
  {
    wins=z;
  }
  unsigned int team::getWins()
  {
   return wins;
  }



  void team::setGames(int w)
  {
    games=w;
  }
  unsigned int team::getGames()
  {
   return games;
  }

  team::team()
  {
      setColor(" ");
      setNum(11);
      setWins(0);
      setGames(0);

  }


  team::team(string a)
  {
   color=a;
   setNum(11);
   setWins(0);
   setGames(0);
  }


  team::~team()
  {
    cout<<"object destroyed"<<endl;
  }

  void team::DisplayData()
  {
    cout<<"Team: "<< color <<endl;
    cout<<"Number of players: "<< num <<endl;
    cout<<"Number of wins: " << wins <<endl;
    cout<<"Number of contests the team participated in: "<< games <<endl;
  }














