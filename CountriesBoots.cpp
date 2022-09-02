#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "CountriesBoots.h"

using namespace std;


CountriesBoots::CountriesBoots()
{
        soldiers = 0;
        population=0;
        countries="";
        PopulationIncreaseRate =1.03;
    
 
}

CountriesBoots::CountriesBoots(int soldiers1,double PopulationIncreaseRate1 ,int population1, string Countries1)
{

        soldiers = soldiers1;
        countries=Countries1;
        population = population1;
        PopulationIncreaseRate = PopulationIncreaseRate1;
    

}

void CountriesBoots::setPopulation(double PopulationIncreaseRate1,int population1)
{

        population = population1;
        PopulationIncreaseRate = PopulationIncreaseRate1;

}

int CountriesBoots::getPopulation()
{
    return population*PopulationIncreaseRate;
}


void CountriesBoots::setSoldiers(int soldiers1)
{

        soldiers = soldiers1*0.001;

}

int CountriesBoots::getSoldiers()
{
    return soldiers;
}

void CountriesBoots::setCountry(string Countries1)
{
 
        countries = Countries1;
}

string CountriesBoots::getCountry()
{
    return countries;
}