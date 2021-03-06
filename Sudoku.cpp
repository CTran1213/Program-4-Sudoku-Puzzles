#include "Sudoku.h"

Sudoku::Sudoku()
{
   
}

int Sudoku::getFitness()
{
   return this->fitnessObject_.howFit(this->sudokuNumbers_);
}

