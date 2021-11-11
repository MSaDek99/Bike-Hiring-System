#include "DATABASE.h"
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
DATABASE::DATABASE()
{
    //ctor
}


void DATABASE::read(int f)
{
    int var=0,stop = 0;
    string x;
    ifstream Database;
    string line[100];
    Database.open("Base.txt");
    if (!Database)
        {
    cout << "Unable to open file Books.txt";
        }
    else
        {
            for(int p=0;p<f;p++)
            {
                getline(Database,line[p]);
            }
            while(Database>>x)
            {
                if(x!="&")
                {
                    if(x!=" ")
                    {
                        Location.push(atoi(x.c_str()));
                    }
                }
                else
                {
                    break;
                }
            }
        }

}
void DATABASE::print()
{
    stack<int> dummystack;
    dummystack= Location;
        if(dummystack.empty())
    {
        cout<<"Location is Empty"<<endl;
    }
    else
    {
        while(!dummystack.empty())
        {
             cout << ' ' <<dummystack.top();
             dummystack.pop();
        }
    }

}
int DATABASE::borrow()//,string destination)
{
    int var;
           if(!Location.empty())
           {
                var=Location.top();
                Location.pop();
                if(Location.empty())
                {
                    cout<<"s";
                }
                return var;
           }
           else
           {
               cout<<"Location is Empty"<<endl;
               return 0;
           }

}
int DATABASE::returned(int var)
{

       Location.push(var);

}



