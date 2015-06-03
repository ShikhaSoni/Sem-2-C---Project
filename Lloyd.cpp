/*
* Lloyd.cpp
*
* @version   $Id: Lloyd.cpp,v 1.4 2014/04/12 21:00:00  $
* Description: Program contains functions for initialization,goal description,
* processing input to reach goal and display result for solving Lloyd task.
*
*
*/


#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <sstream>
#include "Framework.h"
#include "Abstract.h"
#include <stdlib.h>

using namespace std;

/**
 * Lloyd class contains functions to initialize,goal description,
 * processing input to reach goal and display result.
 */

class Lloyd : public Abstract<vector<char> >
{
public:
    
type initial_vector;
type goal_vector;
int rows;
int columns;
typedef vector<char> type;

Lloyd(istream& in) 
{ 
    rows=0;
    columns=0;
    in >> columns >> rows;
    int v_size=rows*columns;
    initial_vector.resize(v_size);
    goal_vector.resize(v_size);

for(int i = 0; i < rows; i++)
    {
    for(int j = 0; j < columns; j++)
        {
            in >> initial_vector[m_index(i, j)];
        }
    }
    
for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            in >> goal_vector[m_index(i, j)];
        }
    }
}

/**
 * initial_state() returns given initial blocks of puzzle
 *
 * @param    none
 * @return   initial_vector  vector to hold initial blocks 
 */
type initial_state() 
{
    return initial_vector;
}

/**
 * goal() returns given defined goal blocks of puzzle
 *
 * @param    none
 * @return   goal_vector  vector to hold defined goal blocks of puzzle 
 */
bool goal(type& state)
{
    return state == goal_vector;
}

/**
 * next_elements() is used to traverse adjacent elements and 
 * swap the elements accordingly 
 *
 * @param    state         current state of Block puzzle
 * @return   state_vector  vector to hold states of Block puzzle
 */
vector<type> next_elements(type& state)
{
vector<type> state_vector;

for(int i = 0; i < rows; i++)
    {
    for(int j = 0; j < columns; j++)
        {
            int index = m_index(i, j);
            if(state[index] == '.')
            {
                if(j != 0)
                {
                type n = state;
                swap(n, index, m_index(i, j - 1));
                state_vector.push_back(n);
                }

                if(i != 0)
                {
                type n = state;
                swap(n, index, m_index(i - 1, j));
                state_vector.push_back(n);
                }

                if(j != columns - 1)
                {
                type n = state;
                swap(n, index, m_index(i, j + 1));
                state_vector.push_back(n);
                }

                if(i != rows - 1)
                {
                type n = state;
                swap(n, index, m_index(i + 1, j));
                state_vector.push_back(n);
                }
            }
        }
    }
return state_vector;
}

/**
 * display()  prints the output
 *
 * @param    state        current state of block puzzle
 * @return   s_out.str()  stringstream object used to output result  
 */

string display(type& state)
{
stringstream s_out;
for(int i = 0; i < rows; i++)
    {
    for(int j = 0; j < columns; j++)
        {
            s_out << state[m_index(i, j)] << " ";
        }
        s_out <<endl;
    }
return s_out.str();
}

/**
 * m_index()  gives index of block puzzle positions
 *
 * @param    r      row of block puzzle
 * @param    c      column of block puzzle
 * @return   i      index of block puzzle positions 
 */

int m_index(int r, int c) 
{
    int i;
    i=c+ (r * columns);
    return i;
}

/**
 * swap()  used to swap elements
 *
 * @param    state      current state of block puzzle
 * @param    block1     element1 to swap with element2
 * @param    block2     element2 to swap with element1 
 * @return   none
 */
void swap(type& state, int block1, int block2)
{
    int temp = state[block1];
    state[block1] = state[block2];
    state[block2] = temp;
}
};

/**
     * The main program used to take input 
     *
     * @param args
     *            command line arguments (ignored)
     */
int main(int argc, char** argv)
{
 if(argc == 3)
 {
    ifstream input_file;
    ofstream output_file;
    istream* input;
    ostream* output;
    if(strcmp(argv[1], "-")==0 && strcmp(argv[2], "-")==0)
    {
        input = &cin;
        output = &cout;
    }
    else
    {
    input_file.open(argv[1]);
    if(!input_file)
    {
        cout << "Unable to open input file " << argv[1] << endl;
        exit(EXIT_FAILURE);
    }
    input = &input_file;
    output_file.open(argv[2]);
    if(!output_file)
    {
        cout <<"Unable to open output file " << argv[2] << endl;
        exit(EXIT_FAILURE);
    }
    output = &output_file;
 }
 Lloyd l_obj(*input);
 Framework::sol_finder(l_obj, *output);
 return 0;
}
else   
 {
    cout << "Invalid input"<<endl;
    exit(EXIT_FAILURE);
 }
}