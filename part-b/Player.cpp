#include "Player.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;
//the classes and methods are described in detail in docs/part-b.md

// CHANGED: keeps fatigue, technical training and popularity between 0 and 100, as the UML diagram of part A says
static int limit(int value)
{
    if (value < 0)
        return 0;
    if (value > 100)
        return 100;
    return value;
}

Player::Player()
{
    // CHANGED: srand(time(NULL)) used to be called here and in the other constructor, so players created in the same second all got the same random values; the generator is now seeded once in main
    name= " ";
    sex= " ";
    age=0; // CHANGED: was never set
    job= " ";
    technicaltraining=rand()%81;
    fatigue =0;
    rateofpopularity=50;
    numberofwins=0;

}

Player::Player(string s1, string s2, int s3, string s4)
{
    name=s1;
    sex=s2;
    age=s3;
    job=s4;
    technicaltraining=rand()%81;
    fatigue =0;
    rateofpopularity=50;
    numberofwins=0;


}

Player::~Player()
{
    cout << "Object destroyed" << endl;
}

    // functions set get
    void Player::setName(string a){
            name=a;
        }
        string Player::getName(){
            return name;
        }

        void Player::setSex(string b){
            sex=b;
        }
        string Player::getSex(){
            return sex;
        }

        void Player::setAge(int c){
            age=c;
        }
        int Player::getAge(){
            return age;
        }

        void Player::setJob(string d){
            job=d;
        }
        string Player::getJob(){
            return job;
        }

        void Player::setTechnicaltraining(int e){
            technicaltraining=e;
        }
        int Player::getTechnicaltrainig(){
            return technicaltraining;
        }

        void Player::setFatigue(int f){
            fatigue=f;
        }
        int Player::getFatigue(){
            return fatigue;
        }

        void Player::setRateofpopularity(int g){
            rateofpopularity=g;
        }
        int Player::getRateofpopularity(){
            return rateofpopularity;
        }

        void Player::setNumberofwins(int h){
            numberofwins=h;
        }
        int Player::getNumberofwins(){
            return numberofwins;
        }

        //basic player functions
        void Player::work()
        {
            fatigue=limit(fatigue+(20+rand()%21));
            technicaltraining=limit(technicaltraining+(technicaltraining*5+99)/100); // CHANGED: 5% of the technical training, at least 1 point (5/100 is 0 in integer division, so it never grew)
        }
        void Player::socialize()
        {
            int i;
            i= (rand()%21)-10;
            rateofpopularity=limit(rateofpopularity+(i*rateofpopularity)/100); // CHANGED: i percent of the popularity (it was i times the popularity)
        }
        void Player::endoftheweek()
        {
            int i=rand()%2; //random choice (50-50) sleep or train
            if(i==0)
                fatigue=0; //sleep
            else
                technicaltraining=limit(technicaltraining+5); //train
        }

        void Player::participation_in_contest()
        {
            fatigue=limit(fatigue+(10+rand()%21));
        }

        void Player::DisplayData()
        {
            cout<<"\n"<<"Name:"<<name;
            cout<<"\n"<<"sex:"<<sex;
            cout<<"\n"<<"age:"<<age;
            cout<<"\n"<<"job:"<<job;
            cout<<"\n"<<"Technical Training:"<<technicaltraining;
            cout<<"\n"<<"Fatigue:"<<fatigue;
            cout<<"\n"<<"Rate of popularity:"<<rateofpopularity;
            cout<<"\n"<<"Number of wins:"<<numberofwins<<endl;



        }
























