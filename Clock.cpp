
/*
* Clock.cpp
*
* @version   $Id: Clock.cpp,v 1.4$
* Description: Initializes by taking input and calls function to find the 
* shortest path to move the hour hand to reach the goal.
*
*/

#include <iostream>
#include <cmath>
#include <string.h>
#include "Framework.h"
#include <queue>
#include "Abstract.h"
#include <stdlib.h>


using namespace std;

/**
 * Clock class is used to check possibility of solution
 * with given input. 
 *
 */
class Clock 
{
public:
    Clock(int n1,int c1,int a1)
    {   
        if(n1==0 || c1==0 || a1==0)
        {
            cout<<"Invalid input"<<endl;
            exit(EXIT_FAILURE);
        }
        if(c1>n1 || a1>n1)
        {
            cout<<"Invalid input: current time and actual time "
                    "exceeds total hours"<<endl;
            exit(EXIT_FAILURE);
        }
        
    }
            
};

   /**
     * The main program used to take input and process input
     *
     * @param args
     *            command line arguments (ignored)
     */
int main(int argc, char** argv)
{ 
 int total_hrs,current_time,actual_time;
 
 if(argc!=4)
    {
        cout << "Invalid input:Enter total no hours,current time,actual time";
        cout<< endl;
        exit(EXIT_FAILURE);
    }
 
 total_hrs = atoi(argv[1]);
 current_time = atoi(argv[2]); 
 actual_time = atoi(argv[3]);
 
 if(current_time==actual_time)
    {
        cout<<"current time and actual time is same.No more moves required";
        cout<<endl;
        exit(EXIT_FAILURE);
    }

Clock c_obj(total_hrs,current_time,actual_time);
Framework::solve(total_hrs,current_time,actual_time);
return 0;
}