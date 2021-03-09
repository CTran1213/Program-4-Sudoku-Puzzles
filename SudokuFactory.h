#pragma once
#include "Puzzle.h"
#include "PuzzleFactory.h"
#include "SudokuOffspring.h"

class SudokuFactory : public PuzzleFactory
{
   public:
   SudokuFactory();
   Puzzle*& createPuzzle(Puzzle*& sudokuPuzzle);
};