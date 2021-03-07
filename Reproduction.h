#pragma once
#include "Puzzle.h"
#include "Sudoku.h"

class Reproduction
{
   public:
      Reproduction()
      {

      }

      virtual Sudoku* makeOffspring(Sudoku*& sudokuPuzzle) = 0;
};