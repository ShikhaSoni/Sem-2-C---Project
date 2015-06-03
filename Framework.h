/*
* Framework.h
* @version $Id: Framework.h, v 1.0$
* Description: This header file provides a framework design 
*             to solve all the puzzles.
*/

#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include <iostream>
#include "Abstract.h"
#include <stdlib.h>
#include <queue>
#include <list>
#include <map>

using namespace std;

/**
 * namespace Framework contains functions to solve the puzzles
 */
namespace Framework {

/**
* display() finds the shortest path to move the hour hand to reach the goal
*
* @param  q       Stores path
* @return none
*/


     void display(queue<int> q)
    {
        while(q.size()!=1)
        {   int h1=q.front();
            q.pop();
            cout<<"Move "<<h1<<" to "<<q.front()<<endl;
        }
    }
 /**
 *
 * solve() moves the hour hand in clockwise and anti-clockwise direction and
 * stores the values in the queues q1 and q2 respectively
 *
 * @param   n     Total Hours
 * @param   c     Current Time
 * @param   a     Actual Time
 */

    void solve(int n,int c,int a)
    {
      queue<int> q1,q2;
      int c1;
      c1=c;
      while(c!=a && c1!=a)
    {
        q1.push(c);
        q2.push(c1);
        if(c==1)
            c=n+1;
        if(c1==n)
            c1==0;
        c--;
        c1++;
    }
     if(c==a)
     {
         q1.push(c);
         display(q1);
     }
     else if(c1==a)
     {
         q2.push(c1);
         display(q2);

     }

    }


/**
*
* sol_finder() Processes the different states of the problem and
* verifies with the goal state
*
* @param   abstract   object to refer the puzzle
* @param   out        ostream object used to output sequence of data
*
*/


template <typename T>
void sol_finder(Abstract<T>& abstract, ostream& out = cout)
    {
        typedef typename Abstract<T>::type type;
        type initial = abstract.initial_state();

        if(abstract.goal(initial))
            {
                out << "No movements required"<< endl;
                return;
            }
        queue<type> stateQueue;

        map<type, type> m;
        m[initial] = initial;
        stateQueue.push(initial);
        bool isResult = false;
        type result;

        while(stateQueue.size())
            {
               type current = stateQueue.front();
               stateQueue.pop();
               vector<type> state_vector = abstract.next_elements(current);
               for(typename vector<type>::iterator index = state_vector.begin();
               index != state_vector.end();
               index++)
                    {
                        if(m.insert(make_pair(*index, current)).second)
                            {
                                if(abstract.goal(*index))
                                    {
                                        isResult = true;
                                        result = *index;
                                        break;
                                    }
                                stateQueue.push(*index);
                            }
                    }
                if(isResult)
                break;
            }
                if(isResult)
                    {
                    list<type*> sequence;
                    type* state = &result;
                    while(*state != initial)
                            {
                                sequence.push_front(state);
                                state = &m[*state];
                            }
                    sequence.push_front(&initial);
                    out << " " << endl;
                    int count = 0;
                    for(typename list<type*>::iterator index = sequence.begin();
                       index != sequence.end();
                       index++)
                            {
                                out << "Sequence " << count++ << ":\n"
                                << abstract.display(**index) << endl;
                            }
                    }
                else
                    out << "No solution." << endl;
            }
}
#endif
