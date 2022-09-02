#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#ifndef COUNTRIESBOOTS_H
#define COUNTRIESBOOTS_H
using namespace std;
// this class for other countries in the game 
// You can not choose to play them but you can attack them and expend you country borders 
// Also you can spy on them before you attack them just to make sure you can deafet them 
class CountriesBoots
{
    


    private:
        string countries;
        double PopulationIncreaseRate;
        int population;
        int soldiers;


    public:
        
        CountriesBoots();
        CountriesBoots (int soldiers,double PopulationIncreaseRate,int population, string Countries) ;

        void setPopulation(double PopulationIncreaseRate, int population);
        int getPopulation();
        
        void setSoldiers(int soldiers);
        int getSoldiers();

        void setCountry(string Countries);
        string getCountry();


};

#endif