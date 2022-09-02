#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#ifndef GERMANY_H
#define GERMANY_H
using namespace std;

// You will play as germany in the game and this class contains the options that you can use as germany to devolop your country

class Germany
{
    


    private:
        int tanks;
        int soldier;
        int population;
        int Gold;
        double country_level;




    public:
        
        Germany();
        Germany (int tanks,int population, int soldier, int gold, double country_level);

        void setGold (int gold1); // the Gold you have as germany
        int getGold();

        void setTanks(int tanks1); //  each tank equall to 10 soldiers power in the game
        int getTanks();

        void setPopulation(int population1); // the population of germany 
        int getPopulation();

        void setSoldier(int soldier1); // soldiers that you can train and attack with 
        int getSoldier();

        void setUpgrade(double country_level1); // this functio you will use it to increase the tax rate to collect more gold to train soldiers or tanks
        double getUpgrade();

};

#endif