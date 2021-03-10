#pragma once
#include "Puzzle.h"
#include "PuzzleFactory.h"
#include "SudokuOffspring.h"
#include "Reproduction.h"

class SudokuFactory : public PuzzleFactory
{
   public:
      SudokuFactory(Reproduction*& offspringCreator);
      Puzzle*& createPuzzle(Puzzle*& sudokuPuzzle);

   private:
      SudokuOffspring* offspringCreator_;
};