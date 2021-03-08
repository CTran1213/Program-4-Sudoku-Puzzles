#include "Sudoku.h"

Sudoku::Sudoku()
{
  sudokuNumbers_.resize(9);
  fixedValues_.resize(9);
  for (int i = 0; i < 9; i++)
  {
     fixedValues_[i].resize(9);
     sudokuNumbers_[i].resize(9);
  }

  for (int i = 0; i < 9; i++)
  {
      for (int j = 0; j < 9; j++)
      {
         fixedValues_[i][j] = false;
      }
  }
}

int Sudoku::getFitness()
{
   return fitnessNumber_;
}

bool Sudoku::setFitnessNumber(int num)
{
   fitnessNumber_ = num;
   return true;
}

vector<vector<int>> Sudoku::getSudokuArray() const
{
   return sudokuNumbers_;
}

bool Sudoku::isFixed(int row, int column) const
{
   if(fixedValues_[row][column])
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
   cout << "NumChange: " << num << endl;
   cout << "Sudoku: " << sudokuNumbers_[row][column] << endl;
   this->sudokuNumbers_[row][column] = num;
   return true;
}

