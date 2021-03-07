#pragma once
#include "Sudoku.h"
#include "PuzzleFactory.h"
#include "SudokuOffspring.h"

class SudokuFactory : public PuzzleFactory
{
   public:
   SudokuFactory();
   Sudoku* createPuzzle(Sudoku*& sudokuPuzzle);
};