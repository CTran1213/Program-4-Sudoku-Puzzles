#pragma once
#include "Puzzle.h"
#include "Sudoku.h"

class Reproduction
{
   public:
      //Constructor
      Reproduction()
      {

      }

      //This is a virtual method that is implemented in SudokuOffspring
      //This method creates a copy of the given puzzle and each sudoku box in
      // the copy has a 3% chance of mutating. If the given puzzle has any 0's
      // in the grid, the 0's are changed to random number between 1-9.
      //Precondition: none
      //Postcondition: A copy of the given puzzle is returned
      virtual Puzzle* makeOffspring(Puzzle*& sudokuPuzzle) = 0;
};