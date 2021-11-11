#include "Hire.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>
#include<iterator>
#include <string.h>
#include <fstream>
#include <stack>
#include<vector>

using namespace std;
Hire::Hire()
{

}

void Hire::hiredbikes(int var,string finaldestination,int starttime)
{
                int f;
                hiretime.push_back(starttime);
                destination.push_back(finaldestination);
                hired.push_back(var);
                f=2;//rand()% 24+1;
                hireperiod.push_back(f);
                cout<<"Pick Up Done Successfully for ";
                cout<<hireperiod[int(hired.size())-1];
                cout<<" Hours..."<<endl<<endl;;
                cout<<"Number Of Hired Bikes:   "<<int(hired.size()) << " Bike(s).\n"<<endl;
                cout << "Hired Bike(s) : "<<endl<<endl;
                for(int m=0;m<int(hired.size());m++)
                {
                    if((hireperiod[m]-(hiretime[hiretime.size()-1]-m-1))>0)
                    {
                        cout<<"Hired At "<<hiretime[m]<<endl;
                        cout<<hired[m]<<" For   "<<hireperiod[m]-(hiretime[hiretime.size()-1]-m-1)<<" Hours"<<" Returning At Destination:  "<< destination[m];
                        cout<<endl<<endl;
                    }
                    else
                    {
                        returnednum.push_back(hired[m]);
                        newlocation.push_back(destination[m]);
                    }
                }
}
vector<int> Hire::bikenum()
{
    return returnednum;
}
vector<string> Hire::bikenewlocation()
{

    return newlocation;
}
void Hire::deletelement(int element)
{
        newlocation.erase (newlocation.begin()+element);
        returnednum.erase (returnednum.begin()+element);
}
