#include "SudokuFactory.h"

SudokuFactory::SudokuFactory()
{

}

Sudoku* SudokuFactory::createPuzzle(Sudoku*& sudokuPuzzle)
{
   SudokuOffspring child;
   child.makeOffspring(sudokuPuzzle);
   return sudokuPuzzle;
}