//SudokuFactory.cpp
//3/12/2021
//@author: Faduma Farah
//@studentID: 1727406
//Catherine Tran ID: 2021829
//A PuzzleFactory is an abstract factory design pattern for producing puzzles.
//A PuzzleFactory is provided at construction time with a Reproduction object 
//that it uses to create new instances of Puzzle.

#pragma once
#include "Puzzle.h"
#include "Reproduction.h"

class PuzzleFactory
{
   public:
   //Constructor
   PuzzleFactory()
   {

   }

   //This is a virtual method that is used in SudokuFactory
   //This method uses the Reproduction data member to create and return a 
   //new puzzle
   //Precondition: None
   //Postcondition: Returns a puzzle created from the sudokuoffspring object
   virtual Puzzle* createPuzzle(Puzzle*& sudoku) = 0;
};

