#pragma once
#include "Sudoku.h"

class PuzzleFactory
{
   public:
   PuzzleFactory()
   {

   }

   virtual Sudoku* createPuzzle(Sudoku*& sudoku) = 0;
};