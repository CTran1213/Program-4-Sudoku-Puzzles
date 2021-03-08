#pragma once
#include "Puzzle.h"
#include "Sudoku.h"

class Reproduction
{
   public:
      Reproduction()
      {

      }

      virtual Puzzle* makeOffspring(Puzzle*& sudokuPuzzle) = 0;
};