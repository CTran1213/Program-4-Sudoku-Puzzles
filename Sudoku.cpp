//Sudoku.cpp
//3/12/2021
//@author: Faduma Farah
//@studentID: 1727406
//Catherine Tran ID: 2021829
//This is the implementation of Sudoku.h
//The Sudoku class must hold the representation of a Sudoku puzzle, meaning it must know which numbers in the 
//9-by-9 grid are fixed (the ones given at the start of the puzzle) and which are variable (the ones written 
//in as a possible solution).

#include "Sudoku.h"

//Constructor. Resizes the vector to hold a 9-by-9 grid. Makes every fixed value false.
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

//Destructor
Sudoku::~Sudoku()
{
   
}

//2nd constructor that copies over a sudoku grid and its fixed values
Sudoku::Sudoku(vector<vector<int>>& a, vector<vector<bool>>& b)
{
   this->sudokuNumbers_ = a;
   this->fixedValues_ = b;
}

//Returns the 9-by-9 vector. Is used in other classes to change or look at each box
//Precondition: none
//Postcondition: the sudoku is initialized and the vector is returned
vector<vector<int>> Sudoku::getSudokuArray()
{
   return sudokuNumbers_;
}

//This method returns the 9-by-9 grid of fixed values. Is normally used with the sudoku array
//Precondition: none
//Postcondition: 9-by-9 grid of booleans are returned
vector<vector<bool>> Sudoku::getFixedValues()
{
   return fixedValues_;
}
//Returns a boolean letting the user know if the box at the specified row and column is fixed or not
//Precondition: the sudoku is initialized
//Postcondition: returns true if the box is fixed, false otherwise
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

//This method sets the value of the specified box
//Precondition: None
//Postcondition: The number at row,column is changed. returns true
bool Sudoku::setSudokuBoxValue(int num, int row, int column)
{
   this->sudokuNumbers_[row][column] = num;
   return true;
}