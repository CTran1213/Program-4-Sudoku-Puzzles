#include "SudokuFactory.h"

SudokuFactory::SudokuFactory()
{

}

Puzzle*& SudokuFactory::createPuzzle(Puzzle*& sudokuPuzzle)
{
   SudokuOffspring child;
   child.makeOffspring(sudokuPuzzle);
   return sudokuPuzzle;
}