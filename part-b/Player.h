#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;
//the classes and methods are described in detail in docs/part-b.md
class Player
{
    public:
        // Constructors and Destructor
        Player();
        Player(string s1, string s2, int s3, string s4);
        ~Player();

        //Set-get functions
        void setName(string a);
        string getName();

        void setSex(string b);
        string getSex();

        void setAge(int c);
        int getAge();

        void setJob(string d);
        string getJob();

        void setTechnicaltraining(int e);
        int getTechnicaltrainig();

        void setFatigue(int f);
        int getFatigue();

        void setRateofpopularity(int g);
        int getRateofpopularity();

        void setNumberofwins(int h);
        int getNumberofwins();

        //Basic player functions
        void work();
        void socialize();
        void endoftheweek();
        void participation_in_contest();


        void DisplayData();


    private:
        string name;
        string sex;
        int age;
        string job;
        int technicaltraining;
        int fatigue;
        int rateofpopularity;
        int numberofwins;
};

#endif // PLAYER_H
