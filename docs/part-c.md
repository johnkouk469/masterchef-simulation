# Master Chef 2018: Part III

Sunday, 13 May 2018

Object-oriented Programming, part C: the competitions. The code is in [part-c/](../part-c/); the assignment is in [brief.md](brief.md).

## Description of the implementation

## Class Competition (Competition.h and Competition.cpp)

This class creates the objects of a competition. It includes the following variables, with access specifier protected:

1. **id:** an integer, unique for each competition.
2. **name:** a string with the name of the competition.
3. **winner:** a string with the name of the winner of the competition, either a team or a single player.

For each of the above variables the corresponding setters and getters are defined. The functions implemented for this class are the following:

- There are two initial-condition functions (constructors). One without arguments, which initialises the above variables (id=0, and name and winner empty \0). The second initial-condition function has as arguments an int a and a string b, to initialise the variables id and name; the variable winner is empty.
- **status():** this function prints the values of the variables on the screen.

## Class TeamCompetition (TeamCompetition.h and TeamCompetition.cpp)

This class creates the objects of a team competition and is a derived class of the class Competition with public access. It includes the variables of the class Competition and in addition has an object of type FoodAward and an array of three positions of type Round. For the above variables the necessary setters and getters have been implemented. The following functions have also been implemented:

- 2 constructors, one with arguments and one without, and both call the corresponding constructor of the class Competition. The one without arguments does not initialise any further variable, so it is empty. The one with arguments takes as an additional argument an object of type FoodAward, to initialise the variable foodaward.

- A function status() that prints the values of the variables on the screen.

- A function compete() that takes as arguments references to the two teams. The following local variables of the function are defined: 1. an array wins of two positions, where the first position records the wins (per round) of team1 and the second those of team2; 2. in a similar way the arrays sumtechnique, sumfatigue, averagetechnique and averagefatigue were defined; 3. two pointers to the players of the two teams (obtained with the function getPlayers()), so that the players who compete are the players of the teams themselves.

  Then there is a big for loop in which each iteration carries out one round of the team competition. For the random selection of the players, two arrays with the numbers 0 to 10 (the positions of the players in the team) are shuffled with a partial shuffle: for each of the first 5 positions, a random one of the remaining positions is swapped in. In this way each team gets 5 different players in every round, and no player takes part more than once in the same round. The sums of technique and fatigue are reset at the start of every round. Next, these 5 players of each team compete, which makes them tired, and the average technique and the average fatigue of each team are calculated. Using the if statement the winner of the round is determined: the team with the higher average technique wins, and if the averages are equal, the team with the lower average fatigue (the less tired team) wins. Finally, again using the if statement, the team that won at least 2 of the 3 rounds wins the competition, and a number is returned depending on the team that lost (0 for the red team, 1 for the blue team). The random number generator is seeded once, at the start of main.

## Class ImmunityCompetition (ImmunityCompetition.h and ImmunityCompetition.cpp)

This class creates objects for the immunity competition. Its constructor takes as arguments the id and the name of the competition, through inheritance from the general class competition, and in addition an object of type ImmunityAward. The necessary setters/getters and constructors/destructors have been implemented, and in addition the function status and the function compete, which implements a simulation of the immunity competition.

## Class CreativityCompetition (CreativityCompetition.h and CreativityCompetition.cpp)

This class creates objects for the creativity competition. Its constructor takes as arguments the id and the name of the competition, through inheritance from the general class competition, and in addition an object of type ExcursionAward. The necessary setters/getters and constructors/destructors have been implemented, and in addition the function status and the function compete, which implements a simulation of the creativity competition. There is also an array of type static string that contains the ingredients the players use.

## File main.cpp

In the file main.cpp a global variable loser is used. It initially has the value -1 and receives the value returned by the function compete() of the class TeamCompetition, so that the appropriate team can be given as an argument to the function compete() of the class ImmunityCompetition.
