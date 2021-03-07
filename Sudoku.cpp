#include "Sudoku.h"

Sudoku::Sudoku()
{
   sudokuNumbers_.resize(9);
   fixedValues_.resize(9);
}

int Sudoku::getFitness()
{
   return this->fitnessObject_.howFit(this->sudokuNumbers_);
}

