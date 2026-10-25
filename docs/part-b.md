# Master Chef 2018: Part II

Thursday, 26 April 2018

Object-oriented Programming, part B: the classes Player and Team. The code is in [part-b/](../part-b/).

## Description of the implementation

In this part of the assignment we implemented the classes player and team in C++, using an algorithm. To give the program more structure, the two classes were each implemented in separate files. In the file of the main function we built a menu that lets the user choose between options.

## Class player

The class player includes 8 variables, which came from the UML diagram:

- name
- sex
- age
- job
- technicaltraining
- fatigue
- rateofpopularity
- numberofwins

These variables are in the private part of the class and to access them we use the public set and get functions. We also have two constructors, one with arguments and one without, so that the variables are initialised automatically when we create a new object. The first four variables are empty in the first constructor and arguments are requested for them in the second constructor, while the other four are initialised by themselves, based on the data in the text and with the help of the function rand(), in both constructors. There is also the corresponding destructor.

Then we created the basic functions that are presented in the text, concerning what the player can do during the game, again with the help of the UML diagram. These functions are:

- work(). This function represents a player's work during a week, that is, it increases the player's fatigue (fatigue) and technical training (technicaltraining).
- socialize(). It represents the result of the interpersonal relations that the players have with each other over a period of a week, using the function rand().
- endoftheweek(). In this function we see how the players spend the last day of the week. Because they choose randomly (50%-50%) whether they will sleep or practise, there is a variable that takes randomly either the value 0 or the value 1, using rand() (again!!). Depending on the result, using the if statement, their fatigue is reset to zero or their technical training increases.
- participation_in_contest(). This function represents the result of the player's participation in a contest, that is, their fatigue.

Finally, we created the function DisplayData(), which prints the values of the variables of the class. This function was used in the main function so that it is clearer and so that we do not have to use the corresponding get functions many times. We created a similar function in the class team.

## Class Team

The class team includes 4 variables:

- color, the colour of the team
- num, the number of players of the team
- wins, the number of wins of the team
- games, the number of contests in which the team has taken part

These variables are in the private part of the class and, like the class player, we use set and get functions to access them. The two constructors initialise the variables according to the scenario. The difference between the two is that the first (without arguments) initialises the variable color with a blank, while the second accepts one argument to initialise it. There is also a destructor.

## The main function

In the main function we created an array of 11 objects of the class player for each team, named playerBlue[] and playerRed[], which represent the players. We also created the objects red and blue of the class team, which represent the two teams. Then we created a menu that is shown to the user repeatedly, by means of the do while loop, and gives these options:

- 1: Add a player to a team.
- 2: See the details of a team.
- 3: See the details of a player, whom the user can look up either by name or by the number of the player's position.
- 0: Exit the program.

- The user chooses by typing a number and, with the help of the if statement, the program carries out the corresponding function.

- Because of the constructor without arguments, 22 players are created from the start, but without personal details. The players are officially "created" when the user gives them a name, age and so on.
