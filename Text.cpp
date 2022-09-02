#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Text.h"

using namespace std;

Text::Text()
{
 CountryName ="";
 deaths =0;
 prisonors =0;
  giftGiver= 0;
}

Text::Text(string CountryName1, int deaths1, int prisonors1, int giftGiver1)
{
 CountryName = CountryName1;
 prisonors = prisonors1;
 deaths = deaths1;
 giftGiver = giftGiver1;
}

void Text::SureAttack(string CountryName)
{
            cout << "Are you sure you want to attack " << CountryName << " ?"<<endl;
            cout << "1- Yes"<<endl;
            cout << "2- No"<<endl;
        
}

void Text::HowToPlay()
{
        cout <<endl;
        cout << "       You will play as Germany in ww1 and your goal is to deafet all countries "<<endl;
        cout << "       You have a certain amount of turns and you need to end the game before your turns finish "<<endl;
        
        cout << endl; 
        cout <<endl;
        
}

void Text::diffculty()
{
    cout << "Choose diffculty"<<endl;
    cout << "1- Hard (30 turns)"<<endl;
    cout << "2- Normal (50 turns)"<<endl;
    cout << "3- Easy (70 turns)" <<endl;
        
}

void Text::GermanyMenu()
{

    cout << "1- attack" << endl;

    cout << "2- Train soldiers"<<endl;

    cout << "3- Train tanks"<<endl;

    cout << "4- Raise taxes"<<endl;

    cout << "5- Spy on countries" <<endl;

    cout << "6- Collect taxes"<<endl;

    cout << "7- Quit"<<endl;
        
}

void Text::DeathsPrisonors(int DestroyedTanks,int deaths, int prisnors)
{

                    cout << deaths << " of your soldiers are dead"<<endl;
                    cout <<prisnors << " of your soldiers are prisoned"<<endl;
                    cout << DestroyedTanks << " of your tanks are destroyed"<<endl;
                    cout << "Would yo like to pay " << prisnors*0.5 << " Gold to free the prisoners?"<<endl;
                    cout << "1- Yes"<<endl;
                    cout << "2- No"<<endl;
        
}

void Text::Gift(int giftGiver)
{
    if (giftGiver ==1 )
    {
    
    cout << endl;
    cout <<endl;
    cout << "               Hungary has sent you 80,000 Gold to support you in the war" <<endl;
    cout << "               1- Accept it "<<endl;
    cout << "               2- Sent it back to them"<<endl;  
    cout <<endl;
    }
    if (giftGiver ==2 )
    {
    
    cout << endl;
    cout <<endl;
    cout << "               Romania has sent you 80,000 Gold to support you in the war" <<endl;
    cout << "               1- Accept it "<<endl;
    cout << "               2- Sent it back to them"<<endl;  
    cout <<endl;
    }
    if (giftGiver ==3 )
    {
    
    cout << endl;
    cout <<endl;
    cout << "               Venezuela has sent you 80,000 Gold to support you in the war" <<endl;
    cout << "               1- Accept it "<<endl;
    cout << "               2- Sent it back to them"<<endl;  
    cout <<endl;
    }
 
}