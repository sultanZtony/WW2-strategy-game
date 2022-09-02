// CS1300 Fall 2020
// Author: Sultan Alshakrah
// Recitation: 510 –  Alci Edward
// Project 3

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#include<cstdlib>
#include<ctime>
#include "CountriesBoots.h"
#include "Germany.h"
#include "accomplishments.h"
#include "Text.h"


using namespace std;

// For increasing the tax rate
double UpgradeCountry( double countrylevel)
{
    double value;
    
    value = countrylevel + 5;
    
    return value;
}

// Random function to use in the game in Attack option and Spy option
double randNum(int min, int max) 
{
        srand(time(0));
        double r = rand() % (max - min) + min;

        return r/10;
}

int main()
{   
// declaering the classes objects that I will need
    Germany Germany;
    CountriesBoots Boots[6];
    accomplishments aco;
    Text text;


    int choice;
    int test;
    cout <<endl;
    cout << "       Welcome to WW1 Game "<<endl;
    cout <<endl;
    cout << "Please make sure that all your responds are correct number"<<endl;
    cout <<endl;

    // loop that will show the first menu choices
    while (true)
    {





    cout << "1- Play"<< endl;
    cout << "2- How to play"<<endl;
    cout << "3- Exit"<<endl;    

    cin >> choice;
        
    if (choice != 1 && choice != 2 && choice != 3)
    {
     cout << "ERROR -- You did not enter the right number"<<endl;
     cout <<endl;  


     cin.clear(); 


     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
 
    if (choice == 1)
    {
        string LeaderName;
        cout << "Enter your nickname: "<<endl;
        cin >> LeaderName;


    int Japan = 0;
    int China =0;
    int UnitedState =0;
    int SovietUnion =0;
    int France =0;
    int Poland =0;


    // variables that will give me a clue if the country is defeted or no


    string line;


    string countriesboot[6];
    string countriespopulation[6];
    double countriessoldiers[6];
    ifstream read("countries.txt");
    for (int i = 0; i <= 5; i++)
    {
        getline(read,countriesboot[i]);
        Boots[i].setCountry(countriesboot[i]);


        getline(read,countriespopulation[i]);
        Boots[i].setPopulation(1.03,stoi(countriespopulation[i]));

        Boots[i].setSoldiers(Boots[i].getPopulation());
    }
    

    
    for (int i = 0; i <= 5; i++)
    {
        countriessoldiers[i]=stod(countriespopulation[i])*0.001;

    }
    
    int options;
    double Tax =10;


    

    int diffculty;
    int turns;
    
    text.diffculty();

    cin >>diffculty;
    ////////////////////////////// Avoid erros that may occur if user choose diffrent number or input an a charactar/////////////////////////

    
    if (diffculty != 1 && diffculty != 2 && diffculty != 3)
    {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (diffculty != 1 && diffculty != 2 && diffculty != 3)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    text.diffculty();
                   cin >>diffculty;


            }
            
            if (diffculty == 1 || diffculty == 2 || diffculty == 3)
            {
                break;
            }
            
        }
        
        
    }
        ///////////////////////////////////////////////////////// Game diffculty Level ////////////////////////////////////////////////////////////

    int gift = 70;//  to give  a random gift during the tunrs
    if (diffculty == 1 )
    {
        turns = 30;
        
    }
    if (diffculty == 2 )
    {
        turns = 50;
        
    }
     if (diffculty == 3 )
    {
        turns = 70;
        
    }

    
    cout <<endl;

    cout << "You are the leader Of Germany in WW1 don't let your people down"<<endl;

    cout <<endl;

            ///////////////////////////////////////////////////////// Game Menu ////////////////////////////////////////////////////////////

    while (true)
    {

        ///////////////////////////////////////////////////////// if the country is deafeted it will show you that beside it name ////////////////////////////////////////////////////////////

    for (int i = 0; i <= 5; i++)
    {
       if (countriessoldiers[i] == 0)
       {
           countriesboot[i]= countriesboot[i] + " (Defeted)";
           countriessoldiers[i]=1;
       }
       
    }


       ///////////////////////////////////////////////////////// If you deafeted all countries Win will be =1 which will be used to end the game ////////////////////////////////////////////////////////////

        int win=0;
        for (int i = 0; i <= 5; i++)
        {
            if (countriessoldiers[i] == 1)
            {
                win =1;
            }
            if (countriessoldiers[i] != 1)
            {
                win =0;
                break;
            }
            
            
        }
                ///////////////////////////////////////////////////////// If win == 1 end the game ////////////////////////////////////////////////////////////

        if (win == 1)
        {
            cout <<endl;
            cout <<endl;
            cout << "       You won the Game !!!!"<<endl;
            aco.win(LeaderName);
            return 0;
        }
            ///////////////////////////////////////////////////////// if the tunrs are finished you will lose the game ////////////////////////////////////////////////////////////

         if (turns == 0)
        {
            cout << "You have 0 turns remaining"<<endl;
            cout << "       You lost the game"<<endl;

            aco.lose(LeaderName);
            return 0;
        }




    cout << "You have "<< turns <<" turns remaining"<<endl;
    cout << "Gold: "<<Germany.getGold()<<endl;
    cout << "Soldiers: "<<Germany.getSoldier()<<endl;
    cout << "Tanks: "<<Germany.getTanks()<<endl;
    cout << "Population: "<<Germany.getPopulation()<<endl;
    cout << "Tax rate:  "<<Tax<<"%"<<endl;

    text.GermanyMenu();
    cin>> options;

    ////////////////////////////// Avoid erros that may occur if user choose diffrent number or input an a charactar/////////////////////////

        if (options != 1 && options != 2 && options != 3 && options != 4 && options != 5 && options != 6 && options != 7)
    {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (options != 1 && options != 2 && options != 3 && options != 4 && options != 5 && options != 6 && options != 7)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "You have "<< turns <<" turns remaining"<<endl;
                cout << "Gold: "<<Germany.getGold()<<endl;
                cout << "Soldiers: "<<Germany.getSoldier()<<endl;
                cout << "Tanks: "<<Germany.getTanks()<<endl;
                cout << "Population: "<<Germany.getPopulation()<<endl;
                cout << "Tax rate:  "<<Tax<<"%"<<endl;

                    text.GermanyMenu();
                   cin >>options;


            }
            
            if (options == 1 || options == 2 || options == 3 || options == 4 || options == 5 || options == 6 || options == 7)
            {
                break;
            }
            
        }
        
        
    }
        ////////////////////////////////////////////////////////////////////////////// Option 1  == attack //////////////////////////////////////////////////////////////////////////////////////

    if (options ==1)
    {
        cout << "List of countries that you can attack "<<endl;
        cout << "Choose a country: "<<endl;
        int attack;
        for (int i = 0; i < 6; i+=2)
        {
            cout << i+1 << "- "<<countriesboot[i]<< "  " <<i+2 <<"- "<< countriesboot[i+1]<<"  ";
        }
        cout << endl;

        cin >> attack;


    ////////////////////////////// Avoid erros that may occur if user choose diffrent number or input an a charactar/////////////////////////


    if (attack != 1 && attack !=2 && attack != 3 && attack !=4 && attack != 5 && attack !=6)
    {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (attack != 1 && attack !=2 && attack != 3 && attack !=4 && attack != 5 && attack !=6)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "List of countries that you can attack "<<endl;
                    cout << "Choose a country: "<<endl;
                    
                    for (int i = 0; i < 6; i+=2)
                    {
                        cout << i+1 << "- "<<countriesboot[i]<< "  " <<i+2 <<"- "<< countriesboot[i+1]<<"  ";
                    }
                    cout << endl;

                    cin >> attack;
                   


            }
            
            if (attack == 1 || attack == 2 || attack == 3 || attack == 4 || attack == 5 || attack == 6)
            {
                break;
            }
            
        }
        
        
    }
    
        ////////////////////////////////////////////////////////////////////////////////// Japan //////////////////////////////////////////////////////////////////////////////////
        
        if (attack == 1)
        {
                // if it already defeated you can not attack it again
            if (Japan == 1)
            {
   
                    cout << "       You already defeted Japan" <<endl;
                    cout <<endl;
                        turns += 1;
            }
            
            if (Japan == 0)
            {

            int sureAttack;
            int losses;
            int deaths;
            int DestroyedTanks = 0.09*Germany.getTanks();
            int prisonrs;

            text.SureAttack(Boots[0].getCountry());


            cin >> sureAttack;
          
        //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////

         if (sureAttack != 1 && sureAttack !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (sureAttack != 1 && sureAttack !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            text.SureAttack(Boots[0].getCountry());
            cin >> sureAttack;


            }
            
            if (sureAttack == 1 || sureAttack ==2)
            {
                break;
            }
            
        }
        
        
  }
            
            



           if (sureAttack == 2)
                {
                    cout << endl;
                    cout << "       Attack is canceled"<<endl; 
                    cout <<endl;
                    turns += 1;
                }



            if (sureAttack == 1)

             {   

                 Germany.setTanks(Germany.getTanks()-DestroyedTanks);
                if (Germany.getSoldier()+(Germany.getTanks()*10)>= Boots[0].getSoldiers() && Japan ==0)
                {
                    int prisonsure;
                    Japan =1;
                    cout << "       The attack is succesful "<<endl;
                    cout <<endl;
                    countriessoldiers[0]=0;
                    losses = randNum(1,4)*Germany.getSoldier(); //random function to calculate the losses
                    deaths = 0.7* losses;
                    prisonrs = 0.3* losses;
                    text.DeathsPrisonors(DestroyedTanks,deaths, prisonrs);
                    cin >> prisonsure;

        //////////////////////////////////////////////////////// Avoid erros that migh be caused if user enter diffrent input for the free of prisonors ///////////////////////////////////////////////////////////

         if (prisonsure != 1 && prisonsure !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (prisonsure != 1 && prisonsure !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
                    cout << "Would yo like to pay " << prisonrs*0.5 << " Gold to free them?"<<endl;
                    cout << "1- Yes"<<endl;
                    cout << "2- No"<<endl;
                    cin >> prisonsure;


            }
            
            if (prisonsure == 1 || prisonsure ==2)
            {
                break;
            }
            
        }
        
        
  }

                    // Free the prisoners
                    if (prisonsure == 1)
                    {
                        if (Germany.getGold() >= prisonrs*0.5)
                        {
                        Germany.setGold(Germany.getGold()-(prisonrs*0.5));
                        Germany.setSoldier(Germany.getSoldier()- deaths);
                        }

                        // If you do not have enough Gold
                        if (Germany.getGold() < (prisonrs*0.5))
                        {
                            cout << "You do not have enough gold to free the prisonrs" <<endl;
                            Germany.setSoldier(Germany.getSoldier()-losses);
                        }
                        
                    }


                    if (prisonsure == 2)
                    {
                        Germany.setSoldier(Germany.getSoldier()-losses);
                    }
                }

                    // If the attack is failed
                if (Germany.getSoldier() + (Germany.getTanks()*10) < Boots[0].getSoldiers() && Japan == 0)
                {
                    int prisonsure;
                    cout << "       The Attack is failed "<<endl;
                    cout <<endl;
                    losses = randNum(5,9)*Germany.getSoldier();//random function to calculate the losses
                    deaths = 0.7* losses;
                    prisonrs = 0.3* losses;
                    text.DeathsPrisonors(DestroyedTanks,deaths, prisonrs);
 
                    cin >> prisonsure;

        //////////////////////////////////////////////////////// Avoid erros that migh be caused if user enter diffrent input for the free of prisonors ///////////////////////////////////////////////////////////

                         if (prisonsure != 1 && prisonsure !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (prisonsure != 1 && prisonsure !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
                    cout << "Would yo like to pay " << prisonrs*0.5 << " Gold to free them?"<<endl;
                    cout << "1- Yes"<<endl;
                    cout << "2- No"<<endl;
                    cin >> prisonsure;


            }
            
            if (prisonsure == 1 || prisonsure ==2)
            {
                break;
            }
            
        }
        
        
  }

                    // Free the prisoners
                    if (prisonsure == 1)
                    {
                        if (Germany.getGold() >= prisonrs*0.5)
                        {
                        Germany.setGold(Germany.getGold()-(prisonrs*0.5));
                        Germany.setSoldier(Germany.getSoldier()- deaths);
                        }

                        // If you do not have enough Gold
                        if (Germany.getGold() < (prisonrs*0.5))
                        {
                            cout << "You do not have enough gold to free the prisonrs" <<endl;
                            Germany.setSoldier(Germany.getSoldier()-losses);
                        }
                        
                    }


                    if (prisonsure == 2)
                    {
                        Germany.setSoldier(Germany.getSoldier()-losses);
                    }
                    



                    
                }
                
            }

            
            }
            
        
        }
        ////////////////////////////////////////////////////////////////////////////////// China //////////////////////////////////////////////////////////////////////////////////

        if (attack == 2)
        {
            // if it already defeated you can not attack it again
            if (China == 1)
            {
   
                    cout << "       You already defeted China" <<endl;
                    cout <<endl;
                        turns += 1;
            }
            
            if (China == 0)
            {

            int sureAttack;
            int losses;
            int deaths;
            int DestroyedTanks = 0.09*Germany.getTanks();
            int prisonrs;
            
            text.SureAttack(Boots[1].getCountry());
            cin >> sureAttack;
          
                  //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////

         if (sureAttack != 1 && sureAttack !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (sureAttack != 1 && sureAttack !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');

            text.SureAttack(Boots[1].getCountry());
            cin >> sureAttack;


            }
            
            if (sureAttack == 1 || sureAttack ==2)
            {
                break;
            }
            
        }
        
        
  }


           if (sureAttack == 2)
                {
                    cout << endl;
                    cout << "       Attack is canceled"<<endl; 
                    cout <<endl;
                    turns += 1;
                }
            if (sureAttack == 1)
            {
                Germany.setTanks(Germany.getTanks()-DestroyedTanks);
                if (Germany.getSoldier()+(Germany.getTanks()*10)>=Boots[1].getSoldiers())
                {
                    int prisonsure;
                    China =1;
                    cout << "       The attack is succesful "<<endl;
                    cout <<endl;
                    countriessoldiers[1]=0;
                    losses = randNum(1,4)*Germany.getSoldier(); //random function to calculate the losses
                    deaths = 0.7* losses;
                    prisonrs = 0.3* losses;
                    text.DeathsPrisonors(DestroyedTanks,deaths, prisonrs);
                    cin >> prisonsure;

                  //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////

         if (prisonsure != 1 && prisonsure !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (prisonsure != 1 && prisonsure !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
                    cout << "Would yo like to pay " << prisonrs*0.5 << " Gold to free them?"<<endl;
                    cout << "1- Yes"<<endl;
                    cout << "2- No"<<endl;
                    cin >> prisonsure;


            }
            
            if (prisonsure == 1 || prisonsure ==2)
            {
                break;
            }
            
        }
        
        
  }



                    // Free the prisoners
                    if (prisonsure == 1)
                    {
                        if (Germany.getGold() >= prisonrs*0.5)
                        {
                        Germany.setGold(Germany.getGold()-(prisonrs*0.5));
                        Germany.setSoldier(Germany.getSoldier()- deaths);
                        }

                        // If you do not have enough Gold
                        if (Germany.getGold() < (prisonrs*0.5))
                        {
                            cout << "You do not have enough gold to free the prisonrs" <<endl;
                            Germany.setSoldier(Germany.getSoldier()-losses);
                        }
                        
                    }


                    if (prisonsure == 2)
                    {
                        Germany.setSoldier(Germany.getSoldier()-losses);
                    }
                }

                // If the attack is failed      
                if (Germany.getSoldier() + (Germany.getTanks()*10) < Boots[1].getSoldiers() && China ==0)
                {
                    int prisonsure;
                    cout << "       The Attack is failed "<<endl;
                    cout <<endl;
                    losses = randNum(5,9)*Germany.getSoldier(); //random function to calculate the losses
                    deaths = 0.7* losses;
                    prisonrs = 0.3* losses;
                     text.DeathsPrisonors(DestroyedTanks,deaths, prisonrs);
                    cin >> prisonsure;

                  //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////

         if (prisonsure != 1 && prisonsure !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (prisonsure != 1 && prisonsure !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
                    cout << "Would yo like to pay " << prisonrs*0.5 << " Gold to free them?"<<endl;
                    cout << "1- Yes"<<endl;
                    cout << "2- No"<<endl;
                    cin >> prisonsure;


            }
            
            if (prisonsure == 1 || prisonsure ==2)
            {
                break;
            }
            
        }
        
        
  }


                    // Free the prisoners
                    if (prisonsure == 1)
                    {
                        if (Germany.getGold() >= prisonrs*0.5)
                        {
                        Germany.setGold(Germany.getGold()-(prisonrs*0.5));
                        Germany.setSoldier(Germany.getSoldier()- deaths);
                        }

                        // If you do not have enough Gold
                        if (Germany.getGold() < (prisonrs*0.5))
                        {
                            cout << "You do not have enough gold to free the prisonrs" <<endl;
                            Germany.setSoldier(Germany.getSoldier()-losses);
                        }
                        
                    }


                    if (prisonsure == 2)
                    {
                        Germany.setSoldier(Germany.getSoldier()-losses);
                    }
                    



                    
                }
                
            }
            
        }

        }
                ////////////////////////////////////////////////////////////////////////////////// United State //////////////////////////////////////////////////////////////////////////////////

               if (attack == 3)
        {
                // if it already defeated you can not attack it again
            if (UnitedState == 1)
            {
   
                    cout << "       You already defeted United State" <<endl;
                    cout <<endl;
                        turns += 1;
            }
            
            if (UnitedState == 0)
            {

            int sureAttack;
            int losses;
            int deaths;
            int prisonrs;
            int DestroyedTanks = 0.09*Germany.getTanks();
            
             text.SureAttack(Boots[2].getCountry());
            cin >> sureAttack;
          

                  //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////


         if (sureAttack != 1 && sureAttack !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (sureAttack != 1 && sureAttack !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            text.SureAttack(Boots[2].getCountry());
            cin >> sureAttack;


            }
            
            if (sureAttack == 1 || sureAttack ==2)
            {
                break;
            }
            
        }
        
        
  }





          
           if (sureAttack == 2)
                {
                    cout << endl;
                    cout << "       Attack is canceled"<<endl; 
                    cout <<endl;
                    turns += 1;
                }
            if (sureAttack == 1)
            {
                Germany.setTanks(Germany.getTanks()-DestroyedTanks);
                if (Germany.getSoldier()+(Germany.getTanks()*10)>=Boots[2].getSoldiers())
                {
                    int prisonsure;
                    UnitedState =1;
                    cout << "       The attack is succesful "<<endl;
                    cout <<endl;
                    countriessoldiers[2]=0;
                    losses = randNum(1,4)*Germany.getSoldier(); //random function to calculate the losses
                    deaths = 0.7* losses;
                    prisonrs = 0.3* losses;
                    text.DeathsPrisonors(DestroyedTanks,deaths, prisonrs);
                    cin >> prisonsure;
                
                  //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////

         if (prisonsure != 1 && prisonsure !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (prisonsure != 1 && prisonsure !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
                    cout << "Would yo like to pay " << prisonrs*0.5 << " Gold to free them?"<<endl;
                    cout << "1- Yes"<<endl;
                    cout << "2- No"<<endl;
                    cin >> prisonsure;


            }
            
            if (prisonsure == 1 || prisonsure ==2)
            {
                break;
            }
            
        }
        
        
  }


                    // Free the prisoners
                    if (prisonsure == 1)
                    {
                        if (Germany.getGold() >= prisonrs*0.5)
                        {
                        Germany.setGold(Germany.getGold()-(prisonrs*0.5));
                        Germany.setSoldier(Germany.getSoldier()- deaths);
                        }

                        // If you do not have enough Gold
                        if (Germany.getGold() < (prisonrs*0.5))
                        {
                            cout << "You do not have enough gold to free the prisonrs" <<endl;
                            Germany.setSoldier(Germany.getSoldier()-losses);
                        }
                        
                    }


                    if (prisonsure == 2)
                    {
                        Germany.setSoldier(Germany.getSoldier()-losses);
                    }
                }

                // If the attack is failed      

                if (Germany.getSoldier() + (Germany.getTanks()*10) < Boots[2].getSoldiers() && UnitedState ==0)
                {
                    int prisonsure;
                    cout << "       The Attack is failed "<<endl;
                    cout <<endl;
                    losses = randNum(5,9)*Germany.getSoldier();//random function to calculate the losses
                    deaths = 0.7* losses;
                    prisonrs = 0.3* losses;
                    text.DeathsPrisonors(DestroyedTanks,deaths, prisonrs);
                    cin >> prisonsure;

                  //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////

         if (prisonsure != 1 && prisonsure !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (prisonsure != 1 && prisonsure !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
                    cout << "Would yo like to pay " << prisonrs*0.5 << " Gold to free them?"<<endl;
                    cout << "1- Yes"<<endl;
                    cout << "2- No"<<endl;
                    cin >> prisonsure;


            }
            
            if (prisonsure == 1 || prisonsure ==2)
            {
                break;
            }
            
        }
        
        
  }


                    // Free the prisoners
                    if (prisonsure == 1)
                    {
                        if (Germany.getGold() >= prisonrs*0.5)
                        {
                        Germany.setGold(Germany.getGold()-(prisonrs*0.5));
                        Germany.setSoldier(Germany.getSoldier()- deaths);
                        }

                        // If you do not have enough Gold
                        if (Germany.getGold() < (prisonrs*0.5))
                        {
                            cout << "You do not have enough gold to free the prisonrs" <<endl;
                            Germany.setSoldier(Germany.getSoldier()-losses);
                        }
                        
                    }


                    if (prisonsure == 2)
                    {
                        Germany.setSoldier(Germany.getSoldier()-losses);
                    }
                    
                    



                    
                }
                
            }
            
        }
        }
            //////////////////////////////////////////////////////////////////////////////////  Soviet Union //////////////////////////////////////////////////////////////////////////////////

               if (attack == 4)
        {
            // if it already defeated you can not attack it again
            if (SovietUnion == 1)
            {
   
                    cout << "       You already defeted Soviet Union" <<endl;
                    cout <<endl;
                        turns += 1;
            }
            
            if (SovietUnion == 0)
            {

            int sureAttack;
            int losses;
            int deaths;
            int prisonrs;
            int DestroyedTanks = 0.09*Germany.getTanks();
            text.SureAttack(Boots[3].getCountry());
            cin >> sureAttack;
          
          
                  //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////

        
         if (sureAttack != 1 && sureAttack !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (sureAttack != 1 && sureAttack !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            text.SureAttack(Boots[3].getCountry());
            cin >> sureAttack;


            }
            
            if (sureAttack == 1 || sureAttack ==2)
            {
                break;
            }
            
        }
        
        
  }




           if (sureAttack == 2)
                {
                    cout << endl;
                    cout << "       Attack is canceled"<<endl; 
                    cout <<endl;
                    turns += 1;
                }
            if (sureAttack == 1)
            {
                Germany.setTanks(Germany.getTanks()-DestroyedTanks);
                if (Germany.getSoldier()+(Germany.getTanks()*10)>=Boots[3].getSoldiers())
                {
                    int prisonsure;
                    SovietUnion =1;
                    cout << "       The attack is succesful "<<endl;
                    cout <<endl;
                    countriessoldiers[3]=0;
                    losses = randNum(1,4)*Germany.getSoldier(); //random function to calculate the losses
                    deaths = 0.7* losses;
                    prisonrs = 0.3* losses;
                    text.DeathsPrisonors(DestroyedTanks,deaths, prisonrs);
                    cin >> prisonsure;

                  //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////

         if (prisonsure != 1 && prisonsure !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (prisonsure != 1 && prisonsure !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
                    cout << "Would yo like to pay " << prisonrs*0.5 << " Gold to free them?"<<endl;
                    cout << "1- Yes"<<endl;
                    cout << "2- No"<<endl;
                    cin >> prisonsure;


            }
            
            if (prisonsure == 1 || prisonsure ==2)
            {
                break;
            }
            
        }
        
        
  }


                    // Free the prisoners
                    if (prisonsure == 1)
                    {
                        if (Germany.getGold() >= prisonrs*0.5)
                        {
                        Germany.setGold(Germany.getGold()-(prisonrs*0.5));
                        Germany.setSoldier(Germany.getSoldier()- deaths);
                        }

                        // If you do not have enough Gold
                        if (Germany.getGold() < (prisonrs*0.5))
                        {
                            cout << "You do not have enough gold to free the prisonrs" <<endl;
                            Germany.setSoldier(Germany.getSoldier()-losses);
                        }
                        
                    }


                    if (prisonsure == 2)
                    {
                        Germany.setSoldier(Germany.getSoldier()-losses);
                    }
                }

                // If the attack is failed      
                if (Germany.getSoldier() + (Germany.getTanks()*10) <Boots[3].getSoldiers() && SovietUnion ==0)
                {
                    int prisonsure;
                    cout << "       The Attack is failed "<<endl;
                    cout <<endl;
                    losses = randNum(5,9)*Germany.getSoldier(); //random function to calculate the losses
                    deaths = 0.7* losses;
                    prisonrs = 0.3* losses;
                    text.DeathsPrisonors(DestroyedTanks,deaths, prisonrs);
                    cin >> prisonsure;

                  //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////

         if (prisonsure != 1 && prisonsure !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (prisonsure != 1 && prisonsure !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
                    cout << "Would yo like to pay " << prisonrs*0.5 << " Gold to free them?"<<endl;
                    cout << "1- Yes"<<endl;
                    cout << "2- No"<<endl;
                    cin >> prisonsure;


            }
            
            if (prisonsure == 1 || prisonsure ==2)
            {
                break;
            }
            
        }
        
        
  }

                     // Free the prisoners
                    if (prisonsure == 1)
                    {
                        if (Germany.getGold() >= prisonrs*0.5)
                        {
                        Germany.setGold(Germany.getGold()-(prisonrs*0.5));
                        Germany.setSoldier(Germany.getSoldier()- deaths);
                        }

                        // If you do not have enough Gold
                        if (Germany.getGold() < (prisonrs*0.5))
                        {
                            cout << "You do not have enough gold to free the prisonrs" <<endl;
                            Germany.setSoldier(Germany.getSoldier()-losses);
                        }
                        
                    }


                    if (prisonsure == 2)
                    {
                        Germany.setSoldier(Germany.getSoldier()-losses);
                    }
                    
                    



                    
                }
                
            }
            }
        }
                    ////////////////////////////////////////////////////////////////////////////////// France //////////////////////////////////////////////////////////////////////////////////
               if (attack == 5)
        {
            // if it already defeated you can not attack it again
            if (France == 1)
            {
   
                    cout << "       You already defeted France" <<endl;
                    cout <<endl;
                        turns += 1;
            }
            
            if (France == 0)
            {

            int sureAttack;
            int losses;
            int deaths;
            int prisonrs;
            int DestroyedTanks = 0.09*Germany.getTanks();
            text.SureAttack(Boots[4].getCountry());
            cin >> sureAttack;
          

                  //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////


         if (sureAttack != 1 && sureAttack !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (sureAttack != 1 && sureAttack !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            text.SureAttack(Boots[4].getCountry());
            cin >> sureAttack;


            }
            
            if (sureAttack == 1 || sureAttack ==2)
            {
                break;
            }
            
        }
        
        
  }


          
           if (sureAttack == 2)
                {
                    cout << endl;
                    cout << "       Attack is canceled"<<endl; 
                    cout <<endl;
                    turns += 1;
                }
            if (sureAttack == 1)
            {
                Germany.setTanks(Germany.getTanks()-DestroyedTanks);
                if (Germany.getSoldier()+(Germany.getTanks()*10)>=Boots[4].getSoldiers())
                {
                    int prisonsure;
                    France =1;
                    cout << "       The attack is succesful "<<endl;
                    cout <<endl;
                    countriessoldiers[4]=0;
                    losses = randNum(1,4)*Germany.getSoldier(); //random function to calculate the losses
                    deaths = 0.7* losses;
                    prisonrs = 0.3* losses;
                    text.DeathsPrisonors(DestroyedTanks,deaths, prisonrs);
                    cin >> prisonsure;

                  //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////

         if (prisonsure != 1 && prisonsure !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (prisonsure != 1 && prisonsure !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
                    cout << "Would yo like to pay " << prisonrs*0.5 << " Gold to free them?"<<endl;
                    cout << "1- Yes"<<endl;
                    cout << "2- No"<<endl;
                    cin >> prisonsure;


            }
            
            if (prisonsure == 1 || prisonsure ==2)
            {
                break;
            }
            
        }
        
        
  }

                    // Free the prisoners
                    if (prisonsure == 1)
                    {
                        if (Germany.getGold() >= prisonrs*0.5)
                        {
                        Germany.setGold(Germany.getGold()-(prisonrs*0.5));
                        Germany.setSoldier(Germany.getSoldier()- deaths);
                        }

                        // If you do not have enough Gold
                        if (Germany.getGold() < (prisonrs*0.5))
                        {
                            cout << "You do not have enough gold to free the prisonrs" <<endl;
                            Germany.setSoldier(Germany.getSoldier()-losses);
                        }
                        
                    }


                    if (prisonsure == 2)
                    {
                        Germany.setSoldier(Germany.getSoldier()-losses);
                    }
                }

                // If the attack is failed      

                if (Germany.getSoldier() + (Germany.getTanks()*10) <Boots[4].getSoldiers() && France ==0)
                {
                    int prisonsure;
                    cout << "       The Attack is failed "<<endl;
                    cout <<endl;
                    losses = randNum(5,9)*Germany.getSoldier(); //random function to calculate the losses
                    deaths = 0.7* losses;
                    prisonrs = 0.3* losses;
                    text.DeathsPrisonors(DestroyedTanks,deaths, prisonrs);
                    cin >> prisonsure;

                  //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////

         if (prisonsure != 1 && prisonsure !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (prisonsure != 1 && prisonsure !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
                    cout << "Would yo like to pay " << prisonrs*0.5 << " Gold to free them?"<<endl;
                    cout << "1- Yes"<<endl;
                    cout << "2- No"<<endl;
                    cin >> prisonsure;


            }
            
            if (prisonsure == 1 || prisonsure ==2)
            {
                break;
            }
            
        }
        
        
  }

                    // Free the prisoners
                    if (prisonsure == 1)
                    {
                        if (Germany.getGold() >= prisonrs*0.5)
                        {
                        Germany.setGold(Germany.getGold()-(prisonrs*0.5));
                        Germany.setSoldier(Germany.getSoldier()- deaths);
                        }

                        // If you do not have enough Gold
                        if (Germany.getGold() < (prisonrs*0.5))
                        {
                            cout << "You do not have enough gold to free the prisonrs" <<endl;
                            Germany.setSoldier(Germany.getSoldier()-losses);
                        }
                        
                    }


                    if (prisonsure == 2)
                    {
                        Germany.setSoldier(Germany.getSoldier()-losses);
                    }
                    
                    



                    
                }
                
            }
            }
        }
                            ////////////////////////////////////////////////////////////////////////////////// Poland //////////////////////////////////////////////////////////////////////////////////
                if (attack == 6)
        {
            // if it already defeated you can not attack it again
            if (Poland == 1)
            {
   
                    cout << "       You already defeted Poland" <<endl;
                    cout <<endl;
                        turns += 1;
            }
            
            if (Poland == 0)
            {

            int sureAttack;
            int losses;
            int deaths;
            int prisonrs;
            int DestroyedTanks = 0.09*Germany.getTanks();
            text.SureAttack(Boots[5].getCountry());
            cin >> sureAttack;
          
             //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////


         if (sureAttack != 1 && sureAttack !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (sureAttack != 1 && sureAttack !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            text.SureAttack(Boots[5].getCountry());
            cin >> sureAttack;


            }
            
            if (sureAttack == 1 || sureAttack ==2)
            {
                break;
            }
            
        }
        
        
  }

          
           if (sureAttack == 2)
                {
                    cout << endl;
                    cout << "       Attack is canceled"<<endl; 
                    cout <<endl;
                    turns += 1;
                }
            if (sureAttack == 1)
            {
                Germany.setTanks(Germany.getTanks()-DestroyedTanks);
                if (Germany.getSoldier()+(Germany.getTanks()*10)>=Boots[5].getSoldiers())
                {
                    int prisonsure;
                    Poland =1;
                    cout << "       The attack is succesful "<<endl;
                    cout <<endl;
                    countriessoldiers[5]=0;
                    losses = randNum(1,4)*Germany.getSoldier(); //random function to calculate the losses
                    deaths = 0.7* losses;
                    prisonrs = 0.3* losses;
                    text.DeathsPrisonors(DestroyedTanks,deaths, prisonrs);
                    cin >> prisonsure;

                  //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////

         if (prisonsure != 1 && prisonsure !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (prisonsure != 1 && prisonsure !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
                    cout << "Would yo like to pay " << prisonrs*0.5 << " Gold to free them?"<<endl;
                    cout << "1- Yes"<<endl;
                    cout << "2- No"<<endl;
                    cin >> prisonsure;


            }
            
            if (prisonsure == 1 || prisonsure ==2)
            {
                break;
            }
            
        }
        
        
  }


                    // Free the prisoners
                    if (prisonsure == 1)
                    {
                        if (Germany.getGold() >= prisonrs*0.5)
                        {
                        Germany.setGold(Germany.getGold()-(prisonrs*0.5));
                        Germany.setSoldier(Germany.getSoldier()- deaths);
                        }

                        // If you do not have enough Gold
                        if (Germany.getGold() < (prisonrs*0.5))
                        {
                            cout << "You do not have enough gold to free the prisonrs" <<endl;
                            Germany.setSoldier(Germany.getSoldier()-losses);
                        }
                        
                    }


                    if (prisonsure == 2)
                    {
                        Germany.setSoldier(Germany.getSoldier()-losses);
                    }
                }

                // If the attack is failed      

                if (Germany.getSoldier() + (Germany.getTanks()*10) <Boots[5].getSoldiers() && Poland ==0)
                {
                    int prisonsure;
                    cout << "       The Attack is failed "<<endl;
                    cout <<endl;
                    losses = randNum(5,9)*Germany.getSoldier(); //random function to calculate the losses
                    deaths = 0.7* losses;
                    prisonrs = 0.3* losses;
                    text.DeathsPrisonors(DestroyedTanks,deaths, prisonrs);
                    cin >> prisonsure;

                  //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////

         if (prisonsure != 1 && prisonsure !=2)

 {
 

        for (int i = 0; i < 100; i++)
        {
            
            
            if (prisonsure != 1 && prisonsure !=2)
            {      
                

                cout << "ERROR -- You did not enter the right number"<<endl;
                cout <<endl;

                // get rid of failure state
                cin.clear(); 


                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
                    cout << "Would yo like to pay " << prisonrs*0.5 << " Gold to free them?"<<endl;
                    cout << "1- Yes"<<endl;
                    cout << "2- No"<<endl;
                    cin >> prisonsure;


            }
            
            if (prisonsure == 1 || prisonsure ==2)
            {
                break;
            }
            
        }
        
        
  }


                      // Free the prisoners
                    if (prisonsure == 1)
                    {
                        if (Germany.getGold() >= prisonrs*0.5)
                        {
                        Germany.setGold(Germany.getGold()-(prisonrs*0.5));
                        Germany.setSoldier(Germany.getSoldier()- deaths);
                        }

                        // If you do not have enough Gold
                        if (Germany.getGold() < (prisonrs*0.5))
                        {
                            cout << "You do not have enough gold to free the prisonrs" <<endl;
                            Germany.setSoldier(Germany.getSoldier()-losses);
                        }
                        
                    }


                    if (prisonsure == 2)
                    {
                        Germany.setSoldier(Germany.getSoldier()-losses);
                    }
                    
                    



                    
                }
                
            }
            }
        }
    
    }


    

    ////////////////////////////////////////////////////////////////////////////// Option 2 == train soldiers //////////////////////////////////////////////////////////////////////////////////////
    
    if (options ==2 )
    {
        int soldiers;
        int Error =0;
        cout << "Each soldier cost 1 gold "<<endl;
        cout<<"How many soldiers would you like to train?"<<endl;
        cin >> soldiers;

                          //////////////////////////////////////////////////////// Avoid erros ///////////////////////////////////////////////////////////

    if (cin.fail())
    {
        cout <<endl;
        cout << "ERROR -- You did not enter an integer";
        cout <<endl;
        
        cin.clear(); 

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout <<endl;

        Error =1;
    }
                      //////////////////////////////////////////////////////// If you do not have enough gold ///////////////////////////////////////////////////////////

    if (soldiers > Germany.getGold() && Error == 0)
    {

        cout <<endl;
        cout << "You do not have enough gold please try again with lower soldiers "<<endl;

        cout <<endl;
        
    }
                      //////////////////////////////////////////////////////// If you have enough gold ///////////////////////////////////////////////////////////

    if (soldiers <= Germany.getGold() && Error == 0)
    {
    Germany.setSoldier(Germany.getSoldier()+soldiers);
    Germany.setGold(Germany.getGold()-soldiers);
    cout <<endl;
    cout << "       Soldiers are ready for your command "<<endl;
    cout<< endl;
    }
    
     turns += 1;

    }

    ////////////////////////////////////////////////////////////////////////////// Option 3 //////////////////////////////////////////////////////////////////////////////////////

    if (options ==3)
    {
        int tanks; 
        int Error =0;
        cout << "Each tank will cost you 10 gold"<<endl;
        cout <<"How many tanks would you like to devolop?"<<endl;
        cin >> tanks;

                          ///////////////////////////////////// Avoid erros ///////////////////////////////////

    if (cin.fail())
    {
        cout <<endl;
        cout << "ERROR -- You did not enter an integer";
        cout <<endl;
        
        cin.clear(); 

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout <<endl;

        Error =1;
    }
                          ////////////////////////////////// If you do not have enough gold ///////////////////////////////////////

     if (tanks *10 > Germany.getGold() && Error ==0)
    {
        cout <<endl;
        cout << "You do not have enough gold please try again with lower number "<<endl;
        cout <<endl;
       
    }
                          ///////////////////////////////////////// If you have enough gold //////////////////////////////////////

    if (tanks*10 <= Germany.getGold() && Error ==0)
    {
    Germany.setTanks(Germany.getTanks()+tanks);
    Germany.setGold(Germany.getGold()-tanks*10);
    cout << endl;
    cout << "       Tanks are ready for your command "<<endl;
    cout<< endl;
    }
    turns += 1;
    }
    

    ////////////////////////////////////////////////////////////////////////////// Option 4 == Raise taxes //////////////////////////////////////////////////////////////////////////////////////

    if (options == 4)
    {
        int sure;
        int Error =0;
        cout << "It will cost you 1000 gold to rise tax rate"<<endl;
        cout << "Do you want to continue ?"<<endl;
        cout << "1- Yes"<<endl;
        cout << "2- No"<<endl;
        cin >> sure;

                          ///////////////////////////////////// Avoid erros //////////////////////////////////

    if (cin.fail())
    {
        cout <<endl;
        cout << "ERROR -- You did not enter an integer";
        cout <<endl;
        
        cin.clear(); 

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout <<endl;

        Error =1;
    }


        if (sure == 1)
        {
             ////////////////////////////////// If you have enough gold the taxes will be raised///////////////////////////////////////

        if (Germany.getGold()>=1000 && Error == 0)
        {
           Tax=  UpgradeCountry(Tax);
            Germany.setGold(Germany.getGold()-1000);
            cout <<endl;
            cout << "Congratulations You have raised taxes"<<endl;
             cout <<endl;

        }
                     ////////////////////////////////// If you do not have enough gold the taxes will not be raised///////////////////////////////////////

        if (Germany.getGold()<1000 && Error == 0)
        {
            cout <<endl;
            cout << "You do not have enough gold to raise taxes"<<endl;
            cout <<endl;
        }
        
        }
    turns += 1;
    }

        ////////////////////////////////////////////////////////////////////////////// Option 5 == spy on countries //////////////////////////////////////////////////////////////////////////////////////

       if (options == 5)
      {
          int spy;
          int Error = 0;
          cout <<"Which country would you like to spy on?"<<endl;

        // show a menu of countries
         for (int i = 0; i < 6; i+=2)
        {
            cout << i+1 << "- "<<Boots[i].getCountry()<< "  " <<i+2 <<"- "<< Boots[i+1].getCountry()<<"  ";
        }
        cout << endl;
            cin >> spy;
 

                           ///////////////////////////////////// Avoid erros //////////////////////////////////

                  if (cin.fail())
                {
                    cout <<endl;
                    cout << "ERROR -- You did not enter an integer";
                    cout <<endl;
                    
                    cin.clear(); 

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout <<endl;

                    Error =1;
                    turns += 1;
                }

            if (Error ==0)
            {


            if (spy == 1 || spy ==2 ||spy == 3 || spy ==4 ||spy == 5 || spy ==6)
            {
                int surespy;
                int massege;
                int persent = randNum(10,1000);// random number that calculte the chance of spy to success
                cout << "It will cost you 2000 Gold to spy on " << Boots[spy-1].getCountry()<<endl;
                cout << "Are you sure of your action ?"<<endl;
                cout << "The chance of succes is "<< persent << "%" <<endl;
                cout <<"1- Yes"<<endl;
                cout << "2- No"<<endl;
                cin >>surespy;

                           ///////////////////////////////////// Avoid erros //////////////////////////////////

                  if (cin.fail())
                {
                    cout <<endl;
                    cout << "ERROR -- You did not enter an integer";
                    cout <<endl;
                    
                    cin.clear(); 

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout <<endl;

                    Error =1;
                    turns += 1;
                }

                if (surespy ==1 && Error == 0)
                {
                    
                Germany.setGold(Germany.getGold() - 2000);
                cout << "Your spy has a massege for you "<<endl;
                cout << "1- Open it "<<endl;
                cout <<"2- ignore it"<<endl;
                cin >>massege;
                
                if (massege != 1)
                {
                    cout <<endl;
                    cout << "       The massege is ignored "<<endl;
                    cout << endl;
                }
                
                
                     ///////////////////////////////////// if the spy success //////////////////////////////////

                if (massege ==1 && persent >=50 )
                {

                    cout << "           It is a succesful mission congratulation"<<endl;

                   if (Germany.getSoldier()+(Germany.getTanks()*10) > Boots[spy-1].getSoldiers())
                   {
                       cout << "        [Spy]: There is a high chance that you can defeat "<<Boots[spy-1].getCountry() <<endl;
                       cout << "        You should attack them right now before they devolop a new soldiers"<<endl;
                   }
                   if (Germany.getSoldier()+(Germany.getTanks()*10) < Boots[spy-1].getSoldiers())
                   {
                       cout << "        [Spy]: You can not defeat them they are more powerful and more orgnaized  "<<endl;
                       cout << "        You should raise taxes and collect them for several turns to train at least 100,000 soldiers"<<endl;
                       
                   }
                   
                }
                if (massege ==1 && persent <50)
                {
                    cout << "       The mission is failed"<<endl;
                }
                
                
                }

                if (surespy == 2)
                {
                    cout << "       The mission is canceled"<<endl;
                    turns += 1;
                }

                if (surespy != 1 && surespy !=2 && Error ==0)
                {
                    cout <<endl;
                    cout << "Wrong number"<<endl;
                    cout <<endl;
                    turns += 1;
                }
                
                
                
            }
        
            if (spy != 1 && spy !=2 &&spy != 3 && spy !=4 &&spy != 5 && spy !=6)
            {
                cout << "Wrong number"<<endl;
                turns += 1;
            }
            
          
          
      }

      }
        ////////////////////////////////////////////////////////////////////////////// Option 6 == Collect taxes //////////////////////////////////////////////////////////////////////////////////////
       if (options == 6)
      {
        Germany.setGold((Germany.getGold()+10)*Tax/100+Germany.getGold());
        cout <<endl;
      }
    
        ////////////////////////////////////////////////////////////////////////////// Option 7 == quit //////////////////////////////////////////////////////////////////////////////////////


        if (options ==7)
        {
            return 0;
        }
        
        

        turns--;

        gift --;
                         ///////////////////////////////////// Gift from a country in the middle of the game //////////////////////////////////

        if (gift == 61 || gift == 41 || gift ==21)
        {
            int accept;
            

            if (gift == 61)
            {
                text.Gift(1);
                cin >> accept;
            }
            
            if (gift == 41)
            {
               text.Gift(2);
               cin >> accept;
            }
            if (gift == 21)
            {
               text.Gift(3);
               cin >> accept;
            }
            
           
                           ///////////////////////////////////// Avoid erros //////////////////////////////////

                    if (cin.fail())
                 {
                        cout <<endl;
                        cout << "ERROR -- You did not enter an integer";
                        cout <<endl;
                        
                        cin.clear(); 

                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout <<endl;

        
                  }
                  
            if (accept != 1 && accept !=2)
            {
                cout <<endl;
                cout << "       Wrong number "<<endl;
                cout << endl;

            }
            
            if (accept == 1)
            {
                Germany.setGold(Germany.getGold()+80000);
            }

            
        }

    }

    }


                            ///////////////////////////////////// Choice 2 == How to play//////////////////////////////////

    if (choice ==2)
    {
        text.HowToPlay();
    }
    
                                   ///////////////////////////////////// choice 3 == Exist //////////////////////////////////

    if (choice == 3)
    {
        return 0;
    }
    
}


}
