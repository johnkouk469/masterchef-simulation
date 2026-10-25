# MasterChef simulation

A C++ simulation of a TV cooking competition, built in four assignments: the design of the classes (part A), players and teams (part B), team, immunity and creativity competitions with inheritance (part C) and a voting process with STL containers (part D).

![UML class diagram of the design in part A, with the classes Team, Player, Prize, Contest, Voting and Vote, their associations and multiplicities.](docs/figures/part-a-uml.png)

## Context

Object-oriented Programming coursework in C++ at the Aristotle University of Thessaloniki, School of Electrical and Computer Engineering, spring semester 2018. Pair project of two students.

The course provided the assignment texts for parts C and D, and for those two parts ready-made classes and a Code::Blocks project: Team, Player, the award classes, Round and, in part D, Competition and ImmunityCompetition. The pair wrote the rest, as listed under [Credits and licence](#credits-and-licence).

The reports are in [docs/part-a.md](docs/part-a.md), [docs/part-b.md](docs/part-b.md), [docs/part-c.md](docs/part-c.md) and [docs/part-d.md](docs/part-d.md), and the assignment texts of parts C and D in [docs/brief.md](docs/brief.md). The reports and the assignments were written in Greek; the files here are English translations.

## What it does

- **Part B** has the classes `Player` and `Team` with constructors, set and get methods and a menu program: add a player to the red or blue team, show a team, show a player by name or by position.
- **Part C** has the base class `Competition` and the derived classes `TeamCompetition`, `ImmunityCompetition` and `CreativityCompetition`. A menu program plays normal days, team competition days, immunity days and creativity days for two teams of eleven players.
- **Part D** has `Voting`, a class of static members that holds the votes in a `std::vector` of `Vote` objects and the results in a `std::map`. It simulates the vote in the team that lost.

## How it works

Part C: a team competition has three rounds. In each round five random players of each team compete, and the team with the better average technique wins the round (on a tie, the less tired team). The team that wins two rounds wins the competition and gets food supplies. The losing team plays the immunity competition, and the player with the best mix of technique and rest wins immunity. In the creativity competition the player with the highest technique wins an excursion award: more technique, less popularity.

Part D: every player votes for someone with opposite characteristics (popularity, fatigue and technique each above or below 50%), otherwise for a random player. Nobody can vote for themselves, for a player who has left or for the immune player, and the immunity winner has more than one vote. Of the two players with the most votes, the one with less technique leaves the team.

## Getting started

### Requirements

g++ with C++11 and GNU Make. The programs were built and run with g++ 11.4.0 and GNU Make 4.3 on Ubuntu 22.04 (WSL).

### Build and run

```
make          # builds part-b, part-c and part-d
make run      # runs each part with the scripted input in its sample_input.txt
```

To use a part interactively, build it and start it from its folder, for example `cd part-c && make && ./masterchef_c`. The menu choices are typed on the keyboard and 0 quits. The executables are `masterchef_b`, `masterchef_c` and `masterchef_d`. The `Makefile` files and the `sample_input.txt` files were added in 2026 to build and run the code on Linux; `MasterChef.cbp` in each folder is the course's Code::Blocks project.

## Project structure

```
part-b/    Player and Team classes and the menu program
part-c/    competition classes, day functions and the course's supplied classes
part-d/    Vote and Voting, and the course's supplied classes
docs/      part-a.md to part-d.md (reports), brief.md (assignments), figures/
Makefile   builds and runs the three parts
```

## Limitations

- The results change from run to run, because the random generator is seeded with the time.
- In part B the `Team` class keeps a fixed count of 11 players and is not connected to the `Player` objects, which are in arrays in `main`.
- In part D most votes end up as random votes, because a preferred target must differ from the voter in all three characteristics.
- The knockout day of the game is not part of the assignments.
- Not tested: the Code::Blocks projects, Windows and macOS builds, and compilers other than g++ 11.4.0.

## Team

Pair project of two students: [@johnkouk469](https://github.com/johnkouk469) and [@chris-trifi](https://github.com/chris-trifi).

## Credits and licence

The code the pair wrote is under the MIT licence (see [LICENSE](LICENSE)):

- all of `part-b/`;
- in `part-c/`: `Competition`, `TeamCompetition`, `ImmunityCompetition` and `CreativityCompetition` (`.h` and `.cpp`) and the four day functions in `main.cpp`;
- in `part-d/`: `Vote.h`, `Voting.h` and `Voting.cpp`;
- the reports and the figure in `docs/`, the `Makefile` files and the `sample_input.txt` files.

The licence does not cover what the course supplied, which has no licence of its own here:

- in `part-c/`: `Award.h`, `ExcursionAward.h`, `FoodAward.h`, `ImmunityAward.h`, `Player.h`, `Player.cpp`, `Round.h`, `Team.h`, `Team.cpp` and the menu and global variables of `main.cpp`;
- in `part-d/`: `Award.h`, `ImmunityAward.h`, `Competition.h`, `ImmunityCompetition.h`, `ImmunityCompetition.cpp`, `Player.h`, `Player.cpp`, `Team.h`, `Team.cpp` and `main.cpp`;
- the three `MasterChef.cbp` project files;
- the assignment texts, which [docs/brief.md](docs/brief.md) translates.

Two of the supplied files differ from the course's version, to follow the assignment text: `Player::compete` in `Player.cpp` (parts C and D) adds 5 to 10 points of fatigue, and `ExcursionAward.h` (part C) gives +10 technique and -10 popularity.
