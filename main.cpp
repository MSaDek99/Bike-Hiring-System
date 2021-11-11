//
//  Main.cpp
//  BIKE_COMPANY
//
//  Created by Mohammed Elsayed
//  Copyright © 2018 Mohammed Elsayed. All rights reserved.
//

#include <iostream>
#include <fstream>
#include<iomanip>
#include <limits>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include <stack>
#include <vector>
#include "DATABASE.h"
#include "Hire.h"
using namespace std;

int main()
{
    DATABASE Locations[6];
    Hire hiring;
    string choice,choicep,choiced;
    char z,v;
    int hours=1,var=0,var2=0,var3=0,repeat=0,loop=0;
    cout<<"\t\t\t\t\tWelcome To Sadinho Bike Company..."<<endl<<endl;
    for(int x=0;x<6;x++)
    {
         Locations[x].read(x);
         cout<<"Location "<<(char)('A'+x)<<": ";
         Locations[x].print();
         cout<<endl;
    }
    while(loop<24)
    {
    do
    {
            cout<<"Do you want to borrow a bike: Y for yes, N for No!(Without Spaces):"<<endl;
            getline(cin,choice);
            if(choice.find_first_of("0123456789") != std::string::npos || (choice!="Y" && choice !="N") || (strlen(choice.c_str())>1) )
            {
                    var++;
                    cout<<"Invalid Input"<<endl;
            }
            else
            {
                    var=0;
            }
    }
    while(var>0);
    if(choice == "Y")
    {
        while(repeat==0)
        {
            do
            {
                     cout<<"Please choose your pick up Location(Without Spaces):"<<endl;
                     getline(cin,choicep);
                    if(choicep.find_first_not_of("ABCDEF") != std::string::npos || (strlen(choicep.c_str())>1) )
                    {
                            var2++;
                            cout<<"Invalid Input"<<endl;
                    }
                    else
                    {
                            var2=0;
                    }
            }
            while(var2>0);
            do
            {
                    cout<<"Please choose your drop off Location(Without Spaces):"<<endl;
                    getline(cin,choiced);
                    if(choiced.find_first_not_of("ABCDEF") != std::string::npos || (strlen(choiced.c_str())>1) )
                    {
                            var3++;
                            cout<<"Invalid Input"<<endl;
                    }
                    else
                    {
                            var3=0;

                    }
            }
            while(var3>0);
            z=choicep[0];
            repeat=Locations[(int(z)-'A')].borrow();
            if(repeat>0)
            {
                   hiring.hiredbikes(repeat,choiced,loop+1);
                   if(hiring.bikenewlocation().size()!=0)
                    {
                            v=(((hiring.bikenewlocation()))[0])[0];
                            Locations[(int(v)-'A')].returned((hiring.bikenum())[0]);
                            hiring.deletelement(0);

                                       //  if(hiring.bikenewlocation().size()!=0)
                                        // {
                                             //((hiring.bikenewlocation())).erase (((hiring.bikenewlocation())).begin());
                                     //   }
                    }
                    cout<<"After "<<loop+1<<"    hour(s) current Pick Up Locations have the following bikes:"<<endl<<endl;
                    for(int x=0;x<6;x++)
                    {
                        cout<<"Location "<<(char)('A'+x)<<": ";
                        Locations[x].print();
                        cout<<endl;
                    }

            }
        }
    }
        repeat=0;
    if(choice == "N")
    {
        cout<<"After "<<loop+1<<"    hour(s) current Pick Up Locations have the following bikes:"<<endl<<endl;
        for(int x=0;x<6;x++)
        {
                        cout<<"Location "<<(char)('A'+x)<<": ";
                        Locations[x].print();
                        cout<<endl;
        }
    }
    loop++;


    }
}
