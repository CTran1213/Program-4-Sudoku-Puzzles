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

vector<vector<int>> Sudoku::getSudokuArray() const
{
   return sudokuNumbers_;
}

bool Sudoku::isFixed(int row, int column) const
{
   if(sudokuNumbers_[row][column])
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool Sudoku::setSudokuBoxValue(int num, int row, int column)
{
   sudokuNumbers_[row][column] = num;
   return true;
}

