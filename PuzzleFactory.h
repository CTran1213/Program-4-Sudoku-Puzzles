#pragma once
#include "Puzzle.h"

class PuzzleFactory
{
   public:
   PuzzleFactory()
   {

   }

   virtual Puzzle* createPuzzle(Puzzle*& sudoku) = 0;
};