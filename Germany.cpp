#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Germany.h"

using namespace std;


Germany::Germany()
{
    population = 83000000;
    soldier = 10000;
    Gold = 5000;
    country_level = 1.1;
    tanks = 1000;

}

Germany::Germany(int tanks1,int population1, int soldier1, int gold1, double country_level1)
{
    population = population1;
    soldier = soldier1;
    Gold = gold1;
    country_level =country_level1;
    tanks = tanks1;
}


void Germany::setGold(int gold1)
{

    Gold = gold1;
}

int Germany::getGold()
{
    return Gold;
}

void Germany::setTanks(int tanks1)
{

    tanks = tanks1;
}

int Germany::getTanks()
{
    return tanks;
}

void Germany::setPopulation(int population1)
{

    population = population1;
}

int Germany::getPopulation()
{
    return population;
}

void Germany::setSoldier(int soldier1)
{

    soldier = soldier1;
}

int Germany::getSoldier()
{
    return soldier;
}

void Germany::setUpgrade(double country_level1)
{

    country_level = country_level1;
}

double Germany::getUpgrade()
{
    return country_level;
}