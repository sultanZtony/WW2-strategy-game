#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#ifndef TEXT_H
#define TEXT_H
using namespace std;
// This class will have the most common sentences that I used in the project 
// Since I will use them more then 12 times I decided to make a class that will save me hunderd of lines and it will be easy to access from this class
class Text
{
private:


  string CountryName;
  int deaths;
  int prisonors;
  int DestroyedTanks;
  int giftGiver;

public:
    Text();
    Text(string CountryName, int deaths , int prisonors, int giftGiver);

    void SureAttack(string CountryName);
    
    void HowToPlay();

    void diffculty();

    void GermanyMenu();
    
    void DeathsPrisonors(int DestroyedTanks,int deaths, int prisonors);

    void Gift(int giftGiver);
                            
};





#endif