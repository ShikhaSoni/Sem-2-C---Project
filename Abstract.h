/*
* Abstract.h
*
* @version   $Id: Abstract.h,v 1.0$
*
* Description: This header file acts as a base class to all the puzzles 
*             to be solved
*
*/

#ifndef ABSTRACT_H
#define ABSTRACT_H
#include <vector>
#include <iostream>
using namespace std;

/**
 * Abstract class declares the functions to solve the puzzle
 */

template <typename T>
class Abstract
{
    public:
            typedef T type;
            virtual type initial_state() = 0;
            virtual bool goal(type&) = 0;
            virtual vector<type> next_elements(type&) = 0;
            virtual string display(type&) = 0;

};
#endif
