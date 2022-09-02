#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Germany.h"
#include "CountriesBoots.h"
#include "accomplishments.h"

using namespace std;

accomplishments::accomplishments()
{
    countries[0].setCountry("Japan");
    countries[1].setCountry("China");
    countries[2].setCountry("United States");
    countries[3].setCountry("Soviet Union");
    countries[4].setCountry("France");
    countries[5].setCountry("Poland");

    name ="";

}
accomplishments::accomplishments(CountriesBoots countries1[6], string name1)
{
    for (int i = 0; i < 6; i++)
    {
        countries[i].getCountry()= countries1[i].getCountry();
    }
    name = name1;
}

void accomplishments::win(string name)
{
     ofstream accomplishments("accomplishments.txt");
      if (accomplishments.is_open())
      {
                    accomplishments <<"This file contains the accomplishments of the graet leader of germany " << name <<endl;

                    accomplishments << name << " has defeted the following countries: "<<endl;

                    for (int i = 0; i < 6; i++)
                    {
                        accomplishments <<i+1 << "- " <<countries[i].getCountry()<<endl;
                    }
                    
      }
}

void accomplishments::lose(string name)
{
         ofstream accomplishments("accomplishments.txt");
      if (accomplishments.is_open())
      {
                    accomplishments <<name <<" has lost the war and ran away from germany some rumors said that he is in island near united kingdom" <<endl;

                    for (int i = 0; i < 5; i++)
                    {
                        accomplishments <<countries[i].getCountry() << ",";
                    }
                    accomplishments <<" and " << countries[5].getCountry() << " have sent troops to find him and bring him to be executed "<<endl;
                    
      }
}