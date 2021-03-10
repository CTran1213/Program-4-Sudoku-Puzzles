#include "SudokuFactory.h"

SudokuFactory::SudokuFactory(Reproduction*& offspringCreator)
{
   SudokuOffspring* temp = (SudokuOffspring *) offspringCreator;
   this->offspringCreator_ = temp;
}

Puzzle*& SudokuFactory::createPuzzle(Puzzle*& sudokuPuzzle)
{
   this->offspringCreator_->makeOffspring(sudokuPuzzle);
   return sudokuPuzzle;
}