#include "SudokuFactory.h"

SudokuFactory::SudokuFactory(Reproduction*& offspringCreator)
{
   SudokuOffspring* temp = (SudokuOffspring *) offspringCreator;
   this->offspringCreator_ = temp;
}

Puzzle*& SudokuFactory::createPuzzle(Puzzle*& sudokuPuzzle)
{
   SudokuOffspring offspringCreator;
   offspringCreator.makeOffspring(sudokuPuzzle);
   return sudokuPuzzle;
}