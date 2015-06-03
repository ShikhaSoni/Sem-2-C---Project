/*
* Water.cpp
*
* @version   $Id: Water.cpp,v 1.0  $
*
* Description: Water class contains functions to initialize,goal description,
*             processing input to reach goal and display result.
*
*/


#include <iostream>
#include <vector>
#include <sstream>
#include "Framework.h"
#include "Abstract.h"
#include <stdlib.h>

using namespace std;

/**
 * Water class initializes the containers and processes the input to reach 
 * the goal state
 */

class Water : public Abstract<vector<int> >
    {
        public:
                int desired_amt;
                vector<int> containers;

Water(int Qty, vector<int>& container)
    {
        desired_amt=Qty;
        containers=container;
    }

/**
* initial_state() initializes the vector according to the input parameters
*
* @param  none
* @return vector<int>    vector such that vector.size() is according to number 
* of containers
*/

vector<int> initial_state() 
{
    int size=containers.size();
    return vector<int>(size,0);
}

/**
* goal() checks whether current state of containers matches the goal state
*
* @param  state    Holds current state of container
* @return boolean  goal found (true)
* @return boolean  goal not found (false)
*
*/

bool goal(vector<int>& state)
    {
        for(vector<int>::const_iterator index = state.begin();
        index != state.end();
        index++)
            {
                if(*index == desired_amt)
                return true;
            }
        return false;
    }

/**
* next_elements() traverses through all the adjacent elements
*
* @param    state          Holds the current state of the container
* @return   state_vector   Stores the other states of containers
*
*/

vector< vector<int> > next_elements(vector<int>& state)
    {
        vector< vector<int> > state_vector;
        for(int i = 0; i < state.size(); i++)
            {
                if(state[i] != containers[i])
                    {
                        vector<int> v(state);
                        v[i] = containers[i];
                        state_vector.push_back(v);
                    }
                if(state[i] != 0)
                    {
                        vector<int> v(state);
                        v[i] = 0;
                        state_vector.push_back(v);
                    }
            }

        for(int j = 0; j < state.size(); j++)
            {
                for(int i = 0; i < state.size(); i++)
                    {
                        if(j != i)
                            {
                                int amt1=containers[i] - state[i];
                                int amt2 =state[j];
                                int transfer = min(amt1,amt2);
                                if (transfer > 0)
                                    {
                                        vector<int> v(state);
                                        v[j] = v[j]- transfer;
                                        v[i] = v[i]+ transfer;
                                        state_vector.push_back(v);
                                    }
                            }
                    }
            }
        return state_vector;
    }

/**
* display() is used to print the output
*
* @param   state   Holds the current state of the container
* @return  s_out  output
*
*/

string display(vector<int>& state)
    {
        stringstream s_out;
        for(int i = 0; i < state.size(); i++)
            {
              s_out <<state[i]<<" lit in (" << containers[i] << ") lit "
                      "capacity container";
              if (i < state.size() - 1)
              s_out << ", ";
            }
    return s_out.str();
    }
};

/**
* This is the main function which takes the input from the user
*
* @param  none
* @return none
*
*/

int main(int argc, char** argv)
    {
        vector<int> measures;
        if(argc < 3)
            {
               cout << "Invalid input:Enter desired amount and container sizes";
               cout<< endl;
               exit(EXIT_FAILURE);
            }

    int Qty = atoi(argv[1]);
    argc=argc-2;
    while(argc)
        {
            int quantity=0;
            stringstream s_out(argv[2]);
            s_out >> quantity;
            if(s_out.fail() || quantity < 1)
                {
                    cout << "Invalid input "<< endl;
                    exit(EXIT_FAILURE);
                }

            measures.push_back(quantity);
            argv++;
            argc--;
        }

    Water w_obj(Qty, measures);
    Framework::sol_finder(w_obj);
    return 0;
    }
