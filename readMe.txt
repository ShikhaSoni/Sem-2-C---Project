README

Version 1.0     5/15/2015


-------------
I. File List
-------------

Abstract.h	Header file which is a base class to other puzzles. 
		
Framework.h	Header file provides common framework design to solve the puzzle by processing the different arrangements of the problem and
		verifies with the goal state.
 
Clock.cpp	Clock.cpp initializes by taking inout and calls function to find the shortest path to move the hour hand to reach the goal.

Water.cpp	Water.cpp contains functions to initialize,goal description,processing input to reach goal and display result.

Lloyd.cpp	Lloyd.cpp contains functions to initialize,goal description,processing input to reach goal and display result.


-----------
II. Design
-----------
 
Abstract.h
-----------

-The header file is a base class to all other puzzles.

-It consists of the template and virtual functions which will be defined in the derived class in main files.


Framework.h
---------

-First the a common Framework for all the given puzzles was designed namely Framework.h. This will be the header file included in all the other puzzles.

-I have designed a template consisting of a sol_finder() method which takes the class object as a parameter.

-I took the initial state of the puzzle and verified it with the defined goal.

-I took all the possible states and for each possible state I verified the goal state. 

-As soon as a solution is found the program halts and displays the path of how the solution was reached.



Clock.cpp (Clock Puzzle)
-------------------------

-The user input is checked, whether it is valid or not. If invalid no solution will exist.

-The input will be number of hours, current time and actual time.

-The constructor is called. It will check whether current and actual time are exceeding the total number of hours.

-The solve1() function in Framework.h is called with the input parameters. 

-Each intermediate move of hour hand in clockwise and anti-clockwise direction are stored in the queues q1 and q2 respectively.

-As the values are stored in the queues, the values are compared with the goal state. If a match is found the output is displayed and further operations halt.


Water.cpp (Water Puzzle)
------------------------

-The user input is checked, whether it is valid or not. If invalid no solution will exist.

-Here user will input the desired amount of water and the amount in each container.

-The constructor is used to store the desired amount of water in desired_amt and stores vector containing the containers quantity provided in input. 

-The sol_finder() fucntion in Framework.h is called. In this function initial state() is called which returns a vector of a size equal to number of containers.

-Then in the function next_elements() the states of containers which represents filling and throwing away the water are verifies with the defined goal state.

-If a goal is reached display() is used in storing output to display the output.


Lloyd.cpp (Sliding Puzzle)
--------------------------

-Here user will input the initial state and the goal state of block puzzle.

-If input is ".\a.out - -" then the input and output are provided in console.

-If input is ".\a.out inputfile outputfile" then the input and output are provided in file form.
   
     ex- ".\a.out input output"

-The user input is checked for validity. If not valid then no solution exists.

-The constructor creates two vectors storing initial state and the goal state of block puzzle respectively.

-The sol_finder() fucntion in Framework.h is called. In this function initial state() is called which returns the initial_vector which stores initial state of block  puzzle.

-Then in the function next_elements(), the empty space block is found and for each adjacent element it checks the defined goal position of blocks and it swaps with the  adjacent elements according to the defined goal arrangement of blocks.

-If a goal is reached display() is used in storing output to display the output.





