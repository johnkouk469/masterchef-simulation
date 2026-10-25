#ifndef EXCURSIONAWARD_H_INCLUDED
#define EXCURSIONAWARD_H_INCLUDED

#include "Award.h"
#include <cstdlib>

using namespace std;

class ExcursionAward : public Award{

    int techniqueBonus;
    int popularityPenalty;

public:

    ExcursionAward(){techniqueBonus = 0; popularityPenalty = 0;}
    ExcursionAward(string n, bool s) : Award(n,s) {techniqueBonus = 10; popularityPenalty = 10;} // CHANGED: +10 technique and -10 popularity as the brief says (was 5 and -10, which raised the popularity)

    int getTechniqueBonus(){return techniqueBonus;}
    int getPopularityPenalty(){return popularityPenalty;}

    void status(){Award::status(); cout << "Technique Bonus: " << techniqueBonus << "\nPopularity Penalty: " << popularityPenalty << endl << endl; }

};


#endif // EXCURSIONAWARD_H_INCLUDED
