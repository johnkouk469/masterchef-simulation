# Master Chef 2018: Part D

Sunday, 3 June 2018

Object-oriented Programming, part D: voting with dynamic data structures. The code is in [part-d/](../part-d/); the assignment is in [brief.md](brief.md).

## Description of the implementation

## Class Vote (Vote.h)

This class creates the objects of type vote. It includes the following variables, voted and reason, which are strings. The corresponding setters and getters are defined, two initial-condition functions, one final-condition function and one function status(), which prints the variables on the screen.

## Class Voting (Voting.h and Voting.cpp)

All the attributes of the class Voting are static and it includes the variables votes and results according to the assignment. The function votingProcess includes the whole process of the Voting.

The strategy by which each player chooses whom to vote for is the following: based on the variables popularity, fatigue and technique, the players choose to vote for another player who has opposite characteristics from theirs. Each variable is split in two, that is, we check whether it is above or below 50%. In this way a player who, for example, has popularity < 50, fatigue > 50 and technique > 50 will choose to vote for a player who has popularity > 50, fatigue < 50 and technique < 50. Because a player may have to choose among more than one player, the variables counter and index are used. The counter is an integer that counts the number of persons the player is thinking of voting for, and the index is an array of integers with 11 positions, one for each slot of the team, in which the positions of the array for the persons the voter chooses are stored.

First, in the function votingProcess an array player of Player objects is created, which contains a copy of all 11 slots of the team (a player who has left the team leaves an empty slot, which is skipped). Then a for loop starts, inside which, one by one, all the players of the array player choose whom they will vote for, and then the vote object of the player is created. Inside this loop it is checked whether the player has votes left (while loop). For every vote the counter starts again from 0, and if there is nobody the player is allowed to vote for (everybody else is immune or has left), the player stops voting. By using the if statement we determine, according to the characteristics of the player, which category we are in (e.g. popularity>50, fatigue>50, technique>50). After the program finds the category, it starts searching the other players for the opposite characteristics (e.g. popularity<50, fatigue<50, technique<50); each time it finds a player that matches, the counter increases and the position of the player is stored in the index. Therefore, if the counter is positive, that is, if the player has found someone to vote for, and the last player stored in the index has no immunity and has not left, a vote object is created that contains that player and the reason "opposite characteristics", it is placed at the end of the vector votes and the counter is decreased by one. Otherwise a vote object is created that contains a random player (who cannot be the one who has immunity, the one who has left or the one who is voting) and the reason "random choice".

After the vector votes has been filled with votes, we print them on the screen. To count the votes we use a for loop that makes as many steps as the number of votes, inside which a bool variable keyexists is initialised that shows whether the key exists in results, as well as another for loop. This for loop uses an iterator from the beginning to the end of results and checks whether the key with the name of the player contained in each vote exists in results; if it exists, keyexists becomes true. After the counting is completed, the results are printed.

The selection of the 2 players with the largest number of votes is done with the iterators max1 and max2. If nobody received a vote, nobody leaves. We considered max1 to be equal to the first element of results and then compared it with the remaining elements with respect to the second parameter; if some other element was larger, it became the new value of max1. This means that when players have the same number of votes, the first name in the alphabetical order of the map is kept. For max2 the same comparison is made among the elements other than max1. If only one player received votes, there is no second candidate and that player leaves.

We change the value of the variable candidate of the 2 players to true and then remove from the team the one with the less technique; if both have the same technique, the second one (max2) leaves. Finally the player who had the immunity stops having it (the immunity is cleared on the players of the team itself), and all the values are deleted from the vector votes and from the map results.
