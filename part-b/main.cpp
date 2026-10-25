#include <iostream>
#include "Player.h"
#include "Team.h"
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL)); // CHANGED: seeded once here instead of in every Player constructor
    team red("red"), blue("blue");
    Player playerRed[11], playerBlue[11];
    int i=0, j=0, k=0, l=0; // CHANGED: were uninitialised
    int counter1, counter2; //used to know how many players have been added in a team
    counter1=0;
    counter2=0;



   do{
        cout<<"Menu"<<endl;
        cout<<"Add a player to a team: press 1 \n Show team elements: press 2 \n Show player elements: press 3 \n Exit: press 0 "<<endl;
        if(!(cin >> i))
            break; // CHANGED: stop when stdin ends
        if(i==1)
        {
            cout<<"To add a player to the red team press 1 \n To add a player to the blue team press 2"<<endl;
            if(!(cin>>j)) // CHANGED: stop when stdin ends or is not a number
                break;
            if(j==1 && counter1>=11) // CHANGED: the 12th player used to be written past the end of the array
            {
                cout<<"The red team already has 11 players."<<endl;
            }
            else if(j==2 && counter2>=11) // CHANGED: same for the blue team
            {
                cout<<"The blue team already has 11 players."<<endl;
            }
            else if(j==1)
            {

                string a;
                int b=0;
                cout<<"Give name: "<<endl;
                cin>>a;
                playerRed[counter1].setName(a);
                cout<<"Give gender: "<<endl;
                cin>>a;
                playerRed[counter1].setSex(a);
                cout<<"Give age: "<<endl;
                cin>>b;
                playerRed[counter1].setAge(b);
                cout<<"Give job: "<<endl;
                cin>>a;
                playerRed[counter1].setJob(a);
                counter1++;

            }
            else if(j==2)
            {
                string a;
                int b=0;
                cout<<"Give name: "<<endl;
                cin>>a;
                playerBlue[counter2].setName(a);
                cout<<"Give gender: "<<endl;
                cin>>a;
                playerBlue[counter2].setSex(a);
                cout<<"Give age: "<<endl;
                cin>>b;
                playerBlue[counter2].setAge(b);
                cout<<"Give job: "<<endl;
                cin>>a;
                playerBlue[counter2].setJob(a);
                counter2++;
            }

        }
        else if(i==2)
        {

            cout<<"to view the details of the blue team press 1"<<endl;
            cout<<"to view the details of the red team press 2"<<endl;
            if(!(cin>>j)) // CHANGED: stop when stdin ends or is not a number
                break;
            if (j==1)
                blue.DisplayData();
            else if(j==2)
                red.DisplayData();
            else
                cout<<"error,invalid input"<<endl;
        }
        else if(i==3)
        {
            cout<<"To find a player by name press 1 \n To find a player by number press 2"<<endl;
            if(!(cin>>j)) // CHANGED: stop when stdin ends or is not a number
                break;
            if(j==1)
            {
                string a;
                cout<<"Enter the name of the player: "<<endl;
                cin>> a;
                for(k=0; k<11; k++)
                {
                    if(a==playerRed[k].getName())
                    {
                        playerRed[k].DisplayData();
                    }
                    if(a==playerBlue[k].getName())
                    {
                        playerBlue[k].DisplayData();
                    }

                }

            }
            else if(j==2)
            {
                cout<<"If the team of the player is the red one: press 1 \n If the team of the player is the blue one: press 2"<<endl;
                if(!(cin>>k)) // CHANGED: stop when stdin ends or is not a number
                    break;
                if(k==1)
                {
                    cout<<"Choose one of the 11 players of the red team by typing a number from 1 to 11"<<endl;
                    if(!(cin>>l)) // CHANGED: stop when stdin ends or is not a number
                        break;
                    if(l<1 || l>11) // CHANGED: any other number used to read outside the array
                        cout<<"error,invalid input"<<endl;
                    else
                        playerRed[l-1].DisplayData();
                }
                else if(k==2)
                {
                    cout<<"Choose one of the 11 players of the blue team by typing a number from 1 to 11"<<endl;
                    if(!(cin>>l)) // CHANGED: stop when stdin ends or is not a number
                        break;
                    if(l<1 || l>11) // CHANGED: any other number used to read outside the array
                        cout<<"error,invalid input"<<endl;
                    else
                        playerBlue[l-1].DisplayData();
                }
            }

        }
      cout<<"\n \n";
    }while(i!=0);


    cout<<"hi"<<endl;


    return 0;
}
