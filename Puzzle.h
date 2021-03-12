//Puzzle.h
//3/12/2021
//@author: Faduma Farah
//@studentID: 1727406
//Catherine Tran ID: 2021829
//The Puzzle class defines the abstract interface for any puzzle to be used 
//by the GA framework. Puzzle class must define stream I/O helper methods 
//(operator<<() and operator>>() to call these methods) and the subclasses
// must implement them.
#pragma once
#include<iostream>
#include <vector>
using namespace std;

class Puzzle
{
   //Defined in Puzzle, but implemented in Sudoku
   //This istream operator takes in a string of characters and uses the first
   // 81 digits to populate the sudoku grid. Digits that are 0 are not fixed 
   //numbers and digits that are 1-9 are fixed numbers
	friend istream& operator>>(istream& instream, Puzzle& puzzle);

   //Defined in Puzzle, but implemented in Sudoku
   //This ostream operator produces a "human friendly" output as formatted 
   //text. Outpust a puzzle as 13 lines of text, with each line either being
   // a separator or one containing the numbers in a row of the puzzle separated
   // by single spaces. Use the '|', '+', and '-' characters to separate 3-by-3
   // blocks (so, each line of output should be 25 printing characters long: 9 
   //digits, 12 spaces, and 4 '|' for "non-divider" lines and 21 '-' and 4 '+'
   // for "divider" lines). An example (very simple puzzle) is shown below.
	friend ostream& operator<<(ostream& outstream, const Puzzle& puzzle);

public:

   //Constructor
   Puzzle()
   {
      
   }
};