#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Germany.h"
#include "CountriesBoots.h"

#ifndef ACCOMPLISHMENTS_H
#define ACCOMPLISHMENTS_H
using namespace std;
// This class is for the accomplishments you made in the game
// After you finish the game text file will be created with your story during the war
class accomplishments
{
    private:
    CountriesBoots countries[6];
    string name;

    public:
    accomplishments();
    accomplishments(CountriesBoots countries[6], string name);

    void win(string name);

    void lose(string name);

};

#endif